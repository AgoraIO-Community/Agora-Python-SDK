import os
import clang.cindex
from clang.cindex import Config
from clang.cindex import Cursor
import argparse
from clang.cindex import CursorKind, TypeKind

class cythonGenerator:
    def __init__(self, headName):
        index = clang.cindex.Index.create()
        self.tu = index.parse("%s.h" % headName, args=['-std=c++11'])
        self.public = True
        self.className = []                          # class name stack
        self.classType = []                          # class type stack: 'class','template','struct'
        self.headName = headName.split('/')[-1]
        self.nameSpace = []                          # namespace stack
        self.classDepth = 0                          # the size of class stack
        self.waitPyx = ''                            # Nested class or struct waiting to write to .pyx
        self.waitPxd = ''                            # Nested class or struct waiting to write to .pxd
        self.typedefMap = {}                         # map a typedef name to its type
        self.nowCursor = None
        self.constructCode = {}                      # map a class name to its constructors
        self.constructDict = {}                      # map a class name to the number of its constructor
        self.abstractMap = {}                        # map a class name to whether it is abstract or not
        self.construct = False                       # is now traversing constructor or not
        self.inClassEnum = False
        self.waitPxdChanged = False
        '''callbackdefine'''
        self.callBackDefine = False

    '''external interface: generate cython code'''
    def generate(self, args, mode, fileName=None):
        assert mode in ["add", "new"]
        if fileName == None: self.file = self.headName
        else: self.file = fileName
        if mode == "add":
            self.f_pxd = open('%s.pxd' % self.file, 'a')
            self.f_pyx = open('%s_pyx.pyx' % self.file, 'a')
        else:
            self.f_pxd = open('%s.pxd'%self.file, 'w')
            self.f_pyx = open('%s_pyx.pyx'%self.file, 'w')
            self.writePyx('# distutils: language=c++\nimport cython\nfrom libc.stdlib cimport free\n')
            self.writePyx('cimport %s\nfrom libcpp cimport bool\n'%self.headName)
            self.writePxd('cdef extern from \"ptr_convert.cpp\":\n')
            self.writePxd('\tvoid* py2voidptr(object)\n\tvoid* int2voidptr(unsigned int)\n')
            self.writePxd('\tunsigned int voidptr2int(void* a)\n')
            self.writePxd('\tvoid** py2voidptrptr(object)\n')
            self.writePxd('\tobject voidptr2py (void*)\n')
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
            self.callBackFile = args.callback_wrapper + '.h'
            tu_callBack = index.parse("%s.h" % args.callback_wrapper, args=['-std=c++11'])
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
        self.nowCursor = cursor

        '''callbackdefine'''
        if (self.callBackDefine and str(self.nowCursor.location.file)!= "None" and
                str(self.nowCursor.location.file) != self.callBackFile):
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
            if (default != None):
                self.writePyx("%s = %s\n" % (cursor.spelling, default))
            else:
                self.writePyx("%s\n" % (cursor.spelling))
        '''push namespace to namespace stack'''
        if cursor.kind == CursorKind.NAMESPACE:
            self.nameSpace.append(cursor.spelling)

        '''C++ class definition'''
        if cursor.kind == CursorKind.CLASS_DECL and len(list(cursor.get_children())) > 0:
            self.classType.append('class')
            self.classDefinition()

        '''translate C++ struct to python class'''
        if cursor.kind == CursorKind.STRUCT_DECL:
            if self.public == False: return
            self.classType.append('struct')
            self.classDefinition()
            if len(list(cursor.get_children())) == 0:
                self.writePxd('\t'*(self.classDepth+1) + 'pass\n')

        '''public or private declaration'''
        if cursor.kind == CursorKind.CXX_ACCESS_SPEC_DECL:
            if list(cursor.get_tokens())[0].spelling == 'public':
                self.public = True
            elif list(cursor.get_tokens())[0].spelling in ['private', 'protected']:
                self.public = False

        '''non-static data member in a struct, union, or C++ class'''
        if self.public and cursor.kind == CursorKind.FIELD_DECL:
            Pointer = False
            if cursor.type.kind in [TypeKind.TYPEDEF, TypeKind.UNEXPOSED]:
                type = list(cursor.get_children())[0].spelling
            elif cursor.type.kind in [TypeKind.ENUM,  TypeKind.RECORD]:
                type = list(cursor.get_children())[0].spelling.split()[1].split('::')[-1]
            elif cursor.type.kind == TypeKind.UINT: type = 'unsigned int'
            elif cursor.type.kind == TypeKind.USHORT: type = 'unsigned short'
            elif cursor.type.kind == TypeKind.LONGLONG: type = 'long long'
            #elif cursor.type.kind == TypeKind.BOOL: type = 'bint'
            elif cursor.type.kind == TypeKind.POINTER:
                if len(list(cursor.get_children())) > 0:
                    if len(list(cursor.get_children())[0].spelling.split()) > 1:
                        type = list(cursor.get_children())[0].spelling.split()[1].split('::')[-1]
                    else:
                        type = list(cursor.get_children())[0].spelling
                else:
                    type = self.getType([_.spelling for _ in list(cursor.get_tokens())], ['const'], '*')
                Pointer = True
            else: type = str(cursor.type.kind).split('.')[1].lower()
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
                if type in self.typedefMap.keys(): type = self.typedefMap[type]
                if '*' in type.split(): Pointer, type = True, type.split()[0]
                if Pointer:
                    if type == 'void':
                        self.writePyx('\t'*2+'return voidptr2py(self.c_%s.%s)\n'%(self.className[-1],cursor.spelling))
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
                if type in self.typedefMap.keys(): type = self.typedefMap[type]
                if '*' in type.split(): Pointer, type = True, type.split()[0]
                if 'void' in type.split(): type = ''
                if Pointer:
                    if type == '':
                        self.writePyx('\t' + 'def %s(self, %s):\n' % (cursor.spelling, cursor.spelling))
                        self.writePyx('\t'*2 + 'self.c_%s.%s=py2voidptr(%s)\n' % (self.className[-1], cursor.spelling, cursor.spelling))
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
                self.writePxd('\t'*(self.classDepth+1) + 'ctypedef ')
                type = self.getType([_.spelling for _ in list(cursor.get_tokens())], ['typedef','::'], cursor.spelling).split()
                self.writePxd(' '.join(type) + ' ' + cursor.spelling + '\n')
                self.typedefMap[cursor.spelling] = ' '.join(type)
            else: return
        '''Constructor'''
        if self.public and cursor.kind == CursorKind.CONSTRUCTOR:
            self.construct = True
            if self.classDepth == 1 and self.constructCode[self.className[-1]] == '':
                self.writeAlloc()
            self.constructDict[self.className[-1]] += 1
            self.writePxd('\t'*(self.classDepth+1) + cursor.spelling + '(')
            self.writePyx('\t'+'def construct_%d(self'%(self.constructDict[self.className[-1]]))
            tmpCode = '\t'*2+'self.c_%s = new %s('%(self.className[-1],self.className[-1])
            tmpCode = self.getParam(tmpCode)
            self.writePxd(') except +\n')
            self.writePyx('):\n'+tmpCode+'\n')

        '''C++ method'''
        if self.public and cursor.kind == CursorKind.CXX_METHOD:
            tokens = [_.spelling for _ in list(cursor.get_tokens())]
            if tokens[-2] == '0' and tokens[-3] == '=':
                self.abstractMap[self.className[-1]] = True
            if cursor.spelling[:8] != 'operator':
                type = self.getType([_.spelling for _ in list(cursor.get_tokens())], ['const','::', 'virtual'], cursor.spelling)
                #if type == 'bool': type = 'bint'
                if '*' in type.split(): ReturnPointer = True
                else: ReturnPointer = False
                self.writePxd('\t' *(self.classDepth+1) + type + ' ' + cursor.spelling + '(')
                self.writePyx('\t' +'def '+cursor.spelling+'(self')
                typeRef = self.getTypeRef()
                if typeRef >= 0 and list(cursor.get_children())[typeRef].type.kind == TypeKind.RECORD:
                    type = list(cursor.get_children())[typeRef].spelling.split()[-1].split('::')[-1]
                    tmpCode = '\t'*2 + 'tmp = py%s()\n'%type
                    if ReturnPointer:
                        tmpCode += '\t'*2+'tmp.c_%s=(self.c_%s.%s('%(type,self.className[-1],cursor.spelling)
                    else:
                        tmpCode += '\t'*2+'tmp.c_%s = &self.c_%s.%s('%(type,self.className[-1],cursor.spelling)
                elif list(cursor.get_tokens())[0].spelling != 'void':
                    type = list(cursor.get_tokens())[0].spelling
                    if type in self.typedefMap.keys(): type = self.typedefMap[type]
                    if '*' in type.split(): ReturnPointer, type = True, type.split()[0]
                    if ReturnPointer:
                        if type == 'void':
                            tmpCode = '\t'*2+'return voidptr2py(self.c_%s.%s('%(self.className[-1], cursor.spelling)
                        else:
                            tmpCode = '\t'*2+'return cython.operator.dereference(self.c_%s.%s('%(self.className[-1], cursor.spelling)
                    else:
                        tmpCode = '\t'*2 + 'return self.c_%s.%s(' % (self.className[-1], cursor.spelling)
                else:
                    if ReturnPointer:
                        tmpCode = '\t' * 2 + 'return voidptr2py(self.c_%s.%s(' % (self.className[-1], cursor.spelling)
                    else:
                        tmpCode = '\t'*2+ 'self.c_%s.%s(' % (self.className[-1], cursor.spelling)
                tmpCode = self.getParam(tmpCode)
                self.writePxd(')\n')
                self.writePyx('):\n')
                if ReturnPointer: self.writePyx(tmpCode+')\n')
                else: self.writePyx(tmpCode + '\n')
                if typeRef >= 0 and list(cursor.get_children())[typeRef].type.kind == TypeKind.RECORD:
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
            for i, c in enumerate(cursor.get_children()):
                self.writePyx('\t'  + c.spelling + ' = ')
                self.writePxd('\t'*(self.classDepth+2) + c.spelling + ' = ')
                if len(list(c.get_tokens())) > 2:
                    self.writePyx(list(c.get_tokens())[2].spelling)
                    self.writePxd(list(c.get_tokens())[2].spelling)
                    if list(c.get_tokens())[2].spelling == '-':
                        self.writePyx(list(c.get_tokens())[3].spelling)
                        self.writePxd(list(c.get_tokens())[3].spelling)
                else:
                    self.writePyx(str(i))
                    self.writePxd(str(i))
                self.writePyx('\n')
                self.writePxd('\n')
            self.inClassEnum = False
            return
        '''C++ function'''
        if cursor.kind == CursorKind.FUNCTION_DECL:
            self.writePxd(self.getExtern())
            tokens = ' :: '.join(cursor.result_type.spelling.split('::')).split()
            tokens.append('#')
            type = self.getType(tokens, ['const','::', 'virtual'], '#')
            type = self.transformType(type)
            self.writePxd('\t' + type + ' ' + cursor.spelling + '(')
            self.writePyx('def py'+cursor.spelling+'(')
            if '*' in type.split(): ReturnPointer = True
            else: ReturnPointer = False
            typeRef = self.getTypeRef()
            if  typeRef >= 0 and list(cursor.get_children())[typeRef].type.kind == TypeKind.RECORD:
                type = list(cursor.get_children())[typeRef].spelling.split()[-1].split('::')[-1]
                tmpCode = '\t' + 'tmp = py%s()\n'%type
                if ReturnPointer:
                    tmpCode += '\t' + 'tmp.c_%s = (%s(' % (type, cursor.spelling)
                else:
                    tmpCode += '\t' + 'tmp.c_%s = &%s(' % (type,  cursor.spelling)
            elif len(tokens) > 0 and tokens[0] != 'void':
                if type in self.typedefMap.keys(): type = self.typedefMap[type]
                if '*' in type.split(): ReturnPointer, type = True, type.split()[0]
                if ReturnPointer:
                    if type == 'char':
                        tmpCode = '\t' + 'return (%s(' % (cursor.spelling)
                    else:
                        tmpCode = '\t' + 'return cython.operator.dereference(%s(' % (cursor.spelling)
                else:
                    tmpCode = '\t' + 'return %s(' % (cursor.spelling)
            else:
                if ReturnPointer:
                    tmpCode = '\t' + 'return voidptr2py(%s(' % (cursor.spelling)
                else:
                    tmpCode = '\t' + '%s(' % (cursor.spelling)
            tmpCode = self.getParam(tmpCode)
            self.writePxd(')\n')
            self.writePyx('):\n')
            if ReturnPointer: self.writePyx(tmpCode+')\n')
            else: self.writePyx(tmpCode + '\n')
            if typeRef >= 0 and list(cursor.get_children())[typeRef].type.kind == TypeKind.RECORD:
                self.writePyx('\t' + 'return tmp\n')

        '''Recursively depth-first search'''
        for c in cursor.get_children():
            self.DFS(c)

        '''Depth-first search return'''
        if cursor.kind == CursorKind.NAMESPACE:
            del self.nameSpace[-1]
        elif cursor.kind == CursorKind.CLASS_DECL and len(list(cursor.get_children())) > 0:
            self.returnClean()
        elif cursor.kind in [CursorKind.CLASS_TEMPLATE, CursorKind.STRUCT_DECL]:
            self.returnClean()
        elif self.public and cursor.kind == CursorKind.CONSTRUCTOR:
            self.construct = False

    '''searching return from class or struct declaration'''
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
    def getParam(self, tmpCode):
        cursor = self.nowCursor
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
                    type = list(c.get_children())[0].spelling.split()[-1].split('::')[-1]
                    self.writePyx(type + ' x%d' % paramCount)
                    tmpCode += 'x%d' % paramCount
                    self.writePxd(type + ' x%d' % paramCount)
                elif c.type.kind == TypeKind.RECORD:
                    type = list(c.get_children())[0].spelling.split()[-1].split('::')[-1]
                    self.writePyx('py' + type + ' x%d' % paramCount)
                    tmpCode += 'cython.operator.dereference(x%d.c_%s)'%(paramCount, type)
                    self.writePxd(type + ' x%d' % paramCount)
                elif c.type.kind == TypeKind.LVALUEREFERENCE:
                    type = self.getType([_.spelling for _ in list(c.get_tokens())], ['::', 'const'], '&')
                    if (len(list(c.get_children())) > 0 and list(c.get_children())[-1].kind == CursorKind.TYPE_REF)\
                            or (type in self.constructDict.keys()):
                        self.writePyx('py' + type + ' x%d' % paramCount)
                        tmpCode += 'cython.operator.dereference(x%d.c_%s)' % (paramCount, type)
                    else:
                        type = self.transformType(type)
                        self.writePyx(type + ' x%d' % paramCount)
                        tmpCode += 'x%d' % paramCount
                    self.writePxd("" + type + '& x%d' % paramCount)
                elif c.type.kind in [TypeKind.TYPEDEF, TypeKind.UNEXPOSED]:
                    Pointer = False
                    #type = list(c.get_children())[0].spelling
                    type = self.getType([_.spelling for _ in list(c.get_tokens())], ['::', 'const'], c.spelling)
                    self.writePxd(type + ' x%d' % paramCount)
                    if type in self.typedefMap.keys(): type = self.typedefMap[type]
                    if '*' in type.split():
                        Pointer, type = True, type.split()[0]
                    if 'void' in type.split(): type = ''
                    self.writePyx(type + ' x%d' % paramCount)
                    if Pointer:
                        if type == '':
                            tmpCode += 'py2voidptr(x%d)' % (paramCount)
                        else: tmpCode += '&x%d' % (paramCount)
                    else: tmpCode += 'x%d' % (paramCount)
                elif c.type.kind == TypeKind.POINTER:
                    if len(list(c.get_children()))>0 and list(c.get_tokens())[-2].spelling != '=':
                        if len(list(c.get_children()))>1 and len(list(c.get_children())[1].spelling.split()) > 0\
                            and list(c.get_children())[1].spelling.split()[0] == 'struct':
                            type = list(c.get_children())[1].spelling.split()[-1].split('::')[-1]
                        else:
                            type = list(c.get_children())[0].spelling.split()[-1].split('::')[-1]
                        self.writePyx('py' + type + ' x%d' % paramCount)
                        tmpCode += 'x%d.c_%s' % (paramCount, type)
                        self.writePxd(type + '*x%d' % paramCount)
                    else:
                        type = self.transformType(self.getType([_.spelling for _ in list(c.get_tokens())], ['const'], '*'))
                        if type == 'char':
                            self.writePyx(type + '*x%d' % paramCount)
                            tmpCode += 'x%d' % paramCount
                            self.writePxd(type + ' *x%d' % paramCount)
                        elif type == 'void':
                            self.writePxd(type + ' *x%d' % paramCount)
                            self.writePyx(' x%d' % paramCount)
                            tmpCode += 'py2voidptr(x%d)' % paramCount
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
                    if c.spelling == '':
                        type = self.getType([_.spelling for _ in list(c.get_tokens())], ['const'], '[')
                    else:
                        type = self.getType([_.spelling for _ in list(c.get_tokens())], ['const'], c.spelling)
                    type = self.transformType(type)
                    if type == 'char':
                        self.writePyx(type + '*x%d' % paramCount)
                        tmpCode += 'x%d' % paramCount
                        self.writePxd(type + ' *x%d' % paramCount)
                    else:
                        self.writePyx(type + ' x%d' % paramCount)
                        tmpCode += '&x%d' % paramCount
                        self.writePxd(type + ' *x%d' % paramCount)
                else:
                    type = self.transformType(str(c.type.kind).split('.')[1].lower())
                    self.writePyx(type + ' x%d' % paramCount)
                    tmpCode += 'x%d' % paramCount
                    self.writePxd(type + ' x%d' % paramCount)
                '''
                if c.type.kind not in [TypeKind.ENUM, TypeKind.RECORD, TypeKind.LVALUEREFERENCE, TypeKind.TYPEDEF, TypeKind.POINTER, TypeKind.CONSTANTARRAY]\
                    and len(list(c.get_children())) != 0:
                    default = str(list(list(c.get_children())[0].get_tokens())[0].spelling)
                    self.writePxd(' = ' + default)
                    if default == 'false': default = '0'
                    if default == 'true': default = '1'
                    self.writePyx(' = ' + default)
                '''
        return tmpCode + ')'

    def classDefinition(self, template=None):
        cursor = self.nowCursor
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

    def getType(self, tokens, beginList, endStr):
        begin, end = 0, 0
        for i, t in enumerate(tokens):
            if t in beginList: begin = i + 1
            if t == endStr:
                end = i
                break
        if endStr == '*' and end + 1 < len(tokens) and tokens[end+1] == '*': end += 1
        return ' '.join(tokens[begin:end])

    def transformType(self, type):
        #if type == 'bool': type = 'bint'
        if type == 'ushort': type = 'unsigned short'
        elif type == 'uint': type = 'unsigned int'
        elif type == 'longlong': type = " long long "
        return type

    def getTypeRef(self):
        for i, c in enumerate(self.nowCursor.get_children()):
            if c.kind == CursorKind.TYPE_REF:
                return i
        return -1

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
        #self.writePyx('\t' * 2 + 'pass\n')
        self.writePyx('\t'*2 + 'self.c_%s = new %s()\n' % (self.className[-1], self.className[-1]))
        self.writePyx('\tdef destruct(self):\n\t\tfree(self.c_%s)\n' % self.className[-1])
        self.writePyx('\tdef __dealloc__(self):\n\t\tpass\n')


if __name__ == '__main__':
    Config.set_library_path('.')
    Config.set_library_file('libclang.dll')
    parse = argparse.ArgumentParser()
    parse.add_argument('--head_path', default='include/IAgoraMediaEngine.h', type=str, help='path for the head file')
    parse.add_argument('--extern_pxd', default='', type=str, help='external pxd code')
    parse.add_argument('--extern_pyx', default='', type=str, help='external pyx code')
    parse.add_argument('--callback_wrapper', default='VideoFrameObserverWrapper.h', type=str, help='external pyx code')
    parse.add_argument('--target_file_name', default='IAgoraRtcEngine', type=str, help='name for the target file. If empty, the target file name will be the same with the head file name')
    parse.add_argument('--mode', default='new', type=str, help='[new, add] add to the target file or create a new target file')
    #VideoFrameObserverWrapper EventHandlerWrapper
    args = parse.parse_args()
    args.head_path = ''.join(args.head_path.split('.')[:-1])
    args.callback_wrapper = ''.join(args.callback_wrapper.split('.')[:-1])
    cython = cythonGenerator(args.head_path)
    cython.generate(args, args.mode, args.target_file_name)


