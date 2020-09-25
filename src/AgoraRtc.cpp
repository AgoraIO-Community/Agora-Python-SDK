#include "AgoraRtc.h"
#include "rtc/rtcEngine/RtcEngineBridge.h"

using namespace agora::rtc;

VideoCanvas createVideoCanvas(uint64_t ptr) {
    VideoCanvas canvas;
    canvas.view = (void *)ptr;
    return canvas;
}

agora::common::RtcEngineBridge* createRtcEngineBridge() {
    return new agora::common::RtcEngineBridge();
}
