//
// Created by 张涛 on 2020-08-10.
//

#pragma once

#include "../callback/rtcChannnelCallback/RtcChannelEventHandler.h"
#include "../common/IBridgeCommon.h"
#include "../common/utils/StructHelper.h"
#include "../observer/metadata/metadata_observer.h"
#include "IRtcChannelBridge.h"

namespace agora {
namespace common {
class RtcChannelBridge : public IRtcChannelBridge {
private:
  rtc::IChannel *channel = nullptr;
  MetadataObserver *metadataObserver = nullptr;
  rtc::IChannelEventHandler *channelEventHandler = nullptr;

public:
  RtcChannelBridge(rtc::IRtcEngine *iRtcEngine, const char *channelId);

  virtual ~RtcChannelBridge();

  virtual int
  initChannelEventHandler(rtc::IChannelEventHandler *eventHandler) override;

  void add_C_ChannelEventHandler(
      CChannelEngineEventHandler *channelEngineEventHandler) override;

  void remove_C_ChannelEventHandler() override;

  virtual int callApi(API_TYPE apiType, const std::string &parameters) override;

  virtual const char *callApi_str(API_TYPE apiType,
                                  const std::string &parameters) override;

  virtual int callApi(API_TYPE apiType, const std::string &parameters,
                      void *ptr) override;

  virtual void release() override;

  int joinChannel(const char *token, const char *info, rtc::uid_t uid,
                  const rtc::ChannelMediaOptions &options);

  int joinChannelWithUserAccount(const char *token, const char *userAccount,
                                 const rtc::ChannelMediaOptions &options);

  int leaveChannel();

  int publish();

  int unpublish();

  const char *channelId();

  int getCallId(util::AString &callId);

  int renewToken(const char *token);

  int setEncryptionSecret(const char *secret);

  int setEncryptionMode(const char *encryptionMode);

  int registerPacketObserver(rtc::IPacketObserver *observer);

  int setClientRole(rtc::CLIENT_ROLE_TYPE role);

  int setRemoteUserPriority(rtc::uid_t uid, rtc::PRIORITY_TYPE userPriority);

  int setRemoteVoicePosition(rtc::uid_t uid, double pan, double gain);

  int setRemoteRenderMode(rtc::uid_t userId, rtc::RENDER_MODE_TYPE renderMode,
                          rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode);

  int setDefaultMuteAllRemoteAudioStreams(bool mute);

  int setDefaultMuteAllRemoteVideoStreams(bool mute);

  int muteAllRemoteAudioStreams(bool mute);

  int adjustUserPlaybackSignalVolume(rtc::uid_t userId, int volume);

  int muteRemoteAudioStream(rtc::uid_t userId, bool mute);

  int muteAllRemoteVideoStreams(bool mute);

  int muteRemoteVideoStream(rtc::uid_t userId, bool mute);

  int setRemoteVideoStreamType(rtc::uid_t userId,
                               rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

  int setRemoteDefaultVideoStreamType(rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

  int addPublishStreamUrl(const char *url, bool transcodingEnabled);

  int removePublishStreamUrl(const char *url);

  int setLiveTranscoding(const rtc::LiveTranscoding &transcoding);

  int addInjectStreamUrl(const char *url,
                         const rtc::InjectStreamConfig &config);

  int removeInjectStreamUrl(const char *url);

  int startChannelMediaRelay(
      const rtc::ChannelMediaRelayConfiguration &configuration);

  int updateChannelMediaRelay(
      const rtc::ChannelMediaRelayConfiguration &configuration);

  int stopChannelMediaRelay();

  int createDataStream(int *streamId, bool reliable, bool ordered);

  int sendStreamMessage(int streamId, const char *data, size_t length);

  rtc::CONNECTION_STATE_TYPE getConnectionState();

  int registerMediaMetadataObserver(rtc::IMetadataObserver *observer,
                                    rtc::IMetadataObserver::METADATA_TYPE type,
                                    bool useSdkDefault = true);

  int sendMetadata(rtc::IMetadataObserver::Metadata *metadata);

  int setMaxMetadataSize(int size);

  rtc::IChannel *getChannel();
};
} // namespace common
} // namespace agora
