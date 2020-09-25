#ifndef LogJson_h
#define LogJson_h

#include "../common/IBridgeCommon.h"
#include "../common/rapidjson/document.h"
#include "../include/IAgoraRtcChannel.h"
#include <string>

namespace agora {
namespace common {

rapidjson::Value createValue(const char *t, rapidjson::Document &doc);

rapidjson::Value createValue(const agora::rtc::ChannelMediaOptions &options,
                             rapidjson::Document &doc);

rapidjson::Value createValue(const agora::rtc::LiveTranscoding &transcoding,
                             rapidjson::Document &doc);

rapidjson::Value createValue(const agora::rtc::InjectStreamConfig &config,
                             rapidjson::Document &doc);

rapidjson::Value
createValue(const rtc::ChannelMediaRelayConfiguration &configuration,
            rapidjson::Document &doc);

rapidjson::Value createValue(const rtc::IMetadataObserver::Metadata &metadata,
                             rapidjson::Document &doc);

template <typename T>
rapidjson::Value createValue(T i, rapidjson::Document &doc) {
  rapidjson::Value v(i);
  return v;
}

template <typename T>
void addMember(rapidjson::Value &obj, const char *k, T v,
               rapidjson::Document &doc) {
  rapidjson::Value key(k, doc.GetAllocator());
  rapidjson::Value value = createValue(v, doc);
  obj.AddMember(key, value, doc.GetAllocator());
}

class LogJson {

public:
  LogJson();

  void log(int apiType);
  void
  log(int apiType,
      const agora::rtc::VideoEncoderConfiguration &videoEncoderConfiguration);
  void log(int apiType, const agora::rtc::CameraCapturerConfiguration
                            &cameraCapturerConfiguration);
  void log(int apiType, unsigned int displayId,
           const rtc::Rectangle &regionRect,
           const rtc::ScreenCaptureParameters &captureParams);
  void log(int apiType, const rtc::Rectangle &screenRect,
           const rtc::Rectangle &regionRect,
           const rtc::ScreenCaptureParameters &captureParams);
  void log(int apiType, rtc::view_t windowId, const rtc::Rectangle &regionRect,
           const rtc::ScreenCaptureParameters &captureParams);
  void log(int apiType, const rtc::ScreenCaptureParameters &captureParams);
  void log(int apiType, const rtc::Rectangle &regionRect);
  void log(int apiType, const rtc::LastmileProbeConfig &config);
  void log(int apiType, const rtc::LiveTranscoding &transcoding);
  void log(int apiType, const rtc::RtcImage &watermark);
  void log(int apiType, const char *watermarkUrl,
           const rtc::WatermarkOptions &options);
  void log(int apiType, bool enabled, const rtc::BeautyOptions &options);
  void log(int apiType, const char *url, const rtc::InjectStreamConfig &config);
  void log(int apiType,
           const rtc::ChannelMediaRelayConfiguration &configuration);
  void log(int apiType, const rtc::VideoCanvas &canvas);
  void log(int apiType, rtc::IMetadataObserver::Metadata *metadata);

  template <typename T> void log(int apiType, const char *key, T t) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key, t, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2, typename T3>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2,
           const char *key3, T3 t3) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);
    addMember(obj, key3, t3, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2, typename T3, typename T4>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2,
           const char *key3, T3 t3, const char *key4, T4 t4) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);
    addMember(obj, key3, t3, document_);
    addMember(obj, key4, t4, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2,
           const char *key3, T3 t3, const char *key4, T4 t4, const char *key5,
           T5 t5) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);
    addMember(obj, key3, t3, document_);
    addMember(obj, key4, t4, document_);
    addMember(obj, key5, t5, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2,
           const char *key3, T3 t3, const char *key4, T4 t4, const char *key5,
           T5 t5, const char *key6, T6 t6) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);
    addMember(obj, key3, t3, document_);
    addMember(obj, key4, t4, document_);
    addMember(obj, key5, t5, document_);
    addMember(obj, key6, t6, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  template <typename T1, typename T2, typename T3, typename T4, typename T5,
            typename T6, typename T7>
  void log(int apiType, const char *key1, T1 t1, const char *key2, T2 t2,
           const char *key3, T3 t3, const char *key4, T4 t4, const char *key5,
           T5 t5, const char *key6, T6 t6, const char *key7, T7 t7) {
    rapidjson::Value obj(rapidjson::kObjectType);

    addMember(obj, key1, t1, document_);
    addMember(obj, key2, t2, document_);
    addMember(obj, key3, t3, document_);
    addMember(obj, key4, t4, document_);
    addMember(obj, key5, t5, document_);
    addMember(obj, key6, t6, document_);
    addMember(obj, key7, t7, document_);

    rapidjson::Value apiObject(rapidjson::kObjectType);
    apiObject.AddMember("apitype", apiType, document_.GetAllocator());
    apiObject.AddMember("param", obj, document_.GetAllocator());
    document_.PushBack(apiObject, document_.GetAllocator());
  }

  void logJson(int apiType, const char *parameter);
  void logJson(const char *eventType, const char *parameter);

  void clearJsonData();

  void compareAndDumpResult(const char *caseFilePath, const char *dumpFilePath);

private:
  rapidjson::Document document_;
};

} // namespace common
} // namespace agora

#endif /* LogJson_hpp */
