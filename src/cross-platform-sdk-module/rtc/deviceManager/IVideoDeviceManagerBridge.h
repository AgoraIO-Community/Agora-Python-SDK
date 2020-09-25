//
// Created by 张涛 on 2020-08-17.
//

#pragma once

#include "../common/IBridgeCommon.h"
#include "../include/IAgoraRtcEngine.h"
#include <string>

namespace agora {
namespace common {
class IVideoDeviceManagerBridge {

public:
  virtual ~IVideoDeviceManagerBridge() = default;

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr) = 0;

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr,
                      void *&ptr2) = 0;

  virtual void release() = 0;
};
} // namespace common
} // namespace agora