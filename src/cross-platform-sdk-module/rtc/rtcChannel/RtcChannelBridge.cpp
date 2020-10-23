//
// Created by 张涛 on 2020-08-10.
//

#include "RtcChannelBridge.h"

#include "../common/utils/DocumentHelper.h"
#include "../include/IAgoraRtcEngine.h"
#include "../rtcEngine/RtcEngineBridge.h"
#include "../test/ApiTester.h"

#define CHANNEL_ID_KEY "channelIdKey"

namespace agora {
namespace common {
using namespace rtc;
using rapidjson::Document;
using rapidjson::Value;

RtcChannelBridge::RtcChannelBridge(IRtcEngine *iRtcEngine,
                                   const char *channelId) {
  auto *rtcEngine2 = reinterpret_cast<IRtcEngine2 *>(iRtcEngine);
  channel = rtcEngine2->createChannel(channelId);
}

RtcChannelBridge::~RtcChannelBridge() {
  if (metadataObserver) {
    delete (metadataObserver);
    metadataObserver = nullptr;
  }

  if (channelEventHandler) {
    delete (channelEventHandler);
    channelEventHandler = nullptr;
  }
}

int RtcChannelBridge::initChannelEventHandler(
    IChannelEventHandler *eventHandler) {
  return channel->setChannelEventHandler(eventHandler);
}

void RtcChannelBridge::add_C_ChannelEventHandler(
    CChannelEngineEventHandler *channelEngineEventHandler) {
  if (!channelEventHandler)
    channelEventHandler = new RtcChannelEventHandler();

  static_cast<RtcChannelEventHandler *>(channelEventHandler)
      ->initChannelCallbackEvent(channelEngineEventHandler);
}

void RtcChannelBridge::remove_C_ChannelEventHandler() {
  if (channelEventHandler) {
    delete (channelEventHandler);
    channelEventHandler = nullptr;
  }
}

int RtcChannelBridge::callApi(API_TYPE apiType, const std::string &parameters) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE::SET_CLIENT_ROLE: {
    int role;
    get_parameter_int(document, "role", role, ret);
    CHECK_RET_ERROR(ret)

    ret = setClientRole(CLIENT_ROLE_TYPE(role));
  } break;

  case API_TYPE::JOIN_CHANNEL: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    std::string info;
    get_parameter_string(document, "info", info, ret);
    CHECK_RET_ERROR(ret)

    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    Value options;
    get_parameter_object(document, "options", options, ret);
    CHECK_RET_ERROR(ret)

    ChannelMediaOptions mediaOptions;
    json_to_ChannelMediaOptions(options, mediaOptions, ret);
    CHECK_RET_ERROR(ret)

    ret = joinChannel(token.c_str(), info.c_str(), uid, mediaOptions);
  } break;

  case API_TYPE::LEAVE_CHANNEL: {
    ret = leaveChannel();
  } break;

  case API_TYPE::RE_NEW_TOKEN: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    ret = renewToken(token.c_str());
  } break;

  case API_TYPE::JOIN_CHANNEL_WITH_USER_ACCOUNT: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    std::string userAccount;
    get_parameter_string(document, "userAccount", userAccount, ret);
    CHECK_RET_ERROR(ret)

    Value options;
    get_parameter_object(document, "options", options, ret);
    CHECK_RET_ERROR(ret)

    ChannelMediaOptions mediaOptions;
    json_to_ChannelMediaOptions(options, mediaOptions, ret);
    CHECK_RET_ERROR(ret)

    ret = joinChannelWithUserAccount(token.c_str(), userAccount.c_str(),
                                     mediaOptions);
  } break;

  case API_TYPE::PUBLISH: {
    ret = publish();
  } break;

  case API_TYPE::UNPUBLISH: {
    ret = unpublish();
  } break;

  case API_TYPE::SET_ENCRYPTION_SECTRT: {
    std::string secret;
    get_parameter_string(document, "secret", secret, ret);
    CHECK_RET_ERROR(ret)

    ret = setEncryptionSecret(secret.c_str());
  } break;

  case API_TYPE::SET_ENCRYPTION_MODE: {
    std::string encryptionMode;
    get_parameter_string(document, "encryptionMode", encryptionMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setEncryptionMode(encryptionMode.c_str());
  } break;

  case API_TYPE::SET_REMOTE_USER_PRIORITY: {
    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    int userPriority;
    get_parameter_int(document, "userPriority", userPriority, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteUserPriority(uid, PRIORITY_TYPE(userPriority));
  } break;

  case API_TYPE::SET_REMOTE_VOICE_POSITIONN: {
    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    double pan;
    get_parameter_double(document, "pan", pan, ret);
    CHECK_RET_ERROR(ret)

    double gain;
    get_parameter_double(document, "gain", gain, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteVoicePosition(uid, pan, gain);
  } break;

  case API_TYPE::SET_REMOTE_RENDER_MODE: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    int renderMode;
    get_parameter_int(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    int mirrorMode;
    get_parameter_int(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteRenderMode(userId, RENDER_MODE_TYPE(renderMode),
                              VIDEO_MIRROR_MODE_TYPE(mirrorMode));
  } break;

  case API_TYPE::SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = setDefaultMuteAllRemoteAudioStreams(mute);
  } break;

  case API_TYPE::SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = setDefaultMuteAllRemoteVideoStreams(mute);
  } break;

  case API_TYPE::MUTE_ALL_REMOTE_AUDIO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteAllRemoteAudioStreams(mute);
  } break;

  case API_TYPE::ADJUST_USER_PLAYBACK_SIGNAL_VOLUME: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustUserPlaybackSignalVolume(userId, volume);
  } break;

  case API_TYPE::MUTE_REMOTE_AUDIO_STREAM: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteRemoteAudioStream(userId, mute);
  } break;

  case API_TYPE::MUTE_REMOTE_VIDEO_STREAM: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteRemoteVideoStream(userId, mute);
  } break;

  case API_TYPE::MUTE_ALL_REMOTE_VIDEO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteAllRemoteVideoStreams(mute);
  } break;

  case API_TYPE::SET_REMOTE_VIDEO_STREAM_TYPE: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    int streamType;
    get_parameter_int(document, "streamType", streamType, ret);
    CHECK_RET_ERROR(ret)

    ret =
        setRemoteVideoStreamType(userId, REMOTE_VIDEO_STREAM_TYPE(streamType));
  } break;

  case API_TYPE::SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE: {
    int streamType;
    get_parameter_int(document, "streamType", streamType, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteDefaultVideoStreamType(REMOTE_VIDEO_STREAM_TYPE(streamType));
  } break;

  case API_TYPE::ADD_PUBLISH_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    bool transcodingEnabled;
    get_parameter_bool(document, "transcodingEnabled", transcodingEnabled, ret);
    CHECK_RET_ERROR(ret)

    ret = addPublishStreamUrl(url.c_str(), transcodingEnabled);
  } break;

  case API_TYPE::REMOVE_PUBLISH_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    ret = removePublishStreamUrl(url.c_str());
  } break;

  case API_TYPE::SET_LIVE_TRANSCODING: {
    Value transcodingValue;
    get_parameter_object(document, "transcoding", transcodingValue, ret);
    CHECK_RET_ERROR(ret)
    LiveTranscoding transcoding;

    get_parameter_int(transcodingValue, "width", transcoding.width, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(transcodingValue, "height", transcoding.height, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(transcodingValue, "videoBitrate",
                      transcoding.videoBitrate, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(transcodingValue, "videoFramerate",
                      transcoding.videoFramerate, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_bool(transcodingValue, "lowLatency", transcoding.lowLatency,
                       ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(transcodingValue, "videoGop", transcoding.videoGop, ret);
    CHECK_RET_ERROR(ret)

    int videoCodecProfile = -1;
    get_parameter_int(transcodingValue, "videoCodecProfile", videoCodecProfile,
                      ret);
    CHECK_RET_ERROR(ret)
    transcoding.videoCodecProfile = VIDEO_CODEC_PROFILE_TYPE(videoCodecProfile);

    get_parameter_uint(transcodingValue, "backgroundColor",
                       transcoding.backgroundColor, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_uint(transcodingValue, "userCount", transcoding.userCount,
                       ret);
    CHECK_RET_ERROR(ret)

    TranscodingUser *transcodingUser =
        new TranscodingUser[transcoding.userCount];
    Value val;
    get_parameter_array(transcodingValue, "transcodingUsers", val, ret);
    CHECK_RET_ERROR(ret);

    json_to_TranscodingUser(val, transcodingUser, transcoding.userCount, ret);
    transcoding.transcodingUsers = transcodingUser;
    std::string transcodingExtraInfo;
    get_parameter_string(transcodingValue, "transcodingExtraInfo",
                         transcodingExtraInfo, ret);
    CHECK_RET_ERROR(ret)
    transcoding.transcodingExtraInfo = transcodingExtraInfo.c_str();

    std::string metadata;
    get_parameter_string(transcodingValue, "metadata", metadata, ret);
    CHECK_RET_ERROR(ret)
    transcoding.metadata = metadata.c_str();

    Value watermark;
    get_parameter_object(transcodingValue, "watermark", watermark, ret);
    CHECK_RET_ERROR(ret)

    RtcImage watermarkImage;
    std::string url;
    json_to_RtcImage(watermark, watermarkImage, url, ret);
    CHECK_RET_ERROR(ret);

    transcoding.watermark = &watermarkImage;

    Value backgroundValue;
    get_parameter_object(transcodingValue, "backgroundImage", backgroundValue,
                         ret);
    CHECK_RET_ERROR(ret)

    RtcImage backGroundImage;
    std::string backGroundUrl;
    json_to_RtcImage(backgroundValue, backGroundImage, backGroundUrl, ret);
    CHECK_RET_ERROR(ret);

    transcoding.backgroundImage = &backGroundImage;
    ret = setLiveTranscoding(transcoding);
    delete[] transcodingUser;
  } break;

  case API_TYPE::ADD_INJECT_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    Value config;
    get_parameter_object(document, "config", config, ret);
    CHECK_RET_ERROR(ret)

    InjectStreamConfig injectStreamConfig;
    json_to_InjectStreamConfig(config, &injectStreamConfig, ret);
    CHECK_RET_ERROR(ret)

    ret = addInjectStreamUrl(url.c_str(), injectStreamConfig);
  } break;

  case API_TYPE::REMOVE_INJECT_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    ret = removeInjectStreamUrl(url.c_str());
  } break;

  case API_TYPE::START_CHANNEL_MEDIA_RELAY: {
    int destCount = -1;
    get_parameter_int(document, "destCount", destCount, ret);
    CHECK_RET_ERROR(ret)

    Value srcInfo;
    get_parameter_object(document, "srcInfo", srcInfo, ret);
    CHECK_RET_ERROR(ret)

    std::string channelName[1];
    std::string token[1];

    ChannelMediaInfo srcChannelMediaInfo;
    json_to_ChannelMediaInfo(srcInfo, &srcChannelMediaInfo, channelName, token,
                             -1, ret);
    CHECK_RET_ERROR(ret);

    Value destInfos;
    get_parameter_array(document, "destInfos", destInfos, ret);
    CHECK_RET_ERROR(ret)

    ChannelMediaInfo *destChannelMediaInfo = new ChannelMediaInfo[destCount];
    std::string *destChannelName = new std::string[destCount];
    std::string *destToken = new std::string[destCount];
    json_to_ChannelMediaInfo(destInfos, destChannelMediaInfo, destChannelName,
                             destToken, destCount, ret);
    CHECK_RET_ERROR(ret);

    ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
    channelMediaRelayConfiguration.destInfos = destChannelMediaInfo;
    channelMediaRelayConfiguration.destCount = destCount;
    ret = startChannelMediaRelay(channelMediaRelayConfiguration);
    delete[] destChannelMediaInfo;
    delete[] destChannelName;
    delete[] destToken;
  } break;

  case API_TYPE::UPDATE_CHANNEL_MEDIA_RELAY: {
    int destCount = -1;
    get_parameter_int(document, "destCount", destCount, ret);
    CHECK_RET_ERROR(ret)

    Value srcInfo;
    get_parameter_object(document, "srcInfo", srcInfo, ret);
    CHECK_RET_ERROR(ret)

    std::string channelName[1];
    std::string token[1];

    ChannelMediaInfo srcChannelMediaInfo;
    json_to_ChannelMediaInfo(srcInfo, &srcChannelMediaInfo, channelName, token,
                             -1, ret);
    CHECK_RET_ERROR(ret);

    Value destInfos;
    get_parameter_array(document, "destInfos", destInfos, ret);
    CHECK_RET_ERROR(ret)

    ChannelMediaInfo *destChannelMediaInfo = new ChannelMediaInfo[destCount];
    std::string *destChannelName = new std::string[destCount];
    std::string *destToken = new std::string[destCount];
    json_to_ChannelMediaInfo(destInfos, destChannelMediaInfo, destChannelName,
                             destToken, destCount, ret);
    CHECK_RET_ERROR(ret);

    ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
    channelMediaRelayConfiguration.destInfos = destChannelMediaInfo;
    channelMediaRelayConfiguration.destCount = destCount;
    ret = updateChannelMediaRelay(channelMediaRelayConfiguration);
    delete[] destChannelMediaInfo;
    delete[] destChannelName;
    delete[] destToken;
  } break;

  case API_TYPE::STOP_CHANNEL_MEDIA_RELAY: {
    ret = stopChannelMediaRelay();
  } break;

  case API_TYPE::GET_CONNECTION_STATE: {
    ret = getConnectionState();
  } break;

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return ret;
}

const char *RtcChannelBridge::callApi_str(API_TYPE apiType,
                                          const std::string &parameters) {
  switch (apiType) {
  case API_TYPE::CHANNEL_ID:
    return channelId();

  default:
    break;
  }
  return "";
}

int RtcChannelBridge::callApi(API_TYPE apiType, const std::string &parameters,
                              void *ptr) {
  Document document;
  document.Parse(parameters.c_str());

  int ret = ERROR_CODE::ERROR_OK;
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case API_TYPE::SEND_STREAM_MESSAGE: {
    int streamId;
    get_parameter_int(document, "streamId", streamId, ret);
    CHECK_RET_ERROR(ret)

    int length;
    get_parameter_int(document, "length", length, ret);
    CHECK_RET_ERROR(ret)

    ret = sendStreamMessage(streamId, reinterpret_cast<const char *>(ptr),
                            (size_t)length);
  } break;

  case API_TYPE::CREATE_DATA_STREAM: {
    bool reliable;
    get_parameter_bool(document, "reliable", reliable, ret);
    CHECK_RET_ERROR(ret)

    bool ordered;
    get_parameter_bool(document, "ordered", ordered, ret);
    CHECK_RET_ERROR(ret)

    ret = createDataStream(reinterpret_cast<int *>(ptr), reliable, ordered);
  } break;

  case SEND_METADATA: {
    IMetadataObserver::Metadata metadata;
    get_parameter_uint(document, "uid", metadata.uid, ret);
    CHECK_RET_ERROR(ret)

    unsigned int size;
    get_parameter_uint(document, "size", metadata.size, ret);
    CHECK_RET_ERROR(ret)

    long long timeStampMs;
    get_parameter_int64(document, "timeStampMs", metadata.timeStampMs, ret);
    CHECK_RET_ERROR(ret)

    metadata.buffer = reinterpret_cast<unsigned char *>(ptr);
    CHECK_RET_ERROR(ret)

    ret = sendMetadata(&metadata);
  } break;

  case SET_MAX_META_SIZE: {
    int size;
    get_parameter_int(document, "size", size, ret);
    CHECK_RET_ERROR(ret)
    ret = setMaxMetadataSize(size);
  } break;

  case REGISTER_MEDIA_META_DATA_OBSERVER: {
    int type;
    get_parameter_int(document, "type", type, ret);
    CHECK_RET_ERROR(ret)

    bool useSdkDefault;
    get_parameter_bool(document, "useSdkDefault", useSdkDefault, ret);
    CHECK_RET_ERROR(ret)

    ret = registerMediaMetadataObserver(
        reinterpret_cast<IMetadataObserver *>(ptr),
        IMetadataObserver::METADATA_TYPE(type), useSdkDefault);
  } break;

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return ret;
}

int RtcChannelBridge::registerMediaMetadataObserver(
    IMetadataObserver *observer, IMetadataObserver::METADATA_TYPE type,
    bool useSdkDefault) {
  LOG_JSON(REGISTER_MEDIA_META_DATA_OBSERVER, CHANNEL_ID_KEY,
           channel->channelId(), "type", type, "useSdkDefault", useSdkDefault);
  int ret;
  if (useSdkDefault) {
    ret = channel->registerMediaMetadataObserver(observer, type);
  } else {
    if (observer) {
      if (metadataObserver) {
        channel->registerMediaMetadataObserver(nullptr, type);
        delete (metadataObserver);
        metadataObserver = nullptr;
        metadataObserver = new MetadataObserver(observer);
        ret = channel->registerMediaMetadataObserver(metadataObserver, type);
      } else {
        metadataObserver = new MetadataObserver(observer);
        ret = channel->registerMediaMetadataObserver(metadataObserver, type);
      }
    } else {
      ret = channel->registerMediaMetadataObserver(nullptr, type);
      if (metadataObserver) {
        delete (metadataObserver);
        metadataObserver = nullptr;
      }
    }
  }
  return ret;
}

int RtcChannelBridge::createDataStream(int *streamId, bool reliable,
                                       bool ordered) {
  LOG_JSON(CREATE_DATA_STREAM, CHANNEL_ID_KEY, channel->channelId(), "reliable",
           reliable, "ordered", ordered);
  return channel->createDataStream(streamId, reliable, ordered);
}

int RtcChannelBridge::sendStreamMessage(int streamId, const char *data,
                                        size_t length) {
  LOG_JSON(SEND_STREAM_MESSAGE, CHANNEL_ID_KEY, channel->channelId(),
           "streamId", streamId, "length", (uint64_t)length);
  return channel->sendStreamMessage(streamId, data, length);
}

int RtcChannelBridge::joinChannel(const char *token, const char *info,
                                  rtc::uid_t uid,
                                  const ChannelMediaOptions &options) {
  LOG_JSON(JOIN_CHANNEL, CHANNEL_ID_KEY, channel->channelId(), "token", token,
           "info", info, "uid", uid, "options", options);
  return channel->joinChannel(token, info, uid, options);
}

int RtcChannelBridge::joinChannelWithUserAccount(
    const char *token, const char *userAccount,
    const ChannelMediaOptions &options) {
  LOG_JSON(JOIN_CHANNEL_WITH_USER_ACCOUNT, CHANNEL_ID_KEY, channel->channelId(),
           "token", token, "userAccount", userAccount, "options", options);
  return channel->joinChannelWithUserAccount(token, userAccount, options);
}

int RtcChannelBridge::leaveChannel() {
  LOG_JSON(LEAVE_CHANNEL, CHANNEL_ID_KEY, channel->channelId());
  return channel->leaveChannel();
}

int RtcChannelBridge::publish() {
  LOG_JSON(PUBLISH, CHANNEL_ID_KEY, channel->channelId());
  return channel->publish();
}

int RtcChannelBridge::unpublish() {
  LOG_JSON(UNPUBLISH, CHANNEL_ID_KEY, channel->channelId());
  return channel->unpublish();
}

const char *RtcChannelBridge::channelId() {
  LOG_JSON(CHANNEL_ID, CHANNEL_ID_KEY, channel->channelId());
  return channel->channelId();
}

int RtcChannelBridge::getCallId(agora::util::AString &callId) {
  return channel->getCallId(callId);
}

int RtcChannelBridge::renewToken(const char *token) {
  LOG_JSON(RE_NEW_TOKEN, CHANNEL_ID_KEY, channel->channelId(), "token", token);
  return channel->renewToken(token);
}

int RtcChannelBridge::setEncryptionSecret(const char *secret) {
  LOG_JSON(SET_ENCRYPTION_SECTRT, CHANNEL_ID_KEY, channel->channelId(),
           "secret", secret);
  return channel->setEncryptionSecret(secret);
}

int RtcChannelBridge::setEncryptionMode(const char *encryptionMode) {
  LOG_JSON(SET_ENCRYPTION_MODE, CHANNEL_ID_KEY, channel->channelId(),
           "encryptionMode", encryptionMode);
  return channel->setEncryptionMode(encryptionMode);
}

int RtcChannelBridge::registerPacketObserver(IPacketObserver *observer) {
  return channel->registerPacketObserver(observer);
}

int RtcChannelBridge::setClientRole(CLIENT_ROLE_TYPE role) {
  LOG_JSON(SET_CLIENT_ROLE, CHANNEL_ID_KEY, channel->channelId(), "role", role);
  return channel->setClientRole(role);
}

int RtcChannelBridge::setRemoteUserPriority(rtc::uid_t uid,
                                            PRIORITY_TYPE userPriority) {
  LOG_JSON(SET_REMOTE_USER_PRIORITY, CHANNEL_ID_KEY, channel->channelId(),
           "uid", uid, "userPriority", userPriority);
  return channel->setRemoteUserPriority(uid, userPriority);
}

int RtcChannelBridge::setRemoteVoicePosition(rtc::uid_t uid, double pan,
                                             double gain) {
  LOG_JSON(SET_REMOTE_VOICE_POSITIONN, CHANNEL_ID_KEY, channel->channelId(),
           "uid", uid, "pan", pan, "gain", gain);
  return channel->setRemoteVoicePosition(uid, pan, gain);
}

int RtcChannelBridge::setRemoteRenderMode(rtc::uid_t userId,
                                          RENDER_MODE_TYPE renderMode,
                                          VIDEO_MIRROR_MODE_TYPE mirrorMode) {
  LOG_JSON(SET_REMOTE_RENDER_MODE, CHANNEL_ID_KEY, channel->channelId(),
           "userId", userId, "renderMode", renderMode, "mirrorMode",
           mirrorMode);
  return channel->setRemoteRenderMode(userId, renderMode, mirrorMode);
}

int RtcChannelBridge::setDefaultMuteAllRemoteAudioStreams(bool mute) {
  LOG_JSON(SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS, CHANNEL_ID_KEY,
           channel->channelId(), "mute", mute);
  return channel->setDefaultMuteAllRemoteAudioStreams(mute);
}

int RtcChannelBridge::setDefaultMuteAllRemoteVideoStreams(bool mute) {
  LOG_JSON(SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS, CHANNEL_ID_KEY,
           channel->channelId(), "mute", mute);
  return channel->setDefaultMuteAllRemoteVideoStreams(mute);
}

int RtcChannelBridge::muteAllRemoteAudioStreams(bool mute) {
  LOG_JSON(MUTE_ALL_REMOTE_AUDIO_STREAMS, CHANNEL_ID_KEY, channel->channelId(),
           "mute", mute);
  return channel->muteAllRemoteAudioStreams(mute);
}

int RtcChannelBridge::adjustUserPlaybackSignalVolume(rtc::uid_t userId,
                                                     int volume) {
  LOG_JSON(ADJUST_USER_PLAYBACK_SIGNAL_VOLUME, CHANNEL_ID_KEY,
           channel->channelId(), "userId", userId, "volume", volume);
  return channel->adjustUserPlaybackSignalVolume(userId, volume);
}

int RtcChannelBridge::muteRemoteAudioStream(rtc::uid_t userId, bool mute) {
  LOG_JSON(MUTE_REMOTE_AUDIO_STREAM, CHANNEL_ID_KEY, channel->channelId(),
           "userId", userId, "mute", mute);
  return channel->muteRemoteAudioStream(userId, mute);
}

int RtcChannelBridge::muteAllRemoteVideoStreams(bool mute) {
  LOG_JSON(MUTE_ALL_REMOTE_VIDEO_STREAMS, CHANNEL_ID_KEY, channel->channelId(),
           "mute", mute);
  return channel->muteAllRemoteVideoStreams(mute);
}

int RtcChannelBridge::muteRemoteVideoStream(rtc::uid_t userId, bool mute) {
  LOG_JSON(MUTE_REMOTE_VIDEO_STREAM, CHANNEL_ID_KEY, channel->channelId(),
           "userId", userId, "mute", mute);
  return channel->muteRemoteVideoStream(userId, mute);
}

int RtcChannelBridge::setRemoteVideoStreamType(
    rtc::uid_t userId, REMOTE_VIDEO_STREAM_TYPE streamType) {
  LOG_JSON(SET_REMOTE_VIDEO_STREAM_TYPE, CHANNEL_ID_KEY, channel->channelId(),
           "userId", userId, "streamType", streamType);
  return channel->setRemoteVideoStreamType(userId, streamType);
}

int RtcChannelBridge::setRemoteDefaultVideoStreamType(
    REMOTE_VIDEO_STREAM_TYPE streamType) {
  LOG_JSON(SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE, CHANNEL_ID_KEY,
           channel->channelId(), "streamType", streamType);
  return channel->setRemoteDefaultVideoStreamType(streamType);
}

int RtcChannelBridge::addPublishStreamUrl(const char *url,
                                          bool transcodingEnabled) {
  LOG_JSON(ADD_PUBLISH_STREAM_URL, CHANNEL_ID_KEY, channel->channelId(), "url",
           url, "transcodingEnabled", transcodingEnabled);
  return channel->addPublishStreamUrl(url, transcodingEnabled);
}

int RtcChannelBridge::removePublishStreamUrl(const char *url) {
  LOG_JSON(REMOVE_PUBLISH_STREAM_URL, CHANNEL_ID_KEY, channel->channelId(),
           "url", url);
  return channel->removePublishStreamUrl(url);
}

int RtcChannelBridge::setLiveTranscoding(const LiveTranscoding &transcoding) {
  LOG_JSON(SET_LIVE_TRANSCODING, CHANNEL_ID_KEY, channel->channelId(),
           "transcoding", transcoding);
  return channel->setLiveTranscoding(transcoding);
}

int RtcChannelBridge::addInjectStreamUrl(const char *url,
                                         const InjectStreamConfig &config) {
  LOG_JSON(ADD_INJECT_STREAM_URL, CHANNEL_ID_KEY, channel->channelId(), "url",
           url, "config", config);
  return channel->addInjectStreamUrl(url, config);
}

int RtcChannelBridge::removeInjectStreamUrl(const char *url) {
  LOG_JSON(REMOVE_INJECT_STREAM_URL, CHANNEL_ID_KEY, channel->channelId(),
           "url", url);
  return channel->removeInjectStreamUrl(url);
}

int RtcChannelBridge::startChannelMediaRelay(
    const ChannelMediaRelayConfiguration &configuration) {
  LOG_JSON(START_CHANNEL_MEDIA_RELAY, CHANNEL_ID_KEY, channel->channelId(),
           "config", configuration);
  return channel->startChannelMediaRelay(configuration);
}

int RtcChannelBridge::updateChannelMediaRelay(
    const ChannelMediaRelayConfiguration &configuration) {
  LOG_JSON(UPDATE_CHANNEL_MEDIA_RELAY, CHANNEL_ID_KEY, channel->channelId(),
           "config", configuration);
  return channel->updateChannelMediaRelay(configuration);
}

int RtcChannelBridge::stopChannelMediaRelay() {
  LOG_JSON(STOP_CHANNEL_MEDIA_RELAY, CHANNEL_ID_KEY, channel->channelId());
  return channel->stopChannelMediaRelay();
}

CONNECTION_STATE_TYPE
RtcChannelBridge::getConnectionState() {
  LOG_JSON(GET_CONNECTION_STATE, CHANNEL_ID_KEY, channel->channelId());
  return channel->getConnectionState();
}

int RtcChannelBridge::sendMetadata(rtc::IMetadataObserver::Metadata *metadata) {
  LOG_JSON(SEND_METADATA, CHANNEL_ID_KEY, channel->channelId(), "metadata",
           *metadata);
  if (metadataObserver) {
    return metadataObserver->sendMetadata(metadata);
  }
  return ERROR_CODE::ERROR_NOT_INITIALIZE_OBSERVER;
}

int RtcChannelBridge::setMaxMetadataSize(int size) {
  LOG_JSON(SET_MAX_META_SIZE, CHANNEL_ID_KEY, channel->channelId(), "size",
           size);
  if (metadataObserver) {
    return metadataObserver->setMaxMetadataSize(size);
  }
  return ERROR_CODE::ERROR_NOT_INITIALIZE_OBSERVER;
}

void RtcChannelBridge::release() {
  channel->release();
  channel = nullptr;
  delete this;
}

rtc::IChannel *RtcChannelBridge::getChannel() { return channel; }
} // namespace common
} // namespace agora
