//
// Created by 张涛 on 2020-08-17.
//

#include "AudioPlaybackDeviceManager.h"
#include "../../common/IBridgeCommon.h"
#include "../../common/rapidjson/document.h"
#include "../../common/utils/DocumentHelper.h"
#include <string>

namespace agora {
namespace common {
using namespace rtc;
using namespace rapidjson;

AudioPlaybackDeviceManager::AudioPlaybackDeviceManager(
    rtc::IRtcEngine *mRtcEngine, ERROR_CODE &ret) {
  audioDeviceManager = new AAudioDeviceManager(mRtcEngine);

  if (audioDeviceManager->get()) {
    audioDeviceCollection = (*audioDeviceManager)->enumeratePlaybackDevices();
    if (audioDeviceCollection) {
      ret = ERROR_CODE::ERROR_OK;
    } else {
      ret = ERROR_CODE::ERROR_NO_DEVICE;
    }
  } else {
    delete audioDeviceManager;
    audioDeviceManager = nullptr;
    ret = ERROR_CODE::ERROR_NO_DEVICE;
  }
}

AudioPlaybackDeviceManager::~AudioPlaybackDeviceManager() {
  if (audioDeviceCollection) {
    audioDeviceCollection->release();
    audioDeviceCollection = nullptr;
  }

  if (audioDeviceManager) {
    if (audioDeviceManager->get()) {
      audioDeviceManager->get()->release();
    }

    delete audioDeviceManager;
    audioDeviceManager = nullptr;
  }
}

int AudioPlaybackDeviceManager::callApi(API_TYPE_DEVICE_MANAGER apiType,
                                        const std::string &parameters) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE_DEVICE_MANAGER::GET_COUNT: {
    ret = getCount();
  } break;

  case API_TYPE_DEVICE_MANAGER::SET_DEVICE_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = setDeviceVolume(volume);
  } break;

  case API_TYPE_DEVICE_MANAGER::SET_DEVICE_MUTE: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = setDeviceMute(mute);
  } break;

  case API_TYPE_DEVICE_MANAGER::STOP_DEVICE_TEST: {
    ret = stopDeviceTest();
  } break;

  case API_TYPE_DEVICE_MANAGER::START_AUDIO_DEVICE_LOOP_BACK_TEST: {
    int indicationInterval;
    get_parameter_int(document, "indicationInterval", indicationInterval, ret);
    CHECK_RET_ERROR(ret)

    ret = startAudioDeviceLoopbackTest(indicationInterval);
  } break;

  case API_TYPE_DEVICE_MANAGER::START_DEVICE_TEST: {
    std::string testAudioFilePath;
    get_parameter_string(document, "testAudioFilePath", testAudioFilePath, ret);
    CHECK_RET_ERROR(ret)

    ret = startDeviceTest(testAudioFilePath.c_str());
  } break;

  case API_TYPE_DEVICE_MANAGER::STOP_AUDIO_DEVICE_LOOP_BACK_TEST: {
    ret = stopAudioDeviceLoopbackTest();
  } break;

  default:
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
    break;
  }
  return ret;
}

int AudioPlaybackDeviceManager::callApi(API_TYPE_DEVICE_MANAGER apiType,
                                        const std::string &parameters,
                                        void *&ptr) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE_DEVICE_MANAGER::GET_CURRENT_DEVICE: {
    ret = getCurrentDevice(reinterpret_cast<char *>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::SET_DEVICE: {
    ret = setDevice(reinterpret_cast<char *>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::GET_DEVICE_VOLUME: {
    ret = getDeviceVolume(reinterpret_cast<int *>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::GET_DEVICE_MUTE: {
    ret = getDeviceMute(reinterpret_cast<bool *>(ptr));
  } break;

  default:
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
    break;
  }
  return ret;
}

int AudioPlaybackDeviceManager::callApi(API_TYPE_DEVICE_MANAGER apiType,
                                        const std::string &parameters,
                                        void *&ptr, void *&ptr2) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE_DEVICE_MANAGER::GET_DEVICE: {
    int index;
    get_parameter_int(document, "index", index, ret);
    CHECK_RET_ERROR(ret)

    ret = getDevice(index, reinterpret_cast<char *>(ptr),
                    reinterpret_cast<char *>(ptr2));
  } break;

  case API_TYPE_DEVICE_MANAGER::GET_CURRENT_DEVICE_INFO: {
    ret = getCurrentDeviceInfo(reinterpret_cast<char *>(ptr),
                               reinterpret_cast<char *>(ptr2));
  } break;

  default:
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
    break;
  }
  return ret;
}

int AudioPlaybackDeviceManager::getCount() {
  if (audioDeviceCollection) {
    return audioDeviceCollection->getCount();
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::getDevice(int index,
                                          char deviceName[MAX_DEVICE_ID_LENGTH],
                                          char deviceId[MAX_DEVICE_ID_LENGTH]) {
  if (audioDeviceCollection) {
    return audioDeviceCollection->getDevice(index, deviceName, deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::getCurrentDevice(
    char deviceId[MAX_DEVICE_ID_LENGTH]) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->getPlaybackDevice(deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::getCurrentDeviceInfo(
    char deviceId[MAX_DEVICE_ID_LENGTH],
    char deviceName[MAX_DEVICE_ID_LENGTH]) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->getPlaybackDeviceInfo(deviceId, deviceName);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::setDevice(
    const char deviceId[MAX_DEVICE_ID_LENGTH]) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->setPlaybackDevice(deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::setDeviceVolume(int volume) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->setPlaybackDeviceVolume(volume);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::getDeviceVolume(int *volume) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->getPlaybackDeviceVolume(volume);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::setDeviceMute(bool mute) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->setPlaybackDeviceMute(mute);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::getDeviceMute(bool *mute) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->getPlaybackDeviceMute(mute);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::startDeviceTest(const char *testAudioFilePath) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->startPlaybackDeviceTest(testAudioFilePath);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::stopDeviceTest() {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->stopPlaybackDeviceTest();
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::startAudioDeviceLoopbackTest(
    int indicationInterval) {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)
        ->startAudioDeviceLoopbackTest(indicationInterval);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int AudioPlaybackDeviceManager::stopAudioDeviceLoopbackTest() {
  if (audioDeviceManager && audioDeviceManager->get()) {
    return (*audioDeviceManager)->stopAudioDeviceLoopbackTest();
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

void AudioPlaybackDeviceManager::release() { delete this; }
} // namespace common
} // namespace agora