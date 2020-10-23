#include "RtcEngineBridge.h"
#include "../test/ApiTester.h"

namespace agora {
namespace common {
using namespace rtc;
using rapidjson::Document;
using rapidjson::Value;

RtcEngineBridge::RtcEngineBridge() { mRtcEngine = createAgoraRtcEngine(); }

RtcEngineBridge::~RtcEngineBridge() {
  mRtcEngine = nullptr;
  mRtcEngineEventHandler = nullptr;
  if (metadataObserver) {
    delete (metadataObserver);
    metadataObserver = nullptr;
  }
}

int RtcEngineBridge::callApi(API_TYPE apiType, const std::string &parameters) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)

  switch (apiType) {
  case INITIALIZE: {
    std::string appId;
    get_parameter_string(document, "appId", appId, ret);
    CHECK_RET_ERROR(ret)

    unsigned int areaCode = AREA_CODE::AREA_CODE_GLOB;
    get_parameter_uint(document, "areaCode", areaCode, ret);
    CHECK_RET_ERROR(ret)

    ret = initialize(appId.c_str(), nullptr, areaCode);
  } break;

  case RELEASE: {
    release(true);
  } break;

  case SET_CHANNEL_PROFILE: {
    int profile;
    get_parameter_int(document, "profile", profile, ret);
    CHECK_RET_ERROR(ret)

    ret = setChannelProfile(CHANNEL_PROFILE_TYPE(profile));
  } break;

  case SET_CLIENT_ROLE: {
    int role;
    get_parameter_int(document, "role", role, ret);
    CHECK_RET_ERROR(ret)

    ret = setClientRole(CLIENT_ROLE_TYPE(role));
  } break;

  case JOIN_CHANNEL: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    std::string channelId;
    get_parameter_string(document, "channelId", channelId, ret);
    CHECK_RET_ERROR(ret)

    std::string info;
    get_parameter_string(document, "info", info, ret);
    CHECK_RET_ERROR(ret)

    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    ret = joinChannel(token.c_str(), channelId.c_str(), info.c_str(), uid);
  } break;

  case SWITCH_CHANNEL: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    std::string channelId;
    get_parameter_string(document, "channelId", channelId, ret);
    CHECK_RET_ERROR(ret)

    ret = switchChannel(token.c_str(), channelId.c_str());
  } break;

  case LEAVE_CHANNEL: {
    ret = leaveChannel();
  } break;

  case RE_NEW_TOKEN: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    ret = renewToken(token.c_str());
  } break;

  case REGISTER_LOCAL_USER_ACCOUNT: {
    std::string appId;
    get_parameter_string(document, "appId", appId, ret);
    CHECK_RET_ERROR(ret)

    std::string userAccount;
    get_parameter_string(document, "userAccount", userAccount, ret);
    CHECK_RET_ERROR(ret)

    ret = registerLocalUserAccount(appId.c_str(), userAccount.c_str());
  } break;

  case JOIN_CHANNEL_WITH_USER_ACCOUNT: {
    std::string token;
    get_parameter_string(document, "token", token, ret);
    CHECK_RET_ERROR(ret)

    std::string channelId;
    get_parameter_string(document, "channelId", channelId, ret);
    CHECK_RET_ERROR(ret)

    std::string userAccount;
    get_parameter_string(document, "userAccount", userAccount, ret);
    CHECK_RET_ERROR(ret)

    ret = joinChannelWithUserAccount(token.c_str(), channelId.c_str(),
                                     userAccount.c_str());
  } break;

  case START_ECHO_TEST: {
    ret = startEchoTest();
  } break;

  case START_ECHO_TEST_2: {
    int intervalInSeconds;
    get_parameter_int(document, "intervalInSeconds", intervalInSeconds, ret);
    CHECK_RET_ERROR(ret)

    ret = startEchoTest(intervalInSeconds);
  } break;

  case STOP_ECHO_TEST: {
    ret = stopEchoTest();
  } break;

  case ENABLE_VIDEO: {
    ret = enableVideo();
  } break;

  case DISABLE_VIDEO: {
    ret = disableVideo();
  } break;

  case SET_VIDEO_PROFILE: {
    int profile;
    get_parameter_int(document, "profile", profile, ret);
    CHECK_RET_ERROR(ret)

    bool swapWidthAndHeight;
    get_parameter_bool(document, "swapWidthAndHeight", swapWidthAndHeight, ret);
    CHECK_RET_ERROR(ret)

    ret = setVideoProfile(VIDEO_PROFILE_TYPE(profile), swapWidthAndHeight);
  } break;

  case SET_VIDEO_ENCODER_CONFIGURATION: {
    Value config;
    get_parameter_object(document, "config", config, ret);
    CHECK_RET_ERROR(ret)

    Value dimensions;
    get_parameter_object(config, "dimensions", dimensions, ret);
    CHECK_RET_ERROR(ret)

    VideoEncoderConfiguration videoEncoderConfiguration;
    json_to_VideoDimension(dimensions, videoEncoderConfiguration.dimensions,
                           ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(config, "minFrameRate",
                      videoEncoderConfiguration.minFrameRate, ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(config, "bitrate", videoEncoderConfiguration.bitrate,
                      ret);
    CHECK_RET_ERROR(ret)

    get_parameter_int(config, "minBitrate",
                      videoEncoderConfiguration.minBitrate, ret);
    CHECK_RET_ERROR(ret)

    int frameRate;
    get_parameter_int(config, "frameRate", frameRate, ret);
    CHECK_RET_ERROR(ret)

    int orientationMode;
    get_parameter_int(config, "orientationMode", orientationMode, ret);
    CHECK_RET_ERROR(ret)

    int degradationPreference;
    get_parameter_int(config, "degradationPreference", degradationPreference,
                      ret);
    CHECK_RET_ERROR(ret)

    int mirrorMode;
    get_parameter_int(config, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    videoEncoderConfiguration.frameRate = FRAME_RATE(frameRate);
    videoEncoderConfiguration.orientationMode =
        ORIENTATION_MODE(orientationMode);
    videoEncoderConfiguration.degradationPreference =
        DEGRADATION_PREFERENCE(degradationPreference);
    videoEncoderConfiguration.mirrorMode = VIDEO_MIRROR_MODE_TYPE(mirrorMode);

    ret = setVideoEncoderConfiguration(videoEncoderConfiguration);
  } break;

  case SET_CAMERA_CAPTURER_CONFIGURATION: {
    Value config;
    get_parameter_object(document, "config", config, ret);
    CHECK_RET_ERROR(ret)

    CameraCapturerConfiguration cameraCapturerConfiguration;
    json_to_CameraCapturerConfiguration(config, cameraCapturerConfiguration,
                                        ret);
    CHECK_RET_ERROR(ret)

    ret = setCameraCapturerConfiguration(cameraCapturerConfiguration);
  } break;

  case START_PREVIEW: {
    ret = startPreview();
  } break;

  case SET_REMOTE_USER_PRIORITY: {
    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    int userPriority;
    get_parameter_int(document, "userPriority", userPriority, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteUserPriority(uid, PRIORITY_TYPE(userPriority));
  } break;

  case STOP_PREVIEW: {
    ret = stopPreview();
  } break;

  case ENABLE_AUDIO: {
    ret = enableAudio();
  } break;

  case ENABLE_LOCAL_AUDIO: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    ret = enableLocalAudio(enabled);
  } break;

  case DISABLE_AUDIO: {
    ret = disableAudio();
  } break;

  case SET_AUDIO_PROFILE: {
    int profile;
    get_parameter_int(document, "profile", profile, ret);
    CHECK_RET_ERROR(ret)

    int scenario;
    get_parameter_int(document, "scenario", scenario, ret);
    CHECK_RET_ERROR(ret)

    ret = setAudioProfile(AUDIO_PROFILE_TYPE(profile),
                          AUDIO_SCENARIO_TYPE(scenario));
  } break;

  case MUTE_LOCAL_AUDIO_STREAM: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteLocalAudioStream(mute);
  } break;

  case MUTE_ALL_REMOTE_AUDIO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteAllRemoteAudioStreams(mute);
  } break;

  case SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = setDefaultMuteAllRemoteAudioStreams(mute);
  } break;

  case ADJUST_USER_PLAYBACK_SIGNAL_VOLUME: {
    unsigned int uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustUserPlaybackSignalVolume(uid, volume);
  } break;

  case MUTE_REMOTE_AUDIO_STREAM: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteRemoteAudioStream(userId, mute);
  } break;

  case MUTE_LOCAL_VIDEO_STREAM: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteLocalVideoStream(mute);
  } break;

  case ENABLE_LOCAL_VIDEO: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    ret = enableLocalVideo(enabled);
  } break;

  case MUTE_ALL_REMOTE_VIDEO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteAllRemoteVideoStreams(mute);
  } break;

  case SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS: {
    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = setDefaultMuteAllRemoteVideoStreams(mute);
  } break;

  case MUTE_REMOTE_VIDEO_STREAM: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    bool mute;
    get_parameter_bool(document, "mute", mute, ret);
    CHECK_RET_ERROR(ret)

    ret = muteRemoteVideoStream(userId, mute);
  } break;

  case SET_REMOTE_VIDEO_STREAM_TYPE: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    int streamType;
    get_parameter_int(document, "streamType", streamType, ret);
    CHECK_RET_ERROR(ret)

    ret =
        setRemoteVideoStreamType(userId, REMOTE_VIDEO_STREAM_TYPE(streamType));
  } break;

  case SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE: {
    int streamType;
    get_parameter_int(document, "streamType", streamType, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteDefaultVideoStreamType(REMOTE_VIDEO_STREAM_TYPE(streamType));
  } break;

  case ENABLE_AUDIO_VOLUME_INDICATION: {
    int interval;
    get_parameter_int(document, "interval", interval, ret);
    CHECK_RET_ERROR(ret)

    int smooth;
    get_parameter_int(document, "smooth", smooth, ret);
    CHECK_RET_ERROR(ret)

    bool report_vad;
    get_parameter_bool(document, "report_vad", report_vad, ret);
    CHECK_RET_ERROR(ret)

    ret = enableAudioVolumeIndication(interval, smooth, report_vad);
  } break;

  case START_AUDIO_RECORDING: {
    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    int quality;
    get_parameter_int(document, "quality", quality, ret);
    CHECK_RET_ERROR(ret)

    ret = startAudioRecording(filePath.c_str(),
                              AUDIO_RECORDING_QUALITY_TYPE(quality));
  } break;

  case START_AUDIO_RECORDING2: {
    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int quality;
    get_parameter_int(document, "quality", quality, ret);
    CHECK_RET_ERROR(ret)

    ret = startAudioRecording(filePath.c_str(), sampleRate,
                              AUDIO_RECORDING_QUALITY_TYPE(quality));
  } break;

  case STOP_AUDIO_RECORDING: {
    ret = stopAudioRecording();
  } break;

  case ENABLE_FACE_DETECTION: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = enableFaceDetection(enabled);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_REMOTE_VOICE_POSITIONN: {
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

  case SET_LOG_FILE: {
    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    ret = setLogFile(filePath.c_str());
  } break;

  case SET_LOG_FILTER: {
    unsigned int filter;
    get_parameter_uint(document, "filter", filter, ret);
    CHECK_RET_ERROR(ret)

    ret = setLogFilter(filter);
  } break;

  case SET_LOG_FILE_SIZE: {
    unsigned int fileSizeInKBytes;
    get_parameter_uint(document, "fileSizeInKBytes", fileSizeInKBytes, ret);
    CHECK_RET_ERROR(ret)

    ret = setLogFileSize(fileSizeInKBytes);
  } break;

  case SET_LOCAL_RENDER_MODE: {
    unsigned int renderMode;
    get_parameter_uint(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setLocalRenderMode(RENDER_MODE_TYPE(renderMode));
  } break;

  case SET_LOCAL_RENDER_MODE_2: {
    unsigned int renderMode;
    get_parameter_uint(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    unsigned int mirrorMode;
    get_parameter_uint(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setLocalRenderMode(RENDER_MODE_TYPE(renderMode),
                             VIDEO_MIRROR_MODE_TYPE(mirrorMode));
  } break;

  case SET_REMOTE_RENDER_MODE: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    unsigned int renderMode;
    get_parameter_uint(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteRenderMode(userId, RENDER_MODE_TYPE(renderMode));
  } break;

  case SET_REMOTE_RENDER_MODE_2: {
    rtc::uid_t userId;
    get_parameter_uint(document, "userId", userId, ret);
    CHECK_RET_ERROR(ret)

    unsigned int renderMode;
    get_parameter_uint(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    unsigned int mirrorMode;
    get_parameter_uint(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteRenderMode(userId, RENDER_MODE_TYPE(renderMode),
                              VIDEO_MIRROR_MODE_TYPE(mirrorMode));
  } break;

  case SET_LOCAL_VIDEO_MIRROR_MODE: {
    unsigned int mirrorMode;
    get_parameter_uint(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setLocalVideoMirrorMode(VIDEO_MIRROR_MODE_TYPE(mirrorMode));
  } break;

  case ENABLE_DUAL_STREAM_MODE: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    ret = enableDualStreamMode(enabled);
  } break;

  case ADJUST_RECORDING_SIGNAL_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustRecordingSignalVolume(volume);
  } break;

  case ADJUST_PLAYBACK_SIGNAL_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustPlaybackSignalVolume(volume);
  } break;

  case ENABLE_WEB_SDK_INTEROPER_ABILITY: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    ret = enableWebSdkInteroperability(enabled);
  } break;

  case SET_VIDEO_QUALITY_PARAMETERS: {
    bool preferFrameRateOverImageQuality;
    get_parameter_bool(document, "preferFrameRateOverImageQuality",
                       preferFrameRateOverImageQuality, ret);
    CHECK_RET_ERROR(ret)

    ret = setVideoQualityParameters(preferFrameRateOverImageQuality);
  } break;

  case SET_LOCAL_PUBLISH_FALLBACK_OPTION: {
    int option;
    get_parameter_int(document, "option", option, ret);
    CHECK_RET_ERROR(ret)

    ret = setLocalPublishFallbackOption(STREAM_FALLBACK_OPTIONS(option));
  } break;

  case SET_REMOTE_SUBSCRIBE_FALLBACK_OPTION: {
    int option;
    get_parameter_int(document, "option", option, ret);
    CHECK_RET_ERROR(ret)

    ret = setRemoteSubscribeFallbackOption(STREAM_FALLBACK_OPTIONS(option));
  } break;

  case SWITCH_CAMERA: {
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = switchCamera();
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SWITCH_CAMERA_2: {
    int direction;
    get_parameter_int(document, "direction", direction, ret);
    CHECK_RET_ERROR(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = switchCamera(CAMERA_DIRECTION(direction));
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_DEFAULT_AUDIO_ROUTE_SPEAKER_PHONE: {
    bool defaultToSpeaker;
    get_parameter_bool(document, "defaultToSpeaker", defaultToSpeaker, ret);
    CHECK_RET_ERROR(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_ENABLE_SPEAKER_PHONE: {
    bool speakerOn;
    get_parameter_bool(document, "speakerOn", speakerOn, ret);
    CHECK_RET_ERROR(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = setEnableSpeakerphone(speakerOn);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case ENABLE_IN_EAR_MONITORING: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = enableInEarMonitoring(enabled);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_IN_EAR_MONITORING_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = setInEarMonitoringVolume(volume);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case IS_SPEAKER_PHONE_ENABLED: {
#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
    ret = isSpeakerphoneEnabled();
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_AUDIO_SESSION_OPERATION_RESTRICTION: {
    int restriction;
    get_parameter_int(document, "restriction", restriction, ret);
    CHECK_RET_ERROR(ret)

#if (defined(__APPLE__) && TARGET_OS_IOS)
    ret = setAudioSessionOperationRestriction(
        rtc::AUDIO_SESSION_OPERATION_RESTRICTION(restriction));
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case ENABLE_LOOP_BACK_RECORDING: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    std::string deviceName;
    get_parameter_string(document, "deviceName", deviceName, ret);
    CHECK_RET_ERROR(ret)

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) ||              \
    defined(_WIN32)
    ret = enableLoopbackRecording(enabled, deviceName.c_str());
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case START_SCREEN_CAPTURE_BY_DISPLAY_ID: {
#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
    unsigned int displayId;
    get_parameter_uint(document, "displayId", displayId, ret);
    CHECK_RET_ERROR(ret)

    Value regionRect;
    get_parameter_object(document, "regionRect", regionRect, ret);
    CHECK_RET_ERROR(ret)

    Rectangle rectangle;
    json_to_Rectangle(regionRect, rectangle, ret);
    CHECK_RET_ERROR(ret)

    Value captureParams;
    get_parameter_object(document, "captureParams", captureParams, ret);
    CHECK_RET_ERROR(ret)

    ScreenCaptureParameters screenCaptureParameters;
    VideoDimensions videoDimensions;
    int windowList[MAX_WINDOW_COUNT];
    json_to_ScreenCaptureParameters(captureParams, screenCaptureParameters,
                                    videoDimensions, windowList, ret);
    ret = startScreenCaptureByDisplayId(displayId, rectangle,
                                        screenCaptureParameters);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case START_SCREEN_CAPTURE_BY_SCREEN_RECT: {
#if defined(_WIN32)
    Value screenRectValue;
    get_parameter_object(document, "screenRect", screenRectValue, ret);
    CHECK_RET_ERROR(ret)

    Rectangle screenRect;
    json_to_Rectangle(screenRectValue, screenRect, ret);
    CHECK_RET_ERROR(ret)

    Value regionRectValue;
    get_parameter_object(document, "regionRect", regionRectValue, ret);
    CHECK_RET_ERROR(ret)

    Rectangle regionRect;
    json_to_Rectangle(regionRectValue, regionRect, ret);
    CHECK_RET_ERROR(ret)

    Value captureParams;
    get_parameter_object(document, "captureParams", captureParams, ret);
    CHECK_RET_ERROR(ret)

    ScreenCaptureParameters screenCaptureParameters;
    VideoDimensions videoDimensions;
    int windowList[MAX_WINDOW_COUNT];
    json_to_ScreenCaptureParameters(captureParams, screenCaptureParameters,
                                    videoDimensions, windowList, ret);
    CHECK_RET_ERROR(ret)

    startScreenCaptureByScreenRect(screenRect, regionRect,
                                   screenCaptureParameters);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case START_SCREEN_CAPTURE_BY_WINDOW_ID: {
#if defined(_WIN32)
    int windowId;
    get_parameter_int(document, "windowId", windowId, ret);
    CHECK_RET_ERROR(ret)

    Value regionRectValue;
    get_parameter_object(document, "regionRect", regionRectValue, ret);
    CHECK_RET_ERROR(ret)

    Rectangle regionRect;
    json_to_Rectangle(regionRectValue, regionRect, ret);
    CHECK_RET_ERROR(ret)

    Value captureParams;
    get_parameter_object(document, "captureParams", captureParams, ret);
    CHECK_RET_ERROR(ret)

    ScreenCaptureParameters screenCaptureParameters;
    VideoDimensions videoDimensions;
    int windowList[MAX_WINDOW_COUNT];
    json_to_ScreenCaptureParameters(captureParams, screenCaptureParameters,
                                    videoDimensions, windowList, ret);
    CHECK_RET_ERROR(ret)

    ret = startScreenCaptureByWindowId(reinterpret_cast<view_t>(windowId),
                                       regionRect, screenCaptureParameters);

#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case SET_SCREEN_CAPTURE_CONTENT_HINT: {
#if defined(_WIN32)
    int contentHint;
    get_parameter_int(document, "contentHint", contentHint, ret);
    CHECK_RET_ERROR(ret)

    ret = setScreenCaptureContentHint(VideoContentHint(contentHint));
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case UPDATE_SCREEN_CAPTURE_PARAMETERS: {
#if defined(_WIN32)
    Value captureParams;
    get_parameter_object(document, "captureParams", captureParams, ret);
    CHECK_RET_ERROR(ret)

    ScreenCaptureParameters screenCaptureParameters;
    VideoDimensions videoDimensions;
    int windowList[MAX_WINDOW_COUNT];
    json_to_ScreenCaptureParameters(captureParams, screenCaptureParameters,
                                    videoDimensions, windowList, ret);
    CHECK_RET_ERROR(ret)

    ret = updateScreenCaptureParameters(screenCaptureParameters);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case UPDATE_SCREEN_CAPTURE_REGION: {
#if defined(_WIN32)
    Value regionRectValue;
    get_parameter_object(document, "regionRect", regionRectValue, ret);
    CHECK_RET_ERROR(ret)

    Rectangle regionRect;
    json_to_Rectangle(regionRectValue, regionRect, ret);
    CHECK_RET_ERROR(ret)

    ret = updateScreenCaptureRegion(regionRect);
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case STOP_SCREEN_CAPTURE: {
#if defined(_WIN32)
    ret = stopScreenCapture();
#else
    ret = ERROR_CODE::ERROR_NOT_SUPPORT_API;
#endif
  } break;

  case RATE: {
    std::string callId;
    get_parameter_string(document, "callId", callId, ret);
    CHECK_RET_ERROR(ret)

    int rating;
    get_parameter_int(document, "rating", rating, ret);
    CHECK_RET_ERROR(ret)

    std::string description;
    get_parameter_string(document, "description", description, ret);
    CHECK_RET_ERROR(ret)

    ret = rate(callId.c_str(), rating, description.c_str());
  } break;

  case COMPLAIN: {
    std::string callId;
    get_parameter_string(document, "callId", callId, ret);
    CHECK_RET_ERROR(ret)

    std::string description;
    get_parameter_string(document, "description", description, ret);
    CHECK_RET_ERROR(ret)

    ret = complain(callId.c_str(), description.c_str());
  } break;

  case ENABLE_LAST_MILE_TEST: {
    ret = enableLastmileTest();
  } break;

  case DISABLE_LAST_MILE_TEST: {
    ret = disableLastmileTest();
  } break;

  case START_LAST_MILE_PROBE_TEST: {
    Value config;
    get_parameter_object(document, "config", config, ret);
    CHECK_RET_ERROR(ret)

    LastmileProbeConfig lastmileProbeConfig;
    json_to_LastmileProbeConfig(config, lastmileProbeConfig, ret);
    CHECK_RET_ERROR(ret)

    ret = startLastmileProbeTest(lastmileProbeConfig);
  } break;

  case STOP_LAST_MILE_PROBE_TEST: {
    ret = stopLastmileProbeTest();
  } break;

  case SET_ENCRYPTION_SECTRT: {
    std::string secret;
    get_parameter_string(document, "secret", secret, ret);
    CHECK_RET_ERROR(ret)

    ret = setEncryptionSecret(secret.c_str());
  } break;

  case SET_ENCRYPTION_MODE: {
    std::string encryptionMode;
    get_parameter_string(document, "encryptionMode", encryptionMode, ret);
    CHECK_RET_ERROR(ret)

    ret = setEncryptionMode(encryptionMode.c_str());
  } break;

  case ADD_PUBLISH_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    bool transcodingEnabled;
    get_parameter_bool(document, "transcodingEnabled", transcodingEnabled, ret);
    CHECK_RET_ERROR(ret)

    ret = addPublishStreamUrl(url.c_str(), transcodingEnabled);
  } break;

  case REMOVE_PUBLISH_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    ret = removePublishStreamUrl(url.c_str());
  } break;

  case SET_LIVE_TRANSCODING: {
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

  case ADD_VIDEO_WATER_MARK: {
    RtcImage rtcImage;
    std::string url;

    Value watermark;
    get_parameter_object(document, "watermark", watermark, ret);
    CHECK_RET_ERROR(ret);

    json_to_RtcImage(watermark, rtcImage, url, ret);
    CHECK_RET_ERROR(ret);

    ret = addVideoWatermark(rtcImage);
  } break;

  case ADD_VIDEO_WATER_MARK_2: {
    std::string watermarkUrl;
    get_parameter_string(document, "watermarkUrl", watermarkUrl, ret);
    CHECK_RET_ERROR(ret)

    Value options;
    get_parameter_object(document, "options", options, ret);
    CHECK_RET_ERROR(ret)

    WatermarkOptions watermarkOptions;
    get_parameter_bool(options, "visibleInPreview",
                       watermarkOptions.visibleInPreview, ret);
    CHECK_RET_ERROR(ret);

    Value positionInLandscapeMode;
    get_parameter_object(options, "positionInLandscapeMode",
                         positionInLandscapeMode, ret);
    CHECK_RET_ERROR(ret)

    Rectangle rectangle_positionInLandscapeMode;
    json_to_Rectangle(positionInLandscapeMode,
                      rectangle_positionInLandscapeMode, ret);
    CHECK_RET_ERROR(ret);

    watermarkOptions.positionInLandscapeMode =
        rectangle_positionInLandscapeMode;

    Value positionInPortraitMode;
    get_parameter_object(options, "positionInPortraitMode",
                         positionInPortraitMode, ret);
    CHECK_RET_ERROR(ret)

    Rectangle rectangle_positionInPortraitMode;
    json_to_Rectangle(positionInPortraitMode, rectangle_positionInPortraitMode,
                      ret);
    CHECK_RET_ERROR(ret);

    watermarkOptions.positionInPortraitMode = rectangle_positionInPortraitMode;

    ret = addVideoWatermark(watermarkUrl.c_str(), watermarkOptions);
  } break;

  case CLEAR_VIDEO_WATER_MARKS: {
    ret = clearVideoWatermarks();
  } break;

  case SET_BEAUTY_EFFECT_OPTIONS: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    Value options;
    get_parameter_object(document, "options", options, ret);
    CHECK_RET_ERROR(ret)

    BeautyOptions beautyOptions;
    json_to_BeautyOptions(options, &beautyOptions, ret);
    CHECK_RET_ERROR(ret);

    ret = setBeautyEffectOptions(enabled, beautyOptions);
  } break;

  case ADD_INJECT_STREAM_URL: {
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

  case START_CHANNEL_MEDIA_RELAY: {
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

  case UPDATE_CHANNEL_MEDIA_RELAY: {
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

  case STOP_CHANNEL_MEDIA_RELAY: {
    ret = stopChannelMediaRelay();
  } break;

  case REMOVE_INJECT_STREAM_URL: {
    std::string url;
    get_parameter_string(document, "url", url, ret);
    CHECK_RET_ERROR(ret)

    ret = removeInjectStreamUrl(url.c_str());
  } break;

  case GET_CONNECTION_STATE: {
    ret = getConnectionState();
  } break;

  case SET_PARAMETERS: {
    std::string _parameters;
    get_parameter_string(document, "parameters", _parameters, ret);
    CHECK_RET_ERROR(ret)

    ret = setParameters(_parameters.c_str());
  } break;

  case SET_PLAYBACK_DEVICE_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = setPlaybackDeviceVolume(volume);
  } break;

  case ENABLE_ENCRYPTION: {
    bool enable;
    get_parameter_bool(document, "enable", enable, ret);
    CHECK_RET_ERROR(ret)

    Value config;
    get_parameter_object(document, "config", config, ret);
    CHECK_RET_ERROR(ret)

    int encryptionMode;
    get_parameter_int(config, "encryptionMode", encryptionMode, ret);
    CHECK_RET_ERROR(ret)

    std::string encryptionKey;
    get_parameter_string(config, "encryptionKey", encryptionKey, ret);
    CHECK_RET_ERROR(ret)

    EncryptionConfig encryptionConfig;
    encryptionConfig.encryptionKey = encryptionKey.c_str();
    encryptionConfig.encryptionMode = ENCRYPTION_MODE(encryptionMode);
    ret = enableEncryption(enable, encryptionConfig);
  } break;

  case SEND_CUSTOM_REPORT_MESSAGE: {
    std::string id;
    get_parameter_string(document, "id", id, ret);
    CHECK_RET_ERROR(ret)

    std::string category;
    get_parameter_string(document, "category", category, ret);
    CHECK_RET_ERROR(ret)

    std::string event;
    get_parameter_string(document, "event", event, ret);
    CHECK_RET_ERROR(ret)

    std::string label;
    get_parameter_string(document, "label", label, ret);
    CHECK_RET_ERROR(ret)

    int value;
    get_parameter_int(document, "value", value, ret);
    CHECK_RET_ERROR(ret)

    ret = sendCustomReportMessage(id.c_str(), category.c_str(), event.c_str(),
                                  label.c_str(), value);
  } break;

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return ret;
}

int RtcEngineBridge::callApi_audioEffect(API_TYPE_AUDIO_EFFECT apiType,
                                         const std::string &parameters) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret);

  switch (apiType) {
  case START_AUDIO_MIXING: {
    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    bool loopback;
    get_parameter_bool(document, "loopback", loopback, ret);
    CHECK_RET_ERROR(ret)

    bool replace;
    get_parameter_bool(document, "replace", replace, ret);
    CHECK_RET_ERROR(ret)

    int cycle;
    get_parameter_int(document, "cycle", cycle, ret);
    CHECK_RET_ERROR(ret)

    ret = startAudioMixing(filePath.c_str(), loopback, replace, cycle);
  } break;

  case STOP_AUDIO_MIXING: {
    ret = stopAudioMixing();
  } break;

  case PAUSE_AUDIO_MIXING: {
    ret = pauseAudioMixing();
  } break;

  case RESUME_AUDIO_MIXING: {
    ret = resumeAudioMixing();
  } break;

  case SET_HIGH_QUALITY_AUDIO_PARAMETERS: {
    bool fullband;
    get_parameter_bool(document, "fullband", fullband, ret);
    CHECK_RET_ERROR(ret)

    bool stereo;
    get_parameter_bool(document, "stereo", stereo, ret);
    CHECK_RET_ERROR(ret)

    bool fullBitrate;
    get_parameter_bool(document, "fullBitrate", fullBitrate, ret);
    CHECK_RET_ERROR(ret)

    ret = setHighQualityAudioParameters(fullband, stereo, fullBitrate);
  } break;

  case ADJUST_AUDIO_MIXING_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustAudioMixingVolume(volume);
  } break;

  case ADJUST_AUDIO_MIXING_PLAYOUT_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustAudioMixingPlayoutVolume(volume);
  } break;

  case GET_AUDIO_MIXING_PLAYOUT_VOLUME: {
    ret = getAudioMixingPlayoutVolume();
  } break;

  case ADJUST_AUDIO_MIXING_PUBLISH_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = adjustAudioMixingPublishVolume(volume);
  } break;

  case GET_AUDIO_MIXING_PUBLISH_VOLUME: {
    ret = getAudioMixingPublishVolume();
  } break;

  case GET_AUDIO_MIXING_DURATION: {
    ret = getAudioMixingDuration();
  } break;

  case GET_AUDIO_MIXING_CURRENT_POSITION: {
    ret = getAudioMixingCurrentPosition();
  } break;

  case SET_AUDIO_MIXING_POSITION: {
    int pos;
    get_parameter_int(document, "pos", pos, ret);
    CHECK_RET_ERROR(ret)

    ret = setAudioMixingPosition(pos);
  } break;

  case GET_EFFECTS_VOLUME: {
    ret = getEffectsVolume();
  } break;

  case SET_EFFECTS_VOLUME: {
    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = setEffectsVolume(volume);
  } break;

  case SET_VOLUME_OF_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    int volume;
    get_parameter_int(document, "volume", volume, ret);
    CHECK_RET_ERROR(ret)

    ret = setVolumeOfEffect(soundId, volume);
  } break;

  case PLAY_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    int loopCount;
    get_parameter_int(document, "loopCount", loopCount, ret);
    CHECK_RET_ERROR(ret)

    double pitch;
    get_parameter_double(document, "pitch", pitch, ret);
    CHECK_RET_ERROR(ret)

    double pan;
    get_parameter_double(document, "pan", pan, ret);
    CHECK_RET_ERROR(ret)

    int gain;
    get_parameter_int(document, "gain", gain, ret);
    CHECK_RET_ERROR(ret)

    bool publish;
    get_parameter_bool(document, "publish", publish, ret);
    CHECK_RET_ERROR(ret)

    ret = playEffect(soundId, filePath.c_str(), loopCount, pitch, pan, gain,
                     publish);
  } break;

  case STOP_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    ret = stopEffect(soundId);
  } break;

  case STOP_ALL_EFFECTS: {
    ret = stopAllEffects();
  } break;

  case PRE_LOAD_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    std::string filePath;
    get_parameter_string(document, "filePath", filePath, ret);
    CHECK_RET_ERROR(ret)

    ret = preloadEffect(soundId, filePath.c_str());
  } break;

  case UN_LOAD_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    ret = unloadEffect(soundId);
  } break;

  case PAUSE_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    ret = pauseEffect(soundId);
  } break;

  case PAUSE_ALL_EFFECTS: {
    ret = pauseAllEffects();
  } break;

  case RESUME_EFFECT: {
    int soundId;
    get_parameter_int(document, "soundId", soundId, ret);
    CHECK_RET_ERROR(ret)

    ret = resumeEffect(soundId);
  } break;

  case RESUME_ALL_EFFECTS: {
    ret = resumeAllEffects();
  } break;

  case ENABLE_SOUND_POSITION_INDICATION: {
    bool enabled;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    ret = enableSoundPositionIndication(enabled);
  } break;

  case SET_LOCAL_VOICE_PITCH: {
    double pitch = -1.0;
    get_parameter_double(document, "pitch", pitch, ret);
    CHECK_RET_ERROR(ret)
    ret = setLocalVoicePitch(pitch);
  } break;

  case SET_LOCAL_VOICE_EQUALIZATION: {
    int bandFrequency;
    get_parameter_int(document, "bandFrequency", bandFrequency, ret);
    CHECK_RET_ERROR(ret)

    int bandGain;
    get_parameter_int(document, "bandGain", bandGain, ret);
    CHECK_RET_ERROR(ret)
    ret = setLocalVoiceEqualization(
        AUDIO_EQUALIZATION_BAND_FREQUENCY(bandFrequency), bandGain);
  } break;

  case SET_LOCAL_VOICE_REVERB: {
    int reverbKey;
    get_parameter_int(document, "reverbKey", reverbKey, ret);
    CHECK_RET_ERROR(ret)

    int value;
    get_parameter_int(document, "value", value, ret);
    CHECK_RET_ERROR(ret)
    ret = setLocalVoiceReverb(AUDIO_REVERB_TYPE(reverbKey), value);
  } break;

  case SET_LOCAL_VOICE_CHANGER: {
    int voiceChanger;
    get_parameter_int(document, "voiceChanger", voiceChanger, ret);
    CHECK_RET_ERROR(ret)
    ret = setLocalVoiceChanger(VOICE_CHANGER_PRESET(voiceChanger));
  } break;

  case SET_LOCAL_VOICE_REVERB_PRESET: {
    int reverbPreset;
    get_parameter_int(document, "reverbPreset", reverbPreset, ret);
    CHECK_RET_ERROR(ret)
    ret = setLocalVoiceReverbPreset(AUDIO_REVERB_PRESET(reverbPreset));
  } break;

  case SET_AUDIO_MIXING_PITCH: {
    int pitch;
    get_parameter_int(document, "pitch", pitch, ret);
    CHECK_RET_ERROR(ret)
    ret = setAudioMixingPitch(pitch);
  } break;

  case SET_EXTERNAL_AUDIO_SOURCE: {
    bool enabled = false;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int channels;
    get_parameter_int(document, "channels", channels, ret);
    CHECK_RET_ERROR(ret)
    ret = setExternalAudioSource(enabled, sampleRate, channels);
  } break;

  case SET_EXTERNAL_AUDIO_SINK: {
    bool enabled = false;
    get_parameter_bool(document, "enabled", enabled, ret);
    CHECK_RET_ERROR(ret)

    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int channels;
    get_parameter_int(document, "channels", channels, ret);
    CHECK_RET_ERROR(ret)

    ret = setExternalAudioSink(enabled, sampleRate, channels);
  } break;

  case SET_RECORDING_AUDIO_FRAME_PARAMETERS: {
    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int channel;
    get_parameter_int(document, "channel", channel, ret);
    CHECK_RET_ERROR(ret)

    int mode;
    get_parameter_int(document, "mode", mode, ret);
    CHECK_RET_ERROR(ret)

    int samplesPerCall;
    get_parameter_int(document, "samplesPerCall", samplesPerCall, ret);
    CHECK_RET_ERROR(ret)

    ret = setRecordingAudioFrameParameters(sampleRate, channel,
                                           RAW_AUDIO_FRAME_OP_MODE_TYPE(mode),
                                           samplesPerCall);
  } break;

  case SET_PLAYBACK_AUDIO_FRAME_PARAMETERS: {
    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int channel;
    get_parameter_int(document, "channel", channel, ret);
    CHECK_RET_ERROR(ret)

    int mode;
    get_parameter_int(document, "mode", mode, ret);
    CHECK_RET_ERROR(ret)

    int samplesPerCall;
    get_parameter_int(document, "samplesPerCall", samplesPerCall, ret);
    CHECK_RET_ERROR(ret)

    ret = setPlaybackAudioFrameParameters(sampleRate, channel,
                                          RAW_AUDIO_FRAME_OP_MODE_TYPE(mode),
                                          samplesPerCall);
  } break;

  case SET_MIXED_AUDIO_FRAME_PARAMETERS: {
    int sampleRate;
    get_parameter_int(document, "sampleRate", sampleRate, ret);
    CHECK_RET_ERROR(ret)

    int samplesPerCall;
    get_parameter_int(document, "samplesPerCall", samplesPerCall, ret);
    CHECK_RET_ERROR(ret)

    ret = setMixedAudioFrameParameters(sampleRate, samplesPerCall);
  } break;

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return ret;
}

const char *RtcEngineBridge::callApi_str(API_TYPE apiType,
                                         const std::string &parameters) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT_CHAR(document)
  switch (apiType) {
  case GET_VERSION: {
    return getVersion();
  }

  case GET_ERROR_DESCRIPTION: {
    int code;
    get_parameter_int(document, "code", code, ret);
    CHECK_RET_ERROR_CHAR(ret)

    return getErrorDescription(code);
  }

  case GET_CALL_ID: {
    agora::util::AString callId;
    getCallId(callId);

    return callId->c_str();
  }

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return "";
}

int RtcEngineBridge::callApi(API_TYPE apiType, const std::string &parameters,
                             void *ptr) {
  int ret = ERROR_CODE::ERROR_OK;
  Document document;
  document.Parse(parameters.c_str());
  CHECK_PARSE_DOCUMENT(document, ret)
  switch (apiType) {
  case GET_USER_INFO_BY_USER_ACCOUNT: {
    std::string userAccount;
    get_parameter_string(document, "userAccount", userAccount, ret);
    ret = getUserInfoByUserAccount(userAccount.c_str(),
                                   reinterpret_cast<UserInfo *>(ptr));
  } break;

  case GET_USER_INFO_BY_UID: {
    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    ret = getUserInfoByUid(uid, reinterpret_cast<UserInfo *>(ptr));
  } break;

  case CREATE_DATA_STREAM: {
    bool ordered;
    get_parameter_bool(document, "ordered", ordered, ret);
    CHECK_RET_ERROR(ret)
    bool reliable;
    get_parameter_bool(document, "reliable", reliable, ret);
    CHECK_RET_ERROR(ret)
    ret = createDataStream(reinterpret_cast<int *>(ptr), reliable, ordered);
  } break;

  case SEND_STREAM_MESSAGE: {
    int streamId;
    get_parameter_int(document, "streamId", streamId, ret);
    CHECK_RET_ERROR(ret)
    int length;
    get_parameter_int(document, "length", length, ret);
    CHECK_RET_ERROR(ret)

    ret = sendStreamMessage(streamId, reinterpret_cast<const char *>(ptr),
                            size_t(length));
  } break;

  case SET_UP_LOCAL_VIDEO: {
    int renderMode;
    get_parameter_int(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    std::string channelId;
    get_parameter_string(document, "channelId", channelId, ret);
    CHECK_RET_ERROR(ret)

    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    int mirrorMode;
    get_parameter_int(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    VideoCanvas videoCanvas;
    videoCanvas.renderMode = renderMode;
    strncpy(videoCanvas.channelId, channelId.c_str(), MAX_CHANNEL_ID_LENGTH);
    videoCanvas.channelId[MAX_CHANNEL_ID_LENGTH - 1] = '\0';
    videoCanvas.uid = uid;
    videoCanvas.mirrorMode = VIDEO_MIRROR_MODE_TYPE(mirrorMode);
    videoCanvas.view = reinterpret_cast<view_t>(ptr);

    ret = setupLocalVideo(videoCanvas);
  } break;

  case SET_UP_REMOTE_VIDEO: {
    int renderMode;
    get_parameter_int(document, "renderMode", renderMode, ret);
    CHECK_RET_ERROR(ret)

    std::string channelId;
    get_parameter_string(document, "channelId", channelId, ret);
    CHECK_RET_ERROR(ret)

    rtc::uid_t uid;
    get_parameter_uint(document, "uid", uid, ret);
    CHECK_RET_ERROR(ret)

    int mirrorMode;
    get_parameter_int(document, "mirrorMode", mirrorMode, ret);
    CHECK_RET_ERROR(ret)

    VideoCanvas videoCanvas;
    videoCanvas.renderMode = renderMode;
    strncpy(videoCanvas.channelId, channelId.c_str(), MAX_CHANNEL_ID_LENGTH);
    videoCanvas.channelId[MAX_CHANNEL_ID_LENGTH - 1] = '\0';
    videoCanvas.uid = uid;
    videoCanvas.mirrorMode = VIDEO_MIRROR_MODE_TYPE(mirrorMode);
    videoCanvas.view = reinterpret_cast<view_t>(ptr);

    ret = setupRemoteVideo(videoCanvas);
  } break;

  case REGISTER_PACKET_OBSERVER: {
    // TODO
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

  case REGISTER_VIDEO_FRAME_OBSERVER: {
    ret = registerVideoFrameObserver(
        reinterpret_cast<media::IVideoFrameObserver *>(ptr));
  } break;

  default:
    ret = ERROR_CODE::ERROR_INVALID_API_TYPE;
    break;
  }
  return ret;
}

int RtcEngineBridge::initEventHandler(IRtcEngineEventHandler *eventHandler) {
  mRtcEngineEventHandler = eventHandler;
  return ERROR_CODE::ERROR_OK;
}

void RtcEngineBridge::add_C_EventHandler(
    CEngineEventHandler *engineEventHandler) {
  if (!mRtcEngineEventHandler)
    mRtcEngineEventHandler = new RtcEngineEventHandler();

  static_cast<RtcEngineEventHandler *>(mRtcEngineEventHandler)
      ->initCallbackEvent(engineEventHandler);
}

void RtcEngineBridge::remove_C_EventHandler() {
  if (mRtcEngineEventHandler) {
    delete (mRtcEngineEventHandler);
    mRtcEngineEventHandler = nullptr;
  }
}

int RtcEngineBridge::getUserInfoByUid(rtc::uid_t uid, UserInfo *userInfo) {
  LOG_JSON(GET_USER_INFO_BY_UID, "uid", uid);
  return mRtcEngine->getUserInfoByUid(uid, userInfo);
}

int RtcEngineBridge::getUserInfoByUserAccount(const char *userAccount,
                                              UserInfo *userInfo) {
  LOG_JSON(GET_USER_INFO_BY_USER_ACCOUNT, "userAccount", userAccount);
  return mRtcEngine->getUserInfoByUserAccount(userAccount, userInfo);
}

// cross-platform fix me EventHandler
int RtcEngineBridge::initialize(const char *appId, void *context,
                                unsigned int areaCode) {
  RtcEngineContext rtcEngineContext;
  rtcEngineContext.appId = appId;
  rtcEngineContext.context = nullptr;
  rtcEngineContext.areaCode = areaCode;
  rtcEngineContext.eventHandler = mRtcEngineEventHandler;

  LOG_JSON(INITIALIZE, "appId", appId, "areaCode", areaCode);
  return mRtcEngine->initialize(rtcEngineContext);
}

const char *RtcEngineBridge::getVersion() {
  LOG_JSON(GET_VERSION);
  int build;
  return mRtcEngine->getVersion(&build);
}

int RtcEngineBridge::setChannelProfile(CHANNEL_PROFILE_TYPE profile) {
  LOG_JSON(SET_CHANNEL_PROFILE, "profile", profile);
  return mRtcEngine->setChannelProfile(profile);
}

int RtcEngineBridge::setClientRole(CLIENT_ROLE_TYPE role) {
  LOG_JSON(SET_CLIENT_ROLE, "role", role);
  return mRtcEngine->setClientRole(role);
}

int RtcEngineBridge::joinChannel(const char *token, const char *channelId,
                                 const char *info, rtc::uid_t uid) {
  LOG_JSON(JOIN_CHANNEL, "token", token, "channelId", channelId, "info", info,
           "uid", uid);
  return mRtcEngine->joinChannel(token, channelId, info, uid);
}

int RtcEngineBridge::switchChannel(const char *token, const char *channelId) {
  LOG_JSON(SWITCH_CHANNEL, "token", token, "channelId", channelId);
  return mRtcEngine->switchChannel(token, channelId);
}

int RtcEngineBridge::leaveChannel() {
  LOG_JSON(LEAVE_CHANNEL);
  return mRtcEngine->leaveChannel();
}

int RtcEngineBridge::renewToken(const char *token) {
  LOG_JSON(RE_NEW_TOKEN, "token", token);
  return mRtcEngine->renewToken(token);
}

int RtcEngineBridge::registerLocalUserAccount(const char *appId,
                                              const char *userAccount) {
  LOG_JSON(REGISTER_LOCAL_USER_ACCOUNT, "appId", appId, "userAccount",
           userAccount);
  return mRtcEngine->registerLocalUserAccount(appId, userAccount);
}

int RtcEngineBridge::joinChannelWithUserAccount(const char *token,
                                                const char *channelId,
                                                const char *userAccount) {
  LOG_JSON(JOIN_CHANNEL_WITH_USER_ACCOUNT, "token", token, "channelId",
           channelId, "userAccount", userAccount);
  return mRtcEngine->joinChannelWithUserAccount(token, channelId, userAccount);
}

const char *RtcEngineBridge::getErrorDescription(int code) {
  LOG_JSON(GET_ERROR_DESCRIPTION, "code", code);
  return mRtcEngine->getErrorDescription(code);
}

int RtcEngineBridge::setLogFilter(unsigned int filter) {
  LOG_JSON(SET_LOG_FILTER, "filter", filter);
  return mRtcEngine->setLogFilter(filter);
}

int RtcEngineBridge::setLogFile(const char *file) {
  LOG_JSON(SET_LOG_FILE, "filePath", file);
  return mRtcEngine->setLogFile(file);
}

int RtcEngineBridge::setLogFileSize(unsigned int fileSizeInKBytes) {
  LOG_JSON(SET_LOG_FILE_SIZE, "fileSizeInKBytes", fileSizeInKBytes);
  return mRtcEngine->setLogFileSize(fileSizeInKBytes);
}

int RtcEngineBridge::setLocalRenderMode(RENDER_MODE_TYPE renderMode) {
  LOG_JSON(SET_LOCAL_RENDER_MODE, "renderMode", renderMode);
  return mRtcEngine->setLocalRenderMode(renderMode);
}

int RtcEngineBridge::setLocalRenderMode(RENDER_MODE_TYPE renderMode,
                                        VIDEO_MIRROR_MODE_TYPE mirrorMode) {
  LOG_JSON(SET_LOCAL_RENDER_MODE_2, "renderMode", renderMode, "mirrorMode",
           mirrorMode);
  return mRtcEngine->setLocalRenderMode(renderMode, mirrorMode);
}

int RtcEngineBridge::setRemoteRenderMode(rtc::uid_t userId,
                                         RENDER_MODE_TYPE renderMode) {
  LOG_JSON(SET_REMOTE_RENDER_MODE, "userId", userId, "renderMode", renderMode);
  return mRtcEngine->setRemoteRenderMode(userId, renderMode);
}

int RtcEngineBridge::setRemoteRenderMode(rtc::uid_t userId,
                                         RENDER_MODE_TYPE renderMode,
                                         VIDEO_MIRROR_MODE_TYPE mirrorMode) {
  LOG_JSON(SET_REMOTE_RENDER_MODE_2, "userId", userId, "renderMode", renderMode,
           "mirrorMode", mirrorMode);
  return mRtcEngine->setRemoteRenderMode(userId, renderMode, mirrorMode);
}

int RtcEngineBridge::enableLocalAudio(bool enabled) {
  LOG_JSON(ENABLE_LOCAL_AUDIO, "enabled", enabled);
  return mRtcEngine->enableLocalAudio(enabled);
}

int RtcEngineBridge::setAudioProfile(AUDIO_PROFILE_TYPE profile,
                                     AUDIO_SCENARIO_TYPE scenario) {
  LOG_JSON(SET_AUDIO_PROFILE, "profile", profile, "scenario", scenario);
  return mRtcEngine->setAudioProfile(profile, scenario);
}

int RtcEngineBridge::setDefaultMuteAllRemoteAudioStreams(bool mute) {
  LOG_JSON(SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS, "mute", mute);
  return mRtcEngine->setDefaultMuteAllRemoteAudioStreams(mute);
}

int RtcEngineBridge::setPlaybackDeviceVolume(int volume) {
  LOG_JSON(SET_PLAYBACK_DEVICE_VOLUME, "volume", volume);
  RtcEngineParameters rtcEngineParameters(mRtcEngine);
  return rtcEngineParameters.setPlaybackDeviceVolume(volume);
}

int RtcEngineBridge::enableAudioVolumeIndication(int interval, int smooth,
                                                 bool report_vad) {
  LOG_JSON(ENABLE_AUDIO_VOLUME_INDICATION, "interval", interval, "smooth",
           smooth, "report_vad", report_vad);
  return mRtcEngine->enableAudioVolumeIndication(interval, smooth, report_vad);
}

int RtcEngineBridge::startAudioRecording(const char *filePath,
                                         AUDIO_RECORDING_QUALITY_TYPE quality) {
  RtcEngineParameters rtcEngineParameters(mRtcEngine);
  LOG_JSON(START_AUDIO_RECORDING, "filePath", filePath, "quality", quality);
  return rtcEngineParameters.startAudioRecording(filePath, quality);
}

int RtcEngineBridge::stopAudioRecording() {
  LOG_JSON(STOP_AUDIO_RECORDING);
  RtcEngineParameters rtcEngineParameters(mRtcEngine);
  return rtcEngineParameters.stopAudioRecording();
}

int RtcEngineBridge::startEchoTest() {
  LOG_JSON(START_ECHO_TEST);
  return mRtcEngine->startEchoTest();
}

int RtcEngineBridge::startEchoTest(int intervalInSeconds) {
  LOG_JSON(START_ECHO_TEST_2, "intervalInSeconds", intervalInSeconds);
  return mRtcEngine->startEchoTest(intervalInSeconds);
}

int RtcEngineBridge::stopEchoTest() {
  LOG_JSON(STOP_ECHO_TEST);
  return mRtcEngine->stopEchoTest();
}

int RtcEngineBridge::enableVideo() {
  LOG_JSON(ENABLE_VIDEO);
  return mRtcEngine->enableVideo();
}

int RtcEngineBridge::disableVideo() {
  LOG_JSON(DISABLE_VIDEO);
  return mRtcEngine->disableVideo();
}

int RtcEngineBridge::setVideoProfile(VIDEO_PROFILE_TYPE profile,
                                     bool swapWidthAndHeight) {
  LOG_JSON(SET_VIDEO_PROFILE, "profile", profile, "swapWidthAndHeight",
           swapWidthAndHeight);
  return mRtcEngine->setVideoProfile(profile, swapWidthAndHeight);
}

int RtcEngineBridge::setVideoEncoderConfiguration(
    const VideoEncoderConfiguration &config) {
  LOG_JSON(SET_VIDEO_ENCODER_CONFIGURATION, config);
  return mRtcEngine->setVideoEncoderConfiguration(config);
}

int RtcEngineBridge::setCameraCapturerConfiguration(
    const CameraCapturerConfiguration &config) {
  LOG_JSON(SET_CAMERA_CAPTURER_CONFIGURATION, config);
  return mRtcEngine->setCameraCapturerConfiguration(config);
}

int RtcEngineBridge::startPreview() {
  LOG_JSON(START_PREVIEW);
  return mRtcEngine->startPreview();
}

int RtcEngineBridge::stopPreview() {
  LOG_JSON(STOP_PREVIEW);
  return mRtcEngine->stopPreview();
}

int RtcEngineBridge::setRemoteUserPriority(rtc::uid_t uid,
                                           PRIORITY_TYPE userPriority) {
  LOG_JSON(SET_REMOTE_USER_PRIORITY, "uid", uid, "userPriority", userPriority);
  return mRtcEngine->setRemoteUserPriority(uid, userPriority);
}

int RtcEngineBridge::enableAudio() {
  LOG_JSON(ENABLE_AUDIO);
  return mRtcEngine->enableAudio();
}

int RtcEngineBridge::disableAudio() {
  LOG_JSON(DISABLE_AUDIO);
  return mRtcEngine->disableAudio();
}

int RtcEngineBridge::muteLocalAudioStream(bool mute) {
  LOG_JSON(MUTE_LOCAL_AUDIO_STREAM, "mute", mute);
  return mRtcEngine->muteLocalAudioStream(mute);
}

int RtcEngineBridge::muteAllRemoteAudioStreams(bool mute) {
  LOG_JSON(MUTE_ALL_REMOTE_AUDIO_STREAMS, "mute", mute);
  return mRtcEngine->muteAllRemoteAudioStreams(mute);
}

int RtcEngineBridge::adjustUserPlaybackSignalVolume(unsigned int uid,
                                                    int volume) {
  LOG_JSON(ADJUST_USER_PLAYBACK_SIGNAL_VOLUME, "uid", uid, "volume", volume);
  return mRtcEngine->adjustUserPlaybackSignalVolume(uid, volume);
}

int RtcEngineBridge::muteRemoteAudioStream(rtc::uid_t userId, bool mute) {
  LOG_JSON(MUTE_REMOTE_AUDIO_STREAM, "userId", userId, "mute", mute);
  return mRtcEngine->muteRemoteAudioStream(userId, mute);
}

int RtcEngineBridge::muteLocalVideoStream(bool mute) {
  LOG_JSON(MUTE_LOCAL_VIDEO_STREAM, "mute", mute);
  return mRtcEngine->muteLocalVideoStream(mute);
}

int RtcEngineBridge::enableLocalVideo(bool enabled) {
  LOG_JSON(ENABLE_LOCAL_VIDEO, "enabled", enabled);
  return mRtcEngine->enableLocalVideo(enabled);
}

int RtcEngineBridge::muteAllRemoteVideoStreams(bool mute) {
  LOG_JSON(MUTE_ALL_REMOTE_VIDEO_STREAMS, "mute", mute);
  return mRtcEngine->muteAllRemoteVideoStreams(mute);
}

int RtcEngineBridge::setDefaultMuteAllRemoteVideoStreams(bool mute) {
  LOG_JSON(SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS, "mute", mute);
  return mRtcEngine->setDefaultMuteAllRemoteVideoStreams(mute);
}

int RtcEngineBridge::muteRemoteVideoStream(rtc::uid_t userId, bool mute) {
  LOG_JSON(MUTE_REMOTE_VIDEO_STREAM, "userId", userId, "mute", mute);
  return mRtcEngine->muteRemoteVideoStream(userId, mute);
}

int RtcEngineBridge::setRemoteVideoStreamType(
    rtc::uid_t userId, REMOTE_VIDEO_STREAM_TYPE streamType) {
  LOG_JSON(SET_REMOTE_VIDEO_STREAM_TYPE, "userId", userId, "streamType",
           streamType);
  return mRtcEngine->setRemoteVideoStreamType(userId, streamType);
}

int RtcEngineBridge::setRemoteDefaultVideoStreamType(
    REMOTE_VIDEO_STREAM_TYPE streamType) {
  LOG_JSON(SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE, "streamType", streamType);
  return mRtcEngine->setRemoteDefaultVideoStreamType(streamType);
}

int RtcEngineBridge::startAudioRecording(const char *filePath, int sampleRate,
                                         AUDIO_RECORDING_QUALITY_TYPE quality) {
  LOG_JSON(START_AUDIO_RECORDING2, "filePath", filePath, "sampleRate",
           sampleRate, "quality", quality);
  return mRtcEngine->startAudioRecording(filePath, sampleRate, quality);
}

int RtcEngineBridge::startAudioMixing(const char *filePath, bool loopback,
                                      bool replace, int cycle) {
  LOG_JSON(START_AUDIO_MIXING, "filePath", filePath, "loopback", loopback,
           "replace", replace, "cycle", cycle);
  return mRtcEngine->startAudioMixing(filePath, loopback, replace, cycle);
}

int RtcEngineBridge::stopAudioMixing() {
  LOG_JSON(STOP_AUDIO_MIXING);
  return mRtcEngine->stopAudioMixing();
}

int RtcEngineBridge::pauseAudioMixing() {
  LOG_JSON(PAUSE_AUDIO_MIXING);
  return mRtcEngine->pauseAudioMixing();
}

int RtcEngineBridge::resumeAudioMixing() {
  LOG_JSON(RESUME_AUDIO_MIXING);
  return mRtcEngine->resumeAudioMixing();
}

int RtcEngineBridge::setHighQualityAudioParameters(bool fullband, bool stereo,
                                                   bool fullBitrate) {
  LOG_JSON(SET_HIGH_QUALITY_AUDIO_PARAMETERS, "fullband", fullband, "stereo",
           stereo, "fullBitrate", fullBitrate);
  return mRtcEngine->setHighQualityAudioParameters(fullband, stereo,
                                                   fullBitrate);
}

int RtcEngineBridge::adjustAudioMixingVolume(int volume) {
  LOG_JSON(ADJUST_AUDIO_MIXING_VOLUME, "volume", volume);
  return mRtcEngine->adjustAudioMixingVolume(volume);
}

int RtcEngineBridge::adjustAudioMixingPlayoutVolume(int volume) {
  LOG_JSON(ADJUST_AUDIO_MIXING_PLAYOUT_VOLUME, "volume", volume);
  return mRtcEngine->adjustAudioMixingPlayoutVolume(volume);
}

int RtcEngineBridge::getAudioMixingPlayoutVolume() {
  LOG_JSON(GET_AUDIO_MIXING_PLAYOUT_VOLUME);
  return mRtcEngine->getAudioMixingPlayoutVolume();
}

int RtcEngineBridge::adjustAudioMixingPublishVolume(int volume) {
  LOG_JSON(ADJUST_AUDIO_MIXING_PUBLISH_VOLUME, "volume", volume);
  return mRtcEngine->adjustAudioMixingPublishVolume(volume);
}

int RtcEngineBridge::getAudioMixingPublishVolume() {
  LOG_JSON(GET_AUDIO_MIXING_PUBLISH_VOLUME);
  return mRtcEngine->getAudioMixingPublishVolume();
}

int RtcEngineBridge::getAudioMixingDuration() {
  LOG_JSON(GET_AUDIO_MIXING_DURATION);
  return mRtcEngine->getAudioMixingDuration();
}

int RtcEngineBridge::getAudioMixingCurrentPosition() {
  LOG_JSON(GET_AUDIO_MIXING_CURRENT_POSITION);
  return mRtcEngine->getAudioMixingCurrentPosition();
}

int RtcEngineBridge::setAudioMixingPosition(int pos /*in ms*/) {
  LOG_JSON(SET_AUDIO_MIXING_POSITION, "pos", pos);
  return mRtcEngine->setAudioMixingPosition(pos);
}

int RtcEngineBridge::setAudioMixingPitch(int pitch) {
  LOG_JSON(SET_AUDIO_MIXING_PITCH, "pitch", pitch);
  return mRtcEngine->setAudioMixingPitch(pitch);
}

int RtcEngineBridge::getEffectsVolume() {
  LOG_JSON(GET_EFFECTS_VOLUME);
  return mRtcEngine->getEffectsVolume();
}

int RtcEngineBridge::setEffectsVolume(int volume) {
  LOG_JSON(SET_EFFECTS_VOLUME, "volume", volume);
  return mRtcEngine->setEffectsVolume(volume);
}

int RtcEngineBridge::setVolumeOfEffect(int soundId, int volume) {
  LOG_JSON(SET_VOLUME_OF_EFFECT, "soundId", soundId, "volume", volume);
  return mRtcEngine->setVolumeOfEffect(soundId, volume);
}

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
int RtcEngineBridge::enableFaceDetection(bool enable) {
  LOG_JSON(ENABLE_FACE_DETECTION, "enabled", enable);
  return mRtcEngine->enableFaceDetection(enable);
}
#endif

int RtcEngineBridge::playEffect(int soundId, const char *filePath,
                                int loopCount, double pitch, double pan,
                                int gain, bool publish) {
  LOG_JSON(PLAY_EFFECT, "soundId", soundId, "filePath", filePath, "loopCount",
           loopCount, "pitch", pitch, "pan", pan, "gain", gain, "publish",
           publish);
  return mRtcEngine->playEffect(soundId, filePath, loopCount, pitch, pan, gain,
                                publish);
}

int RtcEngineBridge::stopEffect(int soundId) {
  LOG_JSON(STOP_EFFECT, "soundId", soundId);
  return mRtcEngine->stopEffect(soundId);
}

int RtcEngineBridge::stopAllEffects() {
  LOG_JSON(STOP_ALL_EFFECTS);
  return mRtcEngine->stopAllEffects();
}

int RtcEngineBridge::preloadEffect(int soundId, const char *filePath) {
  LOG_JSON(PRE_LOAD_EFFECT, "soundId", soundId, "filePath", filePath);
  return mRtcEngine->preloadEffect(soundId, filePath);
}

int RtcEngineBridge::unloadEffect(int soundId) {
  LOG_JSON(UN_LOAD_EFFECT, "soundId", soundId);
  return mRtcEngine->unloadEffect(soundId);
}

int RtcEngineBridge::pauseEffect(int soundId) {
  LOG_JSON(PAUSE_EFFECT, "soundId", soundId);
  return mRtcEngine->pauseEffect(soundId);
}

int RtcEngineBridge::pauseAllEffects() {
  LOG_JSON(PAUSE_ALL_EFFECTS);
  return mRtcEngine->pauseAllEffects();
}

int RtcEngineBridge::resumeEffect(int soundId) {
  LOG_JSON(RESUME_EFFECT, "soundId", soundId);
  return mRtcEngine->resumeEffect(soundId);
}

int RtcEngineBridge::resumeAllEffects() {
  LOG_JSON(RESUME_ALL_EFFECTS);
  return mRtcEngine->resumeAllEffects();
}

int RtcEngineBridge::enableSoundPositionIndication(bool enabled) {
  LOG_JSON(ENABLE_SOUND_POSITION_INDICATION, "enabled", enabled);
  return mRtcEngine->enableSoundPositionIndication(enabled);
}

int RtcEngineBridge::setRemoteVoicePosition(rtc::uid_t uid, double pan,
                                            double gain) {
  LOG_JSON(SET_REMOTE_VOICE_POSITIONN, "uid", uid, "pan", pan, "gain", gain);
  return mRtcEngine->setRemoteVoicePosition(uid, pan, gain);
}

int RtcEngineBridge::setLocalVoicePitch(double pitch) {
  LOG_JSON(SET_LOCAL_VOICE_PITCH, "pitch", pitch);
  return mRtcEngine->setLocalVoicePitch(pitch);
}

int RtcEngineBridge::setLocalVoiceEqualization(
    AUDIO_EQUALIZATION_BAND_FREQUENCY bandFrequency, int bandGain) {
  LOG_JSON(SET_LOCAL_VOICE_EQUALIZATION, "bandFrequency", bandFrequency,
           "bandGain", bandGain);
  return mRtcEngine->setLocalVoiceEqualization(bandFrequency, bandGain);
}

int RtcEngineBridge::setLocalVoiceReverb(AUDIO_REVERB_TYPE reverbKey,
                                         int value) {
  LOG_JSON(SET_LOCAL_VOICE_REVERB, "reverbKey", reverbKey, "value", value);
  return mRtcEngine->setLocalVoiceReverb(reverbKey, value);
}

int RtcEngineBridge::setLocalVoiceChanger(VOICE_CHANGER_PRESET voiceChanger) {
  LOG_JSON(SET_LOCAL_VOICE_CHANGER, "voiceChanger", voiceChanger);
  return mRtcEngine->setLocalVoiceChanger(voiceChanger);
}

int RtcEngineBridge::setLocalVoiceReverbPreset(
    AUDIO_REVERB_PRESET reverbPreset) {
  LOG_JSON(SET_LOCAL_VOICE_REVERB_PRESET, "reverbPreset", reverbPreset);
  return mRtcEngine->setLocalVoiceReverbPreset(reverbPreset);
}

int RtcEngineBridge::adjustRecordingSignalVolume(int volume) {
  LOG_JSON(ADJUST_RECORDING_SIGNAL_VOLUME, "volume", volume);
  return mRtcEngine->adjustRecordingSignalVolume(volume);
}

int RtcEngineBridge::adjustPlaybackSignalVolume(int volume) {
  LOG_JSON(ADJUST_PLAYBACK_SIGNAL_VOLUME, "volume", volume);
  return mRtcEngine->adjustPlaybackSignalVolume(volume);
}

int RtcEngineBridge::setExternalAudioSource(bool enabled, int sampleRate,
                                            int channels) {
  LOG_JSON(SET_EXTERNAL_AUDIO_SOURCE, "enabled", enabled, "sampleRate",
           sampleRate, "channels", channels);
  return mRtcEngine->setExternalAudioSource(enabled, sampleRate, channels);
}

int RtcEngineBridge::setExternalAudioSink(bool enabled, int sampleRate,
                                          int channels) {
  LOG_JSON(SET_EXTERNAL_AUDIO_SINK, "enabled", enabled, "sampleRate",
           sampleRate, "channels", channels);
  return mRtcEngine->setExternalAudioSink(enabled, sampleRate, channels);
}

int RtcEngineBridge::setRecordingAudioFrameParameters(
    int sampleRate, int channel, RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
    int samplesPerCall) {
  LOG_JSON(SET_RECORDING_AUDIO_FRAME_PARAMETERS, "sampleRate", sampleRate,
           "channel", channel, "mode", mode, "samplesPerCall", samplesPerCall);
  return mRtcEngine->setRecordingAudioFrameParameters(sampleRate, channel, mode,
                                                      samplesPerCall);
}

int RtcEngineBridge::setPlaybackAudioFrameParameters(
    int sampleRate, int channel, RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
    int samplesPerCall) {
  LOG_JSON(SET_PLAYBACK_AUDIO_FRAME_PARAMETERS, "sampleRate", sampleRate,
           "channel", channel, "mode", mode, "samplesPerCall", samplesPerCall);
  return mRtcEngine->setPlaybackAudioFrameParameters(sampleRate, channel, mode,
                                                     samplesPerCall);
}

int RtcEngineBridge::setMixedAudioFrameParameters(int sampleRate,
                                                  int samplesPerCall) {
  LOG_JSON(SET_MIXED_AUDIO_FRAME_PARAMETERS, "sampleRate", sampleRate,
           "samplesPerCall", samplesPerCall);
  return mRtcEngine->setMixedAudioFrameParameters(sampleRate, samplesPerCall);
}

int RtcEngineBridge::enableWebSdkInteroperability(bool enabled) {
  LOG_JSON(ENABLE_WEB_SDK_INTEROPER_ABILITY, "enabled", enabled);
  return mRtcEngine->enableWebSdkInteroperability(enabled);
}

int RtcEngineBridge::setVideoQualityParameters(
    bool preferFrameRateOverImageQuality) {
  LOG_JSON(SET_VIDEO_QUALITY_PARAMETERS, "preferFrameRateOverImageQuality",
           preferFrameRateOverImageQuality);
  return mRtcEngine->setVideoQualityParameters(preferFrameRateOverImageQuality);
}

int RtcEngineBridge::setLocalPublishFallbackOption(
    STREAM_FALLBACK_OPTIONS option) {
  LOG_JSON(SET_LOCAL_PUBLISH_FALLBACK_OPTION, "option", option);
  return mRtcEngine->setLocalPublishFallbackOption(option);
}

int RtcEngineBridge::setRemoteSubscribeFallbackOption(
    STREAM_FALLBACK_OPTIONS option) {
  LOG_JSON(SET_REMOTE_SUBSCRIBE_FALLBACK_OPTION, "option", option);
  return mRtcEngine->setRemoteSubscribeFallbackOption(option);
}

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)
int RtcEngineBridge::switchCamera() {
  LOG_JSON(SWITCH_CAMERA);
  return mRtcEngine->switchCamera();
}

int RtcEngineBridge::switchCamera(CAMERA_DIRECTION direction) {
  LOG_JSON(SWITCH_CAMERA_2, "direction", direction);
  return mRtcEngine->switchCamera(direction);
}

int RtcEngineBridge::setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker) {
  LOG_JSON(SET_DEFAULT_AUDIO_ROUTE_SPEAKER_PHONE, "defaultToSpeaker",
           defaultToSpeaker);
  return mRtcEngine->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);
}

int RtcEngineBridge::setEnableSpeakerphone(bool speakerOn) {
  LOG_JSON(SET_ENABLE_SPEAKER_PHONE, "speakerOn", speakerOn);
  return mRtcEngine->setEnableSpeakerphone(speakerOn);
}

int RtcEngineBridge::enableInEarMonitoring(bool enabled) {
  LOG_JSON(ENABLE_IN_EAR_MONITORING, "enabled", enabled);
  return mRtcEngine->enableInEarMonitoring(enabled);
}

int RtcEngineBridge::setInEarMonitoringVolume(int volume) {
  LOG_JSON(SET_IN_EAR_MONITORING_VOLUME, "volume", volume);
  return mRtcEngine->setInEarMonitoringVolume(volume);
}

bool RtcEngineBridge::isSpeakerphoneEnabled() {
  LOG_JSON(IS_SPEAKER_PHONE_ENABLED);
  return mRtcEngine->isSpeakerphoneEnabled();
}
#endif

#if (defined(__APPLE__) && TARGET_OS_IOS)
int RtcEngineBridge::setAudioSessionOperationRestriction(
    rtc::AUDIO_SESSION_OPERATION_RESTRICTION restriction) {
  LOG_JSON(SET_AUDIO_SESSION_OPERATION_RESTRICTION, "restriction", restriction);
  return mRtcEngine->setAudioSessionOperationRestriction(restriction);
}
#endif

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE) ||              \
    defined(_WIN32)
int RtcEngineBridge::enableLoopbackRecording(bool enabled,
                                             const char *deviceName) {
  LOG_JSON(ENABLE_LOOP_BACK_RECORDING, "enabled", enabled, "deviceName",
           deviceName);
  return mRtcEngine->enableLoopbackRecording(enabled, deviceName);
}

#if (defined(__APPLE__) && TARGET_OS_MAC && !TARGET_OS_IPHONE)
int RtcEngineBridge::startScreenCaptureByDisplayId(
    unsigned int displayId, const rtc::Rectangle &regionRect,
    const rtc::ScreenCaptureParameters &captureParams) {
  LOG_JSON(START_SCREEN_CAPTURE_BY_DISPLAY_ID, displayId, regionRect,
           captureParams);
  return mRtcEngine->startScreenCaptureByDisplayId(displayId, regionRect,
                                                   captureParams);
}
#endif

#if defined(_WIN32)
int RtcEngineBridge::startScreenCaptureByScreenRect(
    const rtc::Rectangle &screenRect, const rtc::Rectangle &regionRect,
    const rtc::ScreenCaptureParameters &captureParams) {
  LOG_JSON(START_SCREEN_CAPTURE_BY_SCREEN_RECT, screenRect, regionRect,
           captureParams);
  return mRtcEngine->startScreenCaptureByScreenRect(screenRect, regionRect,
                                                    captureParams);
}

int RtcEngineBridge::startScreenCaptureByWindowId(
    rtc::view_t windowId, const rtc::Rectangle &regionRect,
    const rtc::ScreenCaptureParameters &captureParams) {
  LOG_JSON(START_SCREEN_CAPTURE_BY_WINDOW_ID, windowId, regionRect,
           captureParams);
  return mRtcEngine->startScreenCaptureByWindowId(windowId, regionRect,
                                                  captureParams);
}

int RtcEngineBridge::setScreenCaptureContentHint(
    rtc::VideoContentHint contentHint) {
  LOG_JSON(SET_SCREEN_CAPTURE_CONTENT_HINT, "contentHint", contentHint);
  return mRtcEngine->setScreenCaptureContentHint(contentHint);
}

int RtcEngineBridge::updateScreenCaptureParameters(
    const rtc::ScreenCaptureParameters &captureParams) {
  LOG_JSON(UPDATE_SCREEN_CAPTURE_PARAMETERS, captureParams);
  return mRtcEngine->updateScreenCaptureParameters(captureParams);
}

int RtcEngineBridge::updateScreenCaptureRegion(
    const rtc::Rectangle &regionRect) {
  LOG_JSON(UPDATE_SCREEN_CAPTURE_REGION, regionRect);
  return mRtcEngine->updateScreenCaptureRegion(regionRect);
}

int RtcEngineBridge::updateScreenCaptureRegion(const rtc::Rect *rect) {
  //        LOG_JSON(UPDATE_SCREEN_CAPTURE_REGION, *rect);
  return mRtcEngine->updateScreenCaptureRegion(rect);
}
#endif

int RtcEngineBridge::stopScreenCapture() {
  LOG_JSON(STOP_SCREEN_CAPTURE);
  return mRtcEngine->stopScreenCapture();
}
#endif

RtcChannelBridge *RtcEngineBridge::createChannel(const char *channelId) {
  return new RtcChannelBridge(mRtcEngine, channelId);
}

IAudioDeviceManagerBridge *
RtcEngineBridge::createAudioDeviceManager(DEVICE_TYPE device_type,
                                          ERROR_CODE &erroCode) {
  switch (device_type) {
  case DEVICE_TYPE::PLAYBACK_DEVICE:
    return new AudioPlaybackDeviceManager(mRtcEngine, erroCode);

  case DEVICE_TYPE::RECORDING_DEVICE:
    return new AudioRecordingDeviceManager(mRtcEngine, erroCode);

  default:
    return nullptr;
  }
}

VideoDeviceManager *RtcEngineBridge::createVideoDeviceManager(int *errorCode) {
  ERROR_CODE code;
  auto p = new VideoDeviceManager(mRtcEngine, code);
  *errorCode = code;
  return p;
}

AudioPlaybackDeviceManager *
RtcEngineBridge::createAudioPlaybackDeviceManager(int *errorCode) {
  ERROR_CODE code;
  auto p = new AudioPlaybackDeviceManager(mRtcEngine, code);
  *errorCode = code;
  return p;
}

AudioRecordingDeviceManager *
RtcEngineBridge::createAudioRecordingDeviceManager(int *errorCode) {
  ERROR_CODE code;
  auto p = new AudioRecordingDeviceManager(mRtcEngine, code);
  *errorCode = code;
  return p;
}

IVideoDeviceManagerBridge *
RtcEngineBridge::createVideoDeviceManager(ERROR_CODE &error_code) {
  return new VideoDeviceManager(mRtcEngine, error_code);
}

void RtcEngineBridge::release(bool sync) {
  IRtcEngine::release(sync);
  mRtcEngine = nullptr;
  delete this;
}

int RtcEngineBridge::setupLocalVideo(const VideoCanvas &canvas) {
  LOG_JSON(SET_UP_LOCAL_VIDEO, canvas);
  return mRtcEngine->setupLocalVideo(canvas);
}

int RtcEngineBridge::setupRemoteVideo(const VideoCanvas &canvas) {
  LOG_JSON(SET_UP_REMOTE_VIDEO, canvas);
  return mRtcEngine->setupRemoteVideo(canvas);
}

int RtcEngineBridge::setLocalVideoMirrorMode(
    VIDEO_MIRROR_MODE_TYPE mirrorMode) {
  LOG_JSON(SET_LOCAL_VIDEO_MIRROR_MODE, "mirrorMode", mirrorMode);
  return mRtcEngine->setLocalVideoMirrorMode(mirrorMode);
}

int RtcEngineBridge::enableDualStreamMode(bool enabled) {
  LOG_JSON(ENABLE_DUAL_STREAM_MODE, "enabled", enabled);
  return mRtcEngine->enableDualStreamMode(enabled);
}

int RtcEngineBridge::getCallId(agora::util::AString &callId) {
  LOG_JSON(GET_CALL_ID);
  return mRtcEngine->getCallId(callId);
}

int RtcEngineBridge::rate(const char *callId, int rating,
                          const char *description) {
  LOG_JSON(RATE, "callId", callId, "rating", rating, "description",
           description);
  return mRtcEngine->rate(callId, rating, description);
}

int RtcEngineBridge::complain(const char *callId, const char *description) {
  LOG_JSON(COMPLAIN, "callId", callId, "description", description);
  return mRtcEngine->complain(callId, description);
}

int RtcEngineBridge::enableLastmileTest() {
  LOG_JSON(ENABLE_LAST_MILE_TEST);
  return mRtcEngine->enableLastmileTest();
}

int RtcEngineBridge::disableLastmileTest() {
  LOG_JSON(DISABLE_LAST_MILE_TEST);
  return mRtcEngine->disableLastmileTest();
}

int RtcEngineBridge::startLastmileProbeTest(const LastmileProbeConfig &config) {
  LOG_JSON(START_LAST_MILE_PROBE_TEST, config);
  return mRtcEngine->startLastmileProbeTest(config);
}

int RtcEngineBridge::stopLastmileProbeTest() {
  LOG_JSON(STOP_LAST_MILE_PROBE_TEST);
  return mRtcEngine->stopLastmileProbeTest();
}

int RtcEngineBridge::setEncryptionSecret(const char *secret) {
  LOG_JSON(SET_ENCRYPTION_SECTRT, "secret", secret);
  return mRtcEngine->setEncryptionSecret(secret);
}

int RtcEngineBridge::setEncryptionMode(const char *encryptionMode) {
  LOG_JSON(SET_ENCRYPTION_MODE, "encryptionMode", encryptionMode);
  return mRtcEngine->setEncryptionMode(encryptionMode);
}

int RtcEngineBridge::registerPacketObserver(IPacketObserver *observer) {
  // TODO
  return 0;
}

int RtcEngineBridge::createDataStream(int *streamId, bool reliable,
                                      bool ordered) {
  LOG_JSON(CREATE_DATA_STREAM, "ordered", ordered, "reliable", reliable);
  return mRtcEngine->createDataStream(streamId, reliable, ordered);
}

int RtcEngineBridge::sendStreamMessage(int streamId, const char *data,
                                       size_t length) {
  LOG_JSON(SEND_STREAM_MESSAGE, "streamId", streamId, "length",
           (uint64_t)length);
  return mRtcEngine->sendStreamMessage(streamId, data, length);
}

int RtcEngineBridge::addPublishStreamUrl(const char *url,
                                         bool transcodingEnabled) {
  LOG_JSON(ADD_PUBLISH_STREAM_URL, "url", url, "transcodingEnabled",
           transcodingEnabled);
  return mRtcEngine->addPublishStreamUrl(url, transcodingEnabled);
}

int RtcEngineBridge::removePublishStreamUrl(const char *url) {
  LOG_JSON(REMOVE_PUBLISH_STREAM_URL, "url", url);
  return mRtcEngine->removePublishStreamUrl(url);
}

int RtcEngineBridge::setLiveTranscoding(const LiveTranscoding &transcoding) {
  LOG_JSON(SET_LIVE_TRANSCODING, transcoding);
  return mRtcEngine->setLiveTranscoding(transcoding);
}

int RtcEngineBridge::addVideoWatermark(const RtcImage &watermark) {
  LOG_JSON(ADD_VIDEO_WATER_MARK, watermark);
  return mRtcEngine->addVideoWatermark(watermark);
}

int RtcEngineBridge::addVideoWatermark(const char *watermarkUrl,
                                       const WatermarkOptions &options) {
  LOG_JSON(ADD_VIDEO_WATER_MARK_2, watermarkUrl, options);
  return mRtcEngine->addVideoWatermark(watermarkUrl, options);
}

int RtcEngineBridge::clearVideoWatermarks() {
  LOG_JSON(CLEAR_VIDEO_WATER_MARKS);
  return mRtcEngine->clearVideoWatermarks();
}

int RtcEngineBridge::setBeautyEffectOptions(bool enabled,
                                            BeautyOptions options) {
  LOG_JSON(SET_BEAUTY_EFFECT_OPTIONS, enabled, options);
  return mRtcEngine->setBeautyEffectOptions(enabled, options);
}

int RtcEngineBridge::addInjectStreamUrl(const char *url,
                                        const InjectStreamConfig &config) {
  LOG_JSON(ADD_INJECT_STREAM_URL, url, config);
  return mRtcEngine->addInjectStreamUrl(url, config);
}

int RtcEngineBridge::startChannelMediaRelay(
    const ChannelMediaRelayConfiguration &configuration) {
  LOG_JSON(START_CHANNEL_MEDIA_RELAY, configuration);
  return mRtcEngine->startChannelMediaRelay(configuration);
}

int RtcEngineBridge::updateChannelMediaRelay(
    const ChannelMediaRelayConfiguration &configuration) {
  LOG_JSON(UPDATE_CHANNEL_MEDIA_RELAY, configuration);
  return mRtcEngine->updateChannelMediaRelay(configuration);
}

int RtcEngineBridge::stopChannelMediaRelay() {
  LOG_JSON(STOP_CHANNEL_MEDIA_RELAY);
  return mRtcEngine->stopChannelMediaRelay();
}

int RtcEngineBridge::removeInjectStreamUrl(const char *url) {
  LOG_JSON(REMOVE_INJECT_STREAM_URL, "url", url);
  return mRtcEngine->removeInjectStreamUrl(url);
}

CONNECTION_STATE_TYPE
RtcEngineBridge::getConnectionState() {
  LOG_JSON(GET_CONNECTION_STATE);
  return mRtcEngine->getConnectionState();
}

int RtcEngineBridge::registerMediaMetadataObserver(
    IMetadataObserver *observer, IMetadataObserver::METADATA_TYPE type,
    bool useSdkDefault) {
  LOG_JSON(REGISTER_MEDIA_META_DATA_OBSERVER, "type", type, "useSdkDefault",
           useSdkDefault);
  int ret;
  if (useSdkDefault) {
    ret = mRtcEngine->registerMediaMetadataObserver(observer, type);
  } else {
    if (observer) {
      if (metadataObserver) {
        mRtcEngine->registerMediaMetadataObserver(nullptr, type);
        delete (metadataObserver);
        metadataObserver = nullptr;
        metadataObserver = new MetadataObserver(observer);
        ret = mRtcEngine->registerMediaMetadataObserver(metadataObserver, type);
      } else {
        metadataObserver = new MetadataObserver(observer);
        ret = mRtcEngine->registerMediaMetadataObserver(metadataObserver, type);
      }
    } else {
      ret = mRtcEngine->registerMediaMetadataObserver(nullptr, type);
      if (metadataObserver) {
        delete (metadataObserver);
        metadataObserver = nullptr;
      }
    }
  }

  return ret;
}

int RtcEngineBridge::setParameters(const char *parameters) {
  LOG_JSON(SET_PARAMETERS, "parameters", parameters);
  return mRtcEngine->setParameters(parameters);
}

int RtcEngineBridge::sendMetadata(rtc::IMetadataObserver::Metadata *metadata) {
  LOG_JSON(SEND_METADATA, metadata);
  if (metadataObserver) {
    return metadataObserver->sendMetadata(metadata);
  }

  return ERROR_CODE::ERROR_NOT_INITIALIZE_OBSERVER;
}

int RtcEngineBridge::setMaxMetadataSize(int size) {
  LOG_JSON(SET_MAX_META_SIZE, "size", size);
  if (metadataObserver) {
    return metadataObserver->setMaxMetadataSize(size);
  }

  return ERROR_CODE::ERROR_NOT_INITIALIZE_OBSERVER;
}

int RtcEngineBridge::pushAudioFrame(
    media::MEDIA_SOURCE_TYPE type,
    media::IAudioFrameObserver::AudioFrame *frame, bool wrap) {
  if (!mediaEngine.get()) {
    mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  }

  return mediaEngine->pushAudioFrame(type, frame, wrap);
}

int RtcEngineBridge::pushAudioFrame(
    agora::media::IAudioFrameObserver::AudioFrame *frame) {
  if (!mediaEngine.get()) {
    mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  }

  return mediaEngine->pushAudioFrame(frame);
}

int RtcEngineBridge::pullAudioFrame(
    media::IAudioFrameObserver::AudioFrame *frame) {
  if (!mediaEngine.get()) {
    mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  }

  return mediaEngine->pullAudioFrame(frame);
}

int RtcEngineBridge::setExternalVideoSource(bool enable, bool useTexture) {
  if (!mediaEngine.get()) {
    mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  }

  return mediaEngine->setExternalVideoSource(enable, useTexture);
}

int RtcEngineBridge::pushVideoFrame(media::ExternalVideoFrame *frame) {
  if (!mediaEngine.get()) {
    mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  }

  return mediaEngine->pushVideoFrame(frame);
}

int RtcEngineBridge::enableEncryption(
    bool enabled, const agora::rtc::EncryptionConfig &config) {
  return mRtcEngine->enableEncryption(enabled, config);
}

int RtcEngineBridge::sendCustomReportMessage(const char *id,
                                             const char *category,
                                             const char *event,
                                             const char *label, int value) {
  return mRtcEngine->sendCustomReportMessage(id, category, event, label, value);
}

int RtcEngineBridge::registerVideoFrameObserver(
    media::IVideoFrameObserver *videoFrameObserver) {
  agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
  mediaEngine.queryInterface(mRtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
  if (mediaEngine)
    return mediaEngine->registerVideoFrameObserver(videoFrameObserver);

  return ERROR_CODE::ERROR_NO_ENGINE;
}

CROSS_PLATFORM_EXPORT IRtcEngineBridge *createRtcEngineBridge() {
  return new RtcEngineBridge();
}
} // namespace common
} // namespace agora
