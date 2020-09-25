//
// Created by 张涛 on 2020-08-18.
//

#include "cross_platform_c_api_wrapper.h"
#include "../deviceManager/IAudioDeviceManagerBridge.h"
#include "../deviceManager/IVideoDeviceManagerBridge.h"
#include "../deviceManager/audioDeviceManager/AudioPlaybackDeviceManager.h"
#include "../deviceManager/audioDeviceManager/AudioRecordingDeviceManager.h"
#include "../deviceManager/videoDeviceManager/VideoDeviceManager.h"
#include "../rtcChannel/RtcChannelBridge.h"
#include "../rtcEngine/RtcEngineBridge.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RtcEngineBridge_ptr static_cast<agora::common::RtcEngineBridge*>(apiBridge)
#define RtcChannelBridge_ptr static_cast<agora::common::RtcChannelBridge*>(apiBridge)
#define AudioPlaybackDeviceManagerBridge_ptr static_cast<agora::common::AudioPlaybackDeviceManager*>(apiBridge)
#define AudioRecordingDeviceManagerBridge_ptr static_cast<agora::common::AudioRecordingDeviceManager*>(apiBridge)
#define VideoDeviceManagerBridge_ptr static_cast<agora::common::VideoDeviceManager*>(apiBridge)

IRtcEngineBridge_ptr
createRtcBridge()
{
    return new agora::common::RtcEngineBridge();
}

void release(IRtcEngineBridge_ptr apiBridge, BOOL sync)
{
    RtcEngineBridge_ptr->release(sync);
    apiBridge = NULL;
}

IRtcChannelBridge_ptr
createChannel(IRtcEngineBridge_ptr apiBridge, const char* channelId)
{
    return RtcEngineBridge_ptr->createChannel(channelId);
}

void releaseChannel(IRtcChannelBridge_ptr apiBridge)
{
    RtcChannelBridge_ptr->release();
    apiBridge = NULL;
}

IAudioPlaybackDeviceManager_ptr
createAudioPlaybackDeviceManager(IRtcEngineBridge_ptr apiBridge)
{
    agora::common::ERROR_CODE error_code;
    return RtcEngineBridge_ptr->createAudioDeviceManager(agora::common::DEVICE_TYPE::PLAYBACK_DEVICE, error_code);
}

void releaseAudioPlaybackDeviceManager(IAudioPlaybackDeviceManager_ptr apiBridge)
{
    AudioPlaybackDeviceManagerBridge_ptr->release();
    apiBridge = NULL;
}

IAudioRecordingDeviceManager_ptr
createAudioRecordingDeviceManager(IRtcEngineBridge_ptr apiBridge)
{
    agora::common::ERROR_CODE error_code;
    return RtcEngineBridge_ptr->createAudioDeviceManager(agora::common::DEVICE_TYPE::RECORDING_DEVICE, error_code);
}

void releaseAudioRecordingDeviceManager(IAudioRecordingDeviceManager_ptr apiBridge)
{
    AudioRecordingDeviceManagerBridge_ptr->release();
    apiBridge = NULL;
}

IVideoDeviceManager_ptr
createVideoDeviceManager(IRtcEngineBridge_ptr apiBridge)
{
    agora::common::ERROR_CODE error_code;
    return RtcEngineBridge_ptr->createVideoDeviceManager(error_code);
}

void releaseVideoDeviceManager(IVideoDeviceManager_ptr apiBridge)
{
    VideoDeviceManagerBridge_ptr->release();
    apiBridge = NULL;
}

enum ERROR_CODE
initialize(IRtcEngineBridge_ptr apiBridge, const char* appId, void* context, enum AREA_CODE areaCode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->initialize(appId, context, areaCode));
}

extern void
add_C_EventHandler(IRtcChannelBridge_ptr apiBridge, struct RtcEventHandler* handler)
{
    agora::common::CEngineEventHandler _engineEventHandler;
    _engineEventHandler.onJoinChannelSuccess = handler->onJoinChannelSuccess;
    _engineEventHandler.onReJoinChannelSuccess = handler->onReJoinChannelSuccess;
    _engineEventHandler.onConnectionLost = handler->onConnectionLost;
    _engineEventHandler.onLeaveChannel = handler->onLeaveChannel;
    _engineEventHandler.onConnectionInterrupted = handler->onConnectionInterrupted;
    _engineEventHandler.onRequestToken = handler->onRequestToken;
    _engineEventHandler.onUserJoined = handler->onUserJoined;
    _engineEventHandler.onUserOffline = handler->onUserOffline;
    _engineEventHandler.onAudioVolumeIndication = handler->onAudioVolumeIndication;
    _engineEventHandler.onUserMuteAudio = handler->onUserMuteAudio;
    _engineEventHandler.onWarning = handler->onWarning;
    _engineEventHandler.onError = handler->onError;
    _engineEventHandler.onRtcStats = handler->onRtcStats;
    _engineEventHandler.onAudioMixingFinished = handler->onAudioMixingFinished;
    _engineEventHandler.onAudioRouteChanged = handler->onAudioRouteChanged;
    _engineEventHandler.onFirstRemoteVideoDecoded = handler->onFirstRemoteVideoDecoded;
    _engineEventHandler.onVideoSizeChanged = handler->onVideoSizeChanged;
    _engineEventHandler.onClientRoleChanged = handler->onClientRoleChanged;
    _engineEventHandler.onUserMuteVideo = handler->onUserMuteVideo;
    _engineEventHandler.onMicrophoneEnabled = handler->onMicrophoneEnabled;
    _engineEventHandler.onApiCallExecuted = handler->onApiCallExecuted;
    _engineEventHandler.onFirstLocalAudioFrame = handler->onFirstLocalAudioFrame;
    _engineEventHandler.onFirstRemoteAudioFrame = handler->onFirstRemoteAudioFrame;
    _engineEventHandler.onLastmileQuality = handler->onLastmileQuality;
    _engineEventHandler.onAudioQuality = handler->onAudioQuality;
    _engineEventHandler.onStreamInjectedStatus = handler->onStreamInjectedStatus;
    _engineEventHandler.onStreamUnpublished = handler->onStreamUnpublished;
    _engineEventHandler.onStreamPublished = handler->onStreamPublished;
    _engineEventHandler.onStreamMessageError = handler->onStreamMessageError;
    _engineEventHandler.onStreamMessage = handler->onStreamMessage;
    _engineEventHandler.onConnectionBanned = handler->onConnectionBanned;
    _engineEventHandler.onVideoStopped = handler->onVideoStopped;
    _engineEventHandler.onTokenPrivilegeWillExpire = handler->onTokenPrivilegeWillExpire;
    _engineEventHandler.onNetworkQuality = handler->onNetworkQuality;
    _engineEventHandler.onLocalVideoStats = handler->onLocalVideoStats;
    _engineEventHandler.onRemoteVideoStats = handler->onRemoteVideoStats;
    _engineEventHandler.onRemoteAudioStats = handler->onRemoteAudioStats;
    _engineEventHandler.onFirstLocalVideoFrame = handler->onFirstLocalVideoFrame;
    _engineEventHandler.onFirstRemoteVideoFrame = handler->onFirstRemoteVideoFrame;
    _engineEventHandler.onUserEnableVideo = handler->onUserEnableVideo;
    _engineEventHandler.onAudioDeviceStateChanged = handler->onAudioDeviceStateChanged;
    _engineEventHandler.onCameraReady = handler->onCameraReady;
    _engineEventHandler.onCameraFocusAreaChanged = handler->onCameraFocusAreaChanged;
    _engineEventHandler.onCameraExposureAreaChanged = handler->onCameraExposureAreaChanged;
    _engineEventHandler.onRemoteAudioMixingBegin = handler->onRemoteAudioMixingBegin;
    _engineEventHandler.onRemoteAudioMixingEnd = handler->onRemoteAudioMixingEnd;
    _engineEventHandler.onAudioEffectFinished = handler->onAudioEffectFinished;
    _engineEventHandler.onVideoDeviceStateChanged = handler->onVideoDeviceStateChanged;
    _engineEventHandler.onRemoteVideoStateChanged = handler->onRemoteVideoStateChanged;
    _engineEventHandler.onUserEnableLocalVideo = handler->onUserEnableLocalVideo;
    _engineEventHandler.onLocalPublishFallbackToAudioOnly = handler->onLocalPublishFallbackToAudioOnly;
    _engineEventHandler.onRemoteSubscribeFallbackToAudioOnly = handler->onRemoteSubscribeFallbackToAudioOnly;
    _engineEventHandler.onConnectionStateChanged = handler->onConnectionStateChanged;
    _engineEventHandler.onRemoteVideoTransportStats = handler->onRemoteVideoTransportStats;
    _engineEventHandler.onRemoteAudioTransportStats = handler->onRemoteAudioTransportStats;
    _engineEventHandler.onTranscodingUpdated = handler->onTranscodingUpdated;
    _engineEventHandler.onAudioDeviceVolumeChanged = handler->onAudioDeviceVolumeChanged;
    _engineEventHandler.onActiveSpeaker = handler->onActiveSpeaker;
    _engineEventHandler.onMediaEngineStartCallSuccess = handler->onMediaEngineStartCallSuccess;
    _engineEventHandler.onMediaEngineLoadSuccess = handler->onMediaEngineLoadSuccess;
    _engineEventHandler.onAudioMixingStateChanged = handler->onAudioMixingStateChanged;
    _engineEventHandler.onFirstRemoteAudioDecoded = handler->onFirstRemoteAudioDecoded;
    _engineEventHandler.onLocalVideoStateChanged = handler->onLocalVideoStateChanged;
    _engineEventHandler.onRtmpStreamingStateChanged = handler->onRtmpStreamingStateChanged;
    _engineEventHandler.onNetworkTypeChanged = handler->onNetworkTypeChanged;
    _engineEventHandler.onLastmileProbeResult = handler->onLastmileProbeResult;
    _engineEventHandler.onLocalUserRegistered = handler->onLocalUserRegistered;
    _engineEventHandler.onUserInfoUpdated = handler->onUserInfoUpdated;
    _engineEventHandler.onLocalAudioStateChanged = handler->onLocalAudioStateChanged;
    _engineEventHandler.onRemoteAudioStateChanged = handler->onRemoteAudioStateChanged;
    _engineEventHandler.onLocalAudioStats = handler->onLocalAudioStats;
    _engineEventHandler.onChannelMediaRelayStateChanged = handler->onChannelMediaRelayStateChanged;
    _engineEventHandler.onChannelMediaRelayEvent = handler->onChannelMediaRelayEvent;
    _engineEventHandler.onFacePositionChanged = handler->onFacePositionChanged;
    RtcEngineBridge_ptr->add_C_EventHandler(&_engineEventHandler);
}

extern void
remove_C_EventHandler(IRtcChannelBridge_ptr apiBridge)
{
    RtcEngineBridge_ptr->remove_C_EventHandler();
}

enum ERROR_CODE
setChannelProfile(IRtcEngineBridge_ptr apiBridge, enum CHANNEL_PROFILE_TYPE channel_profile_type)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setChannelProfile(agora::rtc::CHANNEL_PROFILE_TYPE(channel_profile_type)));
}

enum ERROR_CODE
setClientRole(IRtcEngineBridge_ptr apiBridge, enum CLIENT_ROLE_TYPE role)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setClientRole(agora::rtc::CLIENT_ROLE_TYPE(role)));
}

enum ERROR_CODE
joinChannel(IRtcEngineBridge_ptr apiBridge, const char* token, const char* channelId, const char* info, uid_t uid)
{
    return ERROR_CODE(RtcEngineBridge_ptr->joinChannel(token, channelId, info, uid));
}

enum ERROR_CODE
switchChannel(IRtcEngineBridge_ptr apiBridge, const char* token, const char* channelId)
{
    return ERROR_CODE(RtcEngineBridge_ptr->switchChannel(token, channelId));
}

enum ERROR_CODE
leaveChannel(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->leaveChannel());
}

enum ERROR_CODE
renewToken(IRtcEngineBridge_ptr apiBridge, const char* token)
{
    return ERROR_CODE(RtcEngineBridge_ptr->renewToken(token));
}

enum ERROR_CODE
registerLocalUserAccount(IRtcEngineBridge_ptr apiBridge, const char* appId, const char* userAccount)
{
    return ERROR_CODE(RtcEngineBridge_ptr->registerLocalUserAccount(appId, userAccount));
}

enum ERROR_CODE
joinChannelWithUserAccount(IRtcEngineBridge_ptr apiBridge, const char* token,
    const char* channelId,
    const char* userAccount)
{
    return ERROR_CODE(RtcEngineBridge_ptr->joinChannelWithUserAccount(token, channelId, userAccount));
}

enum ERROR_CODE
getUserInfoByUserAccount(IRtcEngineBridge_ptr apiBridge, const char* userAccount, struct UserInfo* userInfo)
{
    agora::rtc::UserInfo info;
    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->getUserInfoByUserAccount(userAccount, &info));
    (*userInfo).uid = info.uid;
    memcpy((*userInfo).userAccount, info.userAccount, MAX_USER_ACCOUNT_LENGTH);

    return error_code;
}

enum ERROR_CODE
getUserInfoByUid(IRtcEngineBridge_ptr apiBridge, uid_t uid, struct UserInfo* userInfo)
{
    agora::rtc::UserInfo info;
    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->getUserInfoByUid(uid, &info));
    (*userInfo).uid = info.uid;
    memcpy((*userInfo).userAccount, info.userAccount, MAX_USER_ACCOUNT_LENGTH);

    return error_code;
}

enum ERROR_CODE
startEchoTest(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startEchoTest());
}

enum ERROR_CODE
startEchoTest2(IRtcEngineBridge_ptr apiBridge, int intervalInSeconds)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startEchoTest(intervalInSeconds));
}

enum ERROR_CODE
stopEchoTest(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopEchoTest());
}

enum ERROR_CODE
enableVideo(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableVideo());
}

enum ERROR_CODE
disableVideo(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->disableVideo());
}

enum ERROR_CODE
setVideoProfile(IRtcEngineBridge_ptr apiBridge, enum VIDEO_PROFILE_TYPE profile, BOOL swapWidthAndHeight)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setVideoProfile(agora::rtc::VIDEO_PROFILE_TYPE(profile), swapWidthAndHeight));
}

enum ERROR_CODE
setVideoEncoderConfiguration(IRtcEngineBridge_ptr apiBridge, const struct VideoEncoderConfiguration config)
{
    agora::rtc::VideoEncoderConfiguration videoEncoderConfiguration;
    videoEncoderConfiguration.dimensions = agora::rtc::VideoDimensions(config.dimensions.width, config.dimensions.height);
    videoEncoderConfiguration.frameRate = agora::rtc::FRAME_RATE(config.frameRate);
    videoEncoderConfiguration.minFrameRate = config.minFrameRate;
    videoEncoderConfiguration.bitrate = config.bitrate;
    videoEncoderConfiguration.minBitrate = config.minBitrate;
    videoEncoderConfiguration.orientationMode = agora::rtc::ORIENTATION_MODE(config.orientationMode);
    videoEncoderConfiguration.degradationPreference = agora::rtc::DEGRADATION_PREFERENCE(config.degradationPreference);
    videoEncoderConfiguration.mirrorMode = agora::rtc::VIDEO_MIRROR_MODE_TYPE(config.mirrorMode);
    return ERROR_CODE(RtcEngineBridge_ptr->setVideoEncoderConfiguration(videoEncoderConfiguration));
}

enum ERROR_CODE
setCameraCapturerConfiguration(IRtcEngineBridge_ptr apiBridge, const struct CameraCapturerConfiguration config)
{
    agora::rtc::CameraCapturerConfiguration cameraCapturerConfiguration;
    cameraCapturerConfiguration.preference = agora::rtc::CAPTURER_OUTPUT_PREFERENCE(config.preference);
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    cameraCapturerConfiguration.cameraDirection = agora::rtc::CAMERA_DIRECTION(config.cameraDirection);
#endif
    return ERROR_CODE(RtcEngineBridge_ptr->setCameraCapturerConfiguration(cameraCapturerConfiguration));
}

enum ERROR_CODE
setupLocalVideo(IRtcEngineBridge_ptr apiBridge, const struct VideoCanvas canvas)
{
    agora::rtc::VideoCanvas videoCanvas;
    videoCanvas.view = canvas.view;
    videoCanvas.renderMode = canvas.renderMode;
    memcpy(videoCanvas.channelId, canvas.channelId, MAX_CHANNEL_ID_LENGTH);
    videoCanvas.uid = canvas.uid;
    videoCanvas.priv = canvas.priv;
    videoCanvas.mirrorMode = agora::rtc::VIDEO_MIRROR_MODE_TYPE(canvas.mirrorMode);
    return ERROR_CODE(RtcEngineBridge_ptr->setupLocalVideo(videoCanvas));
}

enum ERROR_CODE
setupRemoteVideo(IRtcEngineBridge_ptr apiBridge, const struct VideoCanvas canvas)
{
    agora::rtc::VideoCanvas videoCanvas;
    videoCanvas.view = canvas.view;
    videoCanvas.renderMode = canvas.renderMode;
    memcpy(videoCanvas.channelId, canvas.channelId, MAX_CHANNEL_ID_LENGTH);
    videoCanvas.uid = canvas.uid;
    videoCanvas.priv = canvas.priv;
    videoCanvas.mirrorMode = agora::rtc::VIDEO_MIRROR_MODE_TYPE(canvas.mirrorMode);
    return ERROR_CODE(RtcEngineBridge_ptr->setupRemoteVideo(videoCanvas));
}

enum ERROR_CODE
startPreview(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startPreview());
}

enum ERROR_CODE
setRemoteUserPriority(IRtcEngineBridge_ptr apiBridge, uid_t uid, enum PRIORITY_TYPE userPriority)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteUserPriority(uid, agora::rtc::PRIORITY_TYPE(userPriority)));
}

enum ERROR_CODE
stopPreview(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopPreview());
}

enum ERROR_CODE
enableAudio(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableAudio());
}

enum ERROR_CODE
enableLocalAudio(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableLocalAudio(enabled));
}

enum ERROR_CODE
disableAudio(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->disableAudio());
}

enum ERROR_CODE
setAudioProfile(IRtcEngineBridge_ptr apiBridge, enum AUDIO_PROFILE_TYPE profile,
    enum AUDIO_SCENARIO_TYPE scenario)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setAudioProfile(agora::rtc::AUDIO_PROFILE_TYPE(profile), agora::rtc::AUDIO_SCENARIO_TYPE(scenario)));
}

enum ERROR_CODE
muteLocalAudioStream(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteLocalAudioStream(mute));
}

enum ERROR_CODE
muteAllRemoteAudioStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteAllRemoteAudioStreams(mute));
}

enum ERROR_CODE
setDefaultMuteAllRemoteVideoStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setDefaultMuteAllRemoteVideoStreams(mute));
}

enum ERROR_CODE
adjustUserPlaybackSignalVolume(IRtcEngineBridge_ptr apiBridge, uid_t uid, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustUserPlaybackSignalVolume(uid, volume));
}

enum ERROR_CODE
muteRemoteAudioStream(IRtcEngineBridge_ptr apiBridge, uid_t userId, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteRemoteAudioStream(userId, mute));
}

enum ERROR_CODE
muteLocalVideoStream(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteLocalVideoStream(mute));
}

enum ERROR_CODE
enableLocalVideo(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableLocalVideo(enabled));
}

enum ERROR_CODE
muteAllRemoteVideoStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteAllRemoteVideoStreams(mute));
}

enum ERROR_CODE
setDefaultMuteAllRemoteAudioStreams(IRtcEngineBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setDefaultMuteAllRemoteAudioStreams(mute));
}

enum ERROR_CODE
muteRemoteVideoStream(IRtcEngineBridge_ptr apiBridge, uid_t userId, BOOL mute)
{
    return ERROR_CODE(RtcEngineBridge_ptr->muteRemoteVideoStream(userId, mute));
}

enum ERROR_CODE
setRemoteVideoStreamType(IRtcEngineBridge_ptr apiBridge, uid_t userId, enum REMOTE_VIDEO_STREAM_TYPE streamType)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteVideoStreamType(userId, agora::rtc::REMOTE_VIDEO_STREAM_TYPE(streamType)));
}

enum ERROR_CODE
setRemoteDefaultVideoStreamType(IRtcEngineBridge_ptr apiBridge, enum REMOTE_VIDEO_STREAM_TYPE streamType)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteDefaultVideoStreamType(agora::rtc::REMOTE_VIDEO_STREAM_TYPE(streamType)));
}

enum ERROR_CODE
enableAudioVolumeIndication(IRtcEngineBridge_ptr apiBridge, int interval, int smooth, BOOL report_vad)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableAudioVolumeIndication(interval, smooth, report_vad));
}

enum ERROR_CODE
startAudioRecording(IRtcEngineBridge_ptr apiBridge, const char* filePath,
    enum AUDIO_RECORDING_QUALITY_TYPE quality)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startAudioRecording(filePath, agora::rtc::AUDIO_RECORDING_QUALITY_TYPE(quality)));
}

enum ERROR_CODE
startAudioRecording2(IRtcEngineBridge_ptr apiBridge, const char* filePath,
    int sampleRate,
    enum AUDIO_RECORDING_QUALITY_TYPE quality)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startAudioRecording(filePath, sampleRate, agora::rtc::AUDIO_RECORDING_QUALITY_TYPE(quality)));
}

enum ERROR_CODE
stopAudioRecording(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopAudioRecording());
}

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
enum ERROR_CODE
enableFaceDetection(IRtcEngineBridge_ptr apiBridge, BOOL enable)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableFaceDetection(enable));
}
#endif

enum ERROR_CODE
setRemoteVoicePosition(IRtcEngineBridge_ptr apiBridge, uid_t uid, double pan, double gain)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteVoicePosition(uid, pan, gain));
}

enum ERROR_CODE
setLogFile(IRtcEngineBridge_ptr apiBridge, const char* file)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLogFile(file));
}

enum ERROR_CODE
setLogFilter(IRtcEngineBridge_ptr apiBridge, unsigned int filter)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLogFilter(filter));
}

enum ERROR_CODE
setLogFileSize(IRtcEngineBridge_ptr apiBridge, unsigned int fileSizeInKBytes)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLogFileSize(fileSizeInKBytes));
}

enum ERROR_CODE
setLocalRenderMode(IRtcEngineBridge_ptr apiBridge, enum RENDER_MODE_TYPE renderMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalRenderMode(agora::rtc::RENDER_MODE_TYPE(renderMode)));
}

enum ERROR_CODE
setLocalRenderMode2(IRtcEngineBridge_ptr apiBridge, enum RENDER_MODE_TYPE renderMode,
    enum VIDEO_MIRROR_MODE_TYPE mirrorMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalRenderMode(agora::rtc::RENDER_MODE_TYPE(renderMode), agora::rtc::VIDEO_MIRROR_MODE_TYPE(mirrorMode)));
}

enum ERROR_CODE
setRemoteRenderMode(IRtcEngineBridge_ptr apiBridge, uid_t userId, enum RENDER_MODE_TYPE renderMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteRenderMode(userId, agora::rtc::RENDER_MODE_TYPE(renderMode)));
}

enum ERROR_CODE
setRemoteRenderMode2(IRtcEngineBridge_ptr apiBridge, uid_t userId,
    enum RENDER_MODE_TYPE renderMode,
    enum VIDEO_MIRROR_MODE_TYPE mirrorMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteRenderMode(userId, agora::rtc::RENDER_MODE_TYPE(renderMode), agora::rtc::VIDEO_MIRROR_MODE_TYPE(mirrorMode)));
}

enum ERROR_CODE
setLocalVideoMirrorMode(IRtcEngineBridge_ptr apiBridge, enum VIDEO_MIRROR_MODE_TYPE mirrorMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVideoMirrorMode(agora::rtc::VIDEO_MIRROR_MODE_TYPE(mirrorMode)));
}

enum ERROR_CODE
enableDualStreamMode(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableDualStreamMode(enabled));
}

enum ERROR_CODE
adjustRecordingSignalVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustRecordingSignalVolume(volume));
}

enum ERROR_CODE
adjustPlaybackSignalVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustPlaybackSignalVolume(volume));
}

enum ERROR_CODE
enableWebSdkInteroperability(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableWebSdkInteroperability(enabled));
}

enum ERROR_CODE
setVideoQualityParameters(IRtcEngineBridge_ptr apiBridge, BOOL preferFrameRateOverImageQuality)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setVideoQualityParameters(preferFrameRateOverImageQuality));
}

enum ERROR_CODE
setLocalPublishFallbackOption(IRtcEngineBridge_ptr apiBridge, enum STREAM_FALLBACK_OPTIONS option)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalPublishFallbackOption(agora::rtc::STREAM_FALLBACK_OPTIONS(option)));
}

enum ERROR_CODE
setRemoteSubscribeFallbackOption(IRtcEngineBridge_ptr apiBridge, enum STREAM_FALLBACK_OPTIONS option)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRemoteSubscribeFallbackOption(agora::rtc::STREAM_FALLBACK_OPTIONS(option)));
}

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
enum ERROR_CODE
switchCamera(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->switchCamera());
}

enum ERROR_CODE
switchCamera2(IRtcEngineBridge_ptr apiBridge, enum CAMERA_DIRECTION direction)
{
    return ERROR_CODE(RtcEngineBridge_ptr->switchCamera(agora::rtc::CAMERA_DIRECTION(direction)));
}

enum ERROR_CODE
setDefaultAudioRouteToSpeakerphone(IRtcEngineBridge_ptr apiBridge, BOOL defaultToSpeaker)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker));
}

enum ERROR_CODE
setEnableSpeakerphone(IRtcEngineBridge_ptr apiBridge, BOOL speakerOn)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setEnableSpeakerphone(speakerOn));
}

enum ERROR_CODE
enableInEarMonitoring(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableInEarMonitoring(enabled));
}

enum ERROR_CODE
setInEarMonitoringVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setInEarMonitoringVolume(volume));
}

BOOL isSpeakerphoneEnabled(IRtcEngineBridge_ptr apiBridge)
{
    return RtcEngineBridge_ptr->isSpeakerphoneEnabled();
}
#endif

#if (defined(__APPLE__) && TARGET_OS_IOS)
enum ERROR_CODE
setAudioSessionOperationRestriction(IRtcEngineBridge_ptr apiBridge, enum AUDIO_SESSION_OPERATION_RESTRICTION restriction)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setAudioSessionOperationRestriction(agora::rtc::AUDIO_SESSION_OPERATION_RESTRICTION(restriction)));
}
#endif

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) || defined(_WIN32)
enum ERROR_CODE
enableLoopbackRecording(IRtcEngineBridge_ptr apiBridge, BOOL enabled, const char* deviceName)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableLoopbackRecording(enabled, deviceName));
}

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
enum ERROR_CODE
startScreenCaptureByDisplayId(IRtcEngineBridge_ptr apiBridge, unsigned int displayId,
    const struct Rectangle* regionRect,
    const struct ScreenCaptureParameters* captureParams)
{
    agora::rtc::Rectangle region;
    region.height = regionRect->height;
    region.width = regionRect->width;
    region.x = regionRect->x;
    region.y = regionRect->y;

    agora::rtc::ScreenCaptureParameters screenCaptureParameters;
    screenCaptureParameters.bitrate = captureParams->bitrate;
    screenCaptureParameters.frameRate = captureParams->frameRate;
    screenCaptureParameters.dimensions.width = captureParams->dimensions.width;
    screenCaptureParameters.dimensions.height = captureParams->dimensions.height;
    screenCaptureParameters.windowFocus = captureParams->windowFocus;
    screenCaptureParameters.excludeWindowCount = captureParams->excludeWindowCount;

    void** windowList = NULL;

    if (captureParams->excludeWindowCount > 0) {
        windowList = new void*[captureParams->excludeWindowCount];
        for (int i = 0; i < captureParams->excludeWindowCount; i++) {
            windowList[i] = captureParams->excludeWindowList[i];
        }
        screenCaptureParameters.excludeWindowList = windowList;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->startScreenCaptureByDisplayId(displayId, region, screenCaptureParameters));

    delete[] windowList;

    return error_code;
}
#endif

#if defined(_WIN32)
enum ERROR_CODE
startScreenCaptureByScreenRect(IRtcEngineBridge_ptr apiBridge, const struct Rectangle* screenRect,
    const struct Rectangle* regionRect,
    const struct ScreenCaptureParameters* captureParams)
{
    agora::rtc::Rectangle screen;
    screen.height = screenRect->height;
    screen.width = screenRect->width;
    screen.x = screenRect->x;
    screen.y = screenRect->y;

    agora::rtc::Rectangle region;
    region.height = regionRect->height;
    region.width = regionRect->width;
    region.x = regionRect->x;
    region.y = regionRect->y;

    agora::rtc::ScreenCaptureParameters screenCaptureParameters;
    screenCaptureParameters.bitrate = captureParams->bitrate;
    screenCaptureParameters.frameRate = captureParams->frameRate;
    screenCaptureParameters.dimensions.width = captureParams->dimensions.width;
    screenCaptureParameters.dimensions.height = captureParams->dimensions.height;
    screenCaptureParameters.windowFocus = captureParams->windowFocus;
    screenCaptureParameters.excludeWindowCount = captureParams->excludeWindowCount;

    void** windowList = NULL;

    if (captureParams->excludeWindowCount > 0) {
        windowList = new void*[captureParams->excludeWindowList];
        for (int i = 0; i < captureParams->excludeWindowCount; i++) {
            windowList[i] = captureParams->excludeWindowList[i];
        }
        screenCaptureParameters.excludeWindowList = windowList;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->startScreenCaptureByScreenRect(screen, region, screenCaptureParameters));

    delete[] windowList;
    return error_code;
}

enum ERROR_CODE
startScreenCaptureByWindowId(IRtcEngineBridge_ptr apiBridge, view_t windowId,
    const struct Rectangle* regionRect,
    const struct ScreenCaptureParameters* captureParams)
{
    agora::rtc::Rectangle region;
    region.height = regionRect->height;
    region.width = regionRect->width;
    region.x = regionRect->x;
    region.y = regionRect->y;

    agora::rtc::ScreenCaptureParameters screenCaptureParameters;
    screenCaptureParameters.bitrate = captureParams->bitrate;
    screenCaptureParameters.frameRate = captureParams->frameRate;
    screenCaptureParameters.dimensions.width = captureParams->dimensions.width;
    screenCaptureParameters.dimensions.height = captureParams->dimensions.height;
    screenCaptureParameters.windowFocus = captureParams->windowFocus;
    screenCaptureParameters.excludeWindowCount = captureParams->excludeWindowCount;

    void** windowList = NULL;

    if (captureParams->excludeWindowCount > 0) {
        windowList = new void*[captureParams->excludeWindowList];
        for (int i = 0; i < captureParams->excludeWindowCount; i++) {
            windowList[i] = captureParams->excludeWindowList[i];
        }
        screenCaptureParameters.excludeWindowList = windowList;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->startScreenCaptureByWindowId(windowId, region, screenCaptureParameters));

    delete[] windowList;
    return error_code;
}

enum ERROR_CODE
setScreenCaptureContentHint(IRtcEngineBridge_ptr apiBridge, enum VideoContentHint contentHint)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setScreenCaptureContentHint(agora::rtc::VideoContentHint(contentHint)));
}

enum ERROR_CODE
updateScreenCaptureParameters(IRtcEngineBridge_ptr apiBridge, struct ScreenCaptureParameters* captureParams)
{
    agora::rtc::ScreenCaptureParameters screenCaptureParameters;
    screenCaptureParameters.bitrate = captureParams->bitrate;
    screenCaptureParameters.frameRate = captureParams->frameRate;
    screenCaptureParameters.dimensions.width = captureParams->dimensions.width;
    screenCaptureParameters.dimensions.height = captureParams->dimensions.height;
    screenCaptureParameters.windowFocus = captureParams->windowFocus;
    screenCaptureParameters.excludeWindowCount = captureParams->excludeWindowCount;

    void** windowList = NULL;

    if (captureParams->excludeWindowCount > 0) {
        windowList = new void*[captureParams->excludeWindowList];
        for (int i = 0; i < captureParams->excludeWindowCount; i++) {
            windowList[i] = captureParams->excludeWindowList[i];
        }
        screenCaptureParameters.excludeWindowList = windowList;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->updateScreenCaptureParameters(screenCaptureParameters));

    delete[] windowList;
    return error_code;
}

enum ERROR_CODE
updateScreenCaptureRegion(IRtcEngineBridge_ptr apiBridge, struct Rectangle* regionRect)
{
    agora::rtc::Rectangle region;
    region.height = regionRect->height;
    region.width = regionRect->width;
    region.x = regionRect->x;
    region.y = regionRect->y;
    return ERROR_CODE(RtcEngineBridge_ptr->updateScreenCaptureRegion(region));
}

enum ERROR_CODE
updateScreenCaptureRegion(IRtcEngineBridge_ptr apiBridge, struct Rect* rect)
{
    Rect mRect;
    mRect.bottom = rect->bottom;
    mRect.left = rect->left;
    mRect.right = rect->right;
    mRect.top = rect->top;
    return ERROR_CODE(RtcEngineBridge_ptr->updateScreenCaptureRegion(mRect));
}
#endif

enum ERROR_CODE
stopScreenCapture(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopScreenCapture());
}
#endif

const char*
getCallId(IRtcEngineBridge_ptr apiBridge)
{
    agora::util::AString sCallId;
    RtcEngineBridge_ptr->getCallId(sCallId);
    return sCallId->data();
}

enum ERROR_CODE
rate(IRtcEngineBridge_ptr apiBridge, const char* callId, int rating, const char* description)
{
    return ERROR_CODE(RtcEngineBridge_ptr->rate(callId, rating, description));
}

enum ERROR_CODE
complain(IRtcEngineBridge_ptr apiBridge, const char* callId, const char* description)
{
    return ERROR_CODE(RtcEngineBridge_ptr->complain(callId, description));
}

const char*
getVersion(IRtcEngineBridge_ptr apiBridge)
{
    return RtcEngineBridge_ptr->getVersion();
}

enum ERROR_CODE
enableLastmileTest(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableLastmileTest());
}

enum ERROR_CODE
disableLastmileTest(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->disableLastmileTest());
}

enum ERROR_CODE
startLastmileProbeTest(IRtcEngineBridge_ptr apiBridge, const struct LastmileProbeConfig config)
{
    agora::rtc::LastmileProbeConfig lastmileProbeConfig;
    lastmileProbeConfig.probeUplink = config.probeUplink;
    lastmileProbeConfig.probeDownlink = config.probeDownlink;
    lastmileProbeConfig.expectedDownlinkBitrate = config.expectedDownlinkBitrate;
    lastmileProbeConfig.expectedUplinkBitrate = config.expectedUplinkBitrate;
    return ERROR_CODE(RtcEngineBridge_ptr->startLastmileProbeTest(lastmileProbeConfig));
}

enum ERROR_CODE
stopLastmileProbeTest(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopLastmileProbeTest());
}

const char*
getErrorDescription(IRtcEngineBridge_ptr apiBridge, int code)
{
    return RtcEngineBridge_ptr->getErrorDescription(code);
}

enum ERROR_CODE
setEncryptionSecret(IRtcEngineBridge_ptr apiBridge, const char* secret)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setEncryptionSecret(secret));
}

enum ERROR_CODE
setEncryptionMode(IRtcEngineBridge_ptr apiBridge, const char* encryptionMode)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setEncryptionMode(encryptionMode));
}

//enum ERROR_CODE
//registerPacketObserver(IRtcEngineBridge_ptr apiBridge,  IPacketObserver* observer);

enum ERROR_CODE
createDataStream(IRtcEngineBridge_ptr apiBridge, int* streamId, BOOL reliable, BOOL ordered)
{
    return ERROR_CODE(RtcEngineBridge_ptr->createDataStream(streamId, reliable, ordered));
}

enum ERROR_CODE
sendStreamMessage(IRtcEngineBridge_ptr apiBridge, int streamId, const char* data, long long length)
{
    return ERROR_CODE(RtcEngineBridge_ptr->sendStreamMessage(streamId, data, (size_t)length));
}

enum ERROR_CODE
addPublishStreamUrl(IRtcEngineBridge_ptr apiBridge, const char* url, BOOL transcodingEnabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->addPublishStreamUrl(url, transcodingEnabled));
}

enum ERROR_CODE
removePublishStreamUrl(IRtcEngineBridge_ptr apiBridge, const char* url)
{
    return ERROR_CODE(RtcEngineBridge_ptr->removePublishStreamUrl(url));
}

enum ERROR_CODE
setLiveTranscoding(IRtcEngineBridge_ptr apiBridge, const struct LiveTranscoding* transcoding)
{
    agora::rtc::LiveTranscoding liveTranscoding;
    liveTranscoding.width = transcoding->width;
    liveTranscoding.height = transcoding->height;
    liveTranscoding.videoBitrate = transcoding->videoBitrate;
    liveTranscoding.videoFramerate = transcoding->videoFramerate;
    liveTranscoding.lowLatency = transcoding->lowLatency;
    liveTranscoding.videoGop = transcoding->videoGop;
    liveTranscoding.videoCodecProfile = agora::rtc::VIDEO_CODEC_PROFILE_TYPE(transcoding->videoCodecProfile);
    liveTranscoding.backgroundColor = transcoding->backgroundColor;
    liveTranscoding.userCount = transcoding->userCount;
    agora::rtc::TranscodingUser* transcodingUser = NULL;

    if (transcoding->userCount > 0) {
        transcodingUser = new agora::rtc::TranscodingUser[transcoding->userCount];
    }

    for (int i = 0; i < transcoding->userCount; i++) {
        transcodingUser[i].uid = transcoding->transcodingUsers[i].uid;
        transcodingUser[i].x = transcoding->transcodingUsers[i].x;
        transcodingUser[i].y = transcoding->transcodingUsers[i].y;
        transcodingUser[i].width = transcoding->transcodingUsers[i].width;
        transcodingUser[i].height = transcoding->transcodingUsers[i].height;
        transcodingUser[i].zOrder = transcoding->transcodingUsers[i].zOrder;
        transcodingUser[i].alpha = transcoding->transcodingUsers[i].alpha;
        transcodingUser[i].audioChannel = transcoding->transcodingUsers[i].audioChannel;
    }

    liveTranscoding.transcodingUsers = transcodingUser;
    liveTranscoding.transcodingExtraInfo = transcoding->transcodingExtraInfo;
    liveTranscoding.metadata = transcoding->metadata;
    agora::rtc::RtcImage watermark;
    if (transcoding->watermark) {
        watermark.height = transcoding->watermark->height;
        watermark.width = transcoding->watermark->width;
        watermark.url = transcoding->watermark->url;
        watermark.x = transcoding->watermark->x;
        watermark.y = transcoding->watermark->y;
    }
    liveTranscoding.watermark = &watermark;

    agora::rtc::RtcImage background;
    if (transcoding->backgroundImage) {
        background.height = transcoding->backgroundImage->height;
        background.width = transcoding->backgroundImage->width;
        background.url = transcoding->backgroundImage->url;
        background.x = transcoding->backgroundImage->x;
        background.y = transcoding->backgroundImage->y;
    }
    liveTranscoding.backgroundImage = &background;
    liveTranscoding.audioSampleRate = agora::rtc::AUDIO_SAMPLE_RATE_TYPE(transcoding->audioSampleRate);
    liveTranscoding.audioBitrate = transcoding->audioBitrate;
    liveTranscoding.audioChannels = transcoding->audioChannels;
    liveTranscoding.audioCodecProfile = agora::rtc::AUDIO_CODEC_PROFILE_TYPE(transcoding->audioCodecProfile);
    liveTranscoding.advancedFeatures = NULL;
    liveTranscoding.advancedFeatureCount = transcoding->advancedFeatureCount;
    if (liveTranscoding.advancedFeatureCount > 0) {
        liveTranscoding.advancedFeatures = new agora::rtc::LiveStreamAdvancedFeature();
        for (int i = 0; i < liveTranscoding.advancedFeatureCount; i++) {
            liveTranscoding.advancedFeatures[i].featureName = transcoding->advancedFeatures[i].featureName;
            liveTranscoding.advancedFeatures[i].LBHQ = transcoding->advancedFeatures[i].LBHQ;
            liveTranscoding.advancedFeatures[i].opened = transcoding->advancedFeatures[i].opened;
            liveTranscoding.advancedFeatures[i].VEO = transcoding->advancedFeatures[i].VEO;
        }
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->setLiveTranscoding(liveTranscoding));
    delete[] liveTranscoding.advancedFeatures;
    liveTranscoding.advancedFeatures = NULL;
    return error_code;
}

enum ERROR_CODE
addVideoWatermark(IRtcEngineBridge_ptr apiBridge, const struct RtcImage watermark)
{
    agora::rtc::RtcImage rtcImage;
    rtcImage.height = watermark.height;
    rtcImage.width = watermark.width;
    rtcImage.url = watermark.url;
    rtcImage.x = watermark.x;
    rtcImage.y = watermark.y;
    return ERROR_CODE(RtcEngineBridge_ptr->addVideoWatermark(rtcImage));
}

enum ERROR_CODE
addVideoWatermark2(IRtcEngineBridge_ptr apiBridge, const char* watermarkUrl, const struct WatermarkOptions options)
{
    agora::rtc::WatermarkOptions watermarkOptions;

    agora::rtc::Rectangle positionInLandscapeMode;
    positionInLandscapeMode.width = options.positionInLandscapeMode.width;
    positionInLandscapeMode.height = options.positionInLandscapeMode.height;
    positionInLandscapeMode.x = options.positionInLandscapeMode.x;
    positionInLandscapeMode.y = options.positionInLandscapeMode.y;

    agora::rtc::Rectangle positionInPortraitMode;
    positionInPortraitMode.width = options.positionInPortraitMode.width;
    positionInPortraitMode.height = options.positionInPortraitMode.height;
    positionInPortraitMode.x = options.positionInPortraitMode.x;
    positionInPortraitMode.y = options.positionInPortraitMode.y;

    watermarkOptions.visibleInPreview = options.visibleInPreview;
    watermarkOptions.positionInLandscapeMode = positionInLandscapeMode;
    watermarkOptions.positionInPortraitMode = positionInPortraitMode;
    return ERROR_CODE(RtcEngineBridge_ptr->addVideoWatermark(watermarkUrl, watermarkOptions));
}

enum ERROR_CODE
clearVideoWatermarks(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->clearVideoWatermarks());
}

enum ERROR_CODE
setBeautyEffectOptions(IRtcEngineBridge_ptr apiBridge, BOOL enabled, struct BeautyOptions options)
{
    agora::rtc::BeautyOptions beautyOptions;
    beautyOptions.lighteningContrastLevel = agora::rtc::BeautyOptions::LIGHTENING_CONTRAST_LEVEL(options.lighteningContrastLevel);
    beautyOptions.lighteningLevel = options.lighteningLevel;
    beautyOptions.rednessLevel = options.rednessLevel;
    beautyOptions.smoothnessLevel = options.smoothnessLevel;
    return ERROR_CODE(RtcEngineBridge_ptr->setBeautyEffectOptions(enabled, beautyOptions));
}

enum ERROR_CODE
addInjectStreamUrl(IRtcEngineBridge_ptr apiBridge, const char* url, struct InjectStreamConfig config)
{
    agora::rtc::InjectStreamConfig injectStreamConfig;
    injectStreamConfig.width = config.width;
    injectStreamConfig.height = config.height;
    injectStreamConfig.videoGop = config.videoGop;
    injectStreamConfig.videoFramerate = config.videoFramerate;
    injectStreamConfig.videoBitrate = config.videoBitrate;
    injectStreamConfig.audioSampleRate = agora::rtc::AUDIO_SAMPLE_RATE_TYPE(config.audioSampleRate);
    injectStreamConfig.audioBitrate = config.audioBitrate;
    injectStreamConfig.audioChannels = config.audioChannels;
    return ERROR_CODE(RtcEngineBridge_ptr->addInjectStreamUrl(url, injectStreamConfig));
}

enum ERROR_CODE
startChannelMediaRelay(IRtcEngineBridge_ptr apiBridge, struct ChannelMediaRelayConfiguration configuration)
{
    agora::rtc::ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    agora::rtc::ChannelMediaInfo srcMediaInfo;
    agora::rtc::ChannelMediaInfo* destMediaInfo = new agora::rtc::ChannelMediaInfo[configuration.destCount];
    channelMediaRelayConfiguration.srcInfo = &srcMediaInfo;
    channelMediaRelayConfiguration.destInfos = destMediaInfo;
    srcMediaInfo.uid = configuration.srcInfo->uid;
    srcMediaInfo.token = configuration.srcInfo->token;
    srcMediaInfo.channelName = configuration.srcInfo->channelName;

    for (int i = 0; i < configuration.destCount; i++) {
        channelMediaRelayConfiguration.destInfos->channelName = configuration.destInfos->channelName;
        channelMediaRelayConfiguration.destInfos->token = configuration.destInfos->token;
        channelMediaRelayConfiguration.destInfos->uid = configuration.destInfos->uid;
        channelMediaRelayConfiguration.destInfos++;
        configuration.destInfos++;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->startChannelMediaRelay(channelMediaRelayConfiguration));

    return error_code;
}

enum ERROR_CODE
updateChannelMediaRelay(IRtcEngineBridge_ptr apiBridge, struct ChannelMediaRelayConfiguration configuration)
{
    agora::rtc::ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    agora::rtc::ChannelMediaInfo srcMediaInfo;
    agora::rtc::ChannelMediaInfo* destMediaInfo = NULL;
    if (configuration.destCount > 0) {
        destMediaInfo = new agora::rtc::ChannelMediaInfo[configuration.destCount];
    }
    channelMediaRelayConfiguration.srcInfo = &srcMediaInfo;
    channelMediaRelayConfiguration.destInfos = destMediaInfo;
    srcMediaInfo.uid = configuration.srcInfo->uid;
    srcMediaInfo.token = configuration.srcInfo->token;
    srcMediaInfo.channelName = configuration.srcInfo->channelName;

    for (int i = 0; i < configuration.destCount; i++) {
        channelMediaRelayConfiguration.destInfos->channelName = configuration.destInfos->channelName;
        channelMediaRelayConfiguration.destInfos->token = configuration.destInfos->token;
        channelMediaRelayConfiguration.destInfos->uid = configuration.destInfos->uid;
        channelMediaRelayConfiguration.destInfos++;
        configuration.destInfos++;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->updateChannelMediaRelay(channelMediaRelayConfiguration));

    delete[] destMediaInfo;
    destMediaInfo = NULL;
    return error_code;
}

enum ERROR_CODE
stopChannelMediaRelay(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopChannelMediaRelay());
}

enum ERROR_CODE
removeInjectStreamUrl(IRtcEngineBridge_ptr apiBridge, const char* url)
{
    return ERROR_CODE(RtcEngineBridge_ptr->removeInjectStreamUrl(url));
}

enum CONNECTION_STATE_TYPE
getConnectionState(IRtcEngineBridge_ptr apiBridge)
{
    return CONNECTION_STATE_TYPE(RtcEngineBridge_ptr->getConnectionState());
}

enum ERROR_CODE
setParameters(IRtcEngineBridge_ptr apiBridge, const char* parameters)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setParameters(parameters));
}

enum ERROR_CODE
setPlaybackDeviceVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setPlaybackDeviceVolume(volume));
}

enum ERROR_CODE
startAudioMixing(IRtcEngineBridge_ptr apiBridge, const char* filePath, BOOL loopback, BOOL replace, int cycle)
{
    return ERROR_CODE(RtcEngineBridge_ptr->startAudioMixing(filePath, loopback, replace, cycle));
}

enum ERROR_CODE
stopAudioMixing(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopAudioMixing());
}

enum ERROR_CODE
pauseAudioMixing(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->pauseAudioMixing());
}

enum ERROR_CODE
resumeAudioMixing(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->resumeAudioMixing());
}

enum ERROR_CODE
setHighQualityAudioParameters(IRtcEngineBridge_ptr apiBridge, BOOL fullband, BOOL stereo, BOOL fullBitrate)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setHighQualityAudioParameters(fullband, stereo, fullBitrate));
}

enum ERROR_CODE
adjustAudioMixingVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustAudioMixingVolume(volume));
}

enum ERROR_CODE
adjustAudioMixingPlayoutVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustAudioMixingPlayoutVolume(volume));
}

enum ERROR_CODE
getAudioMixingPlayoutVolume(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->getAudioMixingPlayoutVolume());
}

enum ERROR_CODE
adjustAudioMixingPublishVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->adjustAudioMixingPublishVolume(volume));
}

enum ERROR_CODE
getAudioMixingPublishVolume(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->getAudioMixingPublishVolume());
}

enum ERROR_CODE
getAudioMixingDuration(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->getAudioMixingDuration());
}

enum ERROR_CODE
getAudioMixingCurrentPosition(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->getAudioMixingCurrentPosition());
}

enum ERROR_CODE
setAudioMixingPosition(IRtcEngineBridge_ptr apiBridge, int pos /*in ms*/)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setAudioMixingPosition(pos));
}

enum ERROR_CODE
setAudioMixingPitch(IRtcEngineBridge_ptr apiBridge, int pitch)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setAudioMixingPitch(pitch));
}

extern int
getEffectsVolume(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->getEffectsVolume());
}

enum ERROR_CODE
setEffectsVolume(IRtcEngineBridge_ptr apiBridge, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setEffectsVolume(volume));
}

enum ERROR_CODE
setVolumeOfEffect(IRtcEngineBridge_ptr apiBridge, int soundId, int volume)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setVolumeOfEffect(soundId, volume));
}

enum ERROR_CODE
playEffect(IRtcEngineBridge_ptr apiBridge, int soundId,
    const char* filePath,
    int loopCount,
    double pitch,
    double pan,
    int gain,
    BOOL publish)
{
    return ERROR_CODE(RtcEngineBridge_ptr->playEffect(soundId, filePath, loopCount, pitch, pan, gain, publish));
}

enum ERROR_CODE
stopEffect(IRtcEngineBridge_ptr apiBridge, int soundId)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopEffect(soundId));
}

enum ERROR_CODE
stopAllEffects(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->stopAllEffects());
}

enum ERROR_CODE
preloadEffect(IRtcEngineBridge_ptr apiBridge, int soundId, const char* filePath)
{
    return ERROR_CODE(RtcEngineBridge_ptr->preloadEffect(soundId, filePath));
}

enum ERROR_CODE
unloadEffect(IRtcEngineBridge_ptr apiBridge, int soundId)
{
    return ERROR_CODE(RtcEngineBridge_ptr->unloadEffect(soundId));
}

enum ERROR_CODE
pauseEffect(IRtcEngineBridge_ptr apiBridge, int soundId)
{
    return ERROR_CODE(RtcEngineBridge_ptr->pauseEffect(soundId));
}

enum ERROR_CODE
pauseAllEffects(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->pauseAllEffects());
}

enum ERROR_CODE
resumeEffect(IRtcEngineBridge_ptr apiBridge, int soundId)
{
    return ERROR_CODE(RtcEngineBridge_ptr->resumeEffect(soundId));
}

enum ERROR_CODE
resumeAllEffects(IRtcEngineBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcEngineBridge_ptr->resumeAllEffects());
}

enum ERROR_CODE
enableSoundPositionIndication(IRtcEngineBridge_ptr apiBridge, BOOL enabled)
{
    return ERROR_CODE(RtcEngineBridge_ptr->enableSoundPositionIndication(enabled));
}

enum ERROR_CODE
setLocalVoicePitch(IRtcEngineBridge_ptr apiBridge, double pitch)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVoicePitch(pitch));
}

enum ERROR_CODE
setLocalVoiceEqualization(IRtcEngineBridge_ptr apiBridge, enum AUDIO_EQUALIZATION_BAND_FREQUENCY bandFrequency, int bandGain)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVoiceEqualization(agora::rtc::AUDIO_EQUALIZATION_BAND_FREQUENCY(bandFrequency), bandGain));
}

enum ERROR_CODE
setLocalVoiceReverb(IRtcEngineBridge_ptr apiBridge, enum AUDIO_REVERB_TYPE reverbKey, int value)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVoiceReverb(agora::rtc::AUDIO_REVERB_TYPE(reverbKey), value));
}

enum ERROR_CODE
setLocalVoiceChanger(IRtcEngineBridge_ptr apiBridge, enum VOICE_CHANGER_PRESET voiceChanger)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVoiceChanger(agora::rtc::VOICE_CHANGER_PRESET(voiceChanger)));
}

enum ERROR_CODE
setLocalVoiceReverbPreset(IRtcEngineBridge_ptr apiBridge, enum AUDIO_REVERB_PRESET reverbPreset)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setLocalVoiceReverbPreset(agora::rtc::AUDIO_REVERB_PRESET(reverbPreset)));
}

enum ERROR_CODE
setExternalAudioSource(IRtcEngineBridge_ptr apiBridge, BOOL enabled, int sampleRate, int channels)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setExternalAudioSource(enabled, sampleRate, channels));
}

enum ERROR_CODE
setExternalAudioSink(IRtcEngineBridge_ptr apiBridge, BOOL enabled, int sampleRate, int channels)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setExternalAudioSink(enabled, sampleRate, channels));
}

enum ERROR_CODE
setRecordingAudioFrameParameters(IRtcEngineBridge_ptr apiBridge, int sampleRate,
    int channel,
    enum RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
    int samplesPerCall)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setRecordingAudioFrameParameters(sampleRate, channel, agora::rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE(mode), samplesPerCall));
}

enum ERROR_CODE
setPlaybackAudioFrameParameters(IRtcEngineBridge_ptr apiBridge, int sampleRate,
    int channel,
    enum RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
    int samplesPerCall)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setPlaybackAudioFrameParameters(sampleRate, channel, agora::rtc::RAW_AUDIO_FRAME_OP_MODE_TYPE(mode), samplesPerCall));
}

enum ERROR_CODE
setMixedAudioFrameParameters(IRtcEngineBridge_ptr apiBridge, int sampleRate, int samplesPerCall)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setMixedAudioFrameParameters(sampleRate, samplesPerCall));
}

//enum ERROR_CODE
//registerMediaMetadataObserver(IRtcEngineBridge_ptr apiBridge, struct IMetadataObserver *observer, rtc::IMetadataObserver::METADATA_TYPE type,  bool useSdkDefault = true);

//enum ERROR_CODE
//sendMetadata(IRtcEngineBridge_ptr apiBridge, struct IMetadataObserver::Metadata *metadata);

//enum ERROR_CODE
//setMaxMetadataSize(IRtcEngineBridge_ptr apiBridge, int size);

enum ERROR_CODE
pushAudioFrame(IRtcEngineBridge_ptr apiBridge, enum MEDIA_SOURCE_TYPE type,
    struct AudioFrame* frame,
    BOOL wrap)
{
    agora::media::IAudioFrameObserver::AudioFrame audioFrame;
    audioFrame.type = agora::media::IAudioFrameObserver::AUDIO_FRAME_TYPE(frame->type);
    audioFrame.samples = frame->samples;
    audioFrame.bytesPerSample = frame->bytesPerSample;
    audioFrame.channels = frame->channels;
    audioFrame.samplesPerSec = frame->samplesPerSec;
    audioFrame.buffer = frame->buffer;
    audioFrame.renderTimeMs = frame->renderTimeMs;
    audioFrame.avsync_type = frame->avsync_type;
    return ERROR_CODE(RtcEngineBridge_ptr->pushAudioFrame(agora::media::MEDIA_SOURCE_TYPE(type), &audioFrame, wrap));
}

enum ERROR_CODE
pushAudioFrame2(IRtcEngineBridge_ptr apiBridge, struct AudioFrame* frame)
{
    agora::media::IAudioFrameObserver::AudioFrame audioFrame;
    audioFrame.type = agora::media::IAudioFrameObserver::AUDIO_FRAME_TYPE(frame->type);
    audioFrame.samples = frame->samples;
    audioFrame.bytesPerSample = frame->bytesPerSample;
    audioFrame.channels = frame->channels;
    audioFrame.samplesPerSec = frame->samplesPerSec;
    audioFrame.buffer = frame->buffer;
    audioFrame.renderTimeMs = frame->renderTimeMs;
    audioFrame.avsync_type = frame->avsync_type;
    return ERROR_CODE(RtcEngineBridge_ptr->pushAudioFrame(&audioFrame));
}

enum ERROR_CODE
pullAudioFrame(IRtcEngineBridge_ptr apiBridge, struct AudioFrame* frame)
{
    agora::media::IAudioFrameObserver::AudioFrame audioFrame;
    audioFrame.type = agora::media::IAudioFrameObserver::AUDIO_FRAME_TYPE(frame->type);
    audioFrame.samples = frame->samples;
    audioFrame.bytesPerSample = frame->bytesPerSample;
    audioFrame.channels = frame->channels;
    audioFrame.samplesPerSec = frame->samplesPerSec;
    audioFrame.buffer = frame->buffer;
    audioFrame.renderTimeMs = frame->renderTimeMs;
    audioFrame.avsync_type = frame->avsync_type;
    ERROR_CODE error_code = ERROR_CODE(RtcEngineBridge_ptr->pullAudioFrame(&audioFrame));
    frame->type = AUDIO_FRAME_TYPE(audioFrame.type);
    frame->samples = audioFrame.samples;
    frame->bytesPerSample = audioFrame.bytesPerSample;
    frame->channels = audioFrame.channels;
    frame->samplesPerSec = audioFrame.samplesPerSec;
    frame->buffer = audioFrame.buffer;
    frame->renderTimeMs = audioFrame.renderTimeMs;
    frame->avsync_type = audioFrame.avsync_type;
    return error_code;
}

enum ERROR_CODE
setExternalVideoSource(IRtcEngineBridge_ptr apiBridge, BOOL enable, BOOL useTexture)
{
    return ERROR_CODE(RtcEngineBridge_ptr->setExternalVideoSource(enable, useTexture));
}

enum ERROR_CODE
pushVideoFrame(IRtcEngineBridge_ptr apiBridge, struct ExternalVideoFrame* frame)
{
    agora::media::ExternalVideoFrame externalVideoFrame;
    externalVideoFrame.type = agora::media::ExternalVideoFrame::VIDEO_BUFFER_TYPE(frame->type);
    externalVideoFrame.format = agora::media::ExternalVideoFrame::VIDEO_PIXEL_FORMAT(frame->format);
    externalVideoFrame.buffer = frame->buffer;
    externalVideoFrame.stride = frame->stride;
    externalVideoFrame.height = frame->height;
    externalVideoFrame.cropLeft = frame->cropLeft;
    externalVideoFrame.cropTop = frame->cropTop;
    externalVideoFrame.cropRight = frame->cropRight;
    externalVideoFrame.cropBottom = frame->cropBottom;
    externalVideoFrame.rotation = frame->rotation;
    externalVideoFrame.timestamp = frame->timestamp;
    return ERROR_CODE(RtcEngineBridge_ptr->pushVideoFrame(&externalVideoFrame));
}

enum ERROR_CODE enableEncryption(IRtcEngineBridge_ptr apiBridge, BOOL enabled, const EncryptionConfig config)
{

    agora::rtc::EncryptionConfig _config;
    _config.encryptionMode = agora::rtc::ENCRYPTION_MODE(config.encryptionMode);
    _config.encryptionKey = config.encryptionKey;
    return ERROR_CODE(RtcEngineBridge_ptr->enableEncryption(enabled, _config));
}

enum ERROR_CODE sendCustomReportMessage(IRtcEngineBridge_ptr apiBridge, const char* id, const char* category, const char* event, const char* label, int value)
{
    return ERROR_CODE(RtcEngineBridge_ptr->sendCustomReportMessage(id, category, event, label, value));
}

void channel_add_C_ChannelEventHandler(IRtcChannelBridge_ptr apiBridge, struct ChannelEventHandler* channelEventHandler)
{
    agora::common::CChannelEngineEventHandler channelEngineEventHandler;
    channelEngineEventHandler.onWarning = channelEventHandler->onWarning;
    channelEngineEventHandler.onError = channelEventHandler->onError;
    channelEngineEventHandler.onJoinChannelSuccess = channelEventHandler->onJoinChannelSuccess;
    channelEngineEventHandler.onRejoinChannelSuccess = channelEventHandler->onRejoinChannelSuccess;
    channelEngineEventHandler.onLeaveChannel = channelEventHandler->onLeaveChannel;
    channelEngineEventHandler.onClientRoleChanged = channelEventHandler->onClientRoleChanged;
    channelEngineEventHandler.onUserJoined = channelEventHandler->onUserJoined;
    channelEngineEventHandler.onUserOffLine = channelEventHandler->onUserOffLine;
    channelEngineEventHandler.onConnectionLost = channelEventHandler->onConnectionLost;
    channelEngineEventHandler.onRequestToken = channelEventHandler->onRequestToken;
    channelEngineEventHandler.onTokenPrivilegeWillExpire = channelEventHandler->onTokenPrivilegeWillExpire;
    channelEngineEventHandler.onRtcStats = channelEventHandler->onRtcStats;
    channelEngineEventHandler.onNetworkQuality = channelEventHandler->onNetworkQuality;
    channelEngineEventHandler.onRemoteVideoStats = channelEventHandler->onRemoteVideoStats;
    channelEngineEventHandler.onRemoteAudioStats = channelEventHandler->onRemoteAudioStats;
    channelEngineEventHandler.onRemoteAudioStateChanged = channelEventHandler->onRemoteAudioStateChanged;
    channelEngineEventHandler.onActiveSpeaker = channelEventHandler->onActiveSpeaker;
    channelEngineEventHandler.onVideoSizeChanged = channelEventHandler->onVideoSizeChanged;
    channelEngineEventHandler.onRemoteVideoStateChanged = channelEventHandler->onRemoteVideoStateChanged;
    channelEngineEventHandler.onStreamMessage = channelEventHandler->onStreamMessage;
    channelEngineEventHandler.onStreamMessageError = channelEventHandler->onStreamMessageError;
    channelEngineEventHandler.onMediaRelayStateChanged = channelEventHandler->onMediaRelayStateChanged;
    channelEngineEventHandler.onMediaRelayEvent = channelEventHandler->onMediaRelayEvent;
    channelEngineEventHandler.onRtmpStreamingStateChanged = channelEventHandler->onRtmpStreamingStateChanged;
    channelEngineEventHandler.onTranscodingUpdated = channelEventHandler->onTranscodingUpdated;
    channelEngineEventHandler.onStreamInjectedStatus = channelEventHandler->onStreamInjectedStatus;
    channelEngineEventHandler.onRemoteSubscribeFallbackToAudioOnly = channelEventHandler->onRemoteSubscribeFallbackToAudioOnly;
    channelEngineEventHandler.onConnectionStateChanged = channelEventHandler->onConnectionStateChanged;
    channelEngineEventHandler.onLocalPublishFallbackToAudioOnly = channelEventHandler->onLocalPublishFallbackToAudioOnly;
    RtcChannelBridge_ptr->add_C_ChannelEventHandler(&channelEngineEventHandler);
}

void channel_remove_C_ChannelEventHandler(IRtcChannelBridge_ptr apiBridge)
{
    RtcChannelBridge_ptr->remove_C_ChannelEventHandler();
}

enum ERROR_CODE
channel_joinChannel(IRtcChannelBridge_ptr apiBridge, const char* token,
    const char* info,
    uid_t uid,
    const struct ChannelMediaOptions options)
{
    agora::rtc::ChannelMediaOptions mediaOptions;
    mediaOptions.autoSubscribeAudio = options.autoSubscribeAudio;
    mediaOptions.autoSubscribeVideo = options.autoSubscribeVideo;
    return ERROR_CODE(RtcChannelBridge_ptr->joinChannel(token, info, uid, mediaOptions));
}

enum ERROR_CODE
channel_joinChannelWithUserAccount(IRtcChannelBridge_ptr apiBridge, const char* token,
    const char* userAccount,
    const struct ChannelMediaOptions options)
{
    agora::rtc::ChannelMediaOptions mediaOptions;
    mediaOptions.autoSubscribeAudio = options.autoSubscribeAudio;
    mediaOptions.autoSubscribeVideo = options.autoSubscribeVideo;
    return ERROR_CODE(RtcChannelBridge_ptr->joinChannelWithUserAccount(token, userAccount, mediaOptions));
}

enum ERROR_CODE
channel_leaveChannel(IRtcChannelBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcChannelBridge_ptr->leaveChannel());
}

enum ERROR_CODE
channel_publish(IRtcChannelBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcChannelBridge_ptr->publish());
}

enum ERROR_CODE
channel_unpublish(IRtcChannelBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcChannelBridge_ptr->unpublish());
}

const char*
channel_channelId(IRtcChannelBridge_ptr apiBridge)
{
    return RtcChannelBridge_ptr->channelId();
}

const char*
channel_getCallId(IRtcChannelBridge_ptr apiBridge)
{
    agora::util::AString sCallId;
    RtcEngineBridge_ptr->getCallId(sCallId);
    return sCallId->data();
}

enum ERROR_CODE
channel_renewToken(IRtcChannelBridge_ptr apiBridge, const char* token)
{
    return ERROR_CODE(RtcChannelBridge_ptr->renewToken(token));
}

enum ERROR_CODE
channel_setEncryptionSecret(IRtcChannelBridge_ptr apiBridge, const char* secret)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setEncryptionSecret(secret));
}

enum ERROR_CODE
channel_setEncryptionMode(IRtcChannelBridge_ptr apiBridge, const char* encryptionMode)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setEncryptionMode(encryptionMode));
}

//int
//registerPacketObserver(rtc::IPacketObserver* observer);

enum ERROR_CODE
channel_setClientRole(IRtcChannelBridge_ptr apiBridge, enum CLIENT_ROLE_TYPE role)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setClientRole(agora::rtc::CLIENT_ROLE_TYPE(role)));
}

enum ERROR_CODE
channel_setRemoteUserPriority(IRtcChannelBridge_ptr apiBridge, uid_t uid,
    enum PRIORITY_TYPE userPriority)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setRemoteUserPriority(uid, agora::rtc::PRIORITY_TYPE(userPriority)));
}

enum ERROR_CODE
channel_setRemoteVoicePosition(IRtcChannelBridge_ptr apiBridge, uid_t uid, double pan, double gain)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setRemoteVoicePosition(uid, pan, gain));
}

enum ERROR_CODE
channel_setRemoteRenderMode(IRtcChannelBridge_ptr apiBridge, uid_t userId,
    enum RENDER_MODE_TYPE renderMode,
    enum VIDEO_MIRROR_MODE_TYPE mirrorMode)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setRemoteRenderMode(userId, agora::rtc::RENDER_MODE_TYPE(renderMode), agora::rtc::VIDEO_MIRROR_MODE_TYPE(mirrorMode)));
}

enum ERROR_CODE
channel_setDefaultMuteAllRemoteAudioStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setDefaultMuteAllRemoteAudioStreams(mute));
}

enum ERROR_CODE
channel_setDefaultMuteAllRemoteVideoStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setDefaultMuteAllRemoteVideoStreams(mute));
}

enum ERROR_CODE
channel_muteAllRemoteAudioStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->muteAllRemoteAudioStreams(mute));
}

enum ERROR_CODE
channel_adjustUserPlaybackSignalVolume(IRtcChannelBridge_ptr apiBridge, uid_t userId, int volume)
{
    return ERROR_CODE(RtcChannelBridge_ptr->adjustUserPlaybackSignalVolume(userId, volume));
}

enum ERROR_CODE
channel_muteRemoteAudioStream(IRtcChannelBridge_ptr apiBridge, uid_t userId, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->muteRemoteAudioStream(userId, mute));
}

enum ERROR_CODE
channel_muteAllRemoteVideoStreams(IRtcChannelBridge_ptr apiBridge, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->muteAllRemoteVideoStreams(mute));
}

enum ERROR_CODE
channel_muteRemoteVideoStream(IRtcChannelBridge_ptr apiBridge, uid_t userId, BOOL mute)
{
    return ERROR_CODE(RtcChannelBridge_ptr->muteRemoteVideoStream(userId, mute));
}

enum ERROR_CODE
channel_setRemoteVideoStreamType(IRtcChannelBridge_ptr apiBridge, uid_t userId,
    enum REMOTE_VIDEO_STREAM_TYPE streamType)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setRemoteVideoStreamType(userId, agora::rtc::REMOTE_VIDEO_STREAM_TYPE(streamType)));
}

enum ERROR_CODE
channel_setRemoteDefaultVideoStreamType(IRtcChannelBridge_ptr apiBridge, enum REMOTE_VIDEO_STREAM_TYPE streamType)
{
    return ERROR_CODE(RtcChannelBridge_ptr->setRemoteDefaultVideoStreamType(agora::rtc::REMOTE_VIDEO_STREAM_TYPE(streamType)));
}

enum ERROR_CODE
channel_addPublishStreamUrl(IRtcChannelBridge_ptr apiBridge, const char* url, BOOL transcodingEnabled)
{
    return ERROR_CODE(RtcChannelBridge_ptr->addPublishStreamUrl(url, transcodingEnabled));
}

enum ERROR_CODE
channel_removePublishStreamUrl(IRtcChannelBridge_ptr apiBridge, const char* url)
{
    return ERROR_CODE(RtcChannelBridge_ptr->removePublishStreamUrl(url));
}

enum ERROR_CODE
channel_setLiveTranscoding(IRtcChannelBridge_ptr apiBridge, const struct LiveTranscoding* transcoding)
{
    agora::rtc::LiveTranscoding liveTranscoding;
    liveTranscoding.width = transcoding->width;
    liveTranscoding.height = transcoding->height;
    liveTranscoding.videoBitrate = transcoding->videoBitrate;
    liveTranscoding.videoFramerate = transcoding->videoFramerate;
    liveTranscoding.lowLatency = transcoding->lowLatency;
    liveTranscoding.videoGop = transcoding->videoGop;
    liveTranscoding.videoCodecProfile = agora::rtc::VIDEO_CODEC_PROFILE_TYPE(transcoding->videoCodecProfile);
    liveTranscoding.backgroundColor = transcoding->backgroundColor;
    liveTranscoding.userCount = transcoding->userCount;
    agora::rtc::TranscodingUser* transcodingUser = NULL;

    if (transcoding->userCount > 0) {
        transcodingUser = new agora::rtc::TranscodingUser[transcoding->userCount];
    }

    for (int i = 0; i < transcoding->userCount; i++) {
        transcodingUser[i].uid = transcoding->transcodingUsers[i].uid;
        transcodingUser[i].x = transcoding->transcodingUsers[i].x;
        transcodingUser[i].y = transcoding->transcodingUsers[i].y;
        transcodingUser[i].width = transcoding->transcodingUsers[i].width;
        transcodingUser[i].height = transcoding->transcodingUsers[i].height;
        transcodingUser[i].zOrder = transcoding->transcodingUsers[i].zOrder;
        transcodingUser[i].alpha = transcoding->transcodingUsers[i].alpha;
        transcodingUser[i].audioChannel = transcoding->transcodingUsers[i].audioChannel;
    }

    liveTranscoding.transcodingUsers = transcodingUser;
    liveTranscoding.transcodingExtraInfo = transcoding->transcodingExtraInfo;
    liveTranscoding.metadata = transcoding->metadata;
    agora::rtc::RtcImage watermark;
    if (transcoding->watermark) {
        watermark.height = transcoding->watermark->height;
        watermark.width = transcoding->watermark->width;
        watermark.url = transcoding->watermark->url;
        watermark.x = transcoding->watermark->x;
        watermark.y = transcoding->watermark->y;
    }
    liveTranscoding.watermark = &watermark;

    agora::rtc::RtcImage background;
    if (transcoding->backgroundImage) {
        background.height = transcoding->backgroundImage->height;
        background.width = transcoding->backgroundImage->width;
        background.url = transcoding->backgroundImage->url;
        background.x = transcoding->backgroundImage->x;
        background.y = transcoding->backgroundImage->y;
    }
    liveTranscoding.backgroundImage = &background;
    liveTranscoding.audioSampleRate = agora::rtc::AUDIO_SAMPLE_RATE_TYPE(transcoding->audioSampleRate);
    liveTranscoding.audioBitrate = transcoding->audioBitrate;
    liveTranscoding.audioChannels = transcoding->audioChannels;
    liveTranscoding.audioCodecProfile = agora::rtc::AUDIO_CODEC_PROFILE_TYPE(transcoding->audioCodecProfile);
    liveTranscoding.advancedFeatures = NULL;
    liveTranscoding.advancedFeatureCount = transcoding->advancedFeatureCount;
    if (liveTranscoding.advancedFeatureCount > 0) {
        liveTranscoding.advancedFeatures = new agora::rtc::LiveStreamAdvancedFeature();
        for (int i = 0; i < liveTranscoding.advancedFeatureCount; i++) {
            liveTranscoding.advancedFeatures[i].featureName = transcoding->advancedFeatures[i].featureName;
            liveTranscoding.advancedFeatures[i].LBHQ = transcoding->advancedFeatures[i].LBHQ;
            liveTranscoding.advancedFeatures[i].opened = transcoding->advancedFeatures[i].opened;
            liveTranscoding.advancedFeatures[i].VEO = transcoding->advancedFeatures[i].VEO;
        }
    }

    ERROR_CODE error_code = ERROR_CODE(RtcChannelBridge_ptr->setLiveTranscoding(liveTranscoding));
    delete[] liveTranscoding.advancedFeatures;
    liveTranscoding.advancedFeatures = NULL;
    return error_code;
}

enum ERROR_CODE
channel_addInjectStreamUrl(IRtcChannelBridge_ptr apiBridge, const char* url, const struct InjectStreamConfig config)
{
    agora::rtc::InjectStreamConfig injectStreamConfig;
    injectStreamConfig.width = config.width;
    injectStreamConfig.height = config.height;
    injectStreamConfig.videoGop = config.videoGop;
    injectStreamConfig.videoFramerate = config.videoFramerate;
    injectStreamConfig.videoBitrate = config.videoBitrate;
    injectStreamConfig.audioSampleRate = agora::rtc::AUDIO_SAMPLE_RATE_TYPE(config.audioSampleRate);
    injectStreamConfig.audioBitrate = config.audioBitrate;
    injectStreamConfig.audioChannels = config.audioChannels;
    return ERROR_CODE(RtcChannelBridge_ptr->addInjectStreamUrl(url, injectStreamConfig));
}

enum ERROR_CODE
channel_removeInjectStreamUrl(IRtcChannelBridge_ptr apiBridge, const char* url)
{
    return ERROR_CODE(RtcChannelBridge_ptr->removeInjectStreamUrl(url));
}

enum ERROR_CODE
channel_startChannelMediaRelay(IRtcChannelBridge_ptr apiBridge, struct ChannelMediaRelayConfiguration configuration)
{
    agora::rtc::ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    agora::rtc::ChannelMediaInfo srcMediaInfo;
    agora::rtc::ChannelMediaInfo* destMediaInfo = new agora::rtc::ChannelMediaInfo[configuration.destCount];
    channelMediaRelayConfiguration.srcInfo = &srcMediaInfo;
    channelMediaRelayConfiguration.destInfos = destMediaInfo;
    srcMediaInfo.uid = configuration.srcInfo->uid;
    srcMediaInfo.token = configuration.srcInfo->token;
    srcMediaInfo.channelName = configuration.srcInfo->channelName;

    for (int i = 0; i < configuration.destCount; i++) {
        channelMediaRelayConfiguration.destInfos->channelName = configuration.destInfos->channelName;
        channelMediaRelayConfiguration.destInfos->token = configuration.destInfos->token;
        channelMediaRelayConfiguration.destInfos->uid = configuration.destInfos->uid;
        channelMediaRelayConfiguration.destInfos++;
        configuration.destInfos++;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcChannelBridge_ptr->startChannelMediaRelay(channelMediaRelayConfiguration));
    return error_code;
}

enum ERROR_CODE
channel_updateChannelMediaRelay(IRtcChannelBridge_ptr apiBridge, struct ChannelMediaRelayConfiguration configuration)
{
    agora::rtc::ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
    agora::rtc::ChannelMediaInfo srcMediaInfo;
    agora::rtc::ChannelMediaInfo* destMediaInfo = NULL;
    if (configuration.destCount > 0) {
        destMediaInfo = new agora::rtc::ChannelMediaInfo[configuration.destCount];
    }
    channelMediaRelayConfiguration.srcInfo = &srcMediaInfo;
    channelMediaRelayConfiguration.destInfos = destMediaInfo;
    srcMediaInfo.uid = configuration.srcInfo->uid;
    srcMediaInfo.token = configuration.srcInfo->token;
    srcMediaInfo.channelName = configuration.srcInfo->channelName;

    for (int i = 0; i < configuration.destCount; i++) {
        channelMediaRelayConfiguration.destInfos->channelName = configuration.destInfos->channelName;
        channelMediaRelayConfiguration.destInfos->token = configuration.destInfos->token;
        channelMediaRelayConfiguration.destInfos->uid = configuration.destInfos->uid;
        channelMediaRelayConfiguration.destInfos++;
        configuration.destInfos++;
    }

    ERROR_CODE error_code = ERROR_CODE(RtcChannelBridge_ptr->updateChannelMediaRelay(channelMediaRelayConfiguration));

    delete[] destMediaInfo;
    destMediaInfo = NULL;
    return error_code;
}

enum ERROR_CODE
channel_stopChannelMediaRelay(IRtcChannelBridge_ptr apiBridge)
{
    return ERROR_CODE(RtcChannelBridge_ptr->stopChannelMediaRelay());
}

enum ERROR_CODE
channel_createDataStream(IRtcChannelBridge_ptr apiBridge, int* streamId, BOOL reliable, BOOL ordered)
{
    return ERROR_CODE(RtcChannelBridge_ptr->createDataStream(streamId, reliable, ordered));
}

enum ERROR_CODE
channel_sendStreamMessage(IRtcChannelBridge_ptr apiBridge, int streamId, const char* data, long long length)
{
    return ERROR_CODE(RtcChannelBridge_ptr->sendStreamMessage(streamId, data, length));
}

enum CONNECTION_STATE_TYPE
channel_getConnectionState(IRtcChannelBridge_ptr apiBridge)
{
    return CONNECTION_STATE_TYPE(RtcChannelBridge_ptr->getConnectionState());
}

int audio_device_getCount(void* apiBridge, enum DEVICE_TYPE type)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return AudioPlaybackDeviceManagerBridge_ptr->getCount();

    case DEVICE_TYPE::RECORDING_DEVICE:
        return AudioRecordingDeviceManagerBridge_ptr->getCount();

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_getDevice(void* apiBridge, enum DEVICE_TYPE type, int index, char deviceName[MAX_DEVICE_ID_LENGTH], char deviceId[MAX_DEVICE_ID_LENGTH])
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDevice(index, deviceName, deviceId));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDevice(index, deviceName, deviceId));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_getCurrentDevice(void* apiBridge, enum DEVICE_TYPE type, char deviceId[MAX_DEVICE_ID_LENGTH])
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getCurrentDevice(deviceId));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getCurrentDevice(deviceId));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_getCurrentDeviceInfo(void* apiBridge, enum DEVICE_TYPE type, char deviceId[MAX_DEVICE_ID_LENGTH], char deviceName[MAX_DEVICE_ID_LENGTH])
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getCurrentDeviceInfo(deviceId, deviceName));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getCurrentDeviceInfo(deviceId, deviceName));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_setDevice(void* apiBridge, enum DEVICE_TYPE type, const char deviceId[MAX_DEVICE_ID_LENGTH])
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDevice(deviceId));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDevice(deviceId));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_setDeviceVolume(void* apiBridge, enum DEVICE_TYPE type, int volume)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDeviceVolume(volume));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDeviceVolume(volume));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_getDeviceVolume(void* apiBridge, enum DEVICE_TYPE type, int* volume)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDeviceVolume(volume));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDeviceVolume(volume));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_setDeviceMute(void* apiBridge, enum DEVICE_TYPE type, BOOL mute)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDeviceMute(mute));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->setDeviceMute(mute));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_getDeviceMute(void* apiBridge, enum DEVICE_TYPE type, BOOL* mute)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE: {
        bool mutes;
        ERROR_CODE error_code = ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDeviceMute(&mutes));
        *mute = mutes;
        return error_code;
    }

    case DEVICE_TYPE::RECORDING_DEVICE: {
        bool mutes1;
        ERROR_CODE error_code1 = ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->getDeviceMute(&mutes1));
        *mute = mutes1;
        return error_code1;
    }

    default: {
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
    }
}

enum ERROR_CODE
audio_device_startDeviceTest(void* apiBridge, enum DEVICE_TYPE type, const char* testAudioFilePath)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->startDeviceTest(testAudioFilePath));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->startDeviceTest(testAudioFilePath));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_stopDeviceTest(void* apiBridge, enum DEVICE_TYPE type)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->stopDeviceTest());

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->stopDeviceTest());

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_startAudioDeviceLoopbackTest(void* apiBridge, enum DEVICE_TYPE type, int indicationInterval)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->startAudioDeviceLoopbackTest(indicationInterval));

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->startAudioDeviceLoopbackTest(indicationInterval));

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
audio_device_stopAudioDeviceLoopbackTest(void* apiBridge, enum DEVICE_TYPE type)
{
    switch (type) {
    case DEVICE_TYPE::PLAYBACK_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->stopAudioDeviceLoopbackTest());

    case DEVICE_TYPE::RECORDING_DEVICE:
        return ERROR_CODE(AudioPlaybackDeviceManagerBridge_ptr->stopAudioDeviceLoopbackTest());

    default:
        return ERROR_CODE::ERROR_INVALID_DEVICE_TYPE;
    }
}

enum ERROR_CODE
startDeviceTest(IVideoDeviceManager_ptr apiBridge, view_t hwnd)
{
    return ERROR_CODE(VideoDeviceManagerBridge_ptr->startDeviceTest(hwnd));
}

enum ERROR_CODE
stopDeviceTest(IVideoDeviceManager_ptr apiBridge)
{
    return ERROR_CODE(VideoDeviceManagerBridge_ptr->stopDeviceTest());
}

enum ERROR_CODE
setDevice(IVideoDeviceManager_ptr apiBridge, const char deviceId[MAX_DEVICE_ID_LENGTH])
{
    return ERROR_CODE(VideoDeviceManagerBridge_ptr->setDevice(deviceId));
}

enum ERROR_CODE
getDevice(IVideoDeviceManager_ptr apiBridge, int index, char deviceName[MAX_DEVICE_ID_LENGTH], char deviceId[MAX_DEVICE_ID_LENGTH])
{
    return ERROR_CODE(VideoDeviceManagerBridge_ptr->getDevice(index, deviceName, deviceId));
}

enum ERROR_CODE
getCurrentDevice(IVideoDeviceManager_ptr apiBridge, char deviceId[MAX_DEVICE_ID_LENGTH])
{
    return ERROR_CODE(VideoDeviceManagerBridge_ptr->getCurrentDevice(deviceId));
}

#ifdef __cplusplus
};
#endif
