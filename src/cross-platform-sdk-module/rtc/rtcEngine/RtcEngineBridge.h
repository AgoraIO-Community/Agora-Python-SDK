#pragma once

#include "../callback/rtcEngineCallback/RtcEngineEventHandler.h"
#include "../common/IBridgeCommon.h"
#include "../common/utils/DocumentHelper.h"
#include "../common/utils/StructHelper.h"
#include "../include/IAgoraRtcEngine.h"
#include "../rtcChannel/RtcChannelBridge.h"

#include "../deviceManager/audioDeviceManager/AudioPlaybackDeviceManager.h"
#include "../deviceManager/audioDeviceManager/AudioRecordingDeviceManager.h"
#include "../deviceManager/videoDeviceManager/VideoDeviceManager.h"
#include "../include/IAgoraMediaEngine.h"
#include "../observer/metadata/metadata_observer.h"
#include "IRtcEngineBridge.h"

namespace agora {
namespace common {

#define MAX_WINDOW_COUNT 250
class RtcEngineBridge : public IRtcEngineBridge {
public:
  RtcEngineBridge();

  virtual ~RtcEngineBridge();

private:
  rtc::IRtcEngine *mRtcEngine = nullptr;
  rtc::IRtcEngineEventHandler *mRtcEngineEventHandler = nullptr;
  MetadataObserver *metadataObserver = nullptr;
  agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;

public:
  virtual int
  initEventHandler(rtc::IRtcEngineEventHandler *eventHandler) override;

  virtual int callApi(API_TYPE apiType, const std::string &parameters) override;

  virtual int callApi(API_TYPE apiType, const std::string &parameters,
                      void *ptr) override;

  virtual const char *callApi_str(API_TYPE apiType,
                                  const std::string &parameters) override;

  virtual int callApi_audioEffect(API_TYPE_AUDIO_EFFECT apiType,
                                  const std::string &parameters) override;

  virtual void release(bool sync = false) override;

  virtual RtcChannelBridge *createChannel(const char *channelId) override;

  virtual IAudioDeviceManagerBridge *
  createAudioDeviceManager(DEVICE_TYPE device_type,
                           ERROR_CODE &erroCode) override;

  virtual IVideoDeviceManagerBridge *
  createVideoDeviceManager(ERROR_CODE &error_code) override;

  VideoDeviceManager *createVideoDeviceManager(int *errorCode);

  AudioPlaybackDeviceManager *createAudioPlaybackDeviceManager(int *errorCode);

  AudioRecordingDeviceManager *
  createAudioRecordingDeviceManager(int *errorCode);

  void add_C_EventHandler(CEngineEventHandler *engineEventHandler) override;

  void remove_C_EventHandler() override;

  int initialize(const char *appId, void *context, unsigned int areaCode);

  int setChannelProfile(rtc::CHANNEL_PROFILE_TYPE profile);

  int setClientRole(rtc::CLIENT_ROLE_TYPE role);

  int joinChannel(const char *token, const char *channelId, const char *info,
                  rtc::uid_t uid);

  int switchChannel(const char *token, const char *channelId);

  int leaveChannel();

  int renewToken(const char *token);

  int registerLocalUserAccount(const char *appId, const char *userAccount);

  int joinChannelWithUserAccount(const char *token, const char *channelId,
                                 const char *userAccount);

  int getUserInfoByUserAccount(const char *userAccount,
                               rtc::UserInfo *userInfo);

  int getUserInfoByUid(rtc::uid_t uid, rtc::UserInfo *userInfo);

  int startEchoTest();

  int startEchoTest(int intervalInSeconds);

  int stopEchoTest();

  int enableVideo();

  int disableVideo();

  int setVideoProfile(rtc::VIDEO_PROFILE_TYPE profile, bool swapWidthAndHeight);

  int setVideoEncoderConfiguration(
      const rtc::VideoEncoderConfiguration &config);

  int setCameraCapturerConfiguration(
      const rtc::CameraCapturerConfiguration &config);

  int setupLocalVideo(const rtc::VideoCanvas &canvas);

  int setupRemoteVideo(const rtc::VideoCanvas &canvas);

  int startPreview();

  int setRemoteUserPriority(rtc::uid_t uid, rtc::PRIORITY_TYPE userPriority);

  int stopPreview();

  int enableAudio();

  int enableLocalAudio(bool enabled);

  int disableAudio();

  int setAudioProfile(rtc::AUDIO_PROFILE_TYPE profile,
                      rtc::AUDIO_SCENARIO_TYPE scenario);

  int muteLocalAudioStream(bool mute);

  int muteAllRemoteAudioStreams(bool mute);

  int setDefaultMuteAllRemoteVideoStreams(bool mute);

  int adjustUserPlaybackSignalVolume(unsigned int uid, int volume);

  int muteRemoteAudioStream(rtc::uid_t userId, bool mute);

  int muteLocalVideoStream(bool mute);

  int enableLocalVideo(bool enabled);

  int muteAllRemoteVideoStreams(bool mute);

  int setDefaultMuteAllRemoteAudioStreams(bool mute);

  int muteRemoteVideoStream(rtc::uid_t userId, bool mute);

  int setRemoteVideoStreamType(rtc::uid_t userId,
                               rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

  int setRemoteDefaultVideoStreamType(rtc::REMOTE_VIDEO_STREAM_TYPE streamType);

  int enableAudioVolumeIndication(int interval, int smooth, bool report_vad);

  int startAudioRecording(const char *filePath,
                          rtc::AUDIO_RECORDING_QUALITY_TYPE quality);

  int startAudioRecording(const char *filePath, int sampleRate,
                          rtc::AUDIO_RECORDING_QUALITY_TYPE quality);

  int stopAudioRecording();

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
  int enableFaceDetection(bool enable);
#endif

  int setRemoteVoicePosition(rtc::uid_t uid, double pan, double gain);

  int setLogFile(const char *file);

  int setLogFilter(unsigned int filter);

  int setLogFileSize(unsigned int fileSizeInKBytes);

  int setLocalRenderMode(rtc::RENDER_MODE_TYPE renderMode);

  int setLocalRenderMode(rtc::RENDER_MODE_TYPE renderMode,
                         rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode);

  int setRemoteRenderMode(rtc::uid_t userId, rtc::RENDER_MODE_TYPE renderMode);

  int setRemoteRenderMode(rtc::uid_t userId, rtc::RENDER_MODE_TYPE renderMode,
                          rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode);

  int setLocalVideoMirrorMode(rtc::VIDEO_MIRROR_MODE_TYPE mirrorMode);

  int enableDualStreamMode(bool enabled);

  int adjustRecordingSignalVolume(int volume);

  int adjustPlaybackSignalVolume(int volume);

  int enableWebSdkInteroperability(bool enabled);

  int setVideoQualityParameters(bool preferFrameRateOverImageQuality);

  int setLocalPublishFallbackOption(rtc::STREAM_FALLBACK_OPTIONS option);

  int setRemoteSubscribeFallbackOption(rtc::STREAM_FALLBACK_OPTIONS option);

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
  int switchCamera();

  int switchCamera(rtc::CAMERA_DIRECTION direction);

  int setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker);

  int setEnableSpeakerphone(bool speakerOn);

  int enableInEarMonitoring(bool enabled);

  int setInEarMonitoringVolume(int volume);

  bool isSpeakerphoneEnabled();
#endif

#if (defined(__APPLE__) && TARGET_OS_IOS)
  int setAudioSessionOperationRestriction(
      rtc::AUDIO_SESSION_OPERATION_RESTRICTION restriction);
#endif

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) ||              \
    defined(_WIN32)
  int enableLoopbackRecording(bool enabled, const char *deviceName = NULL);

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
  int startScreenCaptureByDisplayId(
      unsigned int displayId, const rtc::Rectangle &regionRect,
      const rtc::ScreenCaptureParameters &captureParams);
#endif

#if defined(_WIN32)
  int startScreenCaptureByScreenRect(
      const rtc::Rectangle &screenRect, const rtc::Rectangle &regionRect,
      const rtc::ScreenCaptureParameters &captureParams);

  int startScreenCaptureByWindowId(
      rtc::view_t windowId, const rtc::Rectangle &regionRect,
      const rtc::ScreenCaptureParameters &captureParams);

  int setScreenCaptureContentHint(rtc::VideoContentHint contentHint);

  int updateScreenCaptureParameters(
      const rtc::ScreenCaptureParameters &captureParams);

  int updateScreenCaptureRegion(const rtc::Rectangle &regionRect);

  int updateScreenCaptureRegion(const rtc::Rect *rect);
#endif

  int stopScreenCapture();
#endif

  int getCallId(agora::util::AString &callId);

  int rate(const char *callId, int rating, const char *description);

  int complain(const char *callId, const char *description);

  const char *getVersion();

  int enableLastmileTest();

  int disableLastmileTest();

  int startLastmileProbeTest(const rtc::LastmileProbeConfig &config);

  int stopLastmileProbeTest();

  const char *getErrorDescription(int code);

  int setEncryptionSecret(const char *secret);

  int setEncryptionMode(const char *encryptionMode);

  int registerPacketObserver(rtc::IPacketObserver *observer);

  int createDataStream(int *streamId, bool reliable, bool ordered);

  int sendStreamMessage(int streamId, const char *data, size_t length);

  int addPublishStreamUrl(const char *url, bool transcodingEnabled);

  int removePublishStreamUrl(const char *url);

  int setLiveTranscoding(const rtc::LiveTranscoding &transcoding);

  int addVideoWatermark(const rtc::RtcImage &watermark);

  int addVideoWatermark(const char *watermarkUrl,
                        const rtc::WatermarkOptions &options);

  int clearVideoWatermarks();

  int setBeautyEffectOptions(bool enabled, rtc::BeautyOptions options);

  int addInjectStreamUrl(const char *url,
                         const rtc::InjectStreamConfig &config);

  int startChannelMediaRelay(
      const rtc::ChannelMediaRelayConfiguration &configuration);

  int updateChannelMediaRelay(
      const rtc::ChannelMediaRelayConfiguration &configuration);

  int stopChannelMediaRelay();

  int removeInjectStreamUrl(const char *url);

  rtc::CONNECTION_STATE_TYPE getConnectionState();

  int setParameters(const char *parameters);

  int setPlaybackDeviceVolume(int volume);

  // API_TYPE_AUDIO_EFFECT

  int startAudioMixing(const char *filePath, bool loopback, bool replace,
                       int cycle);

  int stopAudioMixing();

  int pauseAudioMixing();

  int resumeAudioMixing();

  int setHighQualityAudioParameters(bool fullband, bool stereo,
                                    bool fullBitrate);

  int adjustAudioMixingVolume(int volume);

  int adjustAudioMixingPlayoutVolume(int volume);

  int getAudioMixingPlayoutVolume();

  int adjustAudioMixingPublishVolume(int volume);

  int getAudioMixingPublishVolume();

  int getAudioMixingDuration();

  int getAudioMixingCurrentPosition();

  int setAudioMixingPosition(int pos /*in ms*/);

  int setAudioMixingPitch(int pitch);

  int getEffectsVolume();

  int setEffectsVolume(int volume);

  int setVolumeOfEffect(int soundId, int volume);

  int playEffect(int soundId, const char *filePath, int loopCount, double pitch,
                 double pan, int gain, bool publish = false);

  int stopEffect(int soundId);

  int stopAllEffects();

  int preloadEffect(int soundId, const char *filePath);

  int unloadEffect(int soundId);

  int pauseEffect(int soundId);

  int pauseAllEffects();

  int resumeEffect(int soundId);

  int resumeAllEffects();

  int enableSoundPositionIndication(bool enabled);

  int setLocalVoicePitch(double pitch);

  int setLocalVoiceEqualization(
      rtc::AUDIO_EQUALIZATION_BAND_FREQUENCY bandFrequency, int bandGain);

  int setLocalVoiceReverb(rtc::AUDIO_REVERB_TYPE reverbKey, int value);

  int setLocalVoiceChanger(rtc::VOICE_CHANGER_PRESET voiceChanger);

  int setLocalVoiceReverbPreset(rtc::AUDIO_REVERB_PRESET reverbPreset);

  int setExternalAudioSource(bool enabled, int sampleRate, int channels);

  int setExternalAudioSink(bool enabled, int sampleRate, int channels);

  int setRecordingAudioFrameParameters(int sampleRate, int channel,
                                       rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
                                       int samplesPerCall);

  int setPlaybackAudioFrameParameters(int sampleRate, int channel,
                                      rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
                                      int samplesPerCall);

  int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);

  int registerMediaMetadataObserver(rtc::IMetadataObserver *observer,
                                    rtc::IMetadataObserver::METADATA_TYPE type,
                                    bool useSdkDefault = true);

  int sendMetadata(rtc::IMetadataObserver::Metadata *metadata);

  int setMaxMetadataSize(int size);

  int pushAudioFrame(media::MEDIA_SOURCE_TYPE type,
                     media::IAudioFrameObserver::AudioFrame *frame, bool wrap);

  int pushAudioFrame(media::IAudioFrameObserver::AudioFrame *frame);

  int pullAudioFrame(media::IAudioFrameObserver::AudioFrame *frame);

  int setExternalVideoSource(bool enable, bool useTexture);

  int pushVideoFrame(media::ExternalVideoFrame *frame);

  int enableEncryption(bool enabled,
                       const agora::rtc::EncryptionConfig &config);

  int sendCustomReportMessage(const char *id, const char *category,
                              const char *event, const char *label, int value);

  int registerVideoFrameObserver(
      media::IVideoFrameObserver *videoFrameObserver);
};

CROSS_PLATFORM_EXPORT IRtcEngineBridge *createRtcEngineBridge();
} // namespace common
} // namespace agora
