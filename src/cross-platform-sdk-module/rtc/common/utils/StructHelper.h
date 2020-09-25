//
// Created by 张涛 on 2020-08-13.
//

#pragma once

#include "../../include/IAgoraRtcChannel.h"
#include "../../include/IAgoraRtcEngine.h"
#include "../IBridgeCommon.h"
#include "DocumentHelper.h"
#include <string>

namespace agora {
namespace common {

template <typename T>
void json_to_VideoDimension(T &object, rtc::VideoDimensions &videoDimensions,
                            int &ret) {
  get_parameter_int(object, "width", videoDimensions.width, ret);
  CHECK_RET_ERROR_NULL(ret);
  get_parameter_int(object, "height", videoDimensions.height, ret);
}

template <typename T>
void json_to_CameraCapturerConfiguration(
    T &object, rtc::CameraCapturerConfiguration &cameraCapturerConfiguration,
    int &ret) {
  int preference;
  get_parameter_int(object, "preference", preference, ret);
  CHECK_RET_ERROR_NULL(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
  int cameraDirection;
  get_parameter_int(object, "cameraDirection", cameraDirection, ret);
  CHECK_RET_ERROR_NULL(ret)
  cameraCapturerConfiguration.cameraDirection =
      rtc::CAMERA_DIRECTION(cameraDirection);
#endif

  cameraCapturerConfiguration.preference =
      rtc::CAPTURER_OUTPUT_PREFERENCE(preference);
}

template <typename T>
void json_to_LastmileProbeConfig(T &object,
                                 rtc::LastmileProbeConfig &lastmileProbeConfig,
                                 int &ret) {

  get_parameter_bool(object, "probeUplink", lastmileProbeConfig.probeUplink,
                     ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_bool(object, "probeDownlink", lastmileProbeConfig.probeDownlink,
                     ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_uint(object, "expectedUplinkBitrate",
                     lastmileProbeConfig.expectedUplinkBitrate, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_uint(object, "expectedDownlinkBitrate",
                     lastmileProbeConfig.expectedDownlinkBitrate, ret);
  CHECK_RET_ERROR_NULL(ret)
}

template <typename T>
void json_to_TranscodingUser(T &object, rtc::TranscodingUser *transcodingUser,
                             const int &count, int &ret) {
  for (int i = 0; i < count; i++) {
    rapidjson::Value &value = object[i];
    if (value.HasMember("uid") && value.HasMember("x") &&
        value.HasMember("y") && value.HasMember("width") &&
        value.HasMember("height") && value.HasMember("zOrder") &&
        value.HasMember("alpha") && value.HasMember("audioChannel")) {
      transcodingUser[i].uid = value["uid"].GetUint();
      transcodingUser[i].x = value["x"].GetInt();
      transcodingUser[i].y = value["y"].GetInt();
      transcodingUser[i].width = value["width"].GetInt();
      transcodingUser[i].height = value["height"].GetInt();
      transcodingUser[i].zOrder = value["zOrder"].GetInt();
      transcodingUser[i].alpha = value["alpha"].GetDouble();
      transcodingUser[i].audioChannel = value["audioChannel"].GetInt();
    } else {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
    }
  }
}

template <typename T>
void json_to_RtcImage(T &object, rtc::RtcImage &rtcImage, std::string &url,
                      int &ret) {
  get_parameter_string(object, "url", url, ret);
  CHECK_RET_ERROR_NULL(ret)
  rtcImage.url = url.c_str();

  get_parameter_int(object, "x", rtcImage.x, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "y", rtcImage.y, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "width", rtcImage.width, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "height", rtcImage.height, ret);
  CHECK_RET_ERROR_NULL(ret)
}

template <typename T>
void json_to_Rectangle(T &object, rtc::Rectangle &rectangle, int &ret) {

  get_parameter_int(object, "x", rectangle.x, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "y", rectangle.y, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "width", rectangle.width, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "height", rectangle.height, ret);
  CHECK_RET_ERROR_NULL(ret)
}

template <typename T>
void json_to_BeautyOptions(T &object, rtc::BeautyOptions *beautyOptions,
                           int &ret) {
  int lighteningContrastLevel;
  get_parameter_int(object, "lighteningContrastLevel", lighteningContrastLevel,
                    ret);
  CHECK_RET_ERROR_NULL(ret)

  beautyOptions->lighteningContrastLevel =
      rtc::BeautyOptions::LIGHTENING_CONTRAST_LEVEL(lighteningContrastLevel);

  get_parameter_float(object, "lighteningLevel", beautyOptions->lighteningLevel,
                      ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_float(object, "smoothnessLevel", beautyOptions->smoothnessLevel,
                      ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_float(object, "rednessLevel", beautyOptions->rednessLevel, ret);
  CHECK_RET_ERROR_NULL(ret)
}

template <typename T>
void json_to_InjectStreamConfig(T &object,
                                rtc::InjectStreamConfig *injectStreamConfig,
                                int &ret) {

  get_parameter_int(object, "width", injectStreamConfig->width, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "height", injectStreamConfig->height, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "videoGop", injectStreamConfig->videoGop, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "videoFramerate",
                    injectStreamConfig->videoFramerate, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "videoBitrate", injectStreamConfig->videoBitrate,
                    ret);
  CHECK_RET_ERROR_NULL(ret)

  int audioSampleRate;
  get_parameter_int(object, "audioSampleRate", audioSampleRate, ret);
  CHECK_RET_ERROR_NULL(ret)
  injectStreamConfig->audioSampleRate =
      rtc::AUDIO_SAMPLE_RATE_TYPE(audioSampleRate);

  get_parameter_int(object, "audioBitrate", injectStreamConfig->audioBitrate,
                    ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "audioChannels", injectStreamConfig->audioChannels,
                    ret);
  CHECK_RET_ERROR_NULL(ret)
}

template <typename T>
void json_to_ChannelMediaInfo(T &object,
                              rtc::ChannelMediaInfo *channelMediaInfo,
                              std::string *channelName, std::string *token,
                              const int &count, int &ret) {

  if (count == -1) {
    if (object.HasMember("channelName") && object.HasMember("token") &&
        object.HasMember("uid")) {
      channelName[0] = object["channelName"].GetString();
      token[0] = object["token"].GetString();
      channelMediaInfo[0].channelName = channelName[0].c_str();
      channelMediaInfo[0].token = token[0].c_str();
      channelMediaInfo[0].uid = object["uid"].GetUint();
      return;
    } else {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
  }

  for (int i = 0; i < count; i++) {
    rapidjson::Value &value = object[i];
    if (value.HasMember("channelName") && value.HasMember("token") &&
        value.HasMember("uid")) {
      channelName[i] = value["channelName"].GetString();
      token[i] = value["token"].GetString();
      channelMediaInfo[i].channelName = channelName[i].c_str();
      channelMediaInfo[i].token = token[i].c_str();
      channelMediaInfo[i].uid = value["uid"].GetUint();
    } else {
      ret = ERROR_CODE::ERROR_INVALID_PARAM;
      return;
    }
  }
}

template <typename T>
void json_to_ChannelMediaOptions(T &object,
                                 rtc::ChannelMediaOptions &mediaOptions,
                                 int &ret) {
  get_parameter_bool(object, "autoSubscribeAudio",
                     mediaOptions.autoSubscribeAudio, ret);
  CHECK_RET_ERROR_NULL(ret);

  get_parameter_bool(object, "autoSubscribeVideo",
                     mediaOptions.autoSubscribeVideo, ret);
  CHECK_RET_ERROR_NULL(ret);
}

template <typename T>
void json_to_ScreenCaptureParameters(T &object,
                                     rtc::ScreenCaptureParameters &mediaOptions,
                                     rtc::VideoDimensions &videoDimensions,
                                     int *windowList, int &ret) {
  rapidjson::Value videoDimensionsValue;
  get_parameter_object(object, "dimensions", videoDimensionsValue, ret);
  CHECK_RET_ERROR_NULL(ret)

  json_to_VideoDimension(videoDimensionsValue, videoDimensions, ret);
  CHECK_RET_ERROR_NULL(ret)

  mediaOptions.dimensions = videoDimensions;

  get_parameter_int(object, "frameRate", mediaOptions.frameRate, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "bitrate", mediaOptions.bitrate, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_bool(object, "captureMouseCursor",
                     mediaOptions.captureMouseCursor, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_bool(object, "windowFocus", mediaOptions.windowFocus, ret);
  CHECK_RET_ERROR_NULL(ret)

  get_parameter_int(object, "excludeWindowCount",
                    mediaOptions.excludeWindowCount, ret);
  CHECK_RET_ERROR_NULL(ret)

  rapidjson::Value excludeWindowListValue;
  get_parameter_array(object, "excludeWindowList", excludeWindowListValue, ret);
  CHECK_RET_ERROR_NULL(ret)

  for (int i = 0; i < mediaOptions.excludeWindowCount; i++) {
    windowList[i] = excludeWindowListValue[i].GetInt();
    mediaOptions.excludeWindowList[i] = &windowList[i];
  }
}
} // namespace common
} // namespace agora
