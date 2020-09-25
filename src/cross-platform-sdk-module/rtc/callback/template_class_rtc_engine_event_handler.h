#pragma once

#include <string>

#include "../include/IAgoraRtcEngine.h"

namespace agora {
namespace common {
class EngineEventHandler {
private:
public:
  EngineEventHandler() {}

  virtual ~EngineEventHandler(){};

  void functionCall(std::string callbackName) {}

  template <typename T> void functionCall(std::string callbackName, T t) {}

  template <typename T, typename T1>
  void functionCall(std::string callbackName, T t, T1 t1) {}

  template <typename T, typename T1, typename T2>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2) {}

  template <typename T, typename T1, typename T2, typename T3>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2, T3 t3) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2, T3 t3, T4 t4) {
  }

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2, T3 t3, T4 t4,
                    T5 t5) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2, T3 t3, T4 t4,
                    T5 t5, T6 t6) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7>
  void functionCall(std::string callbackName, T t, T1 t1, T2 t2, T3 t3, T4 t4,
                    T5 t5, T6 t6, T7 t7) {}

  void functionCall(std::string callbackName, const rtc::RtcStats &stats) {}

  void functionCall(std::string callbackName,
                    const rtc::AudioVolumeInfo *speakers,
                    unsigned int speakerNumber, int totalVolume) {}

  void functionCall(std::string callbackName,
                    const rtc::LastmileProbeResult &lastmileProbeResult) {}

  void functionCall(std::string callbackName,
                    const rtc::LocalVideoStats &stats) {}

  void functionCall(std::string callbackName,
                    const rtc::RemoteVideoStats &stats) {}

  void functionCall(std::string callbackName,
                    const rtc::RemoteAudioStats &stats) {}

  void functionCall(std::string callbackName, rtc::uid_t uid,
                    const rtc::UserInfo &info) {}

  void functionCall(std::string callbackName,
                    const rtc::LocalAudioStats &stats) {}

  void functionCall(std::string callbackName, int imageWidth, int imageHeight,
                    const rtc::Rectangle *vecRectangle, const int *vecDistance,
                    int numFaces) {}

  void functionCall(std::string callbackName, rtc::uid_t uid, int streamId,
                    const char *data, size_t length) {}

  void functionCall(std::string callbackName,
                    const rtc::IMetadataObserver::Metadata &metadata) {}
};
} // namespace common
} // namespace agora
