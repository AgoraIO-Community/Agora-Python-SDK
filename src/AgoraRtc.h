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

#endif