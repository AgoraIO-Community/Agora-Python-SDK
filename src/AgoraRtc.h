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

class AudioFrameObserver {
public:
    virtual ~AudioFrameObserver() {}
    virtual void onRecordAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type) = 0;
    virtual void onPlaybackAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type) = 0;
    virtual void onMixedAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type) = 0;
    virtual void onPlaybackAudioFrameBeforeMixing(unsigned int uid, unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type) = 0;

    void * privateData = nullptr;
};

void registerAudioFrameObserver(agora::common::RtcEngineBridge* rtc, AudioFrameObserver * frameObserver);
void unregisterAudioFrameObserver(agora::common::RtcEngineBridge* rtc, AudioFrameObserver * frameObserver);

#endif