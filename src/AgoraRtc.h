#ifndef AGORA_RTC_H
#define AGORA_RTC_H
#include <stdint.h>

namespace agora {
    namespace rtc {
        struct VideoCanvas;
    }
    namespace common {
        class RtcEngineBridge;
    }
}

agora::rtc::VideoCanvas createVideoCanvas(uint64_t ptr);

agora::common::RtcEngineBridge* createRtcEngineBridge();

class VideoFrameObserver {
public:
    virtual ~VideoFrameObserver() {}
    virtual void onCaptureVideoFrame(int width, int height, uint64_t ybuffer, uint64_t ubuffer, uint64_t vbuffer) = 0;
    virtual void onRenderVideoFrame(unsigned int uid, int width, int height, uint64_t ybuffer, uint64_t ubuffer, uint64_t vbuffer) = 0;

    void * privateData = nullptr;
};

void registerVideoFrameObserver(agora::common::RtcEngineBridge* rtc, VideoFrameObserver * frameObserver);
void unregisterVideoFrameObserver(agora::common::RtcEngineBridge* rtc, VideoFrameObserver * frameObserver);

#endif