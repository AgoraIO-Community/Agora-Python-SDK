#include "EventTester.h"
#include "../common/rapidjson/istreamwrapper.h"
#include "../common/rapidjson/ostreamwrapper.h"
#include "../common/rapidjson/stringbuffer.h"
#include "../common/rapidjson/writer.h"
#include "LogJson.h"
#include <fstream>
#include <string.h>

using namespace std;
using namespace rapidjson;
using namespace agora::rtc;
namespace agora {
namespace common {

void json_to_object(Value &v, RtcStats &stats) {
  stats.duration = v["duration"].GetUint();
  stats.txBytes = v["txBytes"].GetUint();
  stats.rxBytes = v["rxBytes"].GetUint();
  stats.txAudioBytes = v["txAudioBytes"].GetUint();
  stats.txVideoBytes = v["txVideoBytes"].GetUint();
  stats.rxAudioBytes = v["rxAudioBytes"].GetUint();
  stats.rxVideoBytes = v["rxVideoBytes"].GetUint();
  stats.txKBitRate = (unsigned short)v["txKBitRate"].GetInt();
  stats.rxKBitRate = (unsigned short)v["rxKBitRate"].GetInt();
  stats.rxAudioKBitRate = (unsigned short)v["rxAudioKBitRate"].GetInt();
  stats.txAudioKBitRate = (unsigned short)v["txAudioKBitRate"].GetInt();
  stats.rxVideoKBitRate = (unsigned short)v["rxVideoKBitRate"].GetInt();
  stats.txVideoKBitRate = (unsigned short)v["txVideoKBitRate"].GetInt();
  stats.lastmileDelay = (unsigned short)v["lastmileDelay"].GetInt();
  stats.txPacketLossRate = (unsigned short)v["txPacketLossRate"].GetInt();
  stats.rxPacketLossRate = (unsigned short)v["rxPacketLossRate"].GetInt();
  stats.userCount = v["userCount"].GetUint();
  stats.cpuAppUsage = v["cpuAppUsage"].GetDouble();
  stats.cpuTotalUsage = v["cpuTotalUsage"].GetDouble();
  stats.gatewayRtt = v["gatewayRtt"].GetInt();
  stats.memoryAppUsageRatio = v["memoryAppUsageRatio"].GetDouble();
  stats.memoryTotalUsageRatio = v["memoryTotalUsageRatio"].GetDouble();
  stats.memoryAppUsageInKbytes = v["memoryAppUsageInKbytes"].GetDouble();
}

void json_to_object(Value &v, AudioVolumeInfo &volumeInfo) {
  volumeInfo.uid = v["uid"].GetUint();
  volumeInfo.volume = v["volume"].GetUint();
  volumeInfo.vad = v["vad"].GetUint();
  volumeInfo.channelId = v["channelId"].GetString();
}

void json_to_object(Value &v, LastmileProbeOneWayResult &result) {
  result.packetLossRate = v["packetLossRate"].GetUint();
  result.jitter = v["jitter"].GetUint();
  result.availableBandwidth = v["availableBandwidth"].GetUint();
}

void json_to_object(Value &v, LastmileProbeResult &result) {
  result.state = (LASTMILE_PROBE_RESULT_STATE)v["state"].GetInt();
  json_to_object(v["uplinkReport"], result.uplinkReport);
  json_to_object(v["downlinkReport"], result.downlinkReport);
  result.rtt = v["rtt"].GetUint();
}

void json_to_object(Value &v, LocalVideoStats &stats) {
  stats.sentBitrate = v["sentBitrate"].GetInt();
  stats.sentFrameRate = v["sentFrameRate"].GetInt();
  stats.encoderOutputFrameRate = v["encoderOutputFrameRate"].GetInt();
  stats.rendererOutputFrameRate = v["rendererOutputFrameRate"].GetInt();
  stats.targetBitrate = v["targetBitrate"].GetInt();
  stats.targetFrameRate = v["targetFrameRate"].GetInt();
  stats.qualityAdaptIndication =
      (QUALITY_ADAPT_INDICATION)v["qualityAdaptIndication"].GetInt();
  stats.encodedBitrate = v["encodedBitrate"].GetInt();
  stats.encodedFrameWidth = v["encodedFrameWidth"].GetInt();
  stats.encodedFrameHeight = v["encodedFrameHeight"].GetInt();
  stats.encodedFrameCount = v["encodedFrameCount"].GetInt();
  stats.codecType = (VIDEO_CODEC_TYPE)v["codecType"].GetInt();
  stats.txPacketLossRate = (unsigned short)v["txPacketLossRate"].GetUint();
  stats.captureFrameRate = v["captureFrameRate"].GetInt();
}

void json_to_object(Value &v, RemoteVideoStats &stats) {
  stats.uid = v["uid"].GetUint();
  stats.delay = v["delay"].GetInt();
  stats.width = v["width"].GetInt();
  stats.height = v["height"].GetInt();
  stats.receivedBitrate = v["receivedBitrate"].GetInt();
  stats.decoderOutputFrameRate = v["decoderOutputFrameRate"].GetInt();
  stats.rendererOutputFrameRate = v["rendererOutputFrameRate"].GetInt();
  stats.packetLossRate = v["packetLossRate"].GetInt();
  stats.rxStreamType = (REMOTE_VIDEO_STREAM_TYPE)v["rxStreamType"].GetInt();
  stats.totalFrozenTime = v["totalFrozenTime"].GetInt();
  stats.frozenRate = v["frozenRate"].GetInt();
  stats.totalActiveTime = v["totalActiveTime"].GetInt();
  stats.publishDuration = v["publishDuration"].GetInt();
}

void json_to_object(Value &v, LocalAudioStats &stats) {
  stats.numChannels = v["numChannels"].GetInt();
  stats.sentSampleRate = v["sentSampleRate"].GetInt();
  stats.sentBitrate = v["sentBitrate"].GetInt();
  stats.txPacketLossRate = (unsigned short)v["txPacketLossRate"].GetUint();
}

void json_to_object(Value &v, RemoteAudioStats &stats) {
  stats.uid = v["uid"].GetUint();
  stats.quality = v["quality"].GetInt();
  stats.networkTransportDelay = v["networkTransportDelay"].GetInt();
  stats.jitterBufferDelay = v["jitterBufferDelay"].GetInt();
  stats.audioLossRate = v["audioLossRate"].GetInt();
  stats.numChannels = v["numChannels"].GetInt();
  stats.receivedSampleRate = v["receivedSampleRate"].GetInt();
  stats.receivedBitrate = v["receivedBitrate"].GetInt();
  stats.totalFrozenTime = v["totalFrozenTime"].GetInt();
  stats.frozenRate = v["frozenRate"].GetInt();
  stats.totalActiveTime = v["totalActiveTime"].GetInt();
  stats.publishDuration = v["publishDuration"].GetInt();
}

void json_to_object(Value &v, agora::rtc::Rectangle &rect) {
  rect.x = v["x"].GetInt();
  rect.y = v["y"].GetInt();
  rect.width = v["width"].GetInt();
  rect.height = v["height"].GetInt();
}

void json_to_object(Value &v, UserInfo &info) {
  info.uid = v["uid"].GetUint();
  auto userAccount = v["userAccount"].GetString();
  strncpy(info.userAccount, userAccount, MAX_USER_ACCOUNT_LENGTH);
}

LogJson &GetEngineEventJsonLogger() {
  static LogJson engineLogJson;
  return engineLogJson;
}

void BeginRtcEngineEventTest(const char *caseFilePath,
                             RtcEngineEventHandlerBase *eventHandler) {
  ifstream ifs(caseFilePath);
  rapidjson::IStreamWrapper isw(ifs);

  GetEngineEventJsonLogger().clearJsonData();

  Document caseDoc;
  caseDoc.ParseStream(isw);

  for (auto &v : caseDoc.GetArray()) {
    std::string type = v["event_type"].GetString();
    Value &param = v["param"];
    if (type == "onJoinChannelSuccess") {
      eventHandler->onJoinChannelSuccess(param["channel"].GetString(),
                                         param["uid"].GetUint(),
                                         param["elapsed"].GetInt());
    } else if (type == "onLeaveChannel") {
      RtcStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onLeaveChannel(stats);
    } else if (type == "onRejoinChannelSuccess") {
      eventHandler->onRejoinChannelSuccess(param["channel"].GetString(),
                                           param["uid"].GetUint(),
                                           param["elapsed"].GetInt());
    } else if (type == "onUserJoined") {
      eventHandler->onUserJoined(param["uid"].GetUint(),
                                 param["elapsed"].GetInt());
    } else if (type == "onClientRoleChanged") {
      eventHandler->onClientRoleChanged(
          CLIENT_ROLE_TYPE(param["oldRole"].GetInt()),
          CLIENT_ROLE_TYPE(param["newRole"].GetInt()));
    } else if (type == "onUserOffline") {
      eventHandler->onUserOffline(
          param["uid"].GetUint(),
          USER_OFFLINE_REASON_TYPE(param["reason"].GetInt()));
    } else if (type == "onUserMuteAudio") {
      eventHandler->onUserMuteAudio(param["uid"].GetUint(),
                                    param["muted"].GetBool());
    } else if (type == "onFirstRemoteVideoDecoded") {
      eventHandler->onFirstRemoteVideoDecoded(
          param["uid"].GetUint(), param["width"].GetInt(),
          param["height"].GetInt(), param["elapsed"].GetInt());
    } else if (type == "onUserMuteVideo") {
      eventHandler->onUserMuteVideo(param["uid"].GetUint(),
                                    param["muted"].GetBool());
    } else if (type == "onAudioRouteChanged") {
      eventHandler->onAudioRouteChanged(
          AUDIO_ROUTE_TYPE(param["routing"].GetInt()));
    } else if (type == "onConnectionLost") {
      eventHandler->onConnectionLost();
    } else if (type == "onRequestToken") {
      eventHandler->onRequestToken();
    } else if (type == "onAudioVolumeIndication") {
      int speakerNumber = (int)param["speakers"].GetArray().Size();
      AudioVolumeInfo *speakers = nullptr;
      if (speakerNumber > 0) {
        speakers = new AudioVolumeInfo[speakerNumber];
        for (int i = 0; i < speakerNumber; i++) {
          AudioVolumeInfo info;
          json_to_object(param["speakers"][i], info);
          speakers[i] = info;
        }
      }
      eventHandler->onAudioVolumeIndication(speakers,
                                            param["speakerNumber"].GetUint(),
                                            param["totalVolume"].GetInt());
      delete[] speakers;
    } else if (type == "onWarning") {
      eventHandler->onWarning(param["warn"].GetInt(), param["msg"].GetString());
    } else if (type == "onError") {
      eventHandler->onError(param["err"].GetInt(), param["msg"].GetString());
    } else if (type == "onRtcStats") {
      RtcStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRtcStats(stats);
    } else if (type == "onAudioMixingFinished") {
      eventHandler->onAudioMixingFinished();
    } else if (type == "onVideoSizeChanged") {
      eventHandler->onVideoSizeChanged(
          param["uid"].GetUint(), param["width"].GetInt(),
          param["height"].GetInt(), param["rotation"].GetInt());
    } else if (type == "onConnectionInterrupted") {
      eventHandler->onConnectionInterrupted();
    } else if (type == "onMicrophoneEnabled") {
      eventHandler->onMicrophoneEnabled(param["enabled"].GetBool());
    } else if (type == "onFirstRemoteAudioFrame") {
      eventHandler->onFirstRemoteAudioFrame(param["uid"].GetUint(),
                                            param["elapsed"].GetInt());
    } else if (type == "onFirstLocalAudioFrame") {
      eventHandler->onFirstLocalAudioFrame(param["elapsed"].GetInt());
    } else if (type == "onApiCallExecuted") {
      eventHandler->onApiCallExecuted(param["err"].GetInt(),
                                      param["api"].GetString(),
                                      param["result"].GetString());
    } else if (type == "onLastmileQuality") {
      eventHandler->onLastmileQuality(param["quality"].GetInt());
    } else if (type == "onLastmileProbeResult") {
      LastmileProbeResult result;
      json_to_object(param["result"], result);
      eventHandler->onLastmileProbeResult(result);
    } else if (type == "onAudioQuality") {
      eventHandler->onAudioQuality(param["uid"].GetUint(),
                                   param["quality"].GetInt(),
                                   (unsigned short)param["delay"].GetUint(),
                                   (unsigned short)param["lost"].GetUint());
    } else if (type == "onRemoteVideoTransportStats") {
      eventHandler->onRemoteVideoTransportStats(
          param["uid"].GetUint(), (unsigned short)param["delay"].GetUint(),
          (unsigned short)param["lost"].GetUint(),
          (unsigned short)param["rxKBitRate"].GetUint());
    } else if (type == "onRemoteAudioTransportStats") {
      eventHandler->onRemoteAudioTransportStats(
          param["uid"].GetUint(), (unsigned short)param["delay"].GetUint(),
          (unsigned short)param["lost"].GetUint(),
          (unsigned short)param["rxKBitRate"].GetUint());
    } else if (type == "onStreamInjectedStatus") {
      eventHandler->onStreamInjectedStatus(param["url"].GetString(),
                                           param["uid"].GetUint(),
                                           param["status"].GetInt());
    } else if (type == "onTranscodingUpdated") {
      eventHandler->onTranscodingUpdated();
    } else if (type == "onStreamUnpublished") {
      eventHandler->onStreamUnpublished(param["url"].GetString());
    } else if (type == "onStreamPublished") {
      eventHandler->onStreamPublished(param["url"].GetString(),
                                      param["error"].GetInt());
    } else if (type == "onAudioDeviceVolumeChanged") {
      eventHandler->onAudioDeviceVolumeChanged(
          (MEDIA_DEVICE_TYPE)param["deviceType"].GetInt(),
          param["volume"].GetInt(), param["muted"].GetBool());
    } else if (type == "onActiveSpeaker") {
      eventHandler->onActiveSpeaker(param["uid"].GetUint());
    } else if (type == "onMediaEngineStartCallSuccess") {
      eventHandler->onMediaEngineStartCallSuccess();
    } else if (type == "onMediaEngineLoadSuccess") {
      eventHandler->onMediaEngineLoadSuccess();
    } else if (type == "onStreamMessageError") {
      eventHandler->onStreamMessageError(
          param["uid"].GetUint(), param["streamId"].GetInt(),
          param["code"].GetInt(), param["missed"].GetInt(),
          param["cached"].GetInt());
    } else if (type == "onStreamMessage") {
      eventHandler->onStreamMessage(
          param["uid"].GetUint(), param["streamId"].GetInt(),
          param["data"].GetString(), (size_t)param["length"].GetUint64());
    } else if (type == "onConnectionBanned") {
      eventHandler->onConnectionBanned();
    } else if (type == "onVideoStopped") {
      eventHandler->onVideoStopped();
    } else if (type == "onTokenPrivilegeWillExpire") {
      eventHandler->onTokenPrivilegeWillExpire(param["token"].GetString());
    } else if (type == "onNetworkQuality") {
      eventHandler->onNetworkQuality(param["uid"].GetUint(),
                                     param["txQuality"].GetInt(),
                                     param["rxQuality"].GetInt());
    } else if (type == "onLocalVideoStats") {
      LocalVideoStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onLocalVideoStats(stats);
    } else if (type == "onLocalAudioStats") {
      LocalAudioStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onLocalAudioStats(stats);
    } else if (type == "onRemoteVideoStats") {
      RemoteVideoStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRemoteVideoStats(stats);
    } else if (type == "onRemoteAudioStats") {
      RemoteAudioStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRemoteAudioStats(stats);
    } else if (type == "onFirstLocalVideoFrame") {
      eventHandler->onFirstLocalVideoFrame(param["width"].GetInt(),
                                           param["height"].GetInt(),
                                           param["elapsed"].GetInt());
    } else if (type == "onFirstRemoteVideoFrame") {
      eventHandler->onFirstRemoteVideoFrame(
          param["uid"].GetUint(), param["width"].GetInt(),
          param["height"].GetInt(), param["elapsed"].GetInt());
    } else if (type == "onUserEnableVideo") {
      eventHandler->onUserEnableVideo(param["uid"].GetUint(),
                                      param["enabled"].GetBool());
    } else if (type == "onAudioDeviceStateChanged") {
      eventHandler->onAudioDeviceStateChanged(param["deviceId"].GetString(),
                                              param["deviceType"].GetInt(),
                                              param["deviceState"].GetInt());
    } else if (type == "onCameraReady") {
      eventHandler->onCameraReady();
    } else if (type == "onCameraFocusAreaChanged") {
      eventHandler->onCameraFocusAreaChanged(
          param["x"].GetInt(), param["y"].GetInt(), param["width"].GetInt(),
          param["height"].GetInt());
    } else if (type == "onCameraExposureAreaChanged") {
      eventHandler->onCameraExposureAreaChanged(
          param["x"].GetInt(), param["y"].GetInt(), param["width"].GetInt(),
          param["height"].GetInt());
    } else if (type == "onRemoteAudioMixingBegin") {
      eventHandler->onRemoteAudioMixingBegin();
    } else if (type == "onRemoteAudioMixingEnd") {
      eventHandler->onRemoteAudioMixingEnd();
    } else if (type == "onAudioEffectFinished") {
      eventHandler->onAudioEffectFinished(param["soundId"].GetInt());
    } else if (type == "onVideoDeviceStateChanged") {
      eventHandler->onVideoDeviceStateChanged(param["deviceId"].GetString(),
                                              param["deviceType"].GetInt(),
                                              param["deviceState"].GetInt());
    } else if (type == "onRemoteVideoStateChanged") {
      eventHandler->onRemoteVideoStateChanged(
          param["uid"].GetUint(), (REMOTE_VIDEO_STATE)param["state"].GetInt(),
          (REMOTE_VIDEO_STATE_REASON)param["reason"].GetInt(),
          param["elapsed"].GetInt());
    } else if (type == "onUserEnableLocalVideo") {
      eventHandler->onUserEnableLocalVideo(param["uid"].GetUint(),
                                           param["enabled"].GetBool());
    } else if (type == "onLocalPublishFallbackToAudioOnly") {
      eventHandler->onLocalPublishFallbackToAudioOnly(
          param["isFallbackOrRecover"].GetBool());
    } else if (type == "onRemoteSubscribeFallbackToAudioOnly") {
      eventHandler->onRemoteSubscribeFallbackToAudioOnly(
          param["uid"].GetUint(), param["isFallbackOrRecover"].GetBool());
    } else if (type == "onConnectionStateChanged") {
      eventHandler->onConnectionStateChanged(
          (CONNECTION_STATE_TYPE)param["state"].GetInt(),
          (CONNECTION_CHANGED_REASON_TYPE)param["reason"].GetInt());
    } else if (type == "onAudioMixingStateChanged") {
      eventHandler->onAudioMixingStateChanged(
          (AUDIO_MIXING_STATE_TYPE)param["state"].GetInt(),
          (AUDIO_MIXING_ERROR_TYPE)param["errorCode"].GetInt());
    } else if (type == "onFirstRemoteAudioDecoded") {
      eventHandler->onFirstRemoteAudioDecoded(param["uid"].GetUint(),
                                              param["elapsed"].GetInt());
    } else if (type == "onLocalVideoStateChanged") {
      eventHandler->onLocalVideoStateChanged(
          (LOCAL_VIDEO_STREAM_STATE)param["localVideoState"].GetInt(),
          (LOCAL_VIDEO_STREAM_ERROR)param["error"].GetInt());
    } else if (type == "onRtmpStreamingStateChanged") {
      eventHandler->onRtmpStreamingStateChanged(
          param["url"].GetString(),
          (RTMP_STREAM_PUBLISH_STATE)param["state"].GetInt(),
          (RTMP_STREAM_PUBLISH_ERROR)param["errCode"].GetInt());
    } else if (type == "onNetworkTypeChanged") {
      eventHandler->onNetworkTypeChanged((NETWORK_TYPE)param["type"].GetInt());
    } else if (type == "onLocalUserRegistered") {
      eventHandler->onLocalUserRegistered(param["uid"].GetUint(),
                                          param["userAccount"].GetString());
    } else if (type == "onUserInfoUpdated") {
      UserInfo info;
      json_to_object(param["info"], info);
      eventHandler->onUserInfoUpdated(param["uid"].GetUint(), info);
    } else if (type == "onLocalAudioStateChanged") {
      eventHandler->onLocalAudioStateChanged(
          (LOCAL_AUDIO_STREAM_STATE)param["state"].GetInt(),
          (LOCAL_AUDIO_STREAM_ERROR)param["error"].GetInt());
    } else if (type == "onRemoteAudioStateChanged") {
      eventHandler->onRemoteAudioStateChanged(
          param["uid"].GetUint(), (REMOTE_AUDIO_STATE)param["state"].GetInt(),
          (REMOTE_AUDIO_STATE_REASON)param["reason"].GetInt(),
          param["elapsed"].GetInt());
    } else if (type == "onChannelMediaRelayStateChanged") {
      eventHandler->onChannelMediaRelayStateChanged(
          (CHANNEL_MEDIA_RELAY_STATE)param["state"].GetInt(),
          (CHANNEL_MEDIA_RELAY_ERROR)param["code"].GetInt());
    } else if (type == "onChannelMediaRelayEvent") {
      eventHandler->onChannelMediaRelayEvent(
          (CHANNEL_MEDIA_RELAY_EVENT)param["code"].GetInt());
    }
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    else if (type == "onFacePositionChanged") {
      Rectangle *vecRenctangle = nullptr;
      int *vecDistance = nullptr;
      int faceCount = (int)param["vecRectangle"].GetArray().Size();
      if (faceCount > 0) {
        vecRenctangle = new Rectangle[faceCount];
        vecDistance = new int[faceCount];
        for (int i = 0; i < faceCount; i++) {
          json_to_object(param["vecRectangle"][i], vecRenctangle[i]);
          vecDistance[i] = param["vecDistance"][i].GetInt();
        }
      }
      eventHandler->onFacePositionChanged(
          param["imageWidth"].GetInt(), param["imageHeight"].GetInt(),
          vecRenctangle, vecDistance, param["numFaces"].GetInt());
      delete[] vecRenctangle;
      delete[] vecDistance;
    }
#endif
  }
  eventHandler->onTestEnd();
}

void CompareAndDumpRtcEngineEventTestResult(
    const char *caseFilePath, const char *dumpFilePath,
    RtcEngineEventHandlerBase *eventHandler) {
  GetEngineEventJsonLogger().compareAndDumpResult(caseFilePath, dumpFilePath);
}

void LogEngineEventCase(const char *eventType, const char *parameter) {
  GetEngineEventJsonLogger().logJson(eventType, parameter);
}

LogJson &GetChannelEventJsonLogger() {
  static LogJson channelLogJson;
  return channelLogJson;
}

void BeginChannelEventTest(const char *caseFilePath,
                           agora::rtc::IChannel *rtcChannel,
                           RtcChannelEventHandlerBase *eventHandler) {
  ifstream ifs(caseFilePath);
  rapidjson::IStreamWrapper isw(ifs);

  GetChannelEventJsonLogger().clearJsonData();

  Document caseDoc;
  caseDoc.ParseStream(isw);

  for (auto &v : caseDoc.GetArray()) {
    std::string type = v["event_type"].GetString();
    Value &param = v["param"];
    if (type == "onChannelWarning") {
      eventHandler->onChannelWarning(rtcChannel, param["warn"].GetInt(),
                                     param["msg"].GetString());
    } else if (type == "onChannelError") {
      eventHandler->onChannelError(rtcChannel, param["err"].GetInt(),
                                   param["msg"].GetString());
    } else if (type == "onJoinChannelSuccess") {
      eventHandler->onJoinChannelSuccess(rtcChannel, param["uid"].GetUint(),
                                         param["elapsed"].GetInt());
    } else if (type == "onRejoinChannelSuccess") {
      eventHandler->onRejoinChannelSuccess(rtcChannel, param["uid"].GetUint(),
                                           param["elapsed"].GetInt());
    } else if (type == "onLeaveChannel") {
      RtcStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onLeaveChannel(rtcChannel, stats);
    } else if (type == "onClientRoleChanged") {
      eventHandler->onClientRoleChanged(
          rtcChannel, (CLIENT_ROLE_TYPE)param["oldRole"].GetInt(),
          (CLIENT_ROLE_TYPE)param["newRole"].GetInt());
    } else if (type == "onUserJoined") {
      eventHandler->onUserJoined(rtcChannel, param["uid"].GetUint(),
                                 param["elapsed"].GetInt());
    } else if (type == "onUserOffline") {
      eventHandler->onUserOffline(
          rtcChannel, param["uid"].GetUint(),
          (USER_OFFLINE_REASON_TYPE)param["reason"].GetInt());
    } else if (type == "onConnectionLost") {
      eventHandler->onConnectionLost(rtcChannel);
    } else if (type == "onRequestToken") {
      eventHandler->onRequestToken(rtcChannel);
    } else if (type == "onTokenPrivilegeWillExpire") {
      eventHandler->onTokenPrivilegeWillExpire(rtcChannel,
                                               param["token"].GetString());
    } else if (type == "onRtcStats") {
      RtcStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRtcStats(rtcChannel, stats);
    } else if (type == "onNetworkQuality") {
      eventHandler->onNetworkQuality(rtcChannel, param["uid"].GetUint(),
                                     param["txQuality"].GetInt(),
                                     param["rxQuality"].GetInt());
    } else if (type == "onRemoteVideoStats") {
      RemoteVideoStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRemoteVideoStats(rtcChannel, stats);
    } else if (type == "onRemoteAudioStats") {
      RemoteAudioStats stats;
      json_to_object(param["stats"], stats);
      eventHandler->onRemoteAudioStats(rtcChannel, stats);
    } else if (type == "onRemoteAudioStateChanged") {
      eventHandler->onRemoteAudioStateChanged(
          rtcChannel, param["uid"].GetUint(),
          (REMOTE_AUDIO_STATE)param["state"].GetInt(),
          (REMOTE_AUDIO_STATE_REASON)param["reason"].GetInt(),
          param["elapsed"].GetInt());
    } else if (type == "onActiveSpeaker") {
      eventHandler->onActiveSpeaker(rtcChannel, param["uid"].GetUint());
    } else if (type == "onVideoSizeChanged") {
      eventHandler->onVideoSizeChanged(
          rtcChannel, param["uid"].GetUint(), param["width"].GetInt(),
          param["height"].GetInt(), param["rotation"].GetInt());
    } else if (type == "onRemoteVideoStateChanged") {
      eventHandler->onRemoteVideoStateChanged(
          rtcChannel, param["uid"].GetUint(),
          (REMOTE_VIDEO_STATE)param["state"].GetInt(),
          (REMOTE_VIDEO_STATE_REASON)param["reason"].GetInt(),
          param["elapsed"].GetInt());
    } else if (type == "onStreamMessage") {
      eventHandler->onStreamMessage(
          rtcChannel, param["uid"].GetUint(), param["streamId"].GetInt(),
          param["data"].GetString(), param["length"].GetInt());
    } else if (type == "onStreamMessageError") {
      eventHandler->onStreamMessageError(
          rtcChannel, param["uid"].GetUint(), param["streamId"].GetInt(),
          param["code"].GetInt(), param["missed"].GetInt(),
          param["cached"].GetInt());
    } else if (type == "onChannelMediaRelayStateChanged") {
      eventHandler->onChannelMediaRelayStateChanged(
          rtcChannel, (CHANNEL_MEDIA_RELAY_STATE)param["state"].GetInt(),
          (CHANNEL_MEDIA_RELAY_ERROR)param["code"].GetInt());
    } else if (type == "onChannelMediaRelayEvent") {
      eventHandler->onChannelMediaRelayEvent(
          rtcChannel, (CHANNEL_MEDIA_RELAY_EVENT)param["code"].GetInt());
    } else if (type == "onRtmpStreamingStateChanged") {
      eventHandler->onRtmpStreamingStateChanged(
          rtcChannel, param["url"].GetString(),
          (RTMP_STREAM_PUBLISH_STATE)param["state"].GetInt(),
          (RTMP_STREAM_PUBLISH_ERROR)param["errCode"].GetInt());
    } else if (type == "onTranscodingUpdated") {
      eventHandler->onTranscodingUpdated(rtcChannel);
    } else if (type == "onStreamInjectedStatus") {
      eventHandler->onStreamInjectedStatus(rtcChannel, param["url"].GetString(),
                                           param["uid"].GetUint(),
                                           param["status"].GetInt());
    } else if (type == "onLocalPublishFallbackToAudioOnly") {
      eventHandler->onLocalPublishFallbackToAudioOnly(
          rtcChannel, param["isFallbackOrRecover"].GetBool());
    } else if (type == "onRemoteSubscribeFallbackToAudioOnly") {
      eventHandler->onRemoteSubscribeFallbackToAudioOnly(
          rtcChannel, param["uid"].GetUint(),
          param["isFallbackOrRecover"].GetBool());
    } else if (type == "onConnectionStateChanged") {
      eventHandler->onConnectionStateChanged(
          rtcChannel, (CONNECTION_STATE_TYPE)param["state"].GetInt(),
          (CONNECTION_CHANGED_REASON_TYPE)param["reason"].GetInt());
    }

    eventHandler->onTestEnd(rtcChannel);
  }
}

void CompareAndDumpChannelEventTestResult(
    const char *caseFilePath, const char *dumpFilePath,
    agora::rtc::IChannel *rtcChannel,
    RtcChannelEventHandlerBase *eventHandler) {
  GetChannelEventJsonLogger().compareAndDumpResult(caseFilePath, dumpFilePath);
}

void LogChannelEventCase(const char *eventType, const char *parameter) {
  GetChannelEventJsonLogger().logJson(eventType, parameter);
}

} // namespace common
} // namespace agora
