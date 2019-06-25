#include "Python.h"
#include "include/IAgoraRtcEngine.h"
#include "include/IAgoraMediaEngine.h"
#include "include/AgoraBase.h"
#include "EventHandlerWrapper.h"
#include "VideoFrameObserverWrapper.h"

void* uint2voidptr(unsigned int e){
    return (void*)e;
}

unsigned int voidptr2uint(void* a){
    return (unsigned int)a;
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





