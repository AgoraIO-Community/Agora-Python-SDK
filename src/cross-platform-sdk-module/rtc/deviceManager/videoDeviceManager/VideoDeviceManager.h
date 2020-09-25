//
// Created by 张涛 on 2020-08-17.
//
#pragma once

#include "../../common/IBridgeCommon.h"
#include "../../include/IAgoraRtcEngine.h"
#include "../IVideoDeviceManagerBridge.h"
#include <stdint.h>

namespace agora {
namespace common {
class VideoDeviceManager : public IVideoDeviceManagerBridge {

private:
  rtc::IVideoDeviceCollection *videoDeviceCollection = nullptr;
  rtc::AVideoDeviceManager *videoDeviceManager = nullptr;

public:
  VideoDeviceManager(rtc::IRtcEngine *mRtcEngine, ERROR_CODE &ret);

  virtual ~VideoDeviceManager();

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr) override;

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr,
                      void *&ptr2) override;

  int startDeviceTest(rtc::view_t hwnd);

  int startDeviceTest(uint64_t hwnd);

  int stopDeviceTest();

  int getDeviceCount();

  int setDevice(const char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  int getCurrentDevice(char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  int getDevice(int index, char deviceName[rtc::MAX_DEVICE_ID_LENGTH],
                char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  virtual void release() override;
};
} // namespace common
} // namespace agora
