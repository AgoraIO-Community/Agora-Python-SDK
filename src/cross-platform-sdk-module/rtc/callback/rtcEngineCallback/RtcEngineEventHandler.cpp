#include "RtcEngineEventHandler.h"

namespace agora {
namespace common {
using namespace rtc;

RtcEngineEventHandler::RtcEngineEventHandler(EngineEventHandler *eventHandler)
    : mEventHandler(eventHandler) {
  cEngineEventHandler = new CEngineEventHandler();
}

RtcEngineEventHandler::~RtcEngineEventHandler() {
  mEventHandler = nullptr;
  if (cEngineEventHandler) {
    delete (cEngineEventHandler);
    cEngineEventHandler = nullptr;
  }
}

RtcEngineEventHandler::RtcEngineEventHandler() {
  cEngineEventHandler = new CEngineEventHandler();
}

void RtcEngineEventHandler::initCallbackEvent(
    CEngineEventHandler *engineEventHandler) {
  cEngineEventHandler->onJoinChannelSuccess =
      engineEventHandler->onJoinChannelSuccess;
  cEngineEventHandler->onReJoinChannelSuccess =
      engineEventHandler->onReJoinChannelSuccess;
  cEngineEventHandler->onConnectionLost = engineEventHandler->onConnectionLost;
  cEngineEventHandler->onLeaveChannel = engineEventHandler->onLeaveChannel;
  cEngineEventHandler->onConnectionInterrupted =
      engineEventHandler->onConnectionInterrupted;
  cEngineEventHandler->onRequestToken = engineEventHandler->onRequestToken;
  cEngineEventHandler->onUserJoined = engineEventHandler->onUserJoined;
  cEngineEventHandler->onUserOffline = engineEventHandler->onUserOffline;
  cEngineEventHandler->onAudioVolumeIndication =
      engineEventHandler->onAudioVolumeIndication;
  cEngineEventHandler->onUserMuteAudio = engineEventHandler->onUserMuteAudio;
  cEngineEventHandler->onWarning = engineEventHandler->onWarning;
  cEngineEventHandler->onError = engineEventHandler->onError;
  cEngineEventHandler->onRtcStats = engineEventHandler->onRtcStats;
  cEngineEventHandler->onAudioMixingFinished =
      engineEventHandler->onAudioMixingFinished;
  cEngineEventHandler->onAudioRouteChanged =
      engineEventHandler->onAudioRouteChanged;
  cEngineEventHandler->onFirstRemoteVideoDecoded =
      engineEventHandler->onFirstRemoteVideoDecoded;
  cEngineEventHandler->onVideoSizeChanged =
      engineEventHandler->onVideoSizeChanged;
  cEngineEventHandler->onClientRoleChanged =
      engineEventHandler->onClientRoleChanged;
  cEngineEventHandler->onUserMuteVideo = engineEventHandler->onUserMuteVideo;
  cEngineEventHandler->onMicrophoneEnabled =
      engineEventHandler->onMicrophoneEnabled;
  cEngineEventHandler->onApiCallExecuted =
      engineEventHandler->onApiCallExecuted;
  cEngineEventHandler->onFirstLocalAudioFrame =
      engineEventHandler->onFirstLocalAudioFrame;
  cEngineEventHandler->onFirstRemoteAudioFrame =
      engineEventHandler->onFirstRemoteAudioFrame;
  cEngineEventHandler->onLastmileQuality =
      engineEventHandler->onLastmileQuality;
  cEngineEventHandler->onAudioQuality = engineEventHandler->onAudioQuality;
  cEngineEventHandler->onStreamInjectedStatus =
      engineEventHandler->onStreamInjectedStatus;
  cEngineEventHandler->onStreamUnpublished =
      engineEventHandler->onStreamUnpublished;
  cEngineEventHandler->onStreamPublished =
      engineEventHandler->onStreamPublished;
  cEngineEventHandler->onStreamMessageError =
      engineEventHandler->onStreamMessageError;
  cEngineEventHandler->onStreamMessage = engineEventHandler->onStreamMessage;
  cEngineEventHandler->onConnectionBanned =
      engineEventHandler->onConnectionBanned;
  cEngineEventHandler->onVideoStopped = engineEventHandler->onVideoStopped;
  cEngineEventHandler->onTokenPrivilegeWillExpire =
      engineEventHandler->onTokenPrivilegeWillExpire;
  cEngineEventHandler->onNetworkQuality = engineEventHandler->onNetworkQuality;
  cEngineEventHandler->onLocalVideoStats =
      engineEventHandler->onLocalVideoStats;
  cEngineEventHandler->onRemoteVideoStats =
      engineEventHandler->onRemoteVideoStats;
  cEngineEventHandler->onRemoteAudioStats =
      engineEventHandler->onRemoteAudioStats;
  cEngineEventHandler->onFirstLocalVideoFrame =
      engineEventHandler->onFirstLocalVideoFrame;
  cEngineEventHandler->onFirstRemoteVideoFrame =
      engineEventHandler->onFirstRemoteVideoFrame;
  cEngineEventHandler->onUserEnableVideo =
      engineEventHandler->onUserEnableVideo;
  cEngineEventHandler->onAudioDeviceStateChanged =
      engineEventHandler->onAudioDeviceStateChanged;
  cEngineEventHandler->onCameraReady = engineEventHandler->onCameraReady;
  cEngineEventHandler->onCameraFocusAreaChanged =
      engineEventHandler->onCameraFocusAreaChanged;
  cEngineEventHandler->onCameraExposureAreaChanged =
      engineEventHandler->onCameraExposureAreaChanged;
  cEngineEventHandler->onRemoteAudioMixingBegin =
      engineEventHandler->onRemoteAudioMixingBegin;
  cEngineEventHandler->onRemoteAudioMixingEnd =
      engineEventHandler->onRemoteAudioMixingEnd;
  cEngineEventHandler->onAudioEffectFinished =
      engineEventHandler->onAudioEffectFinished;
  cEngineEventHandler->onVideoDeviceStateChanged =
      engineEventHandler->onVideoDeviceStateChanged;
  cEngineEventHandler->onRemoteVideoStateChanged =
      engineEventHandler->onRemoteVideoStateChanged;
  cEngineEventHandler->onUserEnableLocalVideo =
      engineEventHandler->onUserEnableLocalVideo;
  cEngineEventHandler->onLocalPublishFallbackToAudioOnly =
      engineEventHandler->onLocalPublishFallbackToAudioOnly;
  cEngineEventHandler->onRemoteSubscribeFallbackToAudioOnly =
      engineEventHandler->onRemoteSubscribeFallbackToAudioOnly;
  cEngineEventHandler->onConnectionStateChanged =
      engineEventHandler->onConnectionStateChanged;
  cEngineEventHandler->onRemoteVideoTransportStats =
      engineEventHandler->onRemoteVideoTransportStats;
  cEngineEventHandler->onRemoteAudioTransportStats =
      engineEventHandler->onRemoteAudioTransportStats;
  cEngineEventHandler->onTranscodingUpdated =
      engineEventHandler->onTranscodingUpdated;
  cEngineEventHandler->onAudioDeviceVolumeChanged =
      engineEventHandler->onAudioDeviceVolumeChanged;
  cEngineEventHandler->onActiveSpeaker = engineEventHandler->onActiveSpeaker;
  cEngineEventHandler->onMediaEngineStartCallSuccess =
      engineEventHandler->onMediaEngineStartCallSuccess;
  cEngineEventHandler->onMediaEngineLoadSuccess =
      engineEventHandler->onMediaEngineLoadSuccess;
  cEngineEventHandler->onAudioMixingStateChanged =
      engineEventHandler->onAudioMixingStateChanged;
  cEngineEventHandler->onFirstRemoteAudioDecoded =
      engineEventHandler->onFirstRemoteAudioDecoded;
  cEngineEventHandler->onLocalVideoStateChanged =
      engineEventHandler->onLocalVideoStateChanged;
  cEngineEventHandler->onRtmpStreamingStateChanged =
      engineEventHandler->onRtmpStreamingStateChanged;
  cEngineEventHandler->onNetworkTypeChanged =
      engineEventHandler->onNetworkTypeChanged;
  cEngineEventHandler->onLastmileProbeResult =
      engineEventHandler->onLastmileProbeResult;
  cEngineEventHandler->onLocalUserRegistered =
      engineEventHandler->onLocalUserRegistered;
  cEngineEventHandler->onUserInfoUpdated =
      engineEventHandler->onUserInfoUpdated;
  cEngineEventHandler->onLocalAudioStateChanged =
      engineEventHandler->onLocalAudioStateChanged;
  cEngineEventHandler->onRemoteAudioStateChanged =
      engineEventHandler->onRemoteAudioStateChanged;
  cEngineEventHandler->onLocalAudioStats =
      engineEventHandler->onLocalAudioStats;
  cEngineEventHandler->onChannelMediaRelayStateChanged =
      engineEventHandler->onChannelMediaRelayStateChanged;
  cEngineEventHandler->onChannelMediaRelayEvent =
      engineEventHandler->onChannelMediaRelayEvent;
  cEngineEventHandler->onFacePositionChanged =
      engineEventHandler->onFacePositionChanged;
  cEngineEventHandler->onTestEnd = engineEventHandler->onTestEnd;
}

void RtcEngineEventHandler::onJoinChannelSuccess(const char *channel,
                                                 rtc::uid_t uid, int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onJoinChannelSuccess)
    cEngineEventHandler->onJoinChannelSuccess(channel, uid, elapsed);

  if (!mEventHandler)
    return;

  std::string mChannel = channel ? channel : "";
  mEventHandler->functionCall<std::string, rtc::uid_t, int>(
      "onJoinChannelSuccess", mChannel, uid, elapsed);
}

void RtcEngineEventHandler::onLeaveChannel(const rtc::RtcStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onLeaveChannel)
    cEngineEventHandler->onLeaveChannel(
        stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes,
        stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes,
        stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate,
        stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate,
        stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate,
        stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage,
        stats.gatewayRtt, stats.memoryAppUsageRatio,
        stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);

  if (!mEventHandler)
    return;

  const rtc::RtcStats mStats = stats;
  mEventHandler->functionCall("onLeaveChannel", mStats);
}

void RtcEngineEventHandler::onRejoinChannelSuccess(const char *channel,
                                                   rtc::uid_t uid,
                                                   int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onReJoinChannelSuccess)
    cEngineEventHandler->onReJoinChannelSuccess(channel, uid, elapsed);

  if (!mEventHandler)
    return;

  std::string mChannel = channel ? channel : "";
  mEventHandler->functionCall<std::string, rtc::uid_t, int>(
      "onRejoinChannelSuccess", mChannel, uid, elapsed);
}

void RtcEngineEventHandler::onUserJoined(rtc::uid_t uid, int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onUserJoined)
    cEngineEventHandler->onUserJoined(uid, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int>("onUserJoined", uid, elapsed);
}

void RtcEngineEventHandler::onClientRoleChanged(rtc::CLIENT_ROLE_TYPE oldRole,
                                                rtc::CLIENT_ROLE_TYPE newRole) {
  if (cEngineEventHandler && cEngineEventHandler->onClientRoleChanged)
    cEngineEventHandler->onClientRoleChanged(int(oldRole), int(newRole));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onClientRoleChanged", oldRole,
                                        newRole);
}

void RtcEngineEventHandler::onUserOffline(
    rtc::uid_t uid, rtc::USER_OFFLINE_REASON_TYPE reason) {
  if (cEngineEventHandler && cEngineEventHandler->onUserOffline)
    cEngineEventHandler->onUserOffline(uid, int(reason));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int>("onUserOffline", uid, reason);
}

void RtcEngineEventHandler::onUserMuteAudio(rtc::uid_t uid, bool muted) {
  if (cEngineEventHandler && cEngineEventHandler->onUserMuteAudio)
    cEngineEventHandler->onUserMuteAudio(uid, muted);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, bool>("onUserMuteAudio", uid, muted);
}

void RtcEngineEventHandler::onFirstRemoteVideoDecoded(rtc::uid_t uid, int width,
                                                      int height, int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstRemoteVideoDecoded)
    cEngineEventHandler->onFirstRemoteVideoDecoded(uid, width, height, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onFirstRemoteVideoDecoded", uid, width, height, elapsed);
}

void RtcEngineEventHandler::onUserMuteVideo(rtc::uid_t uid, bool muted) {
  if (cEngineEventHandler && cEngineEventHandler->onUserMuteVideo)
    cEngineEventHandler->onUserMuteVideo(uid, muted);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, bool>("onUserMuteVideo", uid, muted);
}

void RtcEngineEventHandler::onAudioRouteChanged(rtc::AUDIO_ROUTE_TYPE routing) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioRouteChanged)
    cEngineEventHandler->onAudioRouteChanged(int(routing));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onAudioRouteChanged", routing);
}

void RtcEngineEventHandler::onConnectionLost() {
  if (cEngineEventHandler && cEngineEventHandler->onConnectionLost)
    cEngineEventHandler->onConnectionLost();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onConnectionLost");
}

void RtcEngineEventHandler::onRequestToken() {
  if (cEngineEventHandler && cEngineEventHandler->onRequestToken)
    cEngineEventHandler->onRequestToken();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onRequestToken");
}

void RtcEngineEventHandler::onAudioVolumeIndication(
    const rtc::AudioVolumeInfo *speakers, unsigned int speakerNumber,
    int totalVolume) {
  if (!speakers && speakerNumber > 0)
    return;

  if (cEngineEventHandler && cEngineEventHandler->onAudioVolumeIndication) {
    std::vector<uid_t> uidList;
    std::vector<unsigned int> volumeList;
    std::vector<unsigned int> vadList;
    std::vector<const char *> channelIdList;
    uidList.resize(speakerNumber);
    volumeList.resize(speakerNumber);
    vadList.resize(speakerNumber);
    channelIdList.resize(speakerNumber);

    for (int i = 0; i < speakerNumber; i++) {
      uidList.push_back(speakers[i].uid);
      volumeList.push_back(speakers[i].volume);
      vadList.push_back(speakers[i].vad);
      channelIdList.push_back(speakers[i].channelId);
    }
    cEngineEventHandler->onAudioVolumeIndication(
        uidList.data(), volumeList.data(), vadList.data(), channelIdList.data(),
        speakerNumber, totalVolume);
  }

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onAudioVolumeIndication", speakers,
                              speakerNumber, totalVolume);
}

void RtcEngineEventHandler::onWarning(int warn, const char *msg) {
  if (cEngineEventHandler && cEngineEventHandler->onWarning)
    cEngineEventHandler->onWarning(warn, msg);

  if (!mEventHandler)
    return;

  std::string message = msg ? msg : "";
  mEventHandler->functionCall<int, std::string>("onWarning", warn, message);
}

void RtcEngineEventHandler::onError(int err, const char *msg) {
  if (cEngineEventHandler && cEngineEventHandler->onError)
    cEngineEventHandler->onError(err, msg);

  if (!mEventHandler)
    return;

  std::string message = msg ? msg : "";
  mEventHandler->functionCall<int, std::string>("onError", err, message);
}

void RtcEngineEventHandler::onRtcStats(const rtc::RtcStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onRtcStats)
    cEngineEventHandler->onRtcStats(
        stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes,
        stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes,
        stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate,
        stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate,
        stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate,
        stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage,
        stats.gatewayRtt, stats.memoryAppUsageRatio,
        stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);

  if (!mEventHandler)
    return;

  const RtcStats mStats = stats;
  mEventHandler->functionCall("onRtcStats", mStats);
}

void RtcEngineEventHandler::onAudioMixingFinished() {
  if (cEngineEventHandler && cEngineEventHandler->onAudioMixingFinished)
    cEngineEventHandler->onAudioMixingFinished();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onAudioMixingFinished");
}

void RtcEngineEventHandler::onVideoSizeChanged(rtc::uid_t uid, int width,
                                               int height, int rotation) {
  if (cEngineEventHandler && cEngineEventHandler->onVideoSizeChanged)
    cEngineEventHandler->onVideoSizeChanged(uid, width, height, rotation);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onVideoSizeChanged", uid, width, height, rotation);
}

void RtcEngineEventHandler::onConnectionInterrupted() {
  if (cEngineEventHandler && cEngineEventHandler->onConnectionInterrupted)
    cEngineEventHandler->onConnectionInterrupted();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onConnectionInterrupted");
}

void RtcEngineEventHandler::onMicrophoneEnabled(bool enabled) {
  if (cEngineEventHandler && cEngineEventHandler->onMicrophoneEnabled)
    cEngineEventHandler->onMicrophoneEnabled(enabled);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<bool>("onMicrophoneEnabled", enabled);
}

void RtcEngineEventHandler::onFirstRemoteAudioFrame(rtc::uid_t uid,
                                                    int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstRemoteAudioFrame)
    cEngineEventHandler->onFirstRemoteAudioFrame(uid, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int>("onFirstRemoteAudioFrame", uid,
                                               elapsed);
}

void RtcEngineEventHandler::onFirstLocalAudioFrame(int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstLocalAudioFrame)
    cEngineEventHandler->onFirstLocalAudioFrame(elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onFirstLocalAudioFrame", elapsed);
}

void RtcEngineEventHandler::onApiCallExecuted(int err, const char *api,
                                              const char *result) {
  if (cEngineEventHandler && cEngineEventHandler->onApiCallExecuted)
    cEngineEventHandler->onApiCallExecuted(err, api, result);

  if (!mEventHandler)
    return;

  std::string mApi = api ? api : "";
  std::string mResult = result ? result : "";
  mEventHandler->functionCall<int, std::string, std::string>(
      "onApiCallExecuted", err, mApi, mResult);
}

void RtcEngineEventHandler::onLastmileQuality(int quality) {
  if (cEngineEventHandler && cEngineEventHandler->onLastmileQuality)
    cEngineEventHandler->onLastmileQuality(quality);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onLastmileQuality", quality);
}

void RtcEngineEventHandler::onLastmileProbeResult(
    const LastmileProbeResult &result) {
  if (cEngineEventHandler && cEngineEventHandler->onLastmileProbeResult)
    cEngineEventHandler->onLastmileProbeResult(
        (int)result.state, result.uplinkReport.packetLossRate,
        result.uplinkReport.jitter, result.uplinkReport.availableBandwidth,
        result.downlinkReport.packetLossRate, result.downlinkReport.jitter,
        result.downlinkReport.availableBandwidth, result.rtt);

  if (!mEventHandler)
    return;

  const LastmileProbeResult mResult = result;
  mEventHandler->functionCall("onLastmileProbeResult", mResult);
}

void RtcEngineEventHandler::onAudioQuality(rtc::uid_t uid, int quality,
                                           unsigned short delay,
                                           unsigned short lost) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioQuality)
    cEngineEventHandler->onAudioQuality(uid, quality, delay, lost);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, unsigned short, unsigned short>(
      "onAudioQuality", uid, quality, delay, lost);
}

void RtcEngineEventHandler::onRemoteVideoTransportStats(
    rtc::uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteVideoTransportStats)
    cEngineEventHandler->onRemoteVideoTransportStats(uid, delay, lost,
                                                     rxKBitRate);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, unsigned short, unsigned short,
                              unsigned short>("onRemoteVideoTransportStats",
                                              uid, delay, lost, rxKBitRate);
}

void RtcEngineEventHandler::onRemoteAudioTransportStats(
    rtc::uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteAudioTransportStats)
    cEngineEventHandler->onRemoteAudioTransportStats(uid, delay, lost,
                                                     rxKBitRate);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, unsigned short, unsigned short,
                              unsigned short>("onRemoteAudioTransportStats",
                                              uid, delay, lost, rxKBitRate);
}

void RtcEngineEventHandler::onStreamInjectedStatus(const char *url,
                                                   rtc::uid_t uid, int status) {
  if (cEngineEventHandler && cEngineEventHandler->onStreamInjectedStatus)
    cEngineEventHandler->onStreamInjectedStatus(url, uid, status);

  if (!mEventHandler)
    return;

  std::string mUrl = url ? url : "";
  mEventHandler->functionCall<std::string, rtc::uid_t, int>(
      "onStreamInjectedStatus", mUrl, uid, status);
}

void RtcEngineEventHandler::onTranscodingUpdated() {
  if (cEngineEventHandler && cEngineEventHandler->onTranscodingUpdated)
    cEngineEventHandler->onTranscodingUpdated();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onTranscodingUpdated");
}

void RtcEngineEventHandler::onStreamUnpublished(const char *url) {
  if (cEngineEventHandler && cEngineEventHandler->onStreamUnpublished)
    cEngineEventHandler->onStreamUnpublished(url);

  if (!mEventHandler)
    return;

  std::string mUrl = url ? url : "";
  mEventHandler->functionCall<std::string>("onStreamUnpublished", mUrl);
}

void RtcEngineEventHandler::onStreamPublished(const char *url, int error) {
  if (cEngineEventHandler && cEngineEventHandler->onStreamPublished)
    cEngineEventHandler->onStreamPublished(url, error);

  if (!mEventHandler)
    return;

  std::string mUrl = url ? url : "";
  mEventHandler->functionCall<std::string, int>("onStreamPublished", mUrl,
                                                error);
}

void RtcEngineEventHandler::onAudioDeviceVolumeChanged(
    MEDIA_DEVICE_TYPE deviceType, int volume, bool muted) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioDeviceVolumeChanged)
    cEngineEventHandler->onAudioDeviceVolumeChanged(int(deviceType), volume,
                                                    muted);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int, bool>("onAudioDeviceVolumeChanged",
                                              deviceType, volume, muted);
}

void RtcEngineEventHandler::onActiveSpeaker(rtc::uid_t uid) {
  if (cEngineEventHandler && cEngineEventHandler->onActiveSpeaker)
    cEngineEventHandler->onActiveSpeaker(uid);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t>("onActiveSpeaker", uid);
}

void RtcEngineEventHandler::onMediaEngineStartCallSuccess() {
  if (cEngineEventHandler && cEngineEventHandler->onMediaEngineStartCallSuccess)
    cEngineEventHandler->onMediaEngineStartCallSuccess();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onMediaEngineStartCallSuccess");
}

void RtcEngineEventHandler::onMediaEngineLoadSuccess() {
  if (cEngineEventHandler && cEngineEventHandler->onMediaEngineLoadSuccess)
    cEngineEventHandler->onMediaEngineLoadSuccess();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onMediaEngineLoadSuccess");
}

void RtcEngineEventHandler::onStreamMessageError(rtc::uid_t uid, int streamId,
                                                 int code, int missed,
                                                 int cached) {
  if (cEngineEventHandler && cEngineEventHandler->onStreamMessageError)
    cEngineEventHandler->onStreamMessageError(uid, streamId, code, missed,
                                              cached);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int, int>(
      "onStreamMessageError", uid, streamId, code, missed, cached);
}

void RtcEngineEventHandler::onStreamMessage(rtc::uid_t uid, int streamId,
                                            const char *data, size_t length) {
  if (cEngineEventHandler && cEngineEventHandler->onStreamMessage)
    cEngineEventHandler->onStreamMessage(uid, streamId, data, length);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, const char *, size_t>(
      "onStreamMessage", uid, streamId, data, length);
}

void RtcEngineEventHandler::onConnectionBanned() {
  if (cEngineEventHandler && cEngineEventHandler->onConnectionBanned)
    cEngineEventHandler->onConnectionBanned();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onConnectionBanned");
}

void RtcEngineEventHandler::onVideoStopped() {
  if (cEngineEventHandler && cEngineEventHandler->onVideoStopped)
    cEngineEventHandler->onVideoStopped();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onVideoStopped");
}

void RtcEngineEventHandler::onTokenPrivilegeWillExpire(const char *token) {
  if (cEngineEventHandler && cEngineEventHandler->onTokenPrivilegeWillExpire)
    cEngineEventHandler->onTokenPrivilegeWillExpire(token);

  if (!mEventHandler)
    return;

  std::string mToken = token ? token : "";
  mEventHandler->functionCall<std::string>("onTokenPrivilegeWillExpire",
                                           mToken);
}

void RtcEngineEventHandler::onNetworkQuality(rtc::uid_t uid, int txQuality,
                                             int rxQuality) {
  if (cEngineEventHandler && cEngineEventHandler->onNetworkQuality)
    cEngineEventHandler->onNetworkQuality(uid, txQuality, rxQuality);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int>("onNetworkQuality", uid,
                                                    txQuality, rxQuality);
}

void RtcEngineEventHandler::onLocalVideoStats(const LocalVideoStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onLocalVideoStats)
    cEngineEventHandler->onLocalVideoStats(
        stats.sentBitrate, stats.sentFrameRate, stats.encoderOutputFrameRate,
        stats.rendererOutputFrameRate, stats.targetBitrate,
        stats.targetFrameRate, (int)stats.qualityAdaptIndication,
        stats.encodedBitrate, stats.encodedFrameWidth, stats.encodedFrameHeight,
        stats.encodedFrameCount, (int)stats.codecType);

  if (!mEventHandler)
    return;

  const LocalVideoStats mStats = stats;
  mEventHandler->functionCall("onLocalVideoStats", mStats);
}

void RtcEngineEventHandler::onLocalAudioStats(const LocalAudioStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onLocalAudioStats)
    cEngineEventHandler->onLocalAudioStats(
        stats.numChannels, stats.sentSampleRate, stats.sentBitrate);

  if (!mEventHandler)
    return;

  const LocalAudioStats mStats = stats;
  mEventHandler->functionCall("onLocalAudioStats", mStats);
}

void RtcEngineEventHandler::onRemoteVideoStats(const RemoteVideoStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteVideoStats)
    cEngineEventHandler->onRemoteVideoStats(
        stats.uid, stats.delay, stats.width, stats.height,
        stats.receivedBitrate, stats.decoderOutputFrameRate,
        stats.rendererOutputFrameRate, stats.packetLossRate,
        (int)stats.rxStreamType, stats.totalFrozenTime, stats.frozenRate,
        stats.totalActiveTime);

  if (!mEventHandler)
    return;

  const RemoteVideoStats mStats = stats;
  mEventHandler->functionCall("onRemoteVideoStats", mStats);
}

void RtcEngineEventHandler::onRemoteAudioStats(const RemoteAudioStats &stats) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteAudioStats)
    cEngineEventHandler->onRemoteAudioStats(
        stats.uid, stats.quality, stats.networkTransportDelay,
        stats.jitterBufferDelay, stats.audioLossRate, stats.numChannels,
        stats.receivedSampleRate, stats.receivedBitrate, stats.totalFrozenTime,
        stats.frozenRate, stats.totalActiveTime);

  if (!mEventHandler)
    return;

  const RemoteAudioStats mStats = stats;
  mEventHandler->functionCall("onRemoteAudioStats", mStats);
}

void RtcEngineEventHandler::onFirstLocalVideoFrame(int width, int height,
                                                   int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstLocalVideoFrame)
    cEngineEventHandler->onFirstLocalVideoFrame(width, height, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int, int>("onFirstLocalVideoFrame", width,
                                             height, elapsed);
}

void RtcEngineEventHandler::onFirstRemoteVideoFrame(rtc::uid_t uid, int width,
                                                    int height, int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstRemoteVideoFrame)
    cEngineEventHandler->onFirstRemoteVideoFrame(uid, width, height, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onFirstRemoteVideoFrame", uid, width, height, elapsed);
}

void RtcEngineEventHandler::onUserEnableVideo(rtc::uid_t uid, bool enabled) {
  if (cEngineEventHandler && cEngineEventHandler->onUserEnableVideo)
    cEngineEventHandler->onUserEnableVideo(uid, enabled);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, bool>("onUserEnableVideo", uid,
                                                enabled);
}

void RtcEngineEventHandler::onAudioDeviceStateChanged(const char *deviceId,
                                                      int deviceType,
                                                      int deviceState) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioDeviceStateChanged)
    cEngineEventHandler->onAudioDeviceStateChanged(deviceId, deviceType,
                                                   deviceState);

  if (!mEventHandler)
    return;

  std::string mDeviceId = deviceId ? deviceId : "";
  mEventHandler->functionCall<std::string, int, int>(
      "onAudioDeviceStateChanged", mDeviceId, deviceType, deviceState);
}

void RtcEngineEventHandler::onCameraReady() {
  if (cEngineEventHandler && cEngineEventHandler->onCameraReady)
    cEngineEventHandler->onCameraReady();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onCameraReady");
}

void RtcEngineEventHandler::onCameraFocusAreaChanged(int x, int y, int width,
                                                     int height) {
  if (cEngineEventHandler && cEngineEventHandler->onCameraFocusAreaChanged)
    cEngineEventHandler->onCameraFocusAreaChanged(x, y, width, height);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int, int, int>("onCameraFocusAreaChanged", x,
                                                  y, width, height);
}

void RtcEngineEventHandler::onCameraExposureAreaChanged(int x, int y, int width,
                                                        int height) {
  if (cEngineEventHandler && cEngineEventHandler->onCameraExposureAreaChanged)
    cEngineEventHandler->onCameraExposureAreaChanged(x, y, width, height);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int, int, int>("onCameraExposureAreaChanged",
                                                  x, y, width, height);
}

void RtcEngineEventHandler::onRemoteAudioMixingBegin() {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteAudioMixingBegin)
    cEngineEventHandler->onRemoteAudioMixingBegin();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onRemoteAudioMixingBegin");
}

void RtcEngineEventHandler::onRemoteAudioMixingEnd() {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteAudioMixingEnd)
    cEngineEventHandler->onRemoteAudioMixingEnd();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onRemoteAudioMixingEnd");
}

void RtcEngineEventHandler::onAudioEffectFinished(int soundId) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioEffectFinished)
    cEngineEventHandler->onAudioEffectFinished(soundId);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onAudioEffectFinished", soundId);
}

void RtcEngineEventHandler::onVideoDeviceStateChanged(const char *deviceId,
                                                      int deviceType,
                                                      int deviceState) {
  if (cEngineEventHandler && cEngineEventHandler->onVideoDeviceStateChanged)
    cEngineEventHandler->onVideoDeviceStateChanged(deviceId, deviceType,
                                                   deviceState);

  if (!mEventHandler)
    return;

  std::string mDevieId = deviceId ? deviceId : "";
  mEventHandler->functionCall<std::string, int, int>(
      "onVideoDeviceStateChanged", mDevieId, deviceType, deviceState);
}

void RtcEngineEventHandler::onRemoteVideoStateChanged(
    rtc::uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason,
    int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteVideoStateChanged)
    cEngineEventHandler->onRemoteVideoStateChanged(uid, int(state), int(reason),
                                                   elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onRemoteVideoStateChanged", uid, state, reason, elapsed);
}

void RtcEngineEventHandler::onUserEnableLocalVideo(rtc::uid_t uid,
                                                   bool enabled) {
  if (cEngineEventHandler && cEngineEventHandler->onUserEnableLocalVideo)
    cEngineEventHandler->onUserEnableLocalVideo(uid, enabled);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, bool>("onUserEnableLocalVideo", uid,
                                                enabled);
}

void RtcEngineEventHandler::onLocalPublishFallbackToAudioOnly(
    bool isFallbackOrRecover) {
  if (cEngineEventHandler &&
      cEngineEventHandler->onLocalPublishFallbackToAudioOnly)
    cEngineEventHandler->onLocalPublishFallbackToAudioOnly(isFallbackOrRecover);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<bool>("onLocalPublishFallbackToAudioOnly",
                                    isFallbackOrRecover);
}

void RtcEngineEventHandler::onRemoteSubscribeFallbackToAudioOnly(
    rtc::uid_t uid, bool isFallbackOrRecover) {
  if (cEngineEventHandler &&
      cEngineEventHandler->onRemoteSubscribeFallbackToAudioOnly)
    cEngineEventHandler->onRemoteSubscribeFallbackToAudioOnly(
        uid, isFallbackOrRecover);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, bool>(
      "onRemoteSubscribeFallbackToAudioOnly", uid, isFallbackOrRecover);
}

void RtcEngineEventHandler::onConnectionStateChanged(
    CONNECTION_STATE_TYPE state, CONNECTION_CHANGED_REASON_TYPE reason) {
  if (cEngineEventHandler && cEngineEventHandler->onConnectionStateChanged)
    cEngineEventHandler->onConnectionStateChanged(int(state), int(reason));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onConnectionStateChanged", state,
                                        reason);
}

void RtcEngineEventHandler::onAudioMixingStateChanged(
    AUDIO_MIXING_STATE_TYPE state, AUDIO_MIXING_ERROR_TYPE errorCode) {
  if (cEngineEventHandler && cEngineEventHandler->onAudioMixingStateChanged)
    cEngineEventHandler->onAudioMixingStateChanged(int(state), int(errorCode));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onAudioMixingStateChanged", state,
                                        errorCode);
}

void RtcEngineEventHandler::onFirstRemoteAudioDecoded(rtc::uid_t uid,
                                                      int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onFirstRemoteAudioDecoded)
    cEngineEventHandler->onFirstRemoteAudioDecoded(uid, elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int>("onFirstRemoteAudioDecoded", uid,
                                               elapsed);
}

void RtcEngineEventHandler::onLocalVideoStateChanged(
    LOCAL_VIDEO_STREAM_STATE localVideoState, LOCAL_VIDEO_STREAM_ERROR error) {
  if (cEngineEventHandler && cEngineEventHandler->onLocalVideoStateChanged)
    cEngineEventHandler->onLocalVideoStateChanged(int(localVideoState),
                                                  int(error));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onLocalVideoStateChanged",
                                        localVideoState, error);
}

void RtcEngineEventHandler::onRtmpStreamingStateChanged(
    const char *url, RTMP_STREAM_PUBLISH_STATE state,
    RTMP_STREAM_PUBLISH_ERROR errCode) {
  if (cEngineEventHandler && cEngineEventHandler->onRtmpStreamingStateChanged)
    cEngineEventHandler->onRtmpStreamingStateChanged(url, int(state),
                                                     int(errCode));

  if (!mEventHandler)
    return;

  std::string mUrl = url ? url : "";
  mEventHandler->functionCall<std::string, int, int>(
      "onRtmpStreamingStateChanged", mUrl, state, errCode);
}

void RtcEngineEventHandler::onNetworkTypeChanged(NETWORK_TYPE type) {
  if (cEngineEventHandler && cEngineEventHandler->onNetworkTypeChanged)
    cEngineEventHandler->onNetworkTypeChanged(int(type));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onNetworkTypeChanged", type);
}

void RtcEngineEventHandler::onLocalUserRegistered(rtc::uid_t uid,
                                                  const char *userAccount) {
  if (cEngineEventHandler && cEngineEventHandler->onLocalUserRegistered)
    cEngineEventHandler->onLocalUserRegistered(uid, userAccount);

  if (!mEventHandler)
    return;

  std::string mUserAccount = userAccount ? userAccount : "";
  mEventHandler->functionCall<rtc::uid_t, std::string>("onLocalUserRegistered",
                                                       uid, mUserAccount);
}

void RtcEngineEventHandler::onUserInfoUpdated(rtc::uid_t uid,
                                              const UserInfo &info) {
  if (cEngineEventHandler && cEngineEventHandler->onUserInfoUpdated)
    cEngineEventHandler->onUserInfoUpdated(uid, info.uid,
                                           (char *)info.userAccount);

  if (!mEventHandler)
    return;

  const UserInfo mInfo = info;
  mEventHandler->functionCall("onUserInfoUpdated", uid, mInfo);
}

void RtcEngineEventHandler::onLocalAudioStateChanged(
    LOCAL_AUDIO_STREAM_STATE state, LOCAL_AUDIO_STREAM_ERROR error) {
  if (cEngineEventHandler && cEngineEventHandler->onLocalAudioStateChanged)
    cEngineEventHandler->onLocalAudioStateChanged(int(state), int(error));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onLocalAudioStateChanged", state,
                                        error);
}

void RtcEngineEventHandler::onRemoteAudioStateChanged(
    rtc::uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason,
    int elapsed) {
  if (cEngineEventHandler && cEngineEventHandler->onRemoteAudioStateChanged)
    cEngineEventHandler->onRemoteAudioStateChanged(uid, int(state), int(reason),
                                                   elapsed);

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<rtc::uid_t, int, int, int>(
      "onRemoteAudioStateChanged", uid, state, reason, elapsed);
}

void RtcEngineEventHandler::onChannelMediaRelayStateChanged(
    CHANNEL_MEDIA_RELAY_STATE state, CHANNEL_MEDIA_RELAY_ERROR code) {
  if (cEngineEventHandler &&
      cEngineEventHandler->onChannelMediaRelayStateChanged)
    cEngineEventHandler->onChannelMediaRelayStateChanged(int(state), int(code));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int, int>("onChannelMediaRelayStateChanged",
                                        state, code);
}

void RtcEngineEventHandler::onChannelMediaRelayEvent(
    CHANNEL_MEDIA_RELAY_EVENT code) {
  if (cEngineEventHandler && cEngineEventHandler->onChannelMediaRelayEvent)
    cEngineEventHandler->onChannelMediaRelayEvent(int(code));

  if (!mEventHandler)
    return;

  mEventHandler->functionCall<int>("onChannelMediaRelayEvent", code);
}

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)

void RtcEngineEventHandler::onFacePositionChanged(int imageWidth,
                                                  int imageHeight,
                                                  Rectangle *vecRectangle,
                                                  int *vecDistance,
                                                  int numFaces) {
  if (cEngineEventHandler && cEngineEventHandler->onFacePositionChanged &&
      vecRectangle && vecDistance)
    cEngineEventHandler->onFacePositionChanged(
        imageWidth, imageHeight, vecRectangle->x, vecRectangle->y,
        vecRectangle->width, vecRectangle->height, *vecDistance, numFaces);

  if (!mEventHandler)
    return;

  if (vecRectangle == nullptr || vecDistance == nullptr)
    return;

  mEventHandler->functionCall("onFacePositionChanged", imageWidth, imageHeight,
                              vecRectangle, vecDistance, numFaces);
}

#endif

void RtcEngineEventHandler::onTestEnd() {
  if (cEngineEventHandler && cEngineEventHandler->onTestEnd)
    cEngineEventHandler->onTestEnd();

  if (!mEventHandler)
    return;

  mEventHandler->functionCall("onTestEnd");
}
} // namespace common
} // namespace agora
