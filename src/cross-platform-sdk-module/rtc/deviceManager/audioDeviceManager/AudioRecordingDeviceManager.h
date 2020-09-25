//
// Created by 张涛 on 2020-08-17.
//
#pragma once

#include "../../include/IAgoraRtcEngine.h"
#include "../IAudioDeviceManagerBridge.h"

namespace agora {
namespace common {
class AudioRecordingDeviceManager : public IAudioDeviceManagerBridge {
private:
  rtc::AAudioDeviceManager *audioDeviceManager = nullptr;
  rtc::IAudioDeviceCollection *audioDeviceCollection = nullptr;

public:
  AudioRecordingDeviceManager(rtc::IRtcEngine *mRtcEngine, ERROR_CODE &ret);

  virtual ~AudioRecordingDeviceManager();

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters) override;

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr) override;

  virtual int callApi(API_TYPE_DEVICE_MANAGER apiType,
                      const std::string &parameters, void *&ptr,
                      void *&ptr2) override;

  virtual void release() override;

  int getCount();

  int getDevice(int index, char deviceName[rtc::MAX_DEVICE_ID_LENGTH],
                char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  int getCurrentDevice(char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  int getCurrentDeviceInfo(char deviceId[rtc::MAX_DEVICE_ID_LENGTH],
                           char deviceName[rtc::MAX_DEVICE_ID_LENGTH]);

  int setDevice(const char deviceId[rtc::MAX_DEVICE_ID_LENGTH]);

  int setDeviceVolume(int volume);

  int getDeviceVolume(int *volume);

  int setDeviceMute(bool mute);

  int getDeviceMute(bool *mute);

  int startDeviceTest(const char *testAudioFilePath);

  int stopDeviceTest();

  int startAudioDeviceLoopbackTest(int indicationInterval);

  int stopAudioDeviceLoopbackTest();
};

} // namespace common
} // namespace agora
