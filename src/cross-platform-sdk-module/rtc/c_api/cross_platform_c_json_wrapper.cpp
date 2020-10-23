//
// Created by 张涛 on 2020-08-18.
//

#include "cross_platform_c_json_wrapper.h"
#include "../deviceManager/IAudioDeviceManagerBridge.h"
#include "../deviceManager/IVideoDeviceManagerBridge.h"
#include "../rtcChannel/RtcChannelBridge.h"
#include "../rtcEngine/RtcEngineBridge.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IRtcEngineBridge                                                       \
  static_cast<agora::common::IRtcEngineBridge *>(apiBridge)
#define IRtcChannelBridge                                                      \
  static_cast<agora::common::IRtcChannelBridge *>(apiBridge)
#define IVideoDeviceManagerBridge                                              \
  static_cast<agora::common::IVideoDeviceManagerBridge *>(apiBridge)
#define IAudioDeviceManagerBridge                                              \
  static_cast<agora::common::IAudioDeviceManagerBridge *>(apiBridge)

IRtcEngineBridge_ptr createRtcBridge() {
  return agora::common::createRtcEngineBridge();
}

void add_C_EventHandler(IRtcEngineBridge_ptr apiBridge,
                        struct RtcEventHandler *handler) {
  agora::common::CEngineEventHandler _engineEventHandler;
  _engineEventHandler.onJoinChannelSuccess = handler->onJoinChannelSuccess;
  _engineEventHandler.onReJoinChannelSuccess = handler->onReJoinChannelSuccess;
  _engineEventHandler.onConnectionLost = handler->onConnectionLost;
  _engineEventHandler.onLeaveChannel = handler->onLeaveChannel;
  _engineEventHandler.onConnectionInterrupted =
      handler->onConnectionInterrupted;
  _engineEventHandler.onRequestToken = handler->onRequestToken;
  _engineEventHandler.onUserJoined = handler->onUserJoined;
  _engineEventHandler.onUserOffline = handler->onUserOffline;
  _engineEventHandler.onAudioVolumeIndication =
      handler->onAudioVolumeIndication;
  _engineEventHandler.onUserMuteAudio = handler->onUserMuteAudio;
  _engineEventHandler.onWarning = handler->onWarning;
  _engineEventHandler.onError = handler->onError;
  _engineEventHandler.onRtcStats = handler->onRtcStats;
  _engineEventHandler.onAudioMixingFinished = handler->onAudioMixingFinished;
  _engineEventHandler.onAudioRouteChanged = handler->onAudioRouteChanged;
  _engineEventHandler.onFirstRemoteVideoDecoded =
      handler->onFirstRemoteVideoDecoded;
  _engineEventHandler.onVideoSizeChanged = handler->onVideoSizeChanged;
  _engineEventHandler.onClientRoleChanged = handler->onClientRoleChanged;
  _engineEventHandler.onUserMuteVideo = handler->onUserMuteVideo;
  _engineEventHandler.onMicrophoneEnabled = handler->onMicrophoneEnabled;
  _engineEventHandler.onApiCallExecuted = handler->onApiCallExecuted;
  _engineEventHandler.onFirstLocalAudioFrame = handler->onFirstLocalAudioFrame;
  _engineEventHandler.onFirstRemoteAudioFrame =
      handler->onFirstRemoteAudioFrame;
  _engineEventHandler.onLastmileQuality = handler->onLastmileQuality;
  _engineEventHandler.onAudioQuality = handler->onAudioQuality;
  _engineEventHandler.onStreamInjectedStatus = handler->onStreamInjectedStatus;
  _engineEventHandler.onStreamUnpublished = handler->onStreamUnpublished;
  _engineEventHandler.onStreamPublished = handler->onStreamPublished;
  _engineEventHandler.onStreamMessageError = handler->onStreamMessageError;
  _engineEventHandler.onStreamMessage = handler->onStreamMessage;
  _engineEventHandler.onConnectionBanned = handler->onConnectionBanned;
  _engineEventHandler.onVideoStopped = handler->onVideoStopped;
  _engineEventHandler.onTokenPrivilegeWillExpire =
      handler->onTokenPrivilegeWillExpire;
  _engineEventHandler.onNetworkQuality = handler->onNetworkQuality;
  _engineEventHandler.onLocalVideoStats = handler->onLocalVideoStats;
  _engineEventHandler.onRemoteVideoStats = handler->onRemoteVideoStats;
  _engineEventHandler.onRemoteAudioStats = handler->onRemoteAudioStats;
  _engineEventHandler.onFirstLocalVideoFrame = handler->onFirstLocalVideoFrame;
  _engineEventHandler.onFirstRemoteVideoFrame =
      handler->onFirstRemoteVideoFrame;
  _engineEventHandler.onUserEnableVideo = handler->onUserEnableVideo;
  _engineEventHandler.onAudioDeviceStateChanged =
      handler->onAudioDeviceStateChanged;
  _engineEventHandler.onCameraReady = handler->onCameraReady;
  _engineEventHandler.onCameraFocusAreaChanged =
      handler->onCameraFocusAreaChanged;
  _engineEventHandler.onCameraExposureAreaChanged =
      handler->onCameraExposureAreaChanged;
  _engineEventHandler.onRemoteAudioMixingBegin =
      handler->onRemoteAudioMixingBegin;
  _engineEventHandler.onRemoteAudioMixingEnd = handler->onRemoteAudioMixingEnd;
  _engineEventHandler.onAudioEffectFinished = handler->onAudioEffectFinished;
  _engineEventHandler.onVideoDeviceStateChanged =
      handler->onVideoDeviceStateChanged;
  _engineEventHandler.onRemoteVideoStateChanged =
      handler->onRemoteVideoStateChanged;
  _engineEventHandler.onUserEnableLocalVideo = handler->onUserEnableLocalVideo;
  _engineEventHandler.onLocalPublishFallbackToAudioOnly =
      handler->onLocalPublishFallbackToAudioOnly;
  _engineEventHandler.onRemoteSubscribeFallbackToAudioOnly =
      handler->onRemoteSubscribeFallbackToAudioOnly;
  _engineEventHandler.onConnectionStateChanged =
      handler->onConnectionStateChanged;
  _engineEventHandler.onRemoteVideoTransportStats =
      handler->onRemoteVideoTransportStats;
  _engineEventHandler.onRemoteAudioTransportStats =
      handler->onRemoteAudioTransportStats;
  _engineEventHandler.onTranscodingUpdated = handler->onTranscodingUpdated;
  _engineEventHandler.onAudioDeviceVolumeChanged =
      handler->onAudioDeviceVolumeChanged;
  _engineEventHandler.onActiveSpeaker = handler->onActiveSpeaker;
  _engineEventHandler.onMediaEngineStartCallSuccess =
      handler->onMediaEngineStartCallSuccess;
  _engineEventHandler.onMediaEngineLoadSuccess =
      handler->onMediaEngineLoadSuccess;
  _engineEventHandler.onAudioMixingStateChanged =
      handler->onAudioMixingStateChanged;
  _engineEventHandler.onFirstRemoteAudioDecoded =
      handler->onFirstRemoteAudioDecoded;
  _engineEventHandler.onLocalVideoStateChanged =
      handler->onLocalVideoStateChanged;
  _engineEventHandler.onRtmpStreamingStateChanged =
      handler->onRtmpStreamingStateChanged;
  _engineEventHandler.onNetworkTypeChanged = handler->onNetworkTypeChanged;
  _engineEventHandler.onLastmileProbeResult = handler->onLastmileProbeResult;
  _engineEventHandler.onLocalUserRegistered = handler->onLocalUserRegistered;
  _engineEventHandler.onUserInfoUpdated = handler->onUserInfoUpdated;
  _engineEventHandler.onLocalAudioStateChanged =
      handler->onLocalAudioStateChanged;
  _engineEventHandler.onRemoteAudioStateChanged =
      handler->onRemoteAudioStateChanged;
  _engineEventHandler.onLocalAudioStats = handler->onLocalAudioStats;
  _engineEventHandler.onChannelMediaRelayStateChanged =
      handler->onChannelMediaRelayStateChanged;
  _engineEventHandler.onChannelMediaRelayEvent =
      handler->onChannelMediaRelayEvent;
  _engineEventHandler.onFacePositionChanged = handler->onFacePositionChanged;
  _engineEventHandler.onTestEnd = handler->onTestEnd;
  IRtcEngineBridge->add_C_EventHandler(&_engineEventHandler);
}

void remove_C_EventHandler(IRtcEngineBridge_ptr apiBridge) {
  IRtcEngineBridge->remove_C_EventHandler();
}

enum ERROR_CODE callApi_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                   enum API_TYPE apiType,
                                   const char *parameters) {
  if (apiBridge) {
    return ERROR_CODE(IRtcEngineBridge->callApi(
        agora::common::API_TYPE(apiType), std::string(parameters)));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE callApi2_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                    enum API_TYPE apiType,
                                    const char *parameters, void *ptr) {
  if (apiBridge) {
    return ERROR_CODE(IRtcEngineBridge->callApi(
        agora::common::API_TYPE(apiType), std::string(parameters), ptr));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

const char *callApi_str_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                                   enum API_TYPE apiType,
                                   const char *parameters) {
  if (apiBridge) {
    return IRtcEngineBridge->callApi_str(agora::common::API_TYPE(apiType),
                                         std::string(parameters));
  }

  return "No Engine";
}

enum ERROR_CODE
callApi_audioEffect_rtc_engine(IRtcEngineBridge_ptr apiBridge,
                               enum API_TYPE_AUDIO_EFFECT apiType,
                               const char *parameters) {
  if (apiBridge) {
    return ERROR_CODE(IRtcEngineBridge->callApi_audioEffect(
        agora::common::API_TYPE_AUDIO_EFFECT(apiType),
        std::string(parameters)));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_rtc_engine_bridge(IRtcEngineBridge_ptr apiBridge, BOOL sync) {
  if (apiBridge) {
    IRtcEngineBridge->release(sync);
    apiBridge = NULL;
  }
}

IRtcChannelBridge_ptr createChannelBridge(IRtcEngineBridge_ptr apiBridge,
                                          const char *channelId) {
  if (apiBridge) {
    return IRtcEngineBridge->createChannel(channelId);
  }

  return NULL;
}

void channel_add_C_ChannelEventHandler(
    IRtcChannelBridge_ptr apiBridge,
    struct ChannelEventHandler *channelEventHandler) {
  agora::common::CChannelEngineEventHandler channelEngineEventHandler;
  channelEngineEventHandler.onWarning = channelEventHandler->onWarning;
  channelEngineEventHandler.onError = channelEventHandler->onError;
  channelEngineEventHandler.onJoinChannelSuccess =
      channelEventHandler->onJoinChannelSuccess;
  channelEngineEventHandler.onRejoinChannelSuccess =
      channelEventHandler->onRejoinChannelSuccess;
  channelEngineEventHandler.onLeaveChannel =
      channelEventHandler->onLeaveChannel;
  channelEngineEventHandler.onClientRoleChanged =
      channelEventHandler->onClientRoleChanged;
  channelEngineEventHandler.onUserJoined = channelEventHandler->onUserJoined;
  channelEngineEventHandler.onUserOffLine = channelEventHandler->onUserOffLine;
  channelEngineEventHandler.onConnectionLost =
      channelEventHandler->onConnectionLost;
  channelEngineEventHandler.onRequestToken =
      channelEventHandler->onRequestToken;
  channelEngineEventHandler.onTokenPrivilegeWillExpire =
      channelEventHandler->onTokenPrivilegeWillExpire;
  channelEngineEventHandler.onRtcStats = channelEventHandler->onRtcStats;
  channelEngineEventHandler.onNetworkQuality =
      channelEventHandler->onNetworkQuality;
  channelEngineEventHandler.onRemoteVideoStats =
      channelEventHandler->onRemoteVideoStats;
  channelEngineEventHandler.onRemoteAudioStats =
      channelEventHandler->onRemoteAudioStats;
  channelEngineEventHandler.onRemoteAudioStateChanged =
      channelEventHandler->onRemoteAudioStateChanged;
  channelEngineEventHandler.onActiveSpeaker =
      channelEventHandler->onActiveSpeaker;
  channelEngineEventHandler.onVideoSizeChanged =
      channelEventHandler->onVideoSizeChanged;
  channelEngineEventHandler.onRemoteVideoStateChanged =
      channelEventHandler->onRemoteVideoStateChanged;
  channelEngineEventHandler.onStreamMessage =
      channelEventHandler->onStreamMessage;
  channelEngineEventHandler.onStreamMessageError =
      channelEventHandler->onStreamMessageError;
  channelEngineEventHandler.onMediaRelayStateChanged =
      channelEventHandler->onMediaRelayStateChanged;
  channelEngineEventHandler.onMediaRelayEvent =
      channelEventHandler->onMediaRelayEvent;
  channelEngineEventHandler.onRtmpStreamingStateChanged =
      channelEventHandler->onRtmpStreamingStateChanged;
  channelEngineEventHandler.onTranscodingUpdated =
      channelEventHandler->onTranscodingUpdated;
  channelEngineEventHandler.onStreamInjectedStatus =
      channelEventHandler->onStreamInjectedStatus;
  channelEngineEventHandler.onRemoteSubscribeFallbackToAudioOnly =
      channelEventHandler->onRemoteSubscribeFallbackToAudioOnly;
  channelEngineEventHandler.onConnectionStateChanged =
      channelEventHandler->onConnectionStateChanged;
  channelEngineEventHandler.onLocalPublishFallbackToAudioOnly =
      channelEventHandler->onLocalPublishFallbackToAudioOnly;
  channelEngineEventHandler.onTestEnd = channelEventHandler->onTestEnd;
  IRtcChannelBridge->add_C_ChannelEventHandler(&channelEngineEventHandler);
}

void channel_remove_C_ChannelEventHandler(IRtcChannelBridge_ptr apiBridge) {
  IRtcChannelBridge->remove_C_ChannelEventHandler();
}

enum ERROR_CODE callApi_channel(IRtcChannelBridge_ptr apiBridge,
                                enum API_TYPE apiType, const char *parameters) {
  if (apiBridge) {
    return ERROR_CODE(IRtcChannelBridge->callApi(
        agora::common::API_TYPE(apiType), std::string(parameters)));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

const char *callApi_str_channel(IRtcChannelBridge_ptr apiBridge,
                                enum API_TYPE apiType, const char *parameters) {
  if (apiBridge) {
    return IRtcChannelBridge->callApi_str(agora::common::API_TYPE(apiType),
                                          std::string(parameters));
  }

  return "NO ENGINE";
}

enum ERROR_CODE callApi2_channel(IRtcChannelBridge_ptr apiBridge,
                                 enum API_TYPE apiType, const char *parameters,
                                 void *ptr) {
  if (apiBridge) {
    return ERROR_CODE(IRtcChannelBridge->callApi(
        agora::common::API_TYPE(apiType), std::string(parameters), ptr));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_channel_bridge(IRtcChannelBridge_ptr apiBridge) {
  if (apiBridge) {
    IRtcChannelBridge->release();
    apiBridge = NULL;
  }
}

IVideoDeviceManagerBridge_ptr
createVideoDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge,
                               enum ERROR_CODE *errorCode) {
  agora::common::ERROR_CODE error_code = agora::common::ERROR_CODE::ERROR_OK;

  if (apiBridge) {
    IVideoDeviceManagerBridge_ptr videoDeviceManagerBridge_ptr =
        IRtcEngineBridge->createVideoDeviceManager(error_code);
    *errorCode = ERROR_CODE(error_code);
    return videoDeviceManagerBridge_ptr;
  }

  return NULL;
}

enum ERROR_CODE
callApi_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge,
                             enum API_TYPE_DEVICE_MANAGER apiType,
                             const char *parameters, void *ptr) {
  if (apiBridge) {
    return ERROR_CODE(IVideoDeviceManagerBridge->callApi(
        agora::common::API_TYPE_DEVICE_MANAGER(apiType),
        std::string(parameters), ptr));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi2_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr, void *ptr2) {
  if (apiBridge) {
    return ERROR_CODE(IVideoDeviceManagerBridge->callApi(
        agora::common::API_TYPE_DEVICE_MANAGER(apiType),
        std::string(parameters), ptr, ptr2));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_video_device_manager_bridge(
    IVideoDeviceManagerBridge_ptr apiBridge) {
  if (apiBridge) {
    IVideoDeviceManagerBridge->release();
  }
}

IAudioDeviceManagerBridge_ptr
createDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge,
                          enum DEVICE_TYPE device_type,
                          enum ERROR_CODE *errorCode) {
  agora::common::ERROR_CODE error_code = agora::common::ERROR_CODE::ERROR_OK;
  if (apiBridge) {
    IAudioDeviceManagerBridge_ptr audioDeviceManagerBridge =
        IRtcEngineBridge->createAudioDeviceManager(
            agora::common::DEVICE_TYPE(device_type), error_code);

    *errorCode = ERROR_CODE(error_code);

    return audioDeviceManagerBridge;
  }

  return NULL;
}

enum ERROR_CODE
callApi_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                             enum API_TYPE_DEVICE_MANAGER apiType,
                             const char *parameters) {
  if (apiBridge) {
    return ERROR_CODE(IAudioDeviceManagerBridge->callApi(
        agora::common::API_TYPE_DEVICE_MANAGER(apiType),
        std::string(parameters)));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi2_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr) {
  if (apiBridge) {
    return ERROR_CODE(IAudioDeviceManagerBridge->callApi(
        agora::common::API_TYPE_DEVICE_MANAGER(apiType),
        std::string(parameters), ptr));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi3_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge,
                              enum API_TYPE_DEVICE_MANAGER apiType,
                              const char *parameters, void *ptr, void *ptr2) {
  if (apiBridge) {
    return ERROR_CODE(IAudioDeviceManagerBridge->callApi(
        agora::common::API_TYPE_DEVICE_MANAGER(apiType),
        std::string(parameters), ptr, ptr2));
  }

  return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_audio_device_manager_bridge(
    IAudioDeviceManagerBridge_ptr apiBridge) {
  if (apiBridge) {
    IAudioDeviceManagerBridge->release();
    apiBridge = NULL;
  }
}

#ifdef __cplusplus
};
#endif