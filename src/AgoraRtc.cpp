#include "AgoraRtc.h"
#include "rtc/rtcEngine/RtcEngineBridge.h"
#include "rtc/include/IAgoraMediaEngine.h"

class MyVideoFrameObserver : public agora::media::IVideoFrameObserver {
    public:
    MyVideoFrameObserver(VideoFrameObserver * videoFrameObserver) : videoFrameObserver_(videoFrameObserver) {

    }

    virtual bool onCaptureVideoFrame(VideoFrame& videoFrame) override {
        if (videoFrameObserver_)
        {
            videoFrameObserver_->onCaptureVideoFrame(videoFrame.width, videoFrame.height, (uint64_t)videoFrame.yBuffer, (uint64_t)videoFrame.uBuffer, (uint64_t)videoFrame.vBuffer);
        }
        
        return true;
    }

    virtual bool onPreEncodeVideoFrame(VideoFrame& videoFrame) override {
        return true;
    }

    virtual bool onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame) override {
        if (videoFrameObserver_)
        {
            videoFrameObserver_->onRenderVideoFrame(uid, videoFrame.width, videoFrame.height, (uint64_t)videoFrame.yBuffer, (uint64_t)videoFrame.uBuffer, (uint64_t)videoFrame.vBuffer);
        }
        
        return true;
    }

    virtual bool getRotationApplied() override {
        return true;
    }

    virtual VIDEO_FRAME_TYPE getVideoFormatPreference() override {
        return FRAME_TYPE_RGBA;
    }
    private:
    VideoFrameObserver* videoFrameObserver_ = nullptr;
};

using namespace agora::rtc;

VideoCanvas createVideoCanvas(uint64_t ptr) {
    VideoCanvas canvas;
    canvas.view = (void *)ptr;
    return canvas;
}

agora::common::RtcEngineBridge* createRtcEngineBridge() {
    return new agora::common::RtcEngineBridge();
}

void registerVideoFrameObserver(agora::common::RtcEngineBridge* rtc, VideoFrameObserver * frameObserver) {
    MyVideoFrameObserver * fo = new MyVideoFrameObserver(frameObserver);
    frameObserver->privateData = fo;
    rtc->registerVideoFrameObserver(fo);

}
void unregisterVideoFrameObserver(agora::common::RtcEngineBridge* rtc, VideoFrameObserver * frameObserver) {
    rtc->registerVideoFrameObserver(nullptr);
    MyVideoFrameObserver * fo = (MyVideoFrameObserver *)frameObserver->privateData;
    delete fo;
}