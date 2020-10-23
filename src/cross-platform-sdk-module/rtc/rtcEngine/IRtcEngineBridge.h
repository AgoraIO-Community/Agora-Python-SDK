#pragma once

#include <string>

#include "../callback/rtcEngineCallback/RtcEngineEventHandler.h"
#include "../common/IBridgeCommon.h"
#include "../deviceManager/IAudioDeviceManagerBridge.h"
#include "../deviceManager/IVideoDeviceManagerBridge.h"
#include "../include/IAgoraRtcEngine.h"
#include "../rtcChannel/IRtcChannelBridge.h"

namespace agora {
namespace common {
class IRtcEngineBridge {
public:
  virtual ~IRtcEngineBridge() = default;

  virtual int initEventHandler(rtc::IRtcEngineEventHandler *eventHandler) = 0;

  virtual void add_C_EventHandler(CEngineEventHandler *engineEventHandler) = 0;

  virtual void remove_C_EventHandler() = 0;

  virtual int callApi(API_TYPE apiType, const std::string &parameters) = 0;

  virtual const char *callApi_str(API_TYPE apiType,
                                  const std::string &parameters) = 0;

  virtual int callApi(API_TYPE apiType, const std::string &parameters,
                      void *ptr) = 0;

  virtual int callApi_audioEffect(API_TYPE_AUDIO_EFFECT apiType,
                                  const std::string &parameters) = 0;

  virtual void release(bool sync = false) = 0;

  virtual IRtcChannelBridge *createChannel(const char *channelId) = 0;

  virtual IAudioDeviceManagerBridge *
  createAudioDeviceManager(DEVICE_TYPE device_type, ERROR_CODE &erro_code) = 0;

  virtual IVideoDeviceManagerBridge *
  createVideoDeviceManager(ERROR_CODE &error_code) = 0;
};

CROSS_PLATFORM_EXPORT IRtcEngineBridge *createRtcEngineBridge();
} // namespace common
} // namespace agora
