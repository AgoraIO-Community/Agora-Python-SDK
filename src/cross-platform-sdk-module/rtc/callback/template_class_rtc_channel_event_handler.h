#pragma once

#include <string>

#include "../include/IAgoraRtcEngine.h"

namespace agora {
namespace common {
class ChannelEventHandler {
private:
public:
  ChannelEventHandler() {}

  virtual ~ChannelEventHandler(){};

  void functionCall(std::string callbackName, std::string channelId) {}

  template <typename T>
  void functionCall(std::string callbackName, std::string channelId, T t) {}

  template <typename T, typename T1>
  void functionCall(std::string callbackName, std::string channelId, T t,
                    T1 t1) {}

  template <typename T, typename T1, typename T2>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2) {}

  template <typename T, typename T1, typename T2, typename T3>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2, T3 t3) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2, T3 t3, T4 t4) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2, T3 t3, T4 t4, T5 t5) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) {}

  template <typename T, typename T1, typename T2, typename T3, typename T4,
            typename T5, typename T6, typename T7>
  void functionCall(std::string callbackName, std::string channelId, T t, T1 t1,
                    T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7) {}

  void functionCall(std::string callbackName, std::string channelId,
                    const rtc::RtcStats &stats) {}

  void functionCall(std::string callbackName, std::string channelId,
                    const rtc::RemoteVideoStats &stats) {}

  void functionCall(std::string callbackName, std::string channelId,
                    const rtc::RemoteAudioStats &stats) {}
};
} // namespace common
} // namespace agora
