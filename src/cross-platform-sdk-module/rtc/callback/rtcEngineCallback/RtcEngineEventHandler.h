#pragma once

#include "../template_class_rtc_engine_event_handler.h"
#include "RtcEngineEventHandlerBase.h"
#include "vector"

namespace agora {
namespace common {
#if defined(_WIN32)
typedef void(__stdcall *FUNC_OnJoinChannelSuccess)(const char *, rtc::uid_t uid,
                                                   int elapsed);
typedef void(__stdcall *FUNC_OnReJoinChannelSuccess)(const char *,
                                                     rtc::uid_t uid,
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
typedef void(__stdcall *FUNC_OnUserJoined)(rtc::uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnUserOffline)(rtc::uid_t uid, int offLineReason);
typedef void(__stdcall *FUNC_OnAudioVolumeIndication)(
    rtc::uid_t *uid, unsigned int *volume, unsigned int *vad,
    const char **channelId, int speakerNumber, int totalVolume);
typedef void(__stdcall *FUNC_OnUserMuteAudio)(rtc::uid_t uid, bool muted);
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
typedef void(__stdcall *FUNC_OnFirstRemoteVideoDecoded)(rtc::uid_t uid,
                                                        int width, int height,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnVideoSizeChanged)(rtc::uid_t uid, int width,
                                                 int height, int elapsed);
typedef void(__stdcall *FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void(__stdcall *FUNC_OnUserMuteVideo)(rtc::uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void(__stdcall *FUNC_OnApiExecuted)(int err, const char *api,
                                            const char *result);
typedef void(__stdcall *FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioFrame)(rtc::uid_t userId,
                                                      int elapsed);
typedef void(__stdcall *FUNC_OnLastmileQuality)(int quality);
typedef void(__stdcall *FUNC_OnAudioQuality)(rtc::uid_t userId, int quality,
                                             unsigned short delay,
                                             unsigned short lost);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url,
                                                     rtc::uid_t userId,
                                                     int status);
typedef void(__stdcall *FUNC_OnStreamUnpublished)(const char *url);
typedef void(__stdcall *FUNC_OnStreamPublished)(const char *url, int error);
typedef void(__stdcall *FUNC_OnStreamMessageError)(rtc::uid_t userId,
                                                   int streamId, int code,
                                                   int missed, int cached);
typedef void(__stdcall *FUNC_OnStreamMessage)(rtc::uid_t userId, int streamId,
                                              const char *data, size_t length);
typedef void(__stdcall *FUNC_OnConnectionBanned)();
typedef void(__stdcall *FUNC_OnRemoteVideoTransportStats)(
    rtc::uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnRemoteAudioTransportStats)(
    rtc::uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate);
typedef void(__stdcall *FUNC_OnTranscodingUpdated)();
typedef void(__stdcall *FUNC_OnAudioDeviceVolumeChanged)(int deviceType,
                                                         int volume,
                                                         bool muted);
typedef void(__stdcall *FUNC_OnActiveSpeaker)(rtc::uid_t userId);
typedef void(__stdcall *FUNC_OnMediaEngineStartCallSuccess)();
typedef void(__stdcall *FUNC_OnMediaEngineLoadSuccess)();
typedef void(__stdcall *FUNC_OnVideoStopped)();
typedef void(__stdcall *FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void(__stdcall *FUNC_OnNetworkQuality)(rtc::uid_t uid, int txQuality,
                                               int rxQuality);
typedef void(__stdcall *FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void(__stdcall *FUNC_OnRemoteVideoStats)(
    rtc::uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnRemoteAudioStats)(
    rtc::uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void(__stdcall *FUNC_OnLocalAudioStats)(int numChannels,
                                                int sentSampleRate,
                                                int sentBitrate);
typedef void(__stdcall *FUNC_OnFirstLocalVideoFrame)(int width, int height,
                                                     int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoFrame)(rtc::uid_t uid, int width,
                                                      int height, int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableVideo)(rtc::uid_t uid, bool enabled);
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
typedef void(__stdcall *FUNC_OnRemoteVideoStateChanged)(rtc::uid_t uid,
                                                        int state, int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnUserEnableLocalVideo)(rtc::uid_t uid,
                                                     bool enabled);
typedef void(__stdcall *FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    rtc::uid_t uid, bool isFallbackOrRecover);
typedef void(__stdcall *FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void(__stdcall *FUNC_OnLocalUserRegistered)(rtc::uid_t uid,
                                                    const char *userAccount);
typedef void(__stdcall *FUNC_OnUserInfoUpdated)(rtc::uid_t uid,
                                                rtc::uid_t userId,
                                                char *userAccount);
typedef void(__stdcall *FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void(__stdcall *FUNC_OnRemoteAudioStateChanged)(rtc::uid_t uid,
                                                        int state, int reason,
                                                        int elapsed);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url,
                                                     rtc::uid_t uid,
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
typedef void(__stdcall *FUNC_OnFirstRemoteAudioDecoded)(rtc::uid_t uid,
                                                        int elapsed);
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
typedef void(__stdcall *FUNC_OnTestEnd)();
#else
typedef void (*FUNC_OnJoinChannelSuccess)(const char *, rtc::uid_t uid,
                                          int elapsed);
typedef void (*FUNC_OnReJoinChannelSuccess)(const char *, rtc::uid_t uid,
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
typedef void (*FUNC_OnUserJoined)(rtc::uid_t uid, int elapsed);
typedef void (*FUNC_OnUserOffline)(rtc::uid_t uid, int offLineReason);
typedef void (*FUNC_OnAudioVolumeIndication)(
    rtc::uid_t *uid, unsigned int *volume, unsigned int *vad,
    const char **channelId, int speakerNumber, int totalVolume);
typedef void (*FUNC_OnUserMuteAudio)(rtc::uid_t uid, bool muted);
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
typedef void (*FUNC_OnFirstRemoteVideoDecoded)(rtc::uid_t uid, int width,
                                               int height, int elapsed);
typedef void (*FUNC_OnVideoSizeChanged)(rtc::uid_t uid, int width, int height,
                                        int elapsed);
typedef void (*FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void (*FUNC_OnUserMuteVideo)(rtc::uid_t uid, bool muted);
typedef void (*FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void (*FUNC_OnApiExecuted)(int err, const char *api,
                                   const char *result);
typedef void (*FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void (*FUNC_OnFirstRemoteAudioFrame)(rtc::uid_t userId, int elapsed);
typedef void (*FUNC_OnLastmileQuality)(int quality);
typedef void (*FUNC_OnAudioQuality)(rtc::uid_t userId, int quality,
                                    unsigned short delay, unsigned short lost);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, rtc::uid_t userId,
                                            int status);
typedef void (*FUNC_OnStreamUnpublished)(const char *url);
typedef void (*FUNC_OnStreamPublished)(const char *url, int error);
typedef void (*FUNC_OnStreamMessageError)(rtc::uid_t userId, int streamId,
                                          int code, int missed, int cached);
typedef void (*FUNC_OnStreamMessage)(rtc::uid_t userId, int streamId,
                                     const char *data, size_t length);
typedef void (*FUNC_OnConnectionBanned)();
typedef void (*FUNC_OnRemoteVideoTransportStats)(rtc::uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnRemoteAudioTransportStats)(rtc::uid_t uid,
                                                 unsigned short delay,
                                                 unsigned short lost,
                                                 unsigned short rxKBitRate);
typedef void (*FUNC_OnTranscodingUpdated)();
typedef void (*FUNC_OnAudioDeviceVolumeChanged)(int deviceType, int volume,
                                                bool muted);
typedef void (*FUNC_OnActiveSpeaker)(rtc::uid_t userId);
typedef void (*FUNC_OnMediaEngineStartCallSuccess)();
typedef void (*FUNC_OnMediaEngineLoadSuccess)();
typedef void (*FUNC_OnVideoStopped)();
typedef void (*FUNC_OnTokenPrivilegeWillExpire)(const char *token);
typedef void (*FUNC_OnNetworkQuality)(rtc::uid_t uid, int txQuality,
                                      int rxQuality);
typedef void (*FUNC_OnLocalVideoStats)(
    int sentBitrate, int sentFrameRate, int encoderOutputFrameRate,
    int rendererOutputFrameRate, int targetBitrate, int targetFrameRate,
    int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth,
    int encodedFrameHeight, int encodedFrameCount, int codecType);
typedef void (*FUNC_OnRemoteVideoStats)(
    rtc::uid_t uid, int delay, int width, int height, int receivedBitrate,
    int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate,
    int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnRemoteAudioStats)(
    rtc::uid_t uid, int quality, int networkTransportDelay,
    int jitterBufferDelay, int audioLossRate, int numChannels,
    int receivedSampleRate, int receivedBitrate, int totalFrozenTime,
    int frozenRate, int totalActiveTime);
typedef void (*FUNC_OnLocalAudioStats)(int numChannels, int sentSampleRate,
                                       int sentBitrate);
typedef void (*FUNC_OnFirstLocalVideoFrame)(int width, int height, int elapsed);
typedef void (*FUNC_OnFirstRemoteVideoFrame)(rtc::uid_t uid, int width,
                                             int height, int elapsed);
typedef void (*FUNC_OnUserEnableVideo)(rtc::uid_t uid, bool enabled);
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
typedef void (*FUNC_OnRemoteVideoStateChanged)(rtc::uid_t uid, int state,
                                               int reason, int elapsed);
typedef void (*FUNC_OnUserEnableLocalVideo)(rtc::uid_t uid, bool enabled);
typedef void (*FUNC_OnLocalPublishFallbackToAudioOnly)(
    bool isFallbackOrRecover);
typedef void (*FUNC_OnRemoteSubscribeFallbackToAudioOnly)(
    rtc::uid_t uid, bool isFallbackOrRecover);
typedef void (*FUNC_OnConnectionStateChanged)(int state, int reason);
typedef void (*FUNC_OnRtmpStreamingStateChanged)(const char *url, int state,
                                                 int errCode);
typedef void (*FUNC_OnLocalUserRegistered)(rtc::uid_t uid,
                                           const char *userAccount);
typedef void (*FUNC_OnUserInfoUpdated)(rtc::uid_t uid, rtc::uid_t userUid,
                                       char *userAccount);
typedef void (*FUNC_OnLocalAudioStateChanged)(int state, int error);
typedef void (*FUNC_OnRemoteAudioStateChanged)(rtc::uid_t uid, int state,
                                               int reason, int elapsed);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, rtc::uid_t uid,
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
typedef void (*FUNC_OnFirstRemoteAudioDecoded)(rtc::uid_t uid, int elapsed);
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

class CEngineEventHandler {
public:
  CEngineEventHandler() = default;
  ~CEngineEventHandler() { reset(); }

  FUNC_OnJoinChannelSuccess onJoinChannelSuccess = nullptr;
  FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess = nullptr;
  FUNC_OnLeaveChannel onLeaveChannel = nullptr;
  FUNC_OnConnectionLost onConnectionLost = nullptr;
  FUNC_OnConnectionInterrupted onConnectionInterrupted = nullptr;
  FUNC_OnRequestToken onRequestToken = nullptr;
  FUNC_OnUserJoined onUserJoined = nullptr;
  FUNC_OnUserOffline onUserOffline = nullptr;
  FUNC_OnAudioVolumeIndication onAudioVolumeIndication = nullptr;
  FUNC_OnUserMuteAudio onUserMuteAudio = nullptr;
  FUNC_OnWarning onWarning = nullptr;
  FUNC_OnError onError = nullptr;
  FUNC_OnRtcStats onRtcStats = nullptr;
  FUNC_OnAudioMixingFinished onAudioMixingFinished = nullptr;
  FUNC_OnAudioRouteChanged onAudioRouteChanged = nullptr;
  FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded = nullptr;
  FUNC_OnVideoSizeChanged onVideoSizeChanged = nullptr;
  FUNC_OnClientRoleChanged onClientRoleChanged = nullptr;
  FUNC_OnUserMuteVideo onUserMuteVideo = nullptr;
  FUNC_OnMicrophoneEnabled onMicrophoneEnabled = nullptr;
  FUNC_OnApiExecuted onApiCallExecuted = nullptr;
  FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame = nullptr;
  FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame = nullptr;
  FUNC_OnLastmileQuality onLastmileQuality = nullptr;
  FUNC_OnAudioQuality onAudioQuality = nullptr;
  FUNC_OnStreamInjectedStatus onStreamInjectedStatus = nullptr;
  FUNC_OnStreamUnpublished onStreamUnpublished = nullptr;
  FUNC_OnStreamPublished onStreamPublished = nullptr;
  FUNC_OnStreamMessageError onStreamMessageError = nullptr;
  FUNC_OnStreamMessage onStreamMessage = nullptr;
  FUNC_OnConnectionBanned onConnectionBanned = nullptr;
  FUNC_OnRemoteVideoTransportStats onRemoteVideoTransportStats = nullptr;
  FUNC_OnRemoteAudioTransportStats onRemoteAudioTransportStats = nullptr;
  FUNC_OnTranscodingUpdated onTranscodingUpdated = nullptr;
  FUNC_OnAudioDeviceVolumeChanged onAudioDeviceVolumeChanged = nullptr;
  FUNC_OnActiveSpeaker onActiveSpeaker = nullptr;
  FUNC_OnMediaEngineStartCallSuccess onMediaEngineStartCallSuccess = nullptr;
  FUNC_OnMediaEngineLoadSuccess onMediaEngineLoadSuccess = nullptr;
  FUNC_OnConnectionStateChanged onConnectionStateChanged = nullptr;
  FUNC_OnRemoteSubscribeFallbackToAudioOnly
      onRemoteSubscribeFallbackToAudioOnly = nullptr;
  FUNC_OnLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly =
      nullptr;
  FUNC_OnUserEnableLocalVideo onUserEnableLocalVideo = nullptr;
  FUNC_OnRemoteVideoStateChanged onRemoteVideoStateChanged = nullptr;
  FUNC_OnVideoDeviceStateChanged onVideoDeviceStateChanged = nullptr;
  FUNC_OnAudioEffectFinished onAudioEffectFinished = nullptr;
  FUNC_OnRemoteAudioMixingEnd onRemoteAudioMixingEnd = nullptr;
  FUNC_OnRemoteAudioMixingBegin onRemoteAudioMixingBegin = nullptr;
  FUNC_OnCameraExposureAreaChanged onCameraExposureAreaChanged = nullptr;
  FUNC_OnCameraFocusAreaChanged onCameraFocusAreaChanged = nullptr;
  FUNC_OnCameraReady onCameraReady = nullptr;
  FUNC_OnAudioDeviceStateChanged onAudioDeviceStateChanged = nullptr;
  FUNC_OnUserEnableVideo onUserEnableVideo = nullptr;
  FUNC_OnFirstRemoteVideoFrame onFirstRemoteVideoFrame = nullptr;
  FUNC_OnFirstLocalVideoFrame onFirstLocalVideoFrame = nullptr;
  FUNC_OnRemoteAudioStats onRemoteAudioStats = nullptr;
  FUNC_OnRemoteVideoStats onRemoteVideoStats = nullptr;
  FUNC_OnLocalVideoStats onLocalVideoStats = nullptr;
  FUNC_OnNetworkQuality onNetworkQuality = nullptr;
  FUNC_OnTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = nullptr;
  FUNC_OnVideoStopped onVideoStopped = nullptr;
  FUNC_OnAudioMixingStateChanged onAudioMixingStateChanged = nullptr;
  FUNC_OnFirstRemoteAudioDecoded onFirstRemoteAudioDecoded = nullptr;
  FUNC_OnLocalVideoStateChanged onLocalVideoStateChanged = nullptr;
  FUNC_OnNetworkTypeChanged onNetworkTypeChanged = nullptr;
  FUNC_OnRtmpStreamingStateChanged onRtmpStreamingStateChanged = nullptr;
  FUNC_OnLastmileProbeResult onLastmileProbeResult = nullptr;
  FUNC_OnLocalUserRegistered onLocalUserRegistered = nullptr;
  FUNC_OnUserInfoUpdated onUserInfoUpdated = nullptr;
  FUNC_OnLocalAudioStateChanged onLocalAudioStateChanged = nullptr;
  FUNC_OnRemoteAudioStateChanged onRemoteAudioStateChanged = nullptr;
  FUNC_OnLocalAudioStats onLocalAudioStats = nullptr;
  FUNC_OnChannelMediaRelayStateChanged onChannelMediaRelayStateChanged =
      nullptr;
  FUNC_OnChannelMediaRelayEvent onChannelMediaRelayEvent = nullptr;
  FUNC_OnFacePositionChanged onFacePositionChanged = nullptr;
  FUNC_OnTestEnd onTestEnd = nullptr;

  void reset() {
    onJoinChannelSuccess = nullptr;
    onReJoinChannelSuccess = nullptr;
    onLeaveChannel = nullptr;
    onConnectionLost = nullptr;
    onConnectionInterrupted = nullptr;
    onRequestToken = nullptr;
    onUserJoined = nullptr;
    onUserOffline = nullptr;
    onAudioVolumeIndication = nullptr;
    onUserMuteAudio = nullptr;
    onWarning = nullptr;
    onError = nullptr;
    onRtcStats = nullptr;
    onAudioMixingFinished = nullptr;
    onAudioRouteChanged = nullptr;
    onFirstRemoteVideoDecoded = nullptr;
    onVideoSizeChanged = nullptr;
    onClientRoleChanged = nullptr;
    onUserMuteVideo = nullptr;
    onMicrophoneEnabled = nullptr;
    onApiCallExecuted = nullptr;
    onFirstLocalAudioFrame = nullptr;
    onFirstRemoteAudioFrame = nullptr;
    onLastmileQuality = nullptr;
    onAudioQuality = nullptr;
    onStreamInjectedStatus = nullptr;
    onStreamUnpublished = nullptr;
    onStreamPublished = nullptr;
    onStreamMessageError = nullptr;
    onStreamMessage = nullptr;
    onConnectionBanned = nullptr;
    onRemoteVideoTransportStats = nullptr;
    onRemoteAudioTransportStats = nullptr;
    onTranscodingUpdated = nullptr;
    onAudioDeviceVolumeChanged = nullptr;
    onActiveSpeaker = nullptr;
    onMediaEngineStartCallSuccess = nullptr;
    onMediaEngineLoadSuccess = nullptr;
    onConnectionStateChanged = nullptr;
    onRemoteSubscribeFallbackToAudioOnly = nullptr;
    onLocalPublishFallbackToAudioOnly = nullptr;
    onUserEnableLocalVideo = nullptr;
    onRemoteVideoStateChanged = nullptr;
    onVideoDeviceStateChanged = nullptr;
    onAudioEffectFinished = nullptr;
    onRemoteAudioMixingEnd = nullptr;
    onRemoteAudioMixingBegin = nullptr;
    onCameraExposureAreaChanged = nullptr;
    onCameraFocusAreaChanged = nullptr;
    onCameraReady = nullptr;
    onAudioDeviceStateChanged = nullptr;
    onUserEnableVideo = nullptr;
    onFirstRemoteVideoFrame = nullptr;
    onFirstLocalVideoFrame = nullptr;
    onRemoteAudioStats = nullptr;
    onRemoteVideoStats = nullptr;
    onLocalVideoStats = nullptr;
    onNetworkQuality = nullptr;
    onTokenPrivilegeWillExpire = nullptr;
    onVideoStopped = nullptr;
    onAudioMixingStateChanged = nullptr;
    onFirstRemoteAudioDecoded = nullptr;
    onLocalVideoStateChanged = nullptr;
    onNetworkTypeChanged = nullptr;
    onRtmpStreamingStateChanged = nullptr;
    onLastmileProbeResult = nullptr;
    onLocalUserRegistered = nullptr;
    onUserInfoUpdated = nullptr;
    onLocalAudioStateChanged = nullptr;
    onRemoteAudioStateChanged = nullptr;
    onLocalAudioStats = nullptr;
    onChannelMediaRelayStateChanged = nullptr;
    onChannelMediaRelayEvent = nullptr;
    onFacePositionChanged = nullptr;
    onTestEnd = nullptr;
  }
};

class RtcEngineEventHandler : public RtcEngineEventHandlerBase {
private:
  EngineEventHandler *mEventHandler = nullptr;
  CEngineEventHandler *cEngineEventHandler = nullptr;

public:
  RtcEngineEventHandler(EngineEventHandler *eventHandler);

  RtcEngineEventHandler();

  virtual ~RtcEngineEventHandler();

  void initCallbackEvent(CEngineEventHandler *engineEventHandler);

  void onJoinChannelSuccess(const char *channel, rtc::uid_t uid,
                            int elapsed) override;

  void onLeaveChannel(const rtc::RtcStats &stats) override;

  void onRejoinChannelSuccess(const char *channel, rtc::uid_t uid,
                              int elapsed) override;

  void onUserJoined(rtc::uid_t uid, int elapsed) override;

  void onClientRoleChanged(rtc::CLIENT_ROLE_TYPE oldRole,
                           rtc::CLIENT_ROLE_TYPE newRole) override;

  void onUserOffline(rtc::uid_t uid,
                     rtc::USER_OFFLINE_REASON_TYPE reason) override;

  void onUserMuteAudio(rtc::uid_t uid, bool muted) override;

  void onFirstRemoteVideoDecoded(rtc::uid_t uid, int width, int height,
                                 int elapsed) override;

  void onUserMuteVideo(rtc::uid_t uid, bool muted) override;

  void onAudioRouteChanged(rtc::AUDIO_ROUTE_TYPE routing) override;

  void onConnectionLost() override;

  void onRequestToken() override;

  void onAudioVolumeIndication(const rtc::AudioVolumeInfo *speakers,
                               unsigned int speakerNumber,
                               int totalVolume) override;

  void onWarning(int warn, const char *msg) override;

  void onError(int err, const char *msg) override;

  void onRtcStats(const rtc::RtcStats &stats) override;

  void onAudioMixingFinished() override;

  void onVideoSizeChanged(rtc::uid_t uid, int width, int height,
                          int rotation) override;

  void onConnectionInterrupted() override;

  void onMicrophoneEnabled(bool enabled) override;

  void onAudioQuality(rtc::uid_t uid, int quality, unsigned short delay,
                      unsigned short lost) override;

  void onRemoteVideoTransportStats(rtc::uid_t uid, unsigned short delay,
                                   unsigned short lost,
                                   unsigned short rxKBitRate) override;

  void onRemoteAudioTransportStats(rtc::uid_t uid, unsigned short delay,
                                   unsigned short lost,
                                   unsigned short rxKBitRate) override;

  void onStreamInjectedStatus(const char *url, rtc::uid_t uid,
                              int status) override;

  void onTranscodingUpdated() override;

  void onStreamUnpublished(const char *url) override;

  void onStreamPublished(const char *url, int error) override;

  void onAudioDeviceVolumeChanged(rtc::MEDIA_DEVICE_TYPE deviceType, int volume,
                                  bool muted) override;

  void onActiveSpeaker(rtc::uid_t uid) override;

  void onFirstRemoteAudioFrame(rtc::uid_t uid, int elapsed) override;

  void onFirstLocalAudioFrame(int elapsed) override;

  void onMediaEngineStartCallSuccess() override;

  void onMediaEngineLoadSuccess() override;

  void onStreamMessageError(rtc::uid_t uid, int streamId, int code, int missed,
                            int cached) override;

  void onStreamMessage(rtc::uid_t uid, int streamId, const char *data,
                       size_t length) override;

  void onConnectionBanned() override;

  void onLastmileQuality(int quality) override;

  void onVideoStopped() override;

  void onApiCallExecuted(int err, const char *api, const char *result) override;

  void onTokenPrivilegeWillExpire(const char *token) override;

  void onNetworkQuality(rtc::uid_t uid, int txQuality, int rxQuality) override;

  void onLocalVideoStats(const rtc::LocalVideoStats &stats) override;

  void onLocalAudioStats(const rtc::LocalAudioStats &stats) override;

  void onRemoteVideoStats(const rtc::RemoteVideoStats &stats) override;

  void onRemoteAudioStats(const rtc::RemoteAudioStats &stats) override;

  void onFirstLocalVideoFrame(int width, int height, int elapsed) override;

  void onFirstRemoteVideoFrame(rtc::uid_t uid, int width, int height,
                               int elapsed) override;

  void onUserEnableVideo(rtc::uid_t uid, bool enabled) override;

  void onAudioDeviceStateChanged(const char *deviceId, int deviceType,
                                 int deviceState) override;

  void onCameraReady() override;

  void onCameraFocusAreaChanged(int x, int y, int width, int height) override;

  void onCameraExposureAreaChanged(int x, int y, int width,
                                   int height) override;

  void onRemoteAudioMixingBegin() override;

  void onRemoteAudioMixingEnd() override;

  void onAudioEffectFinished(int soundId) override;

  void onVideoDeviceStateChanged(const char *deviceId, int deviceType,
                                 int deviceState) override;

  void onRemoteVideoStateChanged(rtc::uid_t uid, rtc::REMOTE_VIDEO_STATE state,
                                 rtc::REMOTE_VIDEO_STATE_REASON reason,
                                 int elapsed) override;

  void onUserEnableLocalVideo(rtc::uid_t uid, bool enabled) override;

  void onLocalPublishFallbackToAudioOnly(bool isFallbackOrRecover) override;

  void onRemoteSubscribeFallbackToAudioOnly(rtc::uid_t uid,
                                            bool isFallbackOrRecover) override;

  void
  onConnectionStateChanged(rtc::CONNECTION_STATE_TYPE state,
                           rtc::CONNECTION_CHANGED_REASON_TYPE reason) override;

  void
  onAudioMixingStateChanged(rtc::AUDIO_MIXING_STATE_TYPE state,
                            rtc::AUDIO_MIXING_ERROR_TYPE errorCode) override;

  void onFirstRemoteAudioDecoded(rtc::uid_t uid, int elapsed) override;

  void onLocalVideoStateChanged(rtc::LOCAL_VIDEO_STREAM_STATE localVideoState,
                                rtc::LOCAL_VIDEO_STREAM_ERROR error) override;

  void
  onRtmpStreamingStateChanged(const char *url,
                              rtc::RTMP_STREAM_PUBLISH_STATE state,
                              rtc::RTMP_STREAM_PUBLISH_ERROR errCode) override;

  void onNetworkTypeChanged(rtc::NETWORK_TYPE type) override;

  void onLastmileProbeResult(const rtc::LastmileProbeResult &result) override;

  void onLocalUserRegistered(rtc::uid_t uid, const char *userAccount) override;

  void onUserInfoUpdated(rtc::uid_t uid, const rtc::UserInfo &info) override;

  void onLocalAudioStateChanged(rtc::LOCAL_AUDIO_STREAM_STATE state,
                                rtc::LOCAL_AUDIO_STREAM_ERROR error) override;

  void onRemoteAudioStateChanged(rtc::uid_t uid, rtc::REMOTE_AUDIO_STATE state,
                                 rtc::REMOTE_AUDIO_STATE_REASON reason,
                                 int elapsed) override;

  void
  onChannelMediaRelayStateChanged(rtc::CHANNEL_MEDIA_RELAY_STATE state,
                                  rtc::CHANNEL_MEDIA_RELAY_ERROR code) override;

  void onChannelMediaRelayEvent(rtc::CHANNEL_MEDIA_RELAY_EVENT code) override;

#if defined(__ANDROID__) || (defined(__APPLE__) && TARGET_OS_IOS)

  void onFacePositionChanged(int imageWidth, int imageHeight,
                             rtc::Rectangle *vecRectangle, int *vecDistance,
                             int numFaces) override;

#endif
  void onTestEnd() override;
};
} // namespace common
} // namespace agora
