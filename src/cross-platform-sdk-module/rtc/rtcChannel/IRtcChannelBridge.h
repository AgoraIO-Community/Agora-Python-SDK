//
// Created by 张涛 on 2020-08-10.
//

#pragma once

#include <string>

#include "../callback/rtcChannnelCallback/RtcChannelEventHandler.h"
#include "../common/IBridgeCommon.h"
#include "../include/IAgoraRtcChannel.h"

namespace agora {
namespace common {
class IRtcChannelBridge {
public:
  virtual ~IRtcChannelBridge() = default;

  virtual int
  initChannelEventHandler(rtc::IChannelEventHandler *eventHandler) = 0;

  virtual void add_C_ChannelEventHandler(
      CChannelEngineEventHandler *channelEngineEventHandler) = 0;

  virtual void remove_C_ChannelEventHandler() = 0;

  virtual int callApi(API_TYPE apiType, const std::string &parameters) = 0;

  virtual const char *callApi_str(API_TYPE apiType,
                                  const std::string &parameters) = 0;

  virtual int callApi(API_TYPE apiType, const std::string &parameters,
                      void *ptr) = 0;

  virtual void release() = 0;
};
} // namespace common
} // namespace agora
