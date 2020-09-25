//
// Created by 张涛 on 2020-08-17.
//

#include "VideoDeviceManager.h"
#include "../../common/IBridgeCommon.h"
#include "../../common/rapidjson/document.h"
#include "../../common/utils/DocumentHelper.h"
#include <string>

namespace agora {
namespace common {
using namespace rtc;
using namespace rapidjson;

VideoDeviceManager::VideoDeviceManager(rtc::IRtcEngine *mRtcEngine,
                                       ERROR_CODE &ret) {
  videoDeviceManager = new AVideoDeviceManager(mRtcEngine);

  if (videoDeviceManager->get()) {
    videoDeviceCollection = (*videoDeviceManager)->enumerateVideoDevices();
    if (videoDeviceCollection) {
      ret = ERROR_CODE::ERROR_OK;
    } else {
      ret = ERROR_CODE::ERROR_NO_DEVICE;
    }
  } else {
    delete videoDeviceManager;
    videoDeviceManager = nullptr;
    ret = ERROR_CODE::ERROR_NO_DEVICE;
  }
}

VideoDeviceManager::~VideoDeviceManager() {
  if (videoDeviceCollection) {
    videoDeviceCollection->release();
    videoDeviceCollection = nullptr;
  }

  if (videoDeviceManager) {
    if (videoDeviceManager->get()) {
      videoDeviceManager->get()->release();
    }

    delete videoDeviceManager;
    videoDeviceManager = nullptr;
  }
}

int VideoDeviceManager::callApi(API_TYPE_DEVICE_MANAGER apiType,
                                const std::string &parameters, void *&ptr) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE_DEVICE_MANAGER::START_DEVICE_TEST: {
    ret = startDeviceTest(reinterpret_cast<view_t>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::SET_DEVICE: {
    ret = setDevice(reinterpret_cast<char *>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::GET_CURRENT_DEVICE_INFO: {
    ret = getCurrentDevice(reinterpret_cast<char *>(ptr));
  } break;

  case API_TYPE_DEVICE_MANAGER::STOP_DEVICE_TEST: {
    ret = stopDeviceTest();
  } break;

  default:
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
    break;
  }
  return ret;
}

int VideoDeviceManager::callApi(API_TYPE_DEVICE_MANAGER apiType,
                                const std::string &parameters, void *&ptr,
                                void *&ptr2) {
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

  default:
    ret = ERROR_CODE::ERROR_NO_CURRENT_PARAMETER;
    break;
  }
  return ret;
}

int VideoDeviceManager::startDeviceTest(rtc::view_t hwnd) {
  if (videoDeviceManager && videoDeviceManager->get()) {
    return (*videoDeviceManager)->startDeviceTest(hwnd);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int VideoDeviceManager::startDeviceTest(uint64_t hwnd) {
  return startDeviceTest((rtc::view_t)hwnd);
}

int VideoDeviceManager::stopDeviceTest() {
  if (videoDeviceManager && videoDeviceManager->get()) {
    return (*videoDeviceManager)->stopDeviceTest();
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int VideoDeviceManager::setDevice(
    const char deviceId[rtc::MAX_DEVICE_ID_LENGTH]) {
  if (videoDeviceManager && videoDeviceManager->get()) {
    return (*videoDeviceManager)->setDevice(deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int VideoDeviceManager::getCurrentDevice(
    char deviceId[rtc::MAX_DEVICE_ID_LENGTH]) {
  if (videoDeviceManager && videoDeviceManager->get()) {
    return (*videoDeviceManager)->getDevice(deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

int VideoDeviceManager::getDeviceCount() {
  if (videoDeviceCollection) {
    return videoDeviceCollection->getCount();
  }
  return 0;
}

int VideoDeviceManager::getDevice(int index,
                                  char deviceName[rtc::MAX_DEVICE_ID_LENGTH],
                                  char deviceId[rtc::MAX_DEVICE_ID_LENGTH]) {
  if (videoDeviceCollection) {
    return videoDeviceCollection->getDevice(index, deviceName, deviceId);
  }
  return ERROR_CODE::ERROR_NO_DEVICE;
}

void VideoDeviceManager::release() { delete this; }
} // namespace common
} // namespace agora
