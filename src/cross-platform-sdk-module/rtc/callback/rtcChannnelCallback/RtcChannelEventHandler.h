//
// Created by LXH on 2020/8/7.
//

#pragma once

#include "../template_class_rtc_channel_event_handler.h"
#include "RtcChannelEventHandlerBase.h"

namespace agora {
namespace common {
#if defined(_WIN32)
typedef void(__stdcall *FUNC_OnChannelWarning)(const char *channelId, int warn,
                                               const char *msg);
typedef void(__stdcall *FUNC_OnChannelError)(const char *channelId, int err,
                                             const char *msg);
typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                          rtc::uid_t uid,
                                                          int elapsed);
typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(
    const char *channelId, rtc::uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelLeaveChannel)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelClientRoleChanged)(const char *channelId,
                                                         int oldRole,
                                                         int newRole);
typedef void(__stdcall *FUNC_OnChannelUserJoined)(const char *channelId,
                                                  rtc::uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char *channelId,
                                                   rtc::uid_t uid, int reason);
typedef void(__stdcall *FUNC_OnChannelConnectionLost)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelRequestToken)(const char *channelId);
typedef void(__stdcall *FUNC_OnChannelTokenPrivilegeWillExpire)(
    const char *channelId, const char *token);
typedef void(__stdcall *FUNC_OnChannelRtcStats)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnChannelNetworkQuality)(const char *channelId,
                                                      rtc::uid_t uid,
                                                      int txQuality,
                                                      int rxQuality);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, rtc::uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, rtc::uid_t uid, int quality,
    int networkTransportDelay, int jitterBufferDelay, int audioLossRate,
    int numChannels, int receivedSampleRate, int receivedBitrate,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(
    const char *channelId, rtc::uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                                     rtc::uid_t uid);
typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                                        rtc::uid_t uid,
                                                        int width, int height,
                                                        int rotation);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(
    const char *channelId, rtc::uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char *channelId,
                                                     rtc::uid_t uid,
                                                     int streamId,
                                                     const char *data,
                                                     size_t length);
typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                          rtc::uid_t uid,
                                                          int streamId,
                                                          int code, int missed,
                                                          int cached);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged2)(
    const char *channelId, int state, int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent2)(const char *channelId,
                                                        int code);
typedef void(__stdcall *FUNC_OnChannelRtmpStreamingStateChanged)(
    const char *channelId, const char *url, int state, int errCode);
typedef void(__stdcall *FUNC_OnChannelTranscodingUpdated)(
    const char *channelId);
typedef void(__stdcall *FUNC_OnChannelStreamInjectedStatus)(
    const char *channelId, const char *url, rtc::uid_t uid, int status);
typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, rtc::uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelConnectionStateChanged)(
    const char *channelId, int state, int reason);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged)(int state,
                                                              int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent)(int code);
typedef void(__stdcall *FUNC_OnChannelTestEnd)(const char *channelId);
#else
typedef void (*FUNC_OnChannelWarning)(const char *channelId, int warn,
                                      const char *msg);
typedef void (*FUNC_OnChannelError)(const char *channelId, int err,
                                    const char *msg);
typedef void (*FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                 rtc::uid_t uid, int elapsed);
typedef void (*FUNC_OnChannelReJoinChannelSuccess)(const char *channelId,
                                                   rtc::uid_t uid, int elapsed);
typedef void (*FUNC_OnChannelLeaveChannel)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnChannelClientRoleChanged)(const char *channelId,
                                                int oldRole, int newRole);
typedef void (*FUNC_OnChannelUserJoined)(const char *channelId, rtc::uid_t uid,
                                         int elapsed);
typedef void (*FUNC_OnChannelUserOffLine)(const char *channelId, rtc::uid_t uid,
                                          int reason);
typedef void (*FUNC_OnChannelConnectionLost)(const char *channelId);
typedef void (*FUNC_OnChannelRequestToken)(const char *channelId);
typedef void (*FUNC_OnChannelTokenPrivilegeWillExpire)(const char *channelId,
                                                       const char *token);
typedef void (*FUNC_OnChannelRtcStats)(
    const char *channelId, unsigned int duration, unsigned int txBytes,
    unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnChannelNetworkQuality)(const char *channelId,
                                             rtc::uid_t uid, int txQuality,
                                             int rxQuality);
typedef void (*FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, rtc::uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, rtc::uid_t uid, int quality,
    int networkTransportDelay, int jitterBufferDelay, int audioLossRate,
    int numChannels, int receivedSampleRate, int receivedBitrate,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStateChanged)(const char *channelId,
                                                      rtc::uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                            rtc::uid_t uid);
typedef void (*FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                               rtc::uid_t uid, int width,
                                               int height, int rotation);
typedef void (*FUNC_OnChannelRemoteVideoStateChanged)(const char *channelId,
                                                      rtc::uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelStreamMessage)(const char *channelId,
                                            rtc::uid_t uid, int streamId,
                                            const char *data, size_t length);
typedef void (*FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                 rtc::uid_t uid, int streamId,
                                                 int code, int missed,
                                                 int cached);
typedef void (*FUNC_OnChannelMediaRelayStateChanged2)(const char *channelId,
                                                      int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent2)(const char *channelId, int code);
typedef void (*FUNC_OnChannelRtmpStreamingStateChanged)(const char *channelId,
                                                        const char *url,
                                                        int state, int errCode);
typedef void (*FUNC_OnChannelTranscodingUpdated)(const char *channelId);
typedef void (*FUNC_OnChannelStreamInjectedStatus)(const char *channelId,
                                                   const char *url,
                                                   rtc::uid_t uid, int status);
typedef void (*FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, rtc::uid_t uid, bool isFallbackOrRecover);
typedef void (*FUNC_OnChannelConnectionStateChanged)(const char *channelId,
                                                     int state, int reason);
typedef void (*FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight,
                                           int x, int y, int width, int height,
                                           int vecDistance, int numFaces);
typedef void (*FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void (*FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent)(int code);
typedef void (*FUNC_OnChannelTestEnd)(const char *channelId);
#endif

class CChannelEngineEventHandler {
public:
  CChannelEngineEventHandler() = default;

  ~CChannelEngineEventHandler() { reset(); }

  FUNC_OnChannelWarning onWarning = nullptr;
  FUNC_OnChannelError onError = nullptr;
  FUNC_OnChannelJoinChannelSuccess onJoinChannelSuccess = nullptr;
  FUNC_OnChannelReJoinChannelSuccess onRejoinChannelSuccess = nullptr;
  FUNC_OnChannelLeaveChannel onLeaveChannel = nullptr;
  FUNC_OnChannelClientRoleChanged onClientRoleChanged = nullptr;
  FUNC_OnChannelUserJoined onUserJoined = nullptr;
  FUNC_OnChannelUserOffLine onUserOffLine = nullptr;
  FUNC_OnChannelConnectionLost onConnectionLost = nullptr;
  FUNC_OnChannelRequestToken onRequestToken = nullptr;
  FUNC_OnChannelTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = nullptr;
  FUNC_OnChannelRtcStats onRtcStats = nullptr;
  FUNC_OnChannelNetworkQuality onNetworkQuality = nullptr;
  FUNC_OnChannelRemoteVideoStats onRemoteVideoStats = nullptr;
  FUNC_OnChannelRemoteAudioStats onRemoteAudioStats = nullptr;
  FUNC_OnChannelRemoteAudioStateChanged onRemoteAudioStateChanged = nullptr;
  FUNC_OnChannelActiveSpeaker onActiveSpeaker = nullptr;
  FUNC_OnChannelVideoSizeChanged onVideoSizeChanged = nullptr;
  FUNC_OnChannelRemoteVideoStateChanged onRemoteVideoStateChanged = nullptr;
  FUNC_OnChannelStreamMessage onStreamMessage = nullptr;
  FUNC_OnChannelStreamMessageError onStreamMessageError = nullptr;
  FUNC_OnChannelMediaRelayStateChanged2 onMediaRelayStateChanged = nullptr;
  FUNC_OnChannelMediaRelayEvent2 onMediaRelayEvent = nullptr;
  FUNC_OnChannelRtmpStreamingStateChanged onRtmpStreamingStateChanged = nullptr;
  FUNC_OnChannelTranscodingUpdated onTranscodingUpdated = nullptr;
  FUNC_OnChannelStreamInjectedStatus onStreamInjectedStatus = nullptr;
  FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = nullptr;
  FUNC_OnChannelConnectionStateChanged onConnectionStateChanged = nullptr;
  FUNC_OnChannelLocalPublishFallbackToAudioOnly
      onLocalPublishFallbackToAudioOnly = nullptr;
  FUNC_OnChannelTestEnd onTestEnd = nullptr;

  void reset() {
    onWarning = nullptr;
    onError = nullptr;
    onJoinChannelSuccess = nullptr;
    onRejoinChannelSuccess = nullptr;
    onLeaveChannel = nullptr;
    onClientRoleChanged = nullptr;
    onUserJoined = nullptr;
    onUserOffLine = nullptr;
    onConnectionLost = nullptr;
    onRequestToken = nullptr;
    onTokenPrivilegeWillExpire = nullptr;
    onRtcStats = nullptr;
    onNetworkQuality = nullptr;
    onRemoteVideoStats = nullptr;
    onRemoteAudioStats = nullptr;
    onRemoteAudioStateChanged = nullptr;
    onActiveSpeaker = nullptr;
    onVideoSizeChanged = nullptr;
    onRemoteVideoStateChanged = nullptr;
    onStreamMessage = nullptr;
    onStreamMessageError = nullptr;
    onMediaRelayStateChanged = nullptr;
    onMediaRelayEvent = nullptr;
    onRtmpStreamingStateChanged = nullptr;
    onTranscodingUpdated = nullptr;
    onStreamInjectedStatus = nullptr;
    onRemoteSubscribeFallbackToAudioOnly = nullptr;
    onConnectionStateChanged = nullptr;
    onLocalPublishFallbackToAudioOnly = nullptr;
    onTestEnd = nullptr;
  }
};

class RtcChannelEventHandler : public RtcChannelEventHandlerBase {
private:
  ChannelEventHandler *mEventHandler = nullptr;
  CChannelEngineEventHandler *cChannelEngineEvent = nullptr;

public:
  RtcChannelEventHandler(ChannelEventHandler *mEventHandler);

  RtcChannelEventHandler();

  void initChannelCallbackEvent(CChannelEngineEventHandler *channelEngineEvent);

  virtual ~RtcChannelEventHandler();

  void onChannelWarning(rtc::IChannel *rtcChannel, int warn,
                        const char *msg) override;

  void onChannelError(rtc::IChannel *rtcChannel, int err,
                      const char *msg) override;

  void onJoinChannelSuccess(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                            int elapsed) override;

  void onRejoinChannelSuccess(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                              int elapsed) override;

  void onLeaveChannel(rtc::IChannel *rtcChannel,
                      const rtc::RtcStats &stats) override;

  void onClientRoleChanged(rtc::IChannel *rtcChannel,
                           rtc::CLIENT_ROLE_TYPE oldRole,
                           rtc::CLIENT_ROLE_TYPE newRole) override;

  void onUserJoined(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                    int elapsed) override;

  void onUserOffline(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                     rtc::USER_OFFLINE_REASON_TYPE reason) override;

  void onConnectionLost(rtc::IChannel *rtcChannel) override;

  void onRequestToken(rtc::IChannel *rtcChannel) override;

  void onTokenPrivilegeWillExpire(rtc::IChannel *rtcChannel,
                                  const char *token) override;

  void onRtcStats(rtc::IChannel *rtcChannel,
                  const rtc::RtcStats &stats) override;

  void onNetworkQuality(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                        int txQuality, int rxQuality) override;

  void onRemoteVideoStats(rtc::IChannel *rtcChannel,
                          const rtc::RemoteVideoStats &stats) override;

  void onRemoteAudioStats(rtc::IChannel *rtcChannel,
                          const rtc::RemoteAudioStats &stats) override;

  void onRemoteAudioStateChanged(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                                 rtc::REMOTE_AUDIO_STATE state,
                                 rtc::REMOTE_AUDIO_STATE_REASON reason,
                                 int elapsed) override;

  void onActiveSpeaker(rtc::IChannel *rtcChannel, rtc::uid_t uid) override;

  void onVideoSizeChanged(rtc::IChannel *rtcChannel, rtc::uid_t uid, int width,
                          int height, int rotation) override;

  void onRemoteVideoStateChanged(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                                 rtc::REMOTE_VIDEO_STATE state,
                                 rtc::REMOTE_VIDEO_STATE_REASON reason,
                                 int elapsed) override;

  void onStreamMessage(rtc::IChannel *rtcChannel, rtc::uid_t uid, int streamId,
                       const char *data, size_t length) override;

  void onStreamMessageError(rtc::IChannel *rtcChannel, rtc::uid_t uid,
                            int streamId, int code, int missed,
                            int cached) override;

  void
  onChannelMediaRelayStateChanged(rtc::IChannel *rtcChannel,
                                  rtc::CHANNEL_MEDIA_RELAY_STATE state,
                                  rtc::CHANNEL_MEDIA_RELAY_ERROR code) override;

  void onChannelMediaRelayEvent(rtc::IChannel *rtcChannel,
                                rtc::CHANNEL_MEDIA_RELAY_EVENT code) override;

  void
  onRtmpStreamingStateChanged(rtc::IChannel *rtcChannel, const char *url,
                              rtc::RTMP_STREAM_PUBLISH_STATE state,
                              rtc::RTMP_STREAM_PUBLISH_ERROR errCode) override;

  void onTranscodingUpdated(rtc::IChannel *rtcChannel) override;

  void onStreamInjectedStatus(rtc::IChannel *rtcChannel, const char *url,
                              rtc::uid_t uid, int status) override;

  void onLocalPublishFallbackToAudioOnly(rtc::IChannel *rtcChannel,
                                         bool isFallbackOrRecover) override;

  void onRemoteSubscribeFallbackToAudioOnly(rtc::IChannel *rtcChannel,
                                            rtc::uid_t uid,
                                            bool isFallbackOrRecover) override;

  void
  onConnectionStateChanged(rtc::IChannel *rtcChannel,
                           rtc::CONNECTION_STATE_TYPE state,
                           rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;

  void onTestEnd(rtc::IChannel *rtcChannel) override;
};
} // namespace common
} // namespace agora
