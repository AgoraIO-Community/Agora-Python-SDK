#include "Python.h"
#include "include/IAgoraRtcEngine.h"
#include "include/IAgoraMediaEngine.h"
#include "include/AgoraBase.h"
#include "EventHandlerWrapper.h"
#include "VideoFrameObserverWrapper.h"

void* py2voidptr(PyObject *o)
{
    void* a = o;
    return a;
}

void* int2voidptr(unsigned int e){
    return (void*)e;
}

unsigned int voidptr2int(void* a){
    return (unsigned int)a;
}

PyObject* voidptr2py(void* a)
{
    PyObject *o = (PyObject *) a;
    Py_XINCREF(o);
    return o;
}

void** py2voidptrptr(PyObject *o)
{
    void* a = o;
    return &a;
}

IRtcEngineEventHandler* convert(EventHandler* e)
{
    return e;
}

EventHandler* convertBack(IRtcEngineEventHandler* e)
{
    return dynamic_cast<EventHandler*>(e);
}

IVideoFrameObserver* convert2(VideoFrameObserver* e)
{
    return e;
}

VideoFrameObserver*  convertBack2(IVideoFrameObserver* e)
{
    return dynamic_cast<VideoFrameObserver*>(e);
}

agora::media::IMediaEngine* getMediaEngine(agora::rtc::IRtcEngine* e)
{
    void *p;
    e->queryInterface(agora::AGORA_IID_MEDIA_ENGINE, &p);
    return (agora::media::IMediaEngine*)p;
}





