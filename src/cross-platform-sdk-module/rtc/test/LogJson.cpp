#include "LogJson.h"
#include "../common/rapidjson/istreamwrapper.h"
#include "../common/rapidjson/ostreamwrapper.h"
#include "../common/rapidjson/prettywriter.h"
#include "../common/rapidjson/stringbuffer.h"
#include "../common/rapidjson/writer.h"
#include <fstream>
#include <sstream>
#include <stdint.h>

using namespace std;
namespace agora {
namespace common {
using namespace rtc;

template <typename T> std::string json_to_string(T &json) {
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  json.Accept(writer);
  const char *a = buffer.GetString();
  return string(a);
}

using rapidjson::Document;
using rapidjson::Value;

void structToJsonValue(Value &obj, const rtc::VideoDimensions &videoDimensions,
                       Document &doc) {
  obj.AddMember("width", videoDimensions.width, doc.GetAllocator());
  obj.AddMember("height", videoDimensions.height, doc.GetAllocator());
}

void structToJsonValue(
    Value &obj, const VideoEncoderConfiguration &videoEncoderConfiguration,
    Document &doc) {
  Value dimensions(rapidjson::kObjectType);
  structToJsonValue(dimensions, videoEncoderConfiguration.dimensions, doc);

  obj.AddMember("dimensions", dimensions, doc.GetAllocator());
  obj.AddMember("minFrameRate", videoEncoderConfiguration.minFrameRate,
                doc.GetAllocator());
  obj.AddMember("bitrate", videoEncoderConfiguration.bitrate,
                doc.GetAllocator());
  obj.AddMember("minBitrate", videoEncoderConfiguration.minBitrate,
                doc.GetAllocator());
  obj.AddMember("frameRate", (int)videoEncoderConfiguration.frameRate,
                doc.GetAllocator());
  obj.AddMember("orientationMode",
                (int)videoEncoderConfiguration.orientationMode,
                doc.GetAllocator());
  obj.AddMember("degradationPreference",
                (int)videoEncoderConfiguration.degradationPreference,
                doc.GetAllocator());
  obj.AddMember("mirrorMode", (int)videoEncoderConfiguration.mirrorMode,
                doc.GetAllocator());
}

void structToJsonValue(
    Value &obj, const CameraCapturerConfiguration &cameraCapturerConfiguration,
    Document &doc) {
  obj.AddMember("preference", (int)cameraCapturerConfiguration.preference,
                doc.GetAllocator());

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
  obj.AddMember("cameraDirection", cameraCapturerConfiguration.cameraDirection,
                doc.GetAllocator());
#endif
}

void structToJsonValue(Value &obj, const rtc::Rectangle &rect, Document &doc) {
  obj.AddMember("x", rect.x, doc.GetAllocator());
  obj.AddMember("y", rect.y, doc.GetAllocator());
  obj.AddMember("width", rect.width, doc.GetAllocator());
  obj.AddMember("height", rect.height, doc.GetAllocator());
}

void structToJsonValue(Value &obj,
                       const rtc::ScreenCaptureParameters &captureParams,
                       Document &doc) {
  Value dimensions(rapidjson::kObjectType);
  structToJsonValue(dimensions, captureParams.dimensions, doc);

  obj.AddMember("dimensions", dimensions, doc.GetAllocator());
  obj.AddMember("frameRate", captureParams.frameRate, doc.GetAllocator());
  obj.AddMember("bitrate", captureParams.bitrate, doc.GetAllocator());
  obj.AddMember("captureMouseCursor", captureParams.captureMouseCursor,
                doc.GetAllocator());
  obj.AddMember("windowFocus", captureParams.windowFocus, doc.GetAllocator());
  obj.AddMember("excludeWindowCount", captureParams.excludeWindowCount,
                doc.GetAllocator());

  Value arr(rapidjson::kArrayType);
  for (int i = 0; i < captureParams.excludeWindowCount; ++i) {
    arr.PushBack((uint64_t)captureParams.excludeWindowList[i],
                 doc.GetAllocator());
  }
  obj.AddMember("excludeWindowList", arr, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::LastmileProbeConfig &config,
                       Document &doc) {
  obj.AddMember("probeUplink", config.probeUplink, doc.GetAllocator());
  obj.AddMember("probeDownlink", config.probeDownlink, doc.GetAllocator());
  obj.AddMember("expectedUplinkBitrate", config.expectedUplinkBitrate,
                doc.GetAllocator());
  obj.AddMember("expectedDownlinkBitrate", config.expectedDownlinkBitrate,
                doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::TranscodingUser &transcodingUser,
                       Document &doc) {
  obj.AddMember("uid", transcodingUser.uid, doc.GetAllocator());
  obj.AddMember("x", transcodingUser.x, doc.GetAllocator());
  obj.AddMember("y", transcodingUser.y, doc.GetAllocator());
  obj.AddMember("width", transcodingUser.width, doc.GetAllocator());
  obj.AddMember("height", transcodingUser.height, doc.GetAllocator());
  obj.AddMember("zOrder", transcodingUser.zOrder, doc.GetAllocator());
  obj.AddMember("alpha", transcodingUser.alpha, doc.GetAllocator());
  obj.AddMember("audioChannel", transcodingUser.audioChannel,
                doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::RtcImage &image, Document &doc) {
  obj.AddMember("url", Value(image.url, doc.GetAllocator()).Move(),
                doc.GetAllocator());
  obj.AddMember("x", image.x, doc.GetAllocator());
  obj.AddMember("y", image.y, doc.GetAllocator());
  obj.AddMember("width", image.width, doc.GetAllocator());
  obj.AddMember("height", image.height, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::LiveTranscoding &transcoding,
                       Document &doc) {
  obj.AddMember("width", transcoding.width, doc.GetAllocator());
  obj.AddMember("height", transcoding.height, doc.GetAllocator());
  obj.AddMember("videoBitrate", transcoding.videoBitrate, doc.GetAllocator());
  obj.AddMember("videoFramerate", transcoding.videoFramerate,
                doc.GetAllocator());
  obj.AddMember("lowLatency", transcoding.lowLatency, doc.GetAllocator());
  obj.AddMember("videoGop", transcoding.videoGop, doc.GetAllocator());
  obj.AddMember("videoCodecProfile", (int)transcoding.videoCodecProfile,
                doc.GetAllocator());
  obj.AddMember("backgroundColor", transcoding.backgroundColor,
                doc.GetAllocator());
  obj.AddMember("userCount", transcoding.userCount, doc.GetAllocator());

  Value userArray(rapidjson::kArrayType);
  for (int i = 0; i < transcoding.userCount; ++i) {
    Value user(rapidjson::kObjectType);
    structToJsonValue(user, transcoding.transcodingUsers[i], doc);
    userArray.PushBack(user, doc.GetAllocator());
  }
  obj.AddMember("transcodingUsers", userArray, doc.GetAllocator());

  obj.AddMember(
      "transcodingExtraInfo",
      Value(transcoding.transcodingExtraInfo, doc.GetAllocator()).Move(),
      doc.GetAllocator());
  obj.AddMember("metadata",
                Value(transcoding.metadata, doc.GetAllocator()).Move(),
                doc.GetAllocator());

  Value watermark(rapidjson::kObjectType);
  structToJsonValue(watermark, *transcoding.watermark, doc);
  obj.AddMember("watermark", watermark, doc.GetAllocator());

  Value background(rapidjson::kObjectType);
  structToJsonValue(background, *transcoding.backgroundImage, doc);
  obj.AddMember("backgroundImage", background, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::WatermarkOptions &options,
                       Document &doc) {
  obj.AddMember("visibleInPreview", options.visibleInPreview,
                doc.GetAllocator());

  Value positionInL(rapidjson::kObjectType);
  structToJsonValue(positionInL, options.positionInLandscapeMode, doc);
  obj.AddMember("positionInLandscapeMode", positionInL, doc.GetAllocator());

  Value positionInP(rapidjson::kObjectType);
  structToJsonValue(positionInP, options.positionInPortraitMode, doc);
  obj.AddMember("positionInPortraitMode", positionInP, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::BeautyOptions &options,
                       Document &doc) {
  obj.AddMember("lighteningContrastLevel", options.lighteningContrastLevel,
                doc.GetAllocator());
  obj.AddMember("lighteningLevel", options.lighteningLevel, doc.GetAllocator());
  obj.AddMember("smoothnessLevel", options.smoothnessLevel, doc.GetAllocator());
  obj.AddMember("rednessLevel", options.rednessLevel, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::InjectStreamConfig &config,
                       Document &doc) {
  obj.AddMember("width", config.width, doc.GetAllocator());
  obj.AddMember("height", config.height, doc.GetAllocator());
  obj.AddMember("videoGop", config.videoGop, doc.GetAllocator());
  obj.AddMember("videoFramerate", config.videoFramerate, doc.GetAllocator());
  obj.AddMember("videoBitrate", config.videoBitrate, doc.GetAllocator());
  obj.AddMember("audioSampleRate", config.audioSampleRate, doc.GetAllocator());
  obj.AddMember("audioBitrate", config.audioBitrate, doc.GetAllocator());
  obj.AddMember("audioChannels", config.audioChannels, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::ChannelMediaInfo &mediaInfo,
                       Document &doc) {
  obj.AddMember("channelName",
                Value(mediaInfo.channelName, doc.GetAllocator()).Move(),
                doc.GetAllocator());
  obj.AddMember("token", Value(mediaInfo.token, doc.GetAllocator()).Move(),
                doc.GetAllocator());
  obj.AddMember("uid", mediaInfo.uid, doc.GetAllocator());
}

void structToJsonValue(Value &obj,
                       const rtc::ChannelMediaRelayConfiguration &configuration,
                       Document &doc) {
  obj.AddMember("destCount", configuration.destCount, doc.GetAllocator());

  Value srcObj(rapidjson::kObjectType);
  structToJsonValue(srcObj, *configuration.srcInfo, doc);
  obj.AddMember("srcInfo", srcObj, doc.GetAllocator());

  Value destArr(rapidjson::kArrayType);
  for (int i = 0; i < configuration.destCount; ++i) {
    Value destObj(rapidjson::kObjectType);
    structToJsonValue(destObj, configuration.destInfos[i], doc);
    destArr.PushBack(destObj, doc.GetAllocator());
  }
  obj.AddMember("destInfos", destArr, doc.GetAllocator());
}

void structToJsonValue(Value &obj, const rtc::VideoCanvas &canvas,
                       Document &doc) {
  obj.AddMember("renderMode", canvas.renderMode, doc.GetAllocator());
  obj.AddMember("channelId", Value(canvas.channelId, doc.GetAllocator()).Move(),
                doc.GetAllocator());
  obj.AddMember("uid", canvas.uid, doc.GetAllocator());
  obj.AddMember("mirrorMode", (int)canvas.mirrorMode, doc.GetAllocator());
}

void structToJsonValue(Value &obj,
                       const rtc::IMetadataObserver::Metadata &metadata,
                       Document &doc) {
  obj.AddMember("uid", metadata.uid, doc.GetAllocator());
  obj.AddMember("size", metadata.size, doc.GetAllocator());
  obj.AddMember("timeStampMs", (int64_t)metadata.timeStampMs,
                doc.GetAllocator());
}

void structToJsonValue(Value &obj,
                       const agora::rtc::ChannelMediaOptions &options,
                       Document &doc) {
  obj.AddMember("autoSubscribeAudio", options.autoSubscribeAudio,
                doc.GetAllocator());
  obj.AddMember("autoSubscribeVideo", options.autoSubscribeVideo,
                doc.GetAllocator());
}

Value createValue(const agora::rtc::ChannelMediaOptions &options,
                  rapidjson::Document &doc) {
  Value v(rapidjson::kObjectType);
  structToJsonValue(v, options, doc);
  return v;
}

Value createValue(const agora::rtc::LiveTranscoding &transcoding,
                  rapidjson::Document &doc) {
  Value v(rapidjson::kObjectType);
  structToJsonValue(v, transcoding, doc);
  return v;
}

Value createValue(const agora::rtc::InjectStreamConfig &config,
                  rapidjson::Document &doc) {
  Value v(rapidjson::kObjectType);
  structToJsonValue(v, config, doc);
  return v;
}

Value createValue(const rtc::ChannelMediaRelayConfiguration &configuration,
                  rapidjson::Document &doc) {
  Value v(rapidjson::kObjectType);
  structToJsonValue(v, configuration, doc);
  return v;
}

Value createValue(const rtc::IMetadataObserver::Metadata &metadata,
                  rapidjson::Document &doc) {
  Value v(rapidjson::kObjectType);
  structToJsonValue(v, metadata, doc);
  return v;
}

Value createValue(const char *t, rapidjson::Document &doc) {
  rapidjson::Value v(t, doc.GetAllocator());
  return v;
}

LogJson::LogJson() { document_.SetArray(); }

void LogJson::log(int apiType) {
  std::ostringstream os;
  os << apiType;
  string apiTypeString = os.str();
  rapidjson::Value obj(rapidjson::kObjectType);

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType,
                  const VideoEncoderConfiguration &videoEncoderConfiguration) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value configObj(rapidjson::kObjectType);
  structToJsonValue(configObj, videoEncoderConfiguration, document_);
  obj.AddMember("config", configObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(
    int apiType,
    const CameraCapturerConfiguration &cameraCapturerConfiguration) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value configObj(rapidjson::kObjectType);
  structToJsonValue(configObj, cameraCapturerConfiguration, document_);
  obj.AddMember("config", configObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, unsigned int displayId,
                  const rtc::Rectangle &regionRect,
                  const rtc::ScreenCaptureParameters &captureParams) {
  rapidjson::Value obj(rapidjson::kObjectType);

  obj.AddMember("displayId", displayId, document_.GetAllocator());

  Value rectObj(rapidjson::kObjectType);
  structToJsonValue(rectObj, regionRect, document_);
  obj.AddMember("regionRect", rectObj, document_.GetAllocator());

  Value captureParamObj(rapidjson::kObjectType);
  structToJsonValue(captureParamObj, captureParams, document_);
  obj.AddMember("captureParams", captureParamObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::Rectangle &screenRect,
                  const rtc::Rectangle &regionRect,
                  const rtc::ScreenCaptureParameters &captureParams) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value screenRectObj(rapidjson::kObjectType);
  structToJsonValue(screenRectObj, screenRect, document_);
  obj.AddMember("screenRect", screenRectObj, document_.GetAllocator());

  Value regionRectObj(rapidjson::kObjectType);
  structToJsonValue(regionRectObj, regionRect, document_);
  obj.AddMember("regionRect", regionRectObj, document_.GetAllocator());

  Value captureParamObj(rapidjson::kObjectType);
  structToJsonValue(captureParamObj, captureParams, document_);
  obj.AddMember("captureParams", captureParamObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, rtc::view_t windowId,
                  const rtc::Rectangle &regionRect,
                  const rtc::ScreenCaptureParameters &captureParams) {
  rapidjson::Value obj(rapidjson::kObjectType);

  obj.AddMember("windowId", (uint64_t)windowId, document_.GetAllocator());

  Value rectObj(rapidjson::kObjectType);
  structToJsonValue(rectObj, regionRect, document_);
  obj.AddMember("regionRect", rectObj, document_.GetAllocator());

  Value captureParamObj(rapidjson::kObjectType);
  structToJsonValue(captureParamObj, captureParams, document_);
  obj.AddMember("captureParams", captureParamObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType,
                  const rtc::ScreenCaptureParameters &captureParams) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value captureParamObj(rapidjson::kObjectType);
  structToJsonValue(captureParamObj, captureParams, document_);
  obj.AddMember("captureParams", captureParamObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::Rectangle &regionRect) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value rectObj(rapidjson::kObjectType);
  structToJsonValue(rectObj, regionRect, document_);
  obj.AddMember("regionRect", rectObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::LastmileProbeConfig &config) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value configObj(rapidjson::kObjectType);
  structToJsonValue(configObj, config, document_);
  obj.AddMember("config", configObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::LiveTranscoding &transcoding) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value transcodingObj(rapidjson::kObjectType);
  structToJsonValue(transcodingObj, transcoding, document_);
  obj.AddMember("transcoding", transcodingObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::RtcImage &watermark) {
  rapidjson::Value obj(rapidjson::kObjectType);

  Value watermarkObj(rapidjson::kObjectType);
  structToJsonValue(watermarkObj, watermark, document_);
  obj.AddMember("watermark", watermarkObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const char *watermarkUrl,
                  const rtc::WatermarkOptions &options) {
  rapidjson::Value obj(rapidjson::kObjectType);

  obj.AddMember("watermarkUrl",
                Value(watermarkUrl, document_.GetAllocator()).Move(),
                document_.GetAllocator());

  Value optionsObj(rapidjson::kObjectType);
  structToJsonValue(optionsObj, options, document_);
  obj.AddMember("options", optionsObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, bool enabled,
                  const rtc::BeautyOptions &options) {
  rapidjson::Value obj(rapidjson::kObjectType);

  obj.AddMember("enabled", enabled, document_.GetAllocator());

  Value optionsObj(rapidjson::kObjectType);
  structToJsonValue(optionsObj, options, document_);
  obj.AddMember("options", optionsObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const char *url,
                  const rtc::InjectStreamConfig &config) {
  rapidjson::Value obj(rapidjson::kObjectType);

  obj.AddMember("url", Value(url, document_.GetAllocator()).Move(),
                document_.GetAllocator());

  Value configObj(rapidjson::kObjectType);
  structToJsonValue(configObj, config, document_);
  obj.AddMember("config", configObj, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType,
                  const rtc::ChannelMediaRelayConfiguration &configuration) {
  rapidjson::Value obj(rapidjson::kObjectType);

  structToJsonValue(obj, configuration, document_);

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, const rtc::VideoCanvas &canvas) {
  rapidjson::Value obj(rapidjson::kObjectType);

  structToJsonValue(obj, canvas, document_);

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::log(int apiType, rtc::IMetadataObserver::Metadata *metadata) {
  rapidjson::Value obj(rapidjson::kObjectType);

  structToJsonValue(obj, *metadata, document_);

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());
  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::logJson(int apiType, const char *parameter) {
  rapidjson::Document paramDoc;
  paramDoc.Parse(parameter);
  rapidjson::Value obj;
  obj.CopyFrom(paramDoc, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  apiObject.AddMember("apitype", apiType, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());

  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::logJson(const char *eventType, const char *parameter) {
  rapidjson::Document paramDoc;
  paramDoc.Parse(parameter);
  rapidjson::Value obj;
  obj.CopyFrom(paramDoc, document_.GetAllocator());

  rapidjson::Value apiObject(rapidjson::kObjectType);
  rapidjson::Value eventTypeV(eventType, document_.GetAllocator());
  apiObject.AddMember("event_type", eventTypeV, document_.GetAllocator());
  apiObject.AddMember("param", obj, document_.GetAllocator());

  document_.PushBack(apiObject, document_.GetAllocator());
}

void LogJson::clearJsonData() { document_.SetArray(); }

void LogJson::compareAndDumpResult(const char *caseFilePath,
                                   const char *dumpFilePath) {
  ifstream ifs(caseFilePath);
  rapidjson::IStreamWrapper isw(ifs);

  Document caseDoc;
  caseDoc.ParseStream(isw);

  auto caseLength = caseDoc.GetArray().Size();
  auto actualLength = document_.GetArray().Size();

  Document errorDoc;
  errorDoc.SetArray();

  for (rapidjson::SizeType i = 0; i < caseLength; ++i) {
    if (i < actualLength) {
      Value caseValue(caseDoc[i], document_.GetAllocator());
      Value actualValue(document_[i], document_.GetAllocator());

      if (caseValue != actualValue) {
        Value resultValue(rapidjson::kObjectType);
        resultValue.AddMember("case", caseValue, document_.GetAllocator());
        resultValue.AddMember("actual", actualValue, document_.GetAllocator());

        errorDoc.PushBack(resultValue, document_.GetAllocator());
      }

    } else {
      Value caseValue(caseDoc[i], document_.GetAllocator());
      Value actualValue(rapidjson::kObjectType);

      Value resultValue(rapidjson::kObjectType);
      resultValue.AddMember("case", caseValue, document_.GetAllocator());
      resultValue.AddMember("actual", actualValue, document_.GetAllocator());

      errorDoc.PushBack(resultValue, document_.GetAllocator());
    }
  }

  ofstream ofs(dumpFilePath);
  rapidjson::OStreamWrapper osw(ofs);

  rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);
  errorDoc.Accept(writer);
}

} // namespace common
} // namespace agora
