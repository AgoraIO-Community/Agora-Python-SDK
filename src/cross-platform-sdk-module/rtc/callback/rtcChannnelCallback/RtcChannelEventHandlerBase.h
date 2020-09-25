//
//  RtcChannelBridgeEventHandler.h
//  Agora-Mac-Tutorial-Objective-C
//
//  Created by DYF on 2020/9/10.
//  Copyright © 2020 Agora.io. All rights reserved.
//

#ifndef RtcChannelBridgeEventHandler_h
#define RtcChannelBridgeEventHandler_h

#include "../../include/IAgoraRtcChannel.h"

namespace agora {
namespace common {

class RtcChannelEventHandlerBase : public rtc::IChannelEventHandler {
public:
  virtual void onTestEnd(rtc::IChannel *rtcChannel) {}
};

} // namespace common
} // namespace agora

#endif /* RtcChannelBridgeEventHandler_h */
