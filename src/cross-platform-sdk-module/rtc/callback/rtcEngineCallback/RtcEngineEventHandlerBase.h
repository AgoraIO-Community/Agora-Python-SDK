#ifndef RtcEngineBridgeEventHandler_h
#define RtcEngineBridgeEventHandler_h

#include "../../include/IAgoraRtcEngine.h"

namespace agora {
namespace common {

class RtcEngineEventHandlerBase : public rtc::IRtcEngineEventHandler {
public:
    virtual void onTestEnd() {}
};


}
}


#endif /* RtcEngineBridgeEventHandler_h */
