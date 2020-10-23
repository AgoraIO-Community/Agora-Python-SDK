//
// Created by 张涛 on 2020-08-18.
//

#pragma once

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int BOOL;
typedef unsigned int uid_t;

#define TRUE 1
#define FALSE 0

enum API_TYPE {
  INITIALIZE = 0,
  RELEASE = 1,
  SET_CHANNEL_PROFILE = 2,
  SET_CLIENT_ROLE = 3,
  JOIN_CHANNEL = 4,
  SWITCH_CHANNEL = 5,
  LEAVE_CHANNEL = 6,
  RE_NEW_TOKEN = 7,
  REGISTER_LOCAL_USER_ACCOUNT = 8,
  JOIN_CHANNEL_WITH_USER_ACCOUNT = 9,
  GET_USER_INFO_BY_USER_ACCOUNT = 10,
  GET_USER_INFO_BY_UID = 11,
  START_ECHO_TEST = 12,
  START_ECHO_TEST_2 = 13,
  STOP_ECHO_TEST = 14,
  ENABLE_VIDEO = 15,
  DISABLE_VIDEO = 16,
  SET_VIDEO_PROFILE = 17,
  SET_VIDEO_ENCODER_CONFIGURATION = 18,
  SET_CAMERA_CAPTURER_CONFIGURATION = 19,
  SET_UP_LOCAL_VIDEO = 20,
  SET_UP_REMOTE_VIDEO = 21,
  START_PREVIEW = 22,
  SET_REMOTE_USER_PRIORITY = 23,
  STOP_PREVIEW = 24,
  ENABLE_AUDIO = 25,
  ENABLE_LOCAL_AUDIO = 26,
  DISABLE_AUDIO = 27,
  SET_AUDIO_PROFILE = 28,
  MUTE_LOCAL_AUDIO_STREAM = 29,
  MUTE_ALL_REMOTE_AUDIO_STREAMS = 30,
  SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS = 31,
  ADJUST_USER_PLAYBACK_SIGNAL_VOLUME = 32,
  MUTE_REMOTE_AUDIO_STREAM = 33,
  MUTE_LOCAL_VIDEO_STREAM = 34,
  ENABLE_LOCAL_VIDEO = 35,
  MUTE_ALL_REMOTE_VIDEO_STREAMS = 36,
  SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS = 37,
  MUTE_REMOTE_VIDEO_STREAM = 38,
  SET_REMOTE_VIDEO_STREAM_TYPE = 39,
  SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE = 40,
  ENABLE_AUDIO_VOLUME_INDICATION = 41,
  START_AUDIO_RECORDING = 42,
  START_AUDIO_RECORDING2 = 43,
  STOP_AUDIO_RECORDING = 44,
  ENABLE_FACE_DETECTION = 62,
  SET_REMOTE_VOICE_POSITIONN = 73,
  SET_LOG_FILE = 79,
  SET_LOG_FILTER = 80,
  SET_LOG_FILE_SIZE = 81,
  SET_LOCAL_RENDER_MODE = 82,
  SET_LOCAL_RENDER_MODE_2 = 83,
  SET_REMOTE_RENDER_MODE = 84,
  SET_REMOTE_RENDER_MODE_2 = 85,
  SET_LOCAL_VIDEO_MIRROR_MODE = 86,
  ENABLE_DUAL_STREAM_MODE = 87,
  ADJUST_RECORDING_SIGNAL_VOLUME = 93,
  ADJUST_PLAYBACK_SIGNAL_VOLUME = 94,
  ENABLE_WEB_SDK_INTEROPER_ABILITY = 95,
  SET_VIDEO_QUALITY_PARAMETERS = 96,
  SET_LOCAL_PUBLISH_FALLBACK_OPTION = 97,
  SET_REMOTE_SUBSCRIBE_FALLBACK_OPTION = 98,
  SWITCH_CAMERA = 99,
  SWITCH_CAMERA_2 = 100,
  SET_DEFAULT_AUDIO_ROUTE_SPEAKER_PHONE = 101,
  SET_ENABLE_SPEAKER_PHONE = 102,
  ENABLE_IN_EAR_MONITORING = 103,
  SET_IN_EAR_MONITORING_VOLUME = 104,
  IS_SPEAKER_PHONE_ENABLED = 105,
  SET_AUDIO_SESSION_OPERATION_RESTRICTION = 106,
  ENABLE_LOOP_BACK_RECORDING = 107,
  START_SCREEN_CAPTURE_BY_DISPLAY_ID = 108,
  START_SCREEN_CAPTURE_BY_SCREEN_RECT = 109,
  START_SCREEN_CAPTURE_BY_WINDOW_ID = 110,
  SET_SCREEN_CAPTURE_CONTENT_HINT = 111,
  UPDATE_SCREEN_CAPTURE_PARAMETERS = 112,
  UPDATE_SCREEN_CAPTURE_REGION = 113,
  STOP_SCREEN_CAPTURE = 114,
  GET_CALL_ID = 117,
  RATE = 118,
  COMPLAIN = 119,
  GET_VERSION = 120,
  ENABLE_LAST_MILE_TEST = 121,
  DISABLE_LAST_MILE_TEST = 122,
  START_LAST_MILE_PROBE_TEST = 123,
  STOP_LAST_MILE_PROBE_TEST = 124,
  GET_ERROR_DESCRIPTION = 125,
  SET_ENCRYPTION_SECTRT = 126,
  SET_ENCRYPTION_MODE = 127,
  REGISTER_PACKET_OBSERVER = 128,
  CREATE_DATA_STREAM = 129,
  SEND_STREAM_MESSAGE = 130,
  ADD_PUBLISH_STREAM_URL = 131,
  REMOVE_PUBLISH_STREAM_URL = 132,
  SET_LIVE_TRANSCODING = 133,
  ADD_VIDEO_WATER_MARK = 134,
  ADD_VIDEO_WATER_MARK_2 = 135,
  CLEAR_VIDEO_WATER_MARKS = 136,
  SET_BEAUTY_EFFECT_OPTIONS = 137,
  ADD_INJECT_STREAM_URL = 138,
  START_CHANNEL_MEDIA_RELAY = 139,
  UPDATE_CHANNEL_MEDIA_RELAY = 140,
  STOP_CHANNEL_MEDIA_RELAY = 141,
  REMOVE_INJECT_STREAM_URL = 142,
  GET_CONNECTION_STATE = 143,
  REGISTER_MEDIA_META_DATA_OBSERVER = 144,
  SET_PARAMETERS = 145,
  SET_PLAYBACK_DEVICE_VOLUME = 146,
  PUBLISH = 147,
  UNPUBLISH = 148,
  CHANNEL_ID = 149,
  SEND_METADATA = 150,
  SET_MAX_META_SIZE = 151,
  PUSH_AUDIO_FRAME = 152,
  PUSH_AUDIO_FRAME_2 = 153,
  PULL_AUDIO_FRAME = 154,
  SET_EXTERN_VIDEO_SOURCE = 155,
  PUSH_VIDEO_FRAME = 156
};

enum API_TYPE_AUDIO_EFFECT {
  START_AUDIO_MIXING = 45,
  STOP_AUDIO_MIXING = 46,
  PAUSE_AUDIO_MIXING = 47,
  RESUME_AUDIO_MIXING = 48,
  SET_HIGH_QUALITY_AUDIO_PARAMETERS = 49,
  ADJUST_AUDIO_MIXING_VOLUME = 50,
  ADJUST_AUDIO_MIXING_PLAYOUT_VOLUME = 51,
  GET_AUDIO_MIXING_PLAYOUT_VOLUME = 52,
  ADJUST_AUDIO_MIXING_PUBLISH_VOLUME = 53,
  GET_AUDIO_MIXING_PUBLISH_VOLUME = 54,
  GET_AUDIO_MIXING_DURATION = 55,
  GET_AUDIO_MIXING_CURRENT_POSITION = 56,
  SET_AUDIO_MIXING_POSITION = 57,
  SET_AUDIO_MIXING_PITCH = 58,
  GET_EFFECTS_VOLUME = 59,
  SET_EFFECTS_VOLUME = 60,
  SET_VOLUME_OF_EFFECT = 61,
  PLAY_EFFECT = 63,
  STOP_EFFECT = 64,
  STOP_ALL_EFFECTS = 65,
  PRE_LOAD_EFFECT = 66,
  UN_LOAD_EFFECT = 67,
  PAUSE_EFFECT = 68,
  PAUSE_ALL_EFFECTS = 69,
  RESUME_EFFECT = 70,
  RESUME_ALL_EFFECTS = 71,
  ENABLE_SOUND_POSITION_INDICATION = 72,
  SET_LOCAL_VOICE_PITCH = 74,
  SET_LOCAL_VOICE_EQUALIZATION = 75,
  SET_LOCAL_VOICE_REVERB = 76,
  SET_LOCAL_VOICE_CHANGER = 77,
  SET_LOCAL_VOICE_REVERB_PRESET = 78,
  SET_EXTERNAL_AUDIO_SOURCE = 88,
  SET_EXTERNAL_AUDIO_SINK = 89,
  SET_RECORDING_AUDIO_FRAME_PARAMETERS = 90,
  SET_PLAYBACK_AUDIO_FRAME_PARAMETERS = 91,
  SET_MIXED_AUDIO_FRAME_PARAMETERS = 92,
};

enum API_TYPE_DEVICE_MANAGER {
  GET_COUNT = 151,
  GET_DEVICE = 152,
  GET_CURRENT_DEVICE = 153,
  GET_CURRENT_DEVICE_INFO = 154,
  SET_DEVICE = 155,
  SET_DEVICE_VOLUME = 156,
  GET_DEVICE_VOLUME = 157,
  SET_DEVICE_MUTE = 158,
  GET_DEVICE_MUTE = 159,
  START_DEVICE_TEST = 160,
  STOP_DEVICE_TEST = 161,
  START_AUDIO_DEVICE_LOOP_BACK_TEST = 162,
  STOP_AUDIO_DEVICE_LOOP_BACK_TEST = 163
};

enum ERROR_CODE {
  ERROR_OK = 0,
  ERROR_INVALID_API_TYPE = -100,
  ERROR_INVALID_PARAM = -101,
  ERROR_PARSE_PARAMETER = -102,
  ERROR_NO_CURRENT_PARAMETER = -103,
  ERROR_NOT_SUPPORT_API = -4,
  ERROR_NOT_INITIALIZE_OBSERVER = -104,
  ERROR_NO_DEVICE = -105,
  ERROR_ENGINE_EXIST = -106,
  ERROR_NO_ENGINE = -107
};

enum DEVICE_TYPE { PLAYBACK_DEVICE = 0, RECORDING_DEVICE = 1 };

#if defined(_WIN32)
typedef void(__stdcall *FUNC_OnChannelWarning)(const char *channelId, int warn,
                                               const char *msg);
typedef void(__stdcall *FUNC_OnChannelError)(const char *channelId, int err,
                                             const char *msg);
typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                          uid_t uid,
                                                          int elapsed);
typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(
    const char *channelId, uid_t uid, int elapsed);
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
                                                  uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char *channelId,
                                                   uid_t uid, int reason);
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
                                                      uid_t uid, int txQuality,
                                                      int rxQuality);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                                     uid_t uid);
typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                                        uid_t uid, int width,
                                                        int height,
                                                        int rotation);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char *channelId,
                                                     uid_t uid, int streamId,
                                                     const char *data,
                                                     size_t length);
typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                          uid_t uid,
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
    const char *channelId, const char *url, uid_t uid, int status);
typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
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

typedef void(__stdcall *FUNC_OnJoinChannelSuccess)(const char *, uid_t uid,
                                                   int elapsed);
typedef void(__stdcall *FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid,
                                                     int elapsed);
typedef void(__stdcall *FUNC_OnConnectionLost)();
typedef void(__stdcall *FUNC_OnConnectionInterrupted)();
typedef void(__stdcall *FUNC_OnLeaveChannel)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnRequestToken)();
typedef void(__stdcall *FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void(__stdcall *FUNC_OnAudioVolumeIndication)(const char *volumeInfo,
                                                      int speakerNumber,
                                                      int totalVolume);
typedef void(__stdcall *FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnWarning)(int warn, const char *msg);
typedef void(__stdcall *FUNC_OnError)(int error, const char *msg);
typedef void(__stdcall *FUNC_OnRtcStats)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void(__stdcall *FUNC_OnAudioMixingFinished)();
typedef void(__stdcall *FUNC_OnAudioRouteChanged)(int route);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width,
                                                        int height,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnVideoSizeChanged)(uid_t uid, int width,
                                                 int height, int elapsed);
typedef void(__stdcall *FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void(__stdcall *FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void(__stdcall *FUNC_OnApiExecuted)(int err, const char *api,
                                            const char *result);
typedef void(__stdcall *FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioFrame)(uid_t userId,
                                                      int elapsed);
typedef void(__stdcall *FUNC_OnLastmileQuality)(int quality);
typedef void(__stdcall *FUNC_OnAudioQuality)(uid_t userId, int quality,
                                             unsigned short delay,
                                             unsigned short lost);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url,
                                                     uid_t userId, int status);
typedef void(__stdcall *FUNC_OnStreamUnpublished)(const char *url);
typedef void(__stdcall *FUNC_OnStreamPublished)(const char *url, int error);
typedef void(__stdcall *FUNC_OnStreamMessageError)(uid_t userId, int streamId,
                                                   int code, int missed,
                                                   int cached);
typedef void(__stdcall *FUNC_OnStreamMessage)(uid_t userId, int streamId,
                                              const char *data, size_t length);
typedef void(__stdcall *FUNC_OnConnectionBanned)();
typedef void(__stdcall *FUNC_OnRemoteVideoTransportStats)(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnRemoteAudioTransportStats)(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnTranscodingUpdated)();
typedef void(__stdcall *FUNC_OnAudioDeviceVolumeChanged)(int deviceType,
                                                         int volume,
                                                         bool muted);
typedef void(__stdcall *FUNC_OnActiveSpeaker)(uid_t userId);
typedef void(__stdcall *FUNC_OnMediaEngineStartCallSuccess)();
typedef void(__stdcall *FUNC_OnMediaEngineLoadSuccess)();
typedef void(__stdcall *FUNC_OnVideoStopped)();
typedef void(__stdcall *FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void(__stdcall *FUNC_OnNetworkQuality)(uid_t uid, int txQuality,
                                               int rxQuality);
typedef void(__stdcall *FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void(__stdcall *FUNC_OnRemoteVideoStats)(
    uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnRemoteAudioStats)(
    uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay,
    int audioLossRate, int numChannels, int receivedSampleRate,
    int receivedBitrate, int totalFrozenTime, int frozenRate,
    int totalActiveTime);
typedef void(__stdcall *FUNC_OnLocalAudioStats)(int numChannels,
                                                int sentSampleRate,
                                                int sentBitrate);
typedef void(__stdcall *FUNC_OnFirstLocalVideoFrame)(int width, int height,
                                                     int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width,
                                                      int height, int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
typedef void(__stdcall *FUNC_OnAudioDeviceStateChanged)(const char *deviceId,
                                                        int deviceType,
                                                        int deviceState);
typedef void(__stdcall *FUNC_OnCameraReady)();
typedef void(__stdcall *FUNC_OnCameraFocusAreaChanged)(int x, int y, int width,
                                                       int height);
typedef void(__stdcall *FUNC_OnCameraExposureAreaChanged)(int x, int y,
                                                          int width,
                                                          int height);
typedef void(__stdcall *FUNC_OnRemoteAudioMixingBegin)();
typedef void(__stdcall *FUNC_OnRemoteAudioMixingEnd)();
typedef void(__stdcall *FUNC_OnAudioEffectFinished)(int soundId);
typedef void(__stdcall *FUNC_OnVideoDeviceStateChanged)(const char *deviceId,
                                                        int deviceType,
                                                        int deviceState);
typedef void(__stdcall *FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state,
                                                        int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
typedef void(__stdcall *FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void(__stdcall *FUNC_OnLocalUserRegistered)(uid_t uid,
                                                    const char *userAccount);
typedef void(__stdcall *FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userId,
                                                char *userAccount);
typedef void(__stdcall *FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void(__stdcall *FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state,
                                                        int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url, uid_t uid,
                                                     int status);
typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged)(int state,
                                                              int code);
typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent)(int code);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);

// raw data callback
typedef void(__stdcall *FUNC_OnCaptureVideoFrame)(int videoFrameType, int width,
                                                  int height, int yStride,
                                                  void *yBuffer, int rotation,
                                                  int64_t renderTimeMs);
typedef void(__stdcall *FUNC_OnRenderVideoFrame)(unsigned int uid,
                                                 int videoFrameType, int width,
                                                 int height, int yStride,
                                                 void *yBuffer, int rotation,
                                                 int64_t renderTimeMs);
typedef void(__stdcall *FUNC_OnRecordAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPlaybackAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPullAudioFrame)(int type, int samples,
                                               int bytesPerSample, int channels,
                                               int samplesPerSec, void *buffer,
                                               int64_t renderTimeMs,
                                               int avsync_type);
typedef void(__stdcall *FUNC_OnMixedAudioFrame)(
    int type, int samples, int bytesPerSample, int channels, int samplesPerSec,
    void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnPlaybackAudioFrameBeforeMixing)(
    unsigned int uid, int type, int samples, int bytesPerSample, int channels,
    int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void(__stdcall *FUNC_OnAudioMixingStateChanged)(
    int audioMixingStateType, int audioMixingErrorType);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnLocalVideoStateChanged)(int localVideoState,
                                                       int error);
typedef void(__stdcall *FUNC_OnRtmpStreamingStateChanged)(const char *url,
                                                          int state,
                                                          int errCode);
typedef void(__stdcall *FUNC_OnNetworkTypeChanged)(int networkType);
typedef void(__stdcall *FUNC_OnLastmileProbeResult)(
    int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter,
    unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate,
    unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth,
    unsigned int rtt);
typedef bool(__stdcall *FUNC_OnSendAudioPacket)(const unsigned char *buffer,
                                                void *size);
typedef bool(__stdcall *FUNC_OnSendVideoPacket)(const unsigned char *buffer,
                                                void *size);
typedef bool(__stdcall *FUNC_OnReceiveAudioPacket)(const unsigned char *buffer,
                                                   void *size);
typedef bool(__stdcall *FUNC_OnReceiveVideoPacket)(const unsigned char *buffer,
                                                   void *size);
typedef bool(__stdcall *FUNC_OnReadyToSendMetadata)();
typedef void(__stdcall *FUNC_OnMetadataReceived)(unsigned int uid,
                                                 unsigned int size,
                                                 unsigned char *buffer,
                                                 long long timeStampMs);
typedef int(__stdcall *FUNC_OnGetMaxMetadataSize)();
typedef void(__stdcall *FUNC_OnChannelWarning)(const char *channelId, int warn,
                                               const char *msg);
typedef void(__stdcall *FUNC_OnChannelError)(const char *channelId, int err,
                                             const char *msg);
typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                          uid_t uid,
                                                          int elapsed);
typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(
    const char *channelId, uid_t uid, int elapsed);
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
                                                  uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char *channelId,
                                                   uid_t uid, int reason);
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
                                                      uid_t uid, int txQuality,
                                                      int rxQuality);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char *channelId,
                                                     uid_t uid);
typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char *channelId,
                                                        uid_t uid, int width,
                                                        int height,
                                                        int rotation);
typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(
    const char *channelId, uid_t uid, int state, int reason, int elapsed);
typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char *channelId,
                                                     uid_t uid, int streamId,
                                                     const char *data,
                                                     size_t length);
typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                          uid_t uid,
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
    const char *channelId, const char *url, uid_t uid, int status);
typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnChannelConnectionStateChanged)(
    const char *channelId, int state, int reason);
typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth,
                                                    int imageHeight, int x,
                                                    int y, int width,
                                                    int height, int vecDistance,
                                                    int numFaces);
typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnTestEnd)();
#else
typedef void (*FUNC_OnChannelWarning)(const char *channelId, int warn,
                                      const char *msg);
typedef void (*FUNC_OnChannelError)(const char *channelId, int err,
                                    const char *msg);
typedef void (*FUNC_OnChannelJoinChannelSuccess)(const char *channelId,
                                                 uid_t uid, int elapsed);
typedef void (*FUNC_OnChannelReJoinChannelSuccess)(const char *channelId,
                                                   uid_t uid, int elapsed);
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
typedef void (*FUNC_OnChannelUserJoined)(const char *channelId, uid_t uid,
                                         int elapsed);
typedef void (*FUNC_OnChannelUserOffLine)(const char *channelId, uid_t uid,
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
typedef void (*FUNC_OnChannelNetworkQuality)(const char *channelId, uid_t uid,
                                             int txQuality, int rxQuality);
typedef void (*FUNC_OnChannelRemoteVideoStats)(
    const char *channelId, uid_t uid, int delay, int width, int height,
    int receivedBitrate, int decoderOutputFrameRate,
    int rendererOutputFrameRate, int packetLossRate, int rxStreamType,
    int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStats)(
    const char *channelId, uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnChannelRemoteAudioStateChanged)(const char *channelId,
                                                      uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelActiveSpeaker)(const char *channelId, uid_t uid);
typedef void (*FUNC_OnChannelVideoSizeChanged)(const char *channelId, uid_t uid,
                                               int width, int height,
                                               int rotation);
typedef void (*FUNC_OnChannelRemoteVideoStateChanged)(const char *channelId,
                                                      uid_t uid, int state,
                                                      int reason, int elapsed);
typedef void (*FUNC_OnChannelStreamMessage)(const char *channelId, uid_t uid,
                                            int streamId, const char *data,
                                            size_t length);
typedef void (*FUNC_OnChannelStreamMessageError)(const char *channelId,
                                                 uid_t uid, int streamId,
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
                                                   const char *url, uid_t uid,
                                                   int status);
typedef void (*FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(
    const char *channelId, uid_t uid, bool isFallbackOrRecover);
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

typedef void (*FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void (*FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid,
                                            int elapsed);
typedef void (*FUNC_OnConnectionLost)();
typedef void (*FUNC_OnConnectionInterrupted)();
typedef void (*FUNC_OnLeaveChannel)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnRequestToken)();
typedef void (*FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void (*FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void (*FUNC_OnAudioVolumeIndication)(uid_t *uid, unsigned int *volume,
                                             unsigned int *vad,
                                             const char **channelId,
                                             int speakerNumber,
                                             int totalVolume);
typedef void (*FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void (*FUNC_OnWarning)(int warn, const char *msg);
typedef void (*FUNC_OnError)(int error, const char *msg);
typedef void (*FUNC_OnRtcStats)(
    unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
    unsigned int txAudioBytes, unsigned int txVideoBytes,
    unsigned int rxAudioBytes, unsigned int rxVideoBytes,
    unsigned short txKBitRate, unsigned short rxKBitRate,
    unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate,
    unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate,
    unsigned short lastmileDelay, unsigned short txPacketLossRate,
    unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage,
    double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio,
    double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
typedef void (*FUNC_OnAudioMixingFinished)();
typedef void (*FUNC_OnAudioRouteChanged)(int route);
typedef void (*FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height,
                                               int elapsed);
typedef void (*FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height,
                                        int elapsed);
typedef void (*FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void (*FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void (*FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void (*FUNC_OnApiExecuted)(int err, const char *api,
                                   const char *result);
typedef void (*FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void (*FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
typedef void (*FUNC_OnLastmileQuality)(int quality);
typedef void (*FUNC_OnAudioQuality)(uid_t userId, int quality,
                                    unsigned short delay, unsigned short lost);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId,
                                            int status);
typedef void (*FUNC_OnStreamUnpublished)(const char *url);
typedef void (*FUNC_OnStreamPublished)(const char *url, int error);
typedef void (*FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code,
                                          int missed, int cached);
typedef void (*FUNC_OnStreamMessage)(uid_t userId, int streamId,
                                     const char *data, size_t length);
typedef void (*FUNC_OnConnectionBanned)();
typedef void (*FUNC_OnRemoteVideoTransportStats)(uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnRemoteAudioTransportStats)(uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnTranscodingUpdated)();
typedef void (*FUNC_OnAudioDeviceVolumeChanged)(int deviceType, int volume,
                                                bool muted);
typedef void (*FUNC_OnActiveSpeaker)(uid_t userId);
typedef void (*FUNC_OnMediaEngineStartCallSuccess)();
typedef void (*FUNC_OnMediaEngineLoadSuccess)();
typedef void (*FUNC_OnVideoStopped)();
typedef void (*FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void (*FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);
typedef void (*FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void (*FUNC_OnRemoteVideoStats)(
    uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnRemoteAudioStats)(
    uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay,
    int audioLossRate, int numChannels, int receivedSampleRate,
    int receivedBitrate, int totalFrozenTime, int frozenRate,
    int totalActiveTime);
typedef void (*FUNC_OnLocalAudioStats)(int numChannels, int sentSampleRate,
                                       int sentBitrate);
typedef void (*FUNC_OnFirstLocalVideoFrame)(int width, int height, int elapsed);
typedef void (*FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width, int height,
                                             int elapsed);
typedef void (*FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
typedef void (*FUNC_OnAudioDeviceStateChanged)(const char *deviceId,
                                               int deviceType, int deviceState);
typedef void (*FUNC_OnCameraReady)();
typedef void (*FUNC_OnCameraFocusAreaChanged)(int x, int y, int width,
                                              int height);
typedef void (*FUNC_OnCameraExposureAreaChanged)(int x, int y, int width,
                                                 int height);
typedef void (*FUNC_OnRemoteAudioMixingBegin)();
typedef void (*FUNC_OnRemoteAudioMixingEnd)();
typedef void (*FUNC_OnAudioEffectFinished)(int soundId);
typedef void (*FUNC_OnVideoDeviceStateChanged)(const char *deviceId,
                                               int deviceType, int deviceState);
typedef void (*FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state, int reason,
                                               int elapsed);
typedef void (*FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
typedef void (*FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void (*FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    uid_t uid, bool isFallbackOrRecover);
typedef void (*FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void (*FUNC_OnRtmpStreamingStateChanged)(const char *url, int state,
                                                 int errCode);
typedef void (*FUNC_OnLocalUserRegistered)(uid_t uid, const char *userAccount);
typedef void (*FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userUid,
                                       char *userAccount);
typedef void (*FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void (*FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state, int reason,
                                               int elapsed);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, uid_t uid,
                                            int status);
typedef void (*FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
typedef void (*FUNC_OnChannelMediaRelayEvent)(int code);
typedef void (*FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight,
                                           int x, int y, int width, int height,
                                           int vecDistance, int numFaces);
typedef void (*FUNC_OnChannelLocalPublishFallbackToAudioOnly)(
    const char *channelId, bool isFallbackOrRecover);

// raw data callback
typedef void (*FUNC_OnCaptureVideoFrame)(int videoFrameType, int width,
                                         int height, int yStride, void *yBuffer,
                                         int rotation, int64_t renderTimeMs);
typedef void (*FUNC_OnRenderVideoFrame)(unsigned int uid, int videoFrameType,
                                        int width, int height, int yStride,
                                        void *yBuffer, int rotation,
                                        int64_t renderTimeMs);
typedef void (*FUNC_OnRecordAudioFrame)(int type, int samples,
                                        int bytesPerSample, int channels,
                                        int samplesPerSec, void *buffer,
                                        int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPlaybackAudioFrame)(int type, int samples,
                                          int bytesPerSample, int channels,
                                          int samplesPerSec, void *buffer,
                                          int64_t renderTimeMs,
                                          int avsync_type);
typedef void (*FUNC_OnMixedAudioFrame)(int type, int samples,
                                       int bytesPerSample, int channels,
                                       int samplesPerSec, void *buffer,
                                       int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPlaybackAudioFrameBeforeMixing)(
    unsigned int uid, int type, int samples, int bytesPerSample, int channels,
    int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type);
typedef void (*FUNC_OnPullAudioFrame)(int type, int samples, int bytesPerSample,
                                      int channels, int samplesPerSec,
                                      void *buffer, int64_t renderTimeMs,
                                      int avsync_type);
typedef void (*FUNC_OnAudioMixingStateChanged)(int audioMixingStateType,
                                               int audioMixingErrorType);
typedef void (*FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
typedef void (*FUNC_OnLocalVideoStateChanged)(int localVideoState, int error);
typedef void (*FUNC_OnNetworkTypeChanged)(int networkType);
typedef void (*FUNC_OnLastmileProbeResult)(
    int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter,
    unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate,
    unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth,
    unsigned int rtt);
typedef bool (*FUNC_OnSendAudioPacket)(const unsigned char *buffer, void *size);
typedef bool (*FUNC_OnSendVideoPacket)(const unsigned char *buffer, void *size);
typedef bool (*FUNC_OnReceiveAudioPacket)(const unsigned char *buffer,
                                          void *size);
typedef bool (*FUNC_OnReceiveVideoPacket)(const unsigned char *buffer,
                                          void *size);
typedef bool (*FUNC_OnReadyToSendMetadata)();
typedef void (*FUNC_OnMetadataReceived)(unsigned int uid, unsigned int size,
                                        unsigned char *buffer,
                                        long long timeStampMs);
typedef int (*FUNC_OnGetMaxMetadataSize)();
typedef void (*FUNC_OnTestEnd)();
#endif

struct RtcEventHandler {
  FUNC_OnJoinChannelSuccess onJoinChannelSuccess = NULL;
  FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess = NULL;
  FUNC_OnLeaveChannel onLeaveChannel = NULL;
  FUNC_OnConnectionLost onConnectionLost = NULL;
  FUNC_OnConnectionInterrupted onConnectionInterrupted = NULL;
  FUNC_OnRequestToken onRequestToken = NULL;
  FUNC_OnUserJoined onUserJoined = NULL;
  FUNC_OnUserOffline onUserOffline = NULL;
  FUNC_OnAudioVolumeIndication onAudioVolumeIndication = NULL;
  FUNC_OnUserMuteAudio onUserMuteAudio = NULL;
  FUNC_OnWarning onWarning = NULL;
  FUNC_OnError onError = NULL;
  FUNC_OnRtcStats onRtcStats = NULL;
  FUNC_OnAudioMixingFinished onAudioMixingFinished = NULL;
  FUNC_OnAudioRouteChanged onAudioRouteChanged = NULL;
  FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded = NULL;
  FUNC_OnVideoSizeChanged onVideoSizeChanged = NULL;
  FUNC_OnClientRoleChanged onClientRoleChanged = NULL;
  FUNC_OnUserMuteVideo onUserMuteVideo = NULL;
  FUNC_OnMicrophoneEnabled onMicrophoneEnabled = NULL;
  FUNC_OnApiExecuted onApiCallExecuted = NULL;
  FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame = NULL;
  FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame = NULL;
  FUNC_OnLastmileQuality onLastmileQuality = NULL;
  FUNC_OnAudioQuality onAudioQuality = NULL;
  FUNC_OnStreamInjectedStatus onStreamInjectedStatus = NULL;
  FUNC_OnStreamUnpublished onStreamUnpublished = NULL;
  FUNC_OnStreamPublished onStreamPublished = NULL;
  FUNC_OnStreamMessageError onStreamMessageError = NULL;
  FUNC_OnStreamMessage onStreamMessage = NULL;
  FUNC_OnConnectionBanned onConnectionBanned = NULL;
  FUNC_OnRemoteVideoTransportStats onRemoteVideoTransportStats = NULL;
  FUNC_OnRemoteAudioTransportStats onRemoteAudioTransportStats = NULL;
  FUNC_OnTranscodingUpdated onTranscodingUpdated = NULL;
  FUNC_OnAudioDeviceVolumeChanged onAudioDeviceVolumeChanged = NULL;
  FUNC_OnActiveSpeaker onActiveSpeaker = NULL;
  FUNC_OnMediaEngineStartCallSuccess onMediaEngineStartCallSuccess = NULL;
  FUNC_OnMediaEngineLoadSuccess onMediaEngineLoadSuccess = NULL;
  FUNC_OnConnectionStateChanged onConnectionStateChanged = NULL;
  FUNC_OnRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = NULL;
  FUNC_OnLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly =
      NULL;
  FUNC_OnUserEnableLocalVideo onUserEnableLocalVideo = NULL;
  FUNC_OnRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
  FUNC_OnVideoDeviceStateChanged onVideoDeviceStateChanged = NULL;
  FUNC_OnAudioEffectFinished onAudioEffectFinished = NULL;
  FUNC_OnRemoteAudioMixingEnd onRemoteAudioMixingEnd = NULL;
  FUNC_OnRemoteAudioMixingBegin onRemoteAudioMixingBegin = NULL;
  FUNC_OnCameraExposureAreaChanged onCameraExposureAreaChanged = NULL;
  FUNC_OnCameraFocusAreaChanged onCameraFocusAreaChanged = NULL;
  FUNC_OnCameraReady onCameraReady = NULL;
  FUNC_OnAudioDeviceStateChanged onAudioDeviceStateChanged = NULL;
  FUNC_OnUserEnableVideo onUserEnableVideo = NULL;
  FUNC_OnFirstRemoteVideoFrame onFirstRemoteVideoFrame = NULL;
  FUNC_OnFirstLocalVideoFrame onFirstLocalVideoFrame = NULL;
  FUNC_OnRemoteAudioStats onRemoteAudioStats = NULL;
  FUNC_OnRemoteVideoStats onRemoteVideoStats = NULL;
  FUNC_OnLocalVideoStats onLocalVideoStats = NULL;
  FUNC_OnNetworkQuality onNetworkQuality = NULL;
  FUNC_OnTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
  FUNC_OnVideoStopped onVideoStopped = NULL;
  FUNC_OnAudioMixingStateChanged onAudioMixingStateChanged = NULL;
  FUNC_OnFirstRemoteAudioDecoded onFirstRemoteAudioDecoded = NULL;
  FUNC_OnLocalVideoStateChanged onLocalVideoStateChanged = NULL;
  FUNC_OnNetworkTypeChanged onNetworkTypeChanged = NULL;
  FUNC_OnRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
  FUNC_OnLastmileProbeResult onLastmileProbeResult = NULL;
  FUNC_OnLocalUserRegistered onLocalUserRegistered = NULL;
  FUNC_OnUserInfoUpdated onUserInfoUpdated = NULL;
  FUNC_OnLocalAudioStateChanged onLocalAudioStateChanged = NULL;
  FUNC_OnRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
  FUNC_OnLocalAudioStats onLocalAudioStats = NULL;
  FUNC_OnChannelMediaRelayStateChanged onChannelMediaRelayStateChanged = NULL;
  FUNC_OnChannelMediaRelayEvent onChannelMediaRelayEvent = NULL;
  FUNC_OnFacePositionChanged onFacePositionChanged = NULL;
  FUNC_OnTestEnd onTestEnd = NULL;
};

struct ChannelEventHandler {
  FUNC_OnChannelWarning onWarning = NULL;
  FUNC_OnChannelError onError = NULL;
  FUNC_OnChannelJoinChannelSuccess onJoinChannelSuccess = NULL;
  FUNC_OnChannelReJoinChannelSuccess onRejoinChannelSuccess = NULL;
  FUNC_OnChannelLeaveChannel onLeaveChannel = NULL;
  FUNC_OnChannelClientRoleChanged onClientRoleChanged = NULL;
  FUNC_OnChannelUserJoined onUserJoined = NULL;
  FUNC_OnChannelUserOffLine onUserOffLine = NULL;
  FUNC_OnChannelConnectionLost onConnectionLost = NULL;
  FUNC_OnChannelRequestToken onRequestToken = NULL;
  FUNC_OnChannelTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
  FUNC_OnChannelRtcStats onRtcStats = NULL;
  FUNC_OnChannelNetworkQuality onNetworkQuality = NULL;
  FUNC_OnChannelRemoteVideoStats onRemoteVideoStats = NULL;
  FUNC_OnChannelRemoteAudioStats onRemoteAudioStats = NULL;
  FUNC_OnChannelRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
  FUNC_OnChannelActiveSpeaker onActiveSpeaker = NULL;
  FUNC_OnChannelVideoSizeChanged onVideoSizeChanged = NULL;
  FUNC_OnChannelRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
  FUNC_OnChannelStreamMessage onStreamMessage = NULL;
  FUNC_OnChannelStreamMessageError onStreamMessageError = NULL;
  FUNC_OnChannelMediaRelayStateChanged2 onMediaRelayStateChanged = NULL;
  FUNC_OnChannelMediaRelayEvent2 onMediaRelayEvent = NULL;
  FUNC_OnChannelRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
  FUNC_OnChannelTranscodingUpdated onTranscodingUpdated = NULL;
  FUNC_OnChannelStreamInjectedStatus onStreamInjectedStatus = NULL;
  FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = NULL;
  FUNC_OnChannelConnectionStateChanged onConnectionStateChanged = NULL;
  FUNC_OnChannelLocalPublishFallbackToAudioOnly
      onLocalPublishFallbackToAudioOnly = NULL;
  FUNC_OnChannelTestEnd onTestEnd = NULL;
};

typedef void *IRtcEngineBridge_ptr;
typedef void *IRtcChannelBridge_ptr;
typedef void *IVideoDeviceManagerBridge_ptr;
typedef void *IAudioDeviceManagerBridge_ptr;
typedef void *IAudioDeviceManagerBridge_ptr;
// rtc engine api

extern IRtcEngineBridge_ptr createRtcBridge();

extern void add_C_EventHandler(IRtcEngineBridge_ptr apiBridge,
                               struct RtcEventHandler *handler);

extern void remove_C_EventHandler(IRtcEngineBridge_ptr apiBridge);

extern void channel_add_C_ChannelEventHandler(
    IRtcChannelBridge_ptr apiBridge,
    struct ChannelEventHandler *channelEventHandler);

extern void
channel_remove_C_ChannelEventHandler(IRtcChannelBridge_ptr apiBridge);

extern enum ERROR_CODE callApi_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                          enum API_TYPE apiType,
                                          const char *parameters);

extern const char *callApi_str_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                          enum API_TYPE apiType,
                                          const char *parameters);

extern enum ERROR_CODE callApi2_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                           enum API_TYPE apiType,
                                           const char *parameters, void *ptr);

extern enum ERROR_CODE
callApi_audioEffect_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                               enum API_TYPE_AUDIO_EFFECT apiType,
                               const char *parameters);

extern void release_rtc_engine_bridge(IRtcEngineBridge_ptr apiBridge,
                                      BOOL sync);

// rtc channel api
extern IRtcChannelBridge_ptr createChannelBridge(IRtcEngineBridge_ptr apiBridge,
                                                 const char *channelId);

extern enum ERROR_CODE callApi_channel(IRtcChannelBridge_ptr apiBridge,
                                       enum API_TYPE apiType,
                                       const char *parameters);

extern const char *callApi_str_channel(IRtcChannelBridge_ptr apiBridge,
                                       enum API_TYPE apiType,
                                       const char *parameters);

extern enum ERROR_CODE callApi2_channel(IRtcChannelBridge_ptr apiBridge,
                                        enum API_TYPE apiType,
                                        const char *parameters, void *ptr);

extern void release_channel_bridge(IRtcChannelBridge_ptr apiBridge);

// video device api
extern IVideoDeviceManagerBridge_ptr
createVideoDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge,
                               enum ERROR_CODE *errorCode);

extern enum ERROR_CODE
callApi_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge,
                             enum API_TYPE_DEVICE_MANAGER apiType,
                             const char *parameters, void *ptr);

extern enum ERROR_CODE
callApi2_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr, void *ptr2);

extern void
release_video_device_manager_bridge(IVideoDeviceManagerBridge_ptr apiBridge);

// audio recording device api
extern IAudioDeviceManagerBridge_ptr
createDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge,
                          enum DEVICE_TYPE device_type,
                          enum ERROR_CODE *errorCode);

extern enum ERROR_CODE
callApi_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                             enum API_TYPE_DEVICE_MANAGER apiType,
                             const char *parameters);

extern enum ERROR_CODE
callApi2_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr);

extern enum ERROR_CODE
callApi3_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr, void *ptr2);

extern void
release_audio_device_manager_bridge(IAudioDeviceManagerBridge_ptr apiBridge);

#ifdef __cplusplus
};
#endif
