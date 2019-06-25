import os
import clang.cindex
from clang.cindex import Config
from clang.cindex import Cursor, AccessSpecifier
import argparse
from clang.cindex import CursorKind, TypeKind

class cythonGenerator:
    def __init__(self, headName):
        index = clang.cindex.Index.create()
        self.Conf = Config()
        self.tu = index.parse(headName, args=['-std=c++11'])
        self.className = []                          # class name stack
        self.classType = []                          # class type stack: 'class','template','struct'
        self.headName = headName.split('/')[-1].split('.')[0]
        self.nameSpace = []                          # namespace stack
        self.classDepth = 0                          # the size of class stack
        self.waitPyx = ''                            # Nested class or struct or enum waiting to write to .pyx
        self.waitPxd = ''                            # Nested class or struct or enum waiting to write to .pxd
        self.typedefMap = {}                         # map a typedef name to its type
        self.constructCode = {}                      # map a class name to its constructors
        self.constructDict = {}                      # map a class name to the number of its constructor
        self.abstractMap = {}                        # map a class name to whether it is abstract or not
        self.construct = False                       # is now traversing constructor or not
        self.inClassEnum = False                     # is now traversing nested enum or not
        self.waitPxdChanged = False

        '''callbackdefine'''
        self.callBackDefine = False

    '''external interface: generate cython code'''
    def generate(self, args, mode, fileName=None):
        assert mode in ["add", "new"]
        if fileName == None: self.file = self.headName
        else: self.file = fileName
        if mode == "add":                                        # add to the target file
            self.f_pxd = open('%s.pxd' % self.file, 'a')
            self.f_pyx = open('%s_pyx.pyx' % self.file, 'a')
        else:                                                    # create a new target file
            self.f_pxd = open('%s.pxd'%self.file, 'w')
            self.f_pyx = open('%s_pyx.pyx'%self.file, 'w')
            self.writePyx('# distutils: language=c++\nimport cython\nfrom libc.stdlib cimport free\n')
            self.writePyx('cimport %s\nfrom libcpp cimport bool\n'%self.headName)
            self.writePxd('cdef extern from \"ptr_convert.cpp\":\n')
            self.writePxd('\tvoid* uint2voidptr(unsigned int)\n')
            self.writePxd('\tunsigned int voidptr2uint(void* a)\n')
            self.writePxd('\tvoid** py2voidptrptr(object)\n')
            self.writePxd('\tIRtcEngineEventHandler* convert(EventHandler* e)\n')
            self.writePxd('\tEventHandler* convertBack(IRtcEngineEventHandler* e)\n')
            self.writePxd('\tIVideoFrameObserver* convert2(VideoFrameObserver* e)\n')
            self.writePxd('\tVideoFrameObserver*  convertBack2(IVideoFrameObserver* e)\n')
            self.writePxd('from libcpp cimport bool\n')
        self.DFS(self.tu.cursor)
        index = clang.cindex.Index.create()

        '''callbackdefine'''
        self.callBackDefine = True
        if args.callback_wrapper != "":
            self.callBackFile = args.callback_wrapper
            tu_callBack = index.parse(args.callback_wrapper, args=['-std=c++11'])
            self.DFS(tu_callBack.cursor)
        if (args.extern_pxd != ""):
            extern_f = open(args.extern_pxd, 'r')
            self.f_pxd.write(extern_f.read())
        if (args.extern_pyx != ""):
            extern_f = open(args.extern_pyx, 'r')
            self.f_pyx.write(extern_f.read())
        self.f_pxd.close()
        self.f_pyx.close()

    '''depth-first search'''
    def DFS(self, cursor):
        '''callbackdefine'''
        self.nowCursor = cursor
        if (self.callBackDefine and str(cursor.location.file)!= "None" and
                str(cursor.location.file) != self.callBackFile):
            return
        if cursor.spelling in['AutoPtr', 'ensureGILstate']: return
        #print cursor.spelling, cursor.kind, cursor.type.kind, cursor.location.line

        '''global variable definition'''
        if cursor.kind == CursorKind.VAR_DECL and len(self.className) == 0\
            and str(cursor.location.file).split('/')[-1].split('.')[0] == self.headName:
            default = None
            for i, t in enumerate(list(cursor.get_tokens())):
                if (t.spelling == "="):
                    default = list(cursor.get_tokens())[i+1].spelling
                    if default == '-': default += list(cursor.get_tokens())[i+2].spelling
                    break
            if default != None:
                self.writePyx("%s = %s\n" % (cursor.spelling, default))
            else:
                self.writePyx("%s\n" % (cursor.spelling))

        '''push namespace to namespace stack'''
        if cursor.kind == CursorKind.NAMESPACE:
            self.nameSpace.append(cursor.spelling)

        '''C++ class definition'''
        if cursor.kind == CursorKind.CLASS_DECL:
            if cursor.is_definition():
                self.classType.append('class')
                self.classDefinition(cursor)
            else:
                self.constructDict[cursor.spelling] = 0

        '''translate C++ struct to python class'''
        if cursor.kind == CursorKind.STRUCT_DECL:
            if self.checkAccess(cursor) == False: return
            self.classType.append('struct')
            self.classDefinition(cursor)
            if len(list(cursor.get_children())) == 0:
                self.writePxd('\t'*(self.classDepth+1) + 'pass\n')

        '''non-static data member in a struct, union, or C++ class'''
        if self.checkAccess(cursor) and cursor.kind == CursorKind.FIELD_DECL:
            if cursor.type.kind == TypeKind.POINTER:
                Pointer = True
                type = self.getType(cursor.type.get_pointee().spelling)
            else:
                Pointer = False
                type = self.getType(cursor.type.spelling)
            if Pointer:
                self.writePxd('\t'*(self.classDepth+1) + type + '* ' + cursor.spelling +'\n')
            else:
                self.writePxd('\t' * (self.classDepth + 1) + type + ' ' + cursor.spelling + '\n')
            self.writePyx('\t' + '@property\n\t' + 'def %s(self):\n'%cursor.spelling)
            if type in self.constructDict.keys():
                self.writePyx('\t'*2 + 'tmp = py%s()\n'%type)
                if Pointer:
                    self.writePyx('\t'*2+'tmp.c_%s = (self.c_%s.%s)\n'%(type,self.className[-1], cursor.spelling))
                else:
                    self.writePyx('\t'*2+'tmp.c_%s = &self.c_%s.%s\n'%(type, self.className[-1], cursor.spelling))
                self.writePyx('\t'*2 + 'return tmp\n')
            else:
                if type in self.typedefMap.keys():
                    type = self.typedefMap[type]
                if '*' in type.split(): Pointer, type = True, type.split()[0]
                if Pointer:
                    if type == 'void':
                        self.writePyx('\t'*2+'return voidptr2uint(self.c_%s.%s)\n'%(self.className[-1],cursor.spelling))
                    else:
                        self.writePyx('\t'*2+'return cython.operator.dereference(self.c_%s.%s)\n'%(self.className[-1], cursor.spelling))
                else:
                    self.writePyx('\t'*2 + 'return self.c_%s.%s\n'%(self.className[-1], cursor.spelling))
            self.writePyx('\t' + '@%s.setter\n'%cursor.spelling)
            if type in self.constructDict.keys():
                self.writePyx('\t' + 'def %s(self,py%s %s):\n'%(cursor.spelling, type, cursor.spelling))
                if Pointer:
                    self.writePyx('\t'*2+'self.c_%s.%s=%s.c_%s\n'%(self.className[-1], cursor.spelling, cursor.spelling, type))
                else:
                    self.writePyx('\t'*2+'self.c_%s.%s=cython.operator.dereference(%s.c_%s)\n'%(self.className[-1], cursor.spelling, cursor.spelling, type))
            else:
                if type in self.typedefMap.keys():
                    type = self.typedefMap[type]
                if '*' in type.split(): Pointer, type = True, ' '.join(type.split()[:-1])
                if Pointer:
                    if type == 'void':
                        self.writePyx('\t' + 'def %s(self, unsigned int %s):\n' % (cursor.spelling, cursor.spelling))
                        self.writePyx('\t'*2 + 'self.c_%s.%s=uint2voidptr(%s)\n' % (self.className[-1], cursor.spelling, cursor.spelling))
                    elif type in ['unsigned char', 'char']:
                        self.writePyx('\t' + 'def %s(self, %s):\n' % (cursor.spelling, cursor.spelling))
                        self.writePyx('\t'*2 + 'self.c_%s.%s=%s\n' % (self.className[-1], cursor.spelling, cursor.spelling))
                    else:
                        self.writePyx('\t' + 'def %s(self, %s %s):\n' % (cursor.spelling, type, cursor.spelling))
                        self.writePyx('\t'*2 + 'self.c_%s.%s=&%s\n' % (self.className[-1], cursor.spelling, cursor.spelling))
                else:
                    self.writePyx('\t' + 'def %s(self, %s %s):\n' % (cursor.spelling, type, cursor.spelling))
                    self.writePyx('\t'*2 + 'self.c_%s.%s=%s\n' % (self.className[-1], cursor.spelling, cursor.spelling))

        '''typedef declaration'''
        if cursor.kind == CursorKind.TYPEDEF_DECL:
            if (len(list(cursor.get_children())) == 0 or list(cursor.get_children())[0].kind != CursorKind.STRUCT_DECL):
                if self.classDepth == 0: self.writePxd(self.getExtern())
                type = cursor.underlying_typedef_type.spelling
                self.writePxd('\t'*(self.classDepth+1) + 'ctypedef ')
                self.writePxd(type + ' ' + cursor.spelling + '\n')
                self.typedefMap[cursor.spelling] = type
            else: return

        '''Constructor'''
        if self.checkAccess(cursor) and cursor.kind == CursorKind.CONSTRUCTOR:
            self.construct = True
            if self.classDepth == 1 and self.constructCode[self.className[-1]] == '':
                self.writeAlloc()
            self.constructDict[self.className[-1]] += 1
            self.writePxd('\t'*(self.classDepth+1) + cursor.spelling + '(')
            self.writePyx('\t'+'def construct_%d(self'%(self.constructDict[self.className[-1]]))
            tmpCode = '\t'*2+'self.c_%s = new %s('%(self.className[-1],self.className[-1])
            tmpCode = self.getParam(cursor, tmpCode)
            self.writePxd(') except +\n')
            self.writePyx('):\n'+tmpCode+'\n')

        '''C++ method'''
        if self.checkAccess(cursor) and cursor.kind == CursorKind.CXX_METHOD:
            if self.Conf.lib.clang_CXXMethod_isPureVirtual(cursor):
                self.abstractMap[self.className[-1]] = True
            if cursor.spelling[:8] != 'operator':
                if cursor.result_type.kind == TypeKind.POINTER:
                    ReturnPointer = True
                    type = self.getType(cursor.result_type.get_pointee().spelling)
                    self.writePxd('\t' * (self.classDepth + 1) + type + '* ' + cursor.spelling + '(')
                else:
                    ReturnPointer = False
                    type = self.getType(cursor.result_type.spelling)
                    self.writePxd('\t' * (self.classDepth + 1) + type + ' ' + cursor.spelling + '(')
                self.writePyx('\t' +'def '+cursor.spelling+'(self')
                if type in self.constructDict.keys():
                    tmpCode = '\t'*2 + 'tmp = py%s()\n'%type
                    if ReturnPointer:
                        tmpCode += '\t'*2+'tmp.c_%s=(self.c_%s.%s('%(type,self.className[-1],cursor.spelling)
                    else:
                        tmpCode += '\t'*2+'tmp.c_%s = &self.c_%s.%s('%(type,self.className[-1],cursor.spelling)
                else:
                    if type in self.typedefMap.keys():
                        type = self.typedefMap[type]
                    if '*' in type.split(): ReturnPointer, type = True, ' '.join(type.split()[:-1])
                    if ReturnPointer:
                        if type == 'void':
                            tmpCode = '\t'*2+'return voidptr2uint(self.c_%s.%s('%(self.className[-1], cursor.spelling)
                        else:
                            tmpCode = '\t'*2+'return cython.operator.dereference(self.c_%s.%s('%(self.className[-1], cursor.spelling)
                    else:
                        if type == 'void':
                            tmpCode = '\t' * 2 + 'self.c_%s.%s(' % (self.className[-1], cursor.spelling)
                        else:
                            tmpCode = '\t'*2 + 'return self.c_%s.%s(' % (self.className[-1], cursor.spelling)
                tmpCode = self.getParam(cursor, tmpCode)
                self.writePxd(')\n')
                self.writePyx('):\n')
                if ReturnPointer:
                    self.writePyx(tmpCode+')\n')
                else:
                    self.writePyx(tmpCode + '\n')
                if type in self.constructDict.keys():
                    self.writePyx('\t'*2 + 'return tmp\n')

        '''c++ enum'''
        if cursor.kind == CursorKind.ENUM_DECL:
            if self.classDepth == 0:
                self.writePxd(self.getExtern())
                self.writePxd('\t'*(self.classDepth+1) + 'cdef enum %s:\n'%cursor.spelling)
            else:
                self.inClassEnum = True
                self.waitPxdChanged = True
                self.writePxd('\t' * (self.classDepth + 1) + 'enum %s:\n' % cursor.spelling)
            self.writePyx('class py%s:\n'%(cursor.spelling))
            for c in cursor.get_children():
                self.writePyx('\t%s = %s\n' % (c.spelling, str(c.enum_value)))
                self.writePxd('\t'*(self.classDepth+2) + '%s = %s\n' % (c.spelling, str(c.enum_value)))
            self.inClassEnum = False
            return

        '''C++ function'''
        if cursor.kind == CursorKind.FUNCTION_DECL:
            self.writePxd(self.getExtern())
            if cursor.result_type.kind == TypeKind.POINTER:
                ReturnPointer = True
                type = self.getType(cursor.result_type.get_pointee().spelling)
                self.writePxd('\t' + type + '* ' + cursor.spelling + '(')
            else:
                ReturnPointer = True
                type = self.getType(cursor.result_type.spelling)
                self.writePxd('\t' + type + ' ' + cursor.spelling + '(')
            self.writePyx('def py'+cursor.spelling+'(')
            if type in self.constructDict.keys():
                tmpCode = '\t' + 'tmp = py%s()\n'%type
                if ReturnPointer:
                    tmpCode += '\t' + 'tmp.c_%s = (%s(' % (type, cursor.spelling)
                else:
                    tmpCode += '\t' + 'tmp.c_%s = &%s(' % (type,  cursor.spelling)
            else:
                if type in self.typedefMap.keys():
                    type = self.typedefMap[type]
                if '*' in type.split(): ReturnPointer, type = True, ' '.join(type.split()[:-1])
                if ReturnPointer:
                    if type == 'char':
                        tmpCode = '\t' + 'return (%s(' % (cursor.spelling)
                    elif type == 'void':
                        tmpCode = '\t' + 'return voidptr2uint(%s(' % (cursor.spelling)
                    else:
                        tmpCode = '\t' + 'return cython.operator.dereference(%s(' % (cursor.spelling)
                else:
                    if type == 'void':
                        tmpCode = '\t' + '%s(' % (cursor.spelling)
                    else:
                        tmpCode = '\t' + 'return %s(' % (cursor.spelling)
            tmpCode = self.getParam(cursor, tmpCode)
            self.writePxd(')\n')
            self.writePyx('):\n')
            if ReturnPointer:
                self.writePyx(tmpCode+')\n')
            else:
                self.writePyx(tmpCode + '\n')
            if type in self.constructDict.keys():
                self.writePyx('\t' + 'return tmp\n')

        '''Recursively depth-first search'''
        for c in cursor.get_children():
            self.DFS(c)

        '''Depth-first search return'''
        if cursor.kind == CursorKind.NAMESPACE:
            del self.nameSpace[-1]
        elif cursor.kind == CursorKind.CLASS_DECL and cursor.is_definition():
            self.returnClean()
        elif cursor.kind == CursorKind.STRUCT_DECL:
            self.returnClean()
        elif self.checkAccess(cursor) and cursor.kind == CursorKind.CONSTRUCTOR:
            self.construct = False

    ''' return from class or struct declaration'''
    def returnClean(self):
        if not self.abstractMap[self.className[-1]]:
            if self.constructCode[self.className[-1]] != '':
                self.writePyx(self.constructCode[self.className[-1]])
            else:
                self.writeAlloc()
        self.classDepth -= 1
        del self.className[-1], self.classType[-1], self.nameSpace[-1]
        self.writePyx('')
        self.writePxd('')

    '''write parameters of a C++ method or a function'''
    def getParam(self, cursor, tmpCode):
        paramCount = 0
        for c in cursor.get_children():
            if c.kind == CursorKind.PARM_DECL:
                paramCount += 1
                if cursor.kind != CursorKind.FUNCTION_DECL or paramCount != 1:
                    self.writePyx(',')
                if paramCount != 1:
                    self.writePxd(',')
                    tmpCode += ','
                if c.type.kind == TypeKind.ENUM:
                    type = self.getType(c.type.spelling)
                    self.writePyx(type + ' x%d' % paramCount)
                    tmpCode += 'x%d' % paramCount
                    self.writePxd(type + ' x%d' % paramCount)
                elif c.type.kind == TypeKind.RECORD:
                    type = self.getType(c.type.spelling)
                    self.writePyx('py' + type + ' x%d' % paramCount)
                    tmpCode += 'cython.operator.dereference(x%d.c_%s)'%(paramCount, type)
                    self.writePxd(type + ' x%d' % paramCount)
                elif c.type.kind == TypeKind.LVALUEREFERENCE:
                    type = self.getType(c.type.get_pointee().spelling)
                    if type in self.constructDict.keys():
                        self.writePyx('py' + type + ' x%d' % paramCount)
                        tmpCode += 'cython.operator.dereference(x%d.c_%s)' % (paramCount, type)
                    else:
                        self.writePyx(type + ' x%d' % paramCount)
                        tmpCode += 'x%d' % paramCount
                    self.writePxd("" + type + '& x%d' % paramCount)
                elif c.type.kind in [TypeKind.TYPEDEF, TypeKind.UNEXPOSED]:
                    Pointer, void = False, False
                    type = self.getType(c.type.spelling)
                    self.writePxd(type + ' x%d' % paramCount)
                    if type in self.typedefMap.keys():
                        type = self.typedefMap[type]
                    if '*' in type.split():
                        Pointer, type = True, ' '.join(type.split()[:-1])
                    if 'void' in type.split():
                        type = 'unsigned int'
                        void = True
                    self.writePyx(type + ' x%d' % paramCount)
                    if Pointer:
                        if void:
                            tmpCode += 'uint2voidptr(x%d)' % (paramCount)
                        else: tmpCode += '&x%d' % (paramCount)
                    else: tmpCode += 'x%d' % (paramCount)
                elif c.type.kind == TypeKind.POINTER:
                    type = self.getType(c.type.get_pointee().spelling)
                    if len(list(c.get_children()))>0 and list(c.get_tokens())[-2].spelling != '=':
                        self.writePyx('py' + type + ' x%d' % paramCount)
                        tmpCode += 'x%d.c_%s' % (paramCount, type)
                        self.writePxd(type + '*x%d' % paramCount)
                    else:
                        if type == 'char':
                            self.writePyx(type + '*x%d' % paramCount)
                            tmpCode += 'x%d' % paramCount
                            self.writePxd(type + ' *x%d' % paramCount)
                        elif type == 'void':
                            self.writePxd(type + ' *x%d' % paramCount)
                            self.writePyx('unsigned int x%d' % paramCount)
                            tmpCode += 'uint2voidptr(x%d)' % paramCount
                        elif type == 'void *':
                            self.writePxd(type + ' *x%d' % paramCount)
                            self.writePyx(' x%d' % paramCount)
                            tmpCode += 'py2voidptrptr(x%d)' % paramCount
                        else:
                            self.writePxd(type + ' *x%d' % paramCount)
                            if type == 'void': type = ''
                            self.writePyx(type + ' x%d' % paramCount)
                            tmpCode += '&x%d' % paramCount
                elif c.type.kind in [TypeKind.CONSTANTARRAY, TypeKind.CHAR_S]:
                    type = self.getType(c.type.get_array_element_type().spelling)
                    if type == 'char':
                        self.writePyx(type + '*x%d' % paramCount)
                        tmpCode += 'x%d' % paramCount
                        self.writePxd(type + ' *x%d' % paramCount)
                    else:
                        self.writePyx(type + ' x%d' % paramCount)
                        tmpCode += '&x%d' % paramCount
                        self.writePxd(type + ' *x%d' % paramCount)
                else:
                    self.writePyx(c.type.spelling + ' x%d' % paramCount)
                    tmpCode += 'x%d' % paramCount
                    self.writePxd(c.type.spelling + ' x%d' % paramCount)
        return tmpCode + ')'

    def classDefinition(self, cursor):
        self.className.append(cursor.spelling)
        self.classDepth += 1
        self.constructCode[cursor.spelling] = ''
        self.constructDict[cursor.spelling] = 0
        self.abstractMap[cursor.spelling] = False
        if self.classDepth == 1:
            self.writePxd(self.getExtern())
            self.writePxd('\t' * (self.classDepth) + 'cdef cppclass %s:\n' % cursor.spelling)
        else:
            self.waitPxdChanged = True
            self.writePxd('\t' * (self.classDepth) + 'cppclass %s:\n' % cursor.spelling)
        self.writePyx('from %s cimport %s\n' % (self.file, cursor.spelling))
        self.writePyx('cdef class py%s:\n' % cursor.spelling)
        self.writePyx('\t' + 'cdef %s *c_%s\n' % (cursor.spelling, cursor.spelling))
        self.nameSpace.append(cursor.spelling)

    def getExtern(self):
        extern = 'cdef extern from \"%s\"'%str(self.nowCursor.location.file)
        if len(self.nameSpace) > 0:
            for i, name in enumerate(self.nameSpace):
                if i == 0: extern += ('namespace \"')
                if i > 0: extern += ('::')
                extern += (name)
            extern += ('\"')
        return extern + ":\n"

    def writePxd(self, context):
        if (self.classDepth == 0) and self.waitPxd != '':
            self.f_pxd.write(self.waitPxd)
            self.waitPxd = ''
        self.f_pxd.write(context)
        if self.classDepth > 1 or self.inClassEnum:
            if self.waitPxd == '' or self.waitPxdChanged:
                self.waitPxdChanged = False
                self.waitPxd += self.getExtern()
            if context[0] == '\t':
                self.waitPxd += context[self.classDepth-1:]
            else:
                self.waitPxd += context
    
    def writePyx(self, context):
        if self.classDepth == 1 and self.inClassEnum == False:
            if not self.construct:
                self.f_pyx.write(context)
            else:
                self.constructCode[self.className[-1]] += context
        elif self.classDepth > 1 or self.inClassEnum:
            if not self.construct:
                self.waitPyx += context
            else:
                self.constructCode[self.className[-1]] += context
        else:
            if self.waitPyx != '':
                self.f_pyx.write(self.waitPyx)
            self.waitPyx = ''
            self.f_pyx.write(context)

    def writeAlloc(self):
        self.writePyx('\tdef __cinit__(self):\n')
        self.writePyx('\t'*2 + 'self.c_%s = new %s()\n' % (self.className[-1], self.className[-1]))
        self.writePyx('\tdef destruct(self):\n\t\tfree(self.c_%s)\n' % self.className[-1])
        self.writePyx('\tdef __dealloc__(self):\n\t\tpass\n')

    def checkAccess(self, cursor):
        if cursor.access_specifier in [AccessSpecifier.PROTECTED, AccessSpecifier.PRIVATE]:
            return False
        return True

    def getType(self, context):
        type = context.split()
        if type[0] == 'const':
            type = ' '.join(type[1:])
        else:
            type = ' '.join(type[0:])
        return type.split('::')[-1]

if __name__ == '__main__':
    Config.set_library_path('.')
    Config.set_library_file('libclang.dll')
    parse = argparse.ArgumentParser()
    parse.add_argument('--head_path', default='include/IAgoraRtcEngine.h', type=str, help='path for the head file')
    parse.add_argument('--extern_pxd', default='', type=str, help='external pxd code')
    parse.add_argument('--extern_pyx', default='', type=str, help='external pyx code')
    parse.add_argument('--callback_wrapper', default='EventHandlerWrapper.h', type=str, help='external pyx code')
    parse.add_argument('--target_file_name', default='IAgoraRtcEngine', type=str, help='name for the target file. If empty, the target file name will be the same with the head file name')
    parse.add_argument('--mode', default='new', type=str, help='[new, add] add to the target file or create a new target file')
    args = parse.parse_args()
    cython = cythonGenerator(args.head_path)
    cython.generate(args, args.mode, args.target_file_name)