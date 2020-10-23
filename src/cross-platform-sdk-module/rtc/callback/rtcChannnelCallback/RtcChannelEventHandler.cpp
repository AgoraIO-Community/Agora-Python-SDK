//
// Created by LXH on 2020/8/7.
//

#include "RtcChannelEventHandler.h"

namespace agora {
namespace common {
using namespace rtc;

RtcChannelEventHandler::RtcChannelEventHandler(
    ChannelEventHandler *mEventHandler)
    : mEventHandler(mEventHandler) {}

RtcChannelEventHandler::RtcChannelEventHandler() {
  cChannelEngineEvent = new CChannelEngineEventHandler();
}

RtcChannelEventHandler::~RtcChannelEventHandler() {
  mEventHandler = nullptr;
  if (cChannelEngineEvent) {
    delete cChannelEngineEvent;
    cChannelEngineEvent = nullptr;
  }
}

void RtcChannelEventHandler::initChannelCallbackEvent(
    CChannelEngineEventHandler *channelEngineEvent) {
  cChannelEngineEvent->onWarning = channelEngineEvent->onWarning;
  cChannelEngineEvent->onError = channelEngineEvent->onError;
  cChannelEngineEvent->onJoinChannelSuccess =
      channelEngineEvent->onJoinChannelSuccess;
  cChannelEngineEvent->onRejoinChannelSuccess =
      channelEngineEvent->onRejoinChannelSuccess;
  cChannelEngineEvent->onLeaveChannel = channelEngineEvent->onLeaveChannel;
  cChannelEngineEvent->onClientRoleChanged =
      channelEngineEvent->onClientRoleChanged;
  cChannelEngineEvent->onUserJoined = channelEngineEvent->onUserJoined;
  cChannelEngineEvent->onUserOffLine = channelEngineEvent->onUserOffLine;
  cChannelEngineEvent->onConnectionLost = channelEngineEvent->onConnectionLost;
  cChannelEngineEvent->onRequestToken = channelEngineEvent->onRequestToken;
  cChannelEngineEvent->onTokenPrivilegeWillExpire =
      channelEngineEvent->onTokenPrivilegeWillExpire;
  cChannelEngineEvent->onRtcStats = channelEngineEvent->onRtcStats;
  cChannelEngineEvent->onNetworkQuality = channelEngineEvent->onNetworkQuality;
  cChannelEngineEvent->onRemoteVideoStats =
      channelEngineEvent->onRemoteVideoStats;
  cChannelEngineEvent->onRemoteAudioStats =
      channelEngineEvent->onRemoteAudioStats;
  cChannelEngineEvent->onRemoteAudioStateChanged =
      channelEngineEvent->onRemoteAudioStateChanged;
  cChannelEngineEvent->onActiveSpeaker = channelEngineEvent->onActiveSpeaker;
  cChannelEngineEvent->onVideoSizeChanged =
      channelEngineEvent->onVideoSizeChanged;
  cChannelEngineEvent->onRemoteVideoStateChanged =
      channelEngineEvent->onRemoteVideoStateChanged;
  cChannelEngineEvent->onStreamMessage = channelEngineEvent->onStreamMessage;
  cChannelEngineEvent->onStreamMessageError =
      channelEngineEvent->onStreamMessageError;
  cChannelEngineEvent->onMediaRelayStateChanged =
      channelEngineEvent->onMediaRelayStateChanged;
  cChannelEngineEvent->onMediaRelayEvent =
      channelEngineEvent->onMediaRelayEvent;
  cChannelEngineEvent->onRtmpStreamingStateChanged =
      channelEngineEvent->onRtmpStreamingStateChanged;
  cChannelEngineEvent->onTranscodingUpdated =
      channelEngineEvent->onTranscodingUpdated;
  cChannelEngineEvent->onStreamInjectedStatus =
      channelEngineEvent->onStreamInjectedStatus;
  cChannelEngineEvent->onRemoteSubscribeFallbackToAudioOnly =
      channelEngineEvent->onRemoteSubscribeFallbackToAudioOnly;
  cChannelEngineEvent->onConnectionStateChanged =
      channelEngineEvent->onConnectionStateChanged;
  cChannelEngineEvent->onLocalPublishFallbackToAudioOnly =
      channelEngineEvent->onLocalPublishFallbackToAudioOnly;
  cChannelEngineEvent->onTestEnd = channelEngineEvent->onTestEnd;
}

void RtcChannelEventHandler::onChannelWarning(IChannel *rtcChannel, int warn,
                                              const char *msg) {
  if (cChannelEngineEvent && cChannelEngineEvent->onWarning)
    cChannelEngineEvent->onWarning(rtcChannel->channelId(), warn, msg);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string msgStr = msg ? msg : "";
  mEventHandler->functionCall<int, const char *>("onChannelWarning", channelId,
                                                 warn, msg);
}

void RtcChannelEventHandler::onChannelError(IChannel *rtcChannel, int err,
                                            const char *msg) {
  if (cChannelEngineEvent && cChannelEngineEvent->onError)
    cChannelEngineEvent->onError(rtcChannel->channelId(), err, msg);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string msgStr = msg ? msg : "";
  mEventHandler->functionCall<int, const char *>("onChannelError", channelId,
                                                 err, msg);
}

void RtcChannelEventHandler::onJoinChannelSuccess(IChannel *rtcChannel,
                                                  rtc::uid_t uid, int elapsed) {
  if (cChannelEngineEvent && cChannelEngineEvent->onJoinChannelSuccess)
    cChannelEngineEvent->onJoinChannelSuccess(rtcChannel->channelId(), uid,
                                              elapsed);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int>("onJoinChannelSuccess",
                                               channelId, uid, elapsed);
}

void RtcChannelEventHandler::onRejoinChannelSuccess(IChannel *rtcChannel,
                                                    rtc::uid_t uid,
                                                    int elapsed) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRejoinChannelSuccess)
    cChannelEngineEvent->onRejoinChannelSuccess(rtcChannel->channelId(), uid,
                                                elapsed);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int>("onRejoinChannelSuccess",
                                               channelId, uid, elapsed);
}

void RtcChannelEventHandler::onLeaveChannel(IChannel *rtcChannel,
                                            const RtcStats &stats) {
  if (cChannelEngineEvent && cChannelEngineEvent->onLeaveChannel)
    cChannelEngineEvent->onLeaveChannel(
        rtcChannel->channelId(), stats.duration, stats.txBytes, stats.rxBytes,
        stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes,
        stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate,
        stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate,
        stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate,
        stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage,
        stats.cpuTotalUsage, stats.gatewayRtt, stats.memoryAppUsageRatio,
        stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onLeaveChannel", channelId, stats);
}

void RtcChannelEventHandler::onClientRoleChanged(IChannel *rtcChannel,
                                                 CLIENT_ROLE_TYPE oldRole,
                                                 CLIENT_ROLE_TYPE newRole) {
  if (cChannelEngineEvent && cChannelEngineEvent->onClientRoleChanged)
    cChannelEngineEvent->onClientRoleChanged(rtcChannel->channelId(),
                                             int(oldRole), int(newRole));

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<int, int>("onClientRoleChanged", channelId,
                                        oldRole, newRole);
}

void RtcChannelEventHandler::onUserJoined(IChannel *rtcChannel, rtc::uid_t uid,
                                          int elapsed) {
  if (cChannelEngineEvent && cChannelEngineEvent->onUserJoined)
    cChannelEngineEvent->onUserJoined(rtcChannel->channelId(), uid, elapsed);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int>("onUserJoined", channelId, uid,
                                               elapsed);
}

void RtcChannelEventHandler::onUserOffline(IChannel *rtcChannel, rtc::uid_t uid,
                                           USER_OFFLINE_REASON_TYPE reason) {
  if (cChannelEngineEvent && cChannelEngineEvent->onUserOffLine)
    cChannelEngineEvent->onUserOffLine(rtcChannel->channelId(), uid, reason);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int>("onUserOffline", channelId, uid,
                                               reason);
}

void RtcChannelEventHandler::onConnectionLost(IChannel *rtcChannel) {
  if (cChannelEngineEvent && cChannelEngineEvent->onConnectionLost)
    cChannelEngineEvent->onConnectionLost(rtcChannel->channelId());

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onConnectionLost", channelId);
}

void RtcChannelEventHandler::onRequestToken(IChannel *rtcChannel) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRequestToken)
    cChannelEngineEvent->onRequestToken(rtcChannel->channelId());

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onRequestToken", channelId);
}

void RtcChannelEventHandler::onTokenPrivilegeWillExpire(IChannel *rtcChannel,
                                                        const char *token) {
  if (cChannelEngineEvent && cChannelEngineEvent->onTokenPrivilegeWillExpire)
    cChannelEngineEvent->onTokenPrivilegeWillExpire(rtcChannel->channelId(),
                                                    token);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string tokenStr = token ? token : "";
  mEventHandler->functionCall<std::string>("onTokenPrivilegeWillExpire",
                                           channelId, tokenStr);
}

void RtcChannelEventHandler::onRtcStats(IChannel *rtcChannel,
                                        const RtcStats &stats) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRtcStats)
    cChannelEngineEvent->onRtcStats(
        rtcChannel->channelId(), stats.duration, stats.txBytes, stats.rxBytes,
        stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes,
        stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate,
        stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate,
        stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate,
        stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage,
        stats.cpuTotalUsage, stats.gatewayRtt, stats.memoryAppUsageRatio,
        stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onRtcStats", channelId, stats);
}

void RtcChannelEventHandler::onNetworkQuality(IChannel *rtcChannel,
                                              rtc::uid_t uid, int txQuality,
                                              int rxQuality) {
  if (cChannelEngineEvent && cChannelEngineEvent->onNetworkQuality)
    cChannelEngineEvent->onNetworkQuality(rtcChannel->channelId(), uid,
                                          txQuality, rxQuality);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int, int>(
      "onNetworkQuality", channelId, uid, txQuality, rxQuality);
}

void RtcChannelEventHandler::onRemoteVideoStats(IChannel *rtcChannel,
                                                const RemoteVideoStats &stats) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRemoteVideoStats)
    cChannelEngineEvent->onRemoteVideoStats(
        rtcChannel->channelId(), stats.uid, stats.delay, stats.width,
        stats.height, stats.receivedBitrate, stats.decoderOutputFrameRate,
        stats.rendererOutputFrameRate, stats.packetLossRate,
        (int)stats.rxStreamType, stats.totalFrozenTime, stats.frozenRate,
        stats.totalActiveTime);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onRemoteVideoStats", channelId, stats);
}

void RtcChannelEventHandler::onRemoteAudioStats(IChannel *rtcChannel,
                                                const RemoteAudioStats &stats) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRemoteAudioStats)
    cChannelEngineEvent->onRemoteAudioStats(
        rtcChannel->channelId(), stats.uid, stats.quality,
        stats.networkTransportDelay, stats.jitterBufferDelay,
        stats.audioLossRate, stats.numChannels, stats.receivedSampleRate,
        stats.receivedBitrate, stats.totalFrozenTime, stats.frozenRate,
        stats.totalActiveTime);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onRemoteAudioStats", channelId, stats);
}

void RtcChannelEventHandler::onRemoteAudioStateChanged(
    IChannel *rtcChannel, rtc::uid_t uid, REMOTE_AUDIO_STATE state,
    REMOTE_AUDIO_STATE_REASON reason, int elapsed) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRemoteAudioStateChanged)
    cChannelEngineEvent->onRemoteAudioStateChanged(
        rtcChannel->channelId(), uid, int(state), int(reason), elapsed);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onRemoteAudioStateChanged", channelId, uid, state, reason, elapsed);
}

void RtcChannelEventHandler::onActiveSpeaker(IChannel *rtcChannel,
                                             rtc::uid_t uid) {
  if (cChannelEngineEvent && cChannelEngineEvent->onActiveSpeaker)
    cChannelEngineEvent->onActiveSpeaker(rtcChannel->channelId(), uid);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t>("onActiveSpeaker", channelId, uid);
}

void RtcChannelEventHandler::onVideoSizeChanged(IChannel *rtcChannel,
                                                rtc::uid_t uid, int width,
                                                int height, int rotation) {
  if (cChannelEngineEvent && cChannelEngineEvent->onVideoSizeChanged)
    cChannelEngineEvent->onVideoSizeChanged(rtcChannel->channelId(), uid, width,
                                            height, rotation);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onVideoSizeChanged", channelId, uid, width, height, rotation);
}

void RtcChannelEventHandler::onRemoteVideoStateChanged(
    IChannel *rtcChannel, rtc::uid_t uid, REMOTE_VIDEO_STATE state,
    REMOTE_VIDEO_STATE_REASON reason, int elapsed) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRemoteVideoStateChanged)
    cChannelEngineEvent->onRemoteVideoStateChanged(
        rtcChannel->channelId(), uid, int(state), int(reason), elapsed);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onRemoteVideoStateChanged", channelId, uid, state, reason, elapsed);
}

void RtcChannelEventHandler::onStreamMessage(IChannel *rtcChannel,
                                             rtc::uid_t uid, int streamId,
                                             const char *data, size_t length) {
  if (cChannelEngineEvent && cChannelEngineEvent->onStreamMessage)
    cChannelEngineEvent->onStreamMessage(rtcChannel->channelId(), uid, streamId,
                                         data, length);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string dataStr = data ? data : "";
  mEventHandler->functionCall<rtc::uid_t, int, std::string, size_t>(
      "onStreamMessage", channelId, uid, streamId, dataStr, length);
}

void RtcChannelEventHandler::onStreamMessageError(IChannel *rtcChannel,
                                                  rtc::uid_t uid, int streamId,
                                                  int code, int missed,
                                                  int cached) {
  if (cChannelEngineEvent && cChannelEngineEvent->onStreamMessageError)
    cChannelEngineEvent->onStreamMessageError(rtcChannel->channelId(), uid,
                                              streamId, code, missed, cached);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, int, int, int, int>(
      "onStreamMessageError", channelId, uid, streamId, code, missed, cached);
}

void RtcChannelEventHandler::onChannelMediaRelayStateChanged(
    IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_STATE state,
    CHANNEL_MEDIA_RELAY_ERROR code) {
  if (cChannelEngineEvent && cChannelEngineEvent->onMediaRelayStateChanged)
    cChannelEngineEvent->onMediaRelayStateChanged(rtcChannel->channelId(),
                                                  int(state), int(code));

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<int, int>("onChannelMediaRelayStateChanged",
                                        channelId, state, code);
}

void RtcChannelEventHandler::onChannelMediaRelayEvent(
    IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_EVENT code) {
  if (cChannelEngineEvent && cChannelEngineEvent->onMediaRelayEvent)
    cChannelEngineEvent->onMediaRelayEvent(rtcChannel->channelId(), int(code));

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<int>("onChannelMediaRelayEvent", channelId, code);
}

void RtcChannelEventHandler::onRtmpStreamingStateChanged(
    IChannel *rtcChannel, const char *url, RTMP_STREAM_PUBLISH_STATE state,
    RTMP_STREAM_PUBLISH_ERROR errCode) {
  if (cChannelEngineEvent && cChannelEngineEvent->onRtmpStreamingStateChanged)
    cChannelEngineEvent->onRtmpStreamingStateChanged(
        rtcChannel->channelId(), url, int(state), int(errCode));

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string urlStr = url ? url : "";
  mEventHandler->functionCall<std::string, int, int>(
      "onRtmpStreamingStateChanged", channelId, urlStr, state, errCode);
}

void RtcChannelEventHandler::onTranscodingUpdated(IChannel *rtcChannel) {
  if (cChannelEngineEvent && cChannelEngineEvent->onTranscodingUpdated)
    cChannelEngineEvent->onTranscodingUpdated(rtcChannel->channelId());

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onTranscodingUpdated", channelId);
}

void RtcChannelEventHandler::onStreamInjectedStatus(IChannel *rtcChannel,
                                                    const char *url,
                                                    rtc::uid_t uid,
                                                    int status) {
  if (cChannelEngineEvent && cChannelEngineEvent->onStreamInjectedStatus)
    cChannelEngineEvent->onStreamInjectedStatus(rtcChannel->channelId(), url,
                                                uid, status);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  std::string urlStr = url ? url : "";
  mEventHandler->functionCall<std::string, rtc::uid_t, int>(
      "onStreamInjectedStatus", channelId, urlStr, uid, status);
}

void RtcChannelEventHandler::onLocalPublishFallbackToAudioOnly(
    IChannel *rtcChannel, bool isFallbackOrRecover) {
  if (cChannelEngineEvent &&
      cChannelEngineEvent->onLocalPublishFallbackToAudioOnly)
    cChannelEngineEvent->onLocalPublishFallbackToAudioOnly(
        rtcChannel->channelId(), isFallbackOrRecover);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<bool>("onLocalPublishFallbackToAudioOnly",
                                    channelId, isFallbackOrRecover);
}

void RtcChannelEventHandler::onRemoteSubscribeFallbackToAudioOnly(
    IChannel *rtcChannel, rtc::uid_t uid, bool isFallbackOrRecover) {
  if (cChannelEngineEvent &&
      cChannelEngineEvent->onRemoteSubscribeFallbackToAudioOnly)
    cChannelEngineEvent->onRemoteSubscribeFallbackToAudioOnly(
        rtcChannel->channelId(), uid, isFallbackOrRecover);

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<rtc::uid_t, bool>(
      "onRemoteSubscribeFallbackToAudioOnly", channelId, uid,
      isFallbackOrRecover);
}

void RtcChannelEventHandler::onConnectionStateChanged(
    IChannel *rtcChannel, CONNECTION_STATE_TYPE state,
    CONNECTION_CHANGED_REASON_TYPE reason) {
  if (cChannelEngineEvent && cChannelEngineEvent->onConnectionStateChanged)
    cChannelEngineEvent->onConnectionStateChanged(rtcChannel->channelId(),
                                                  int(state), int(reason));

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall<int, int>("onConnectionStateChanged", channelId,
                                        state, reason);
}

void RtcChannelEventHandler::onTestEnd(IChannel *rtcChannel) {
  if (cChannelEngineEvent && cChannelEngineEvent->onTestEnd)
    cChannelEngineEvent->onTestEnd(rtcChannel->channelId());

  if (!mEventHandler)
    return;

  std::string channelId = rtcChannel->channelId();
  mEventHandler->functionCall("onTestEnd", channelId);
}

} // namespace common
} // namespace agora
