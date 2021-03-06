/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_agorartc_WRAP_H_
#define SWIG_agorartc_WRAP_H_

#include <map>
#include <string>


class SwigDirector_RtcEngineEventHandlerBase : public agora::common::RtcEngineEventHandlerBase, public Swig::Director {

public:
    SwigDirector_RtcEngineEventHandlerBase(PyObject *self);
    virtual ~SwigDirector_RtcEngineEventHandlerBase();
    virtual void onJoinChannelSuccess(char const *channel, agora::rtc::uid_t uid, int elapsed);
    virtual void onLeaveChannel(agora::rtc::RtcStats const &stats);
    virtual void onRejoinChannelSuccess(char const *channel, agora::rtc::uid_t uid, int elapsed);
    virtual void onUserJoined(agora::rtc::uid_t uid, int elapsed);
    virtual void onClientRoleChanged(agora::rtc::CLIENT_ROLE_TYPE oldRole, agora::rtc::CLIENT_ROLE_TYPE newRole);
    virtual void onUserOffline(agora::rtc::uid_t uid, agora::rtc::USER_OFFLINE_REASON_TYPE reason);
    virtual void onUserMuteAudio(agora::rtc::uid_t uid, bool muted);
    virtual void onFirstRemoteVideoDecoded(agora::rtc::uid_t uid, int width, int height, int elapsed);
    virtual void onUserMuteVideo(agora::rtc::uid_t uid, bool muted);
    virtual void onAudioRouteChanged(agora::rtc::AUDIO_ROUTE_TYPE routing);
    virtual void onConnectionLost();
    virtual void onRequestToken();
    virtual void onAudioVolumeIndication(agora::rtc::AudioVolumeInfo const *speakers, unsigned int speakerNumber, int totalVolume);
    virtual void onWarning(int warn, char const *msg);
    virtual void onError(int err, char const *msg);
    virtual void onRtcStats(agora::rtc::RtcStats const &stats);
    virtual void onAudioMixingFinished();
    virtual void onVideoSizeChanged(agora::rtc::uid_t uid, int width, int height, int rotation);
    virtual void onConnectionInterrupted();
    virtual void onMicrophoneEnabled(bool enabled);
    virtual void onAudioQuality(agora::rtc::uid_t uid, int quality, unsigned short delay, unsigned short lost);
    virtual void onRemoteVideoTransportStats(agora::rtc::uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
    virtual void onRemoteAudioTransportStats(agora::rtc::uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
    virtual void onStreamInjectedStatus(char const *url, agora::rtc::uid_t uid, int status);
    virtual void onTranscodingUpdated();
    virtual void onStreamUnpublished(char const *url);
    virtual void onStreamPublished(char const *url, int error);
    virtual void onAudioDeviceVolumeChanged(agora::rtc::MEDIA_DEVICE_TYPE deviceType, int volume, bool muted);
    virtual void onActiveSpeaker(agora::rtc::uid_t uid);
    virtual void onFirstRemoteAudioFrame(agora::rtc::uid_t uid, int elapsed);
    virtual void onFirstLocalAudioFrame(int elapsed);
    virtual void onMediaEngineStartCallSuccess();
    virtual void onMediaEngineLoadSuccess();
    virtual void onStreamMessageError(agora::rtc::uid_t uid, int streamId, int code, int missed, int cached);
    virtual void onStreamMessage(agora::rtc::uid_t uid, int streamId, char const *data, size_t length);
    virtual void onConnectionBanned();
    virtual void onLastmileQuality(int quality);
    virtual void onVideoStopped();
    virtual void onApiCallExecuted(int err, char const *api, char const *result);
    virtual void onTokenPrivilegeWillExpire(char const *token);
    virtual void onNetworkQuality(agora::rtc::uid_t uid, int txQuality, int rxQuality);
    virtual void onLocalVideoStats(agora::rtc::LocalVideoStats const &stats);
    virtual void onLocalAudioStats(agora::rtc::LocalAudioStats const &stats);
    virtual void onRemoteVideoStats(agora::rtc::RemoteVideoStats const &stats);
    virtual void onRemoteAudioStats(agora::rtc::RemoteAudioStats const &stats);
    virtual void onFirstLocalVideoFrame(int width, int height, int elapsed);
    virtual void onFirstRemoteVideoFrame(agora::rtc::uid_t uid, int width, int height, int elapsed);
    virtual void onUserEnableVideo(agora::rtc::uid_t uid, bool enabled);
    virtual void onAudioDeviceStateChanged(char const *deviceId, int deviceType, int deviceState);
    virtual void onCameraReady();
    virtual void onCameraFocusAreaChanged(int x, int y, int width, int height);
    virtual void onCameraExposureAreaChanged(int x, int y, int width, int height);
    virtual void onRemoteAudioMixingBegin();
    virtual void onRemoteAudioMixingEnd();
    virtual void onAudioEffectFinished(int soundId);
    virtual void onVideoDeviceStateChanged(char const *deviceId, int deviceType, int deviceState);
    virtual void onRemoteVideoStateChanged(agora::rtc::uid_t uid, agora::rtc::REMOTE_VIDEO_STATE state, agora::rtc::REMOTE_VIDEO_STATE_REASON reason, int elapsed);
    virtual void onUserEnableLocalVideo(agora::rtc::uid_t uid, bool enabled);
    virtual void onLocalPublishFallbackToAudioOnly(bool isFallbackOrRecover);
    virtual void onRemoteSubscribeFallbackToAudioOnly(agora::rtc::uid_t uid, bool isFallbackOrRecover);
    virtual void onConnectionStateChanged(agora::rtc::CONNECTION_STATE_TYPE state, agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason);
    virtual void onAudioMixingStateChanged(agora::rtc::AUDIO_MIXING_STATE_TYPE state, agora::rtc::AUDIO_MIXING_ERROR_TYPE errorCode);
    virtual void onFirstRemoteAudioDecoded(agora::rtc::uid_t uid, int elapsed);
    virtual void onLocalVideoStateChanged(agora::rtc::LOCAL_VIDEO_STREAM_STATE localVideoState, agora::rtc::LOCAL_VIDEO_STREAM_ERROR error);
    virtual void onRtmpStreamingStateChanged(char const *url, agora::rtc::RTMP_STREAM_PUBLISH_STATE state, agora::rtc::RTMP_STREAM_PUBLISH_ERROR errCode);
    virtual void onNetworkTypeChanged(agora::rtc::NETWORK_TYPE type);
    virtual void onLastmileProbeResult(agora::rtc::LastmileProbeResult const &result);
    virtual void onLocalUserRegistered(agora::rtc::uid_t uid, char const *userAccount);
    virtual void onUserInfoUpdated(agora::rtc::uid_t uid, agora::rtc::UserInfo const &info);
    virtual void onLocalAudioStateChanged(agora::rtc::LOCAL_AUDIO_STREAM_STATE state, agora::rtc::LOCAL_AUDIO_STREAM_ERROR error);
    virtual void onRemoteAudioStateChanged(agora::rtc::uid_t uid, agora::rtc::REMOTE_AUDIO_STATE state, agora::rtc::REMOTE_AUDIO_STATE_REASON reason, int elapsed);
    virtual void onChannelMediaRelayStateChanged(agora::rtc::CHANNEL_MEDIA_RELAY_STATE state, agora::rtc::CHANNEL_MEDIA_RELAY_ERROR code);
    virtual void onChannelMediaRelayEvent(agora::rtc::CHANNEL_MEDIA_RELAY_EVENT code);
    virtual void onTestEnd();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class RtcEngineEventHandlerBase doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[74];
#endif

};


class SwigDirector_RtcChannelEventHandlerBase : public agora::common::RtcChannelEventHandlerBase, public Swig::Director {

public:
    SwigDirector_RtcChannelEventHandlerBase(PyObject *self);
    virtual ~SwigDirector_RtcChannelEventHandlerBase();
    virtual void onChannelWarning(agora::rtc::IChannel *rtcChannel, int warn, char const *msg);
    virtual void onChannelError(agora::rtc::IChannel *rtcChannel, int err, char const *msg);
    virtual void onJoinChannelSuccess(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed);
    virtual void onRejoinChannelSuccess(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed);
    virtual void onLeaveChannel(agora::rtc::IChannel *rtcChannel, agora::rtc::RtcStats const &stats);
    virtual void onClientRoleChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::CLIENT_ROLE_TYPE oldRole, agora::rtc::CLIENT_ROLE_TYPE newRole);
    virtual void onUserJoined(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int elapsed);
    virtual void onUserOffline(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::USER_OFFLINE_REASON_TYPE reason);
    virtual void onConnectionLost(agora::rtc::IChannel *rtcChannel);
    virtual void onRequestToken(agora::rtc::IChannel *rtcChannel);
    virtual void onTokenPrivilegeWillExpire(agora::rtc::IChannel *rtcChannel, char const *token);
    virtual void onRtcStats(agora::rtc::IChannel *rtcChannel, agora::rtc::RtcStats const &stats);
    virtual void onNetworkQuality(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int txQuality, int rxQuality);
    virtual void onRemoteVideoStats(agora::rtc::IChannel *rtcChannel, agora::rtc::RemoteVideoStats const &stats);
    virtual void onRemoteAudioStats(agora::rtc::IChannel *rtcChannel, agora::rtc::RemoteAudioStats const &stats);
    virtual void onRemoteAudioStateChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::REMOTE_AUDIO_STATE state, agora::rtc::REMOTE_AUDIO_STATE_REASON reason, int elapsed);
    virtual void onActiveSpeaker(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid);
    virtual void onVideoSizeChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int width, int height, int rotation);
    virtual void onRemoteVideoStateChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, agora::rtc::REMOTE_VIDEO_STATE state, agora::rtc::REMOTE_VIDEO_STATE_REASON reason, int elapsed);
    virtual void onStreamMessage(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int streamId, char const *data, size_t length);
    virtual void onStreamMessageError(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, int streamId, int code, int missed, int cached);
    virtual void onChannelMediaRelayStateChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_STATE state, agora::rtc::CHANNEL_MEDIA_RELAY_ERROR code);
    virtual void onChannelMediaRelayEvent(agora::rtc::IChannel *rtcChannel, agora::rtc::CHANNEL_MEDIA_RELAY_EVENT code);
    virtual void onRtmpStreamingStateChanged(agora::rtc::IChannel *rtcChannel, char const *url, agora::rtc::RTMP_STREAM_PUBLISH_STATE state, agora::rtc::RTMP_STREAM_PUBLISH_ERROR errCode);
    virtual void onTranscodingUpdated(agora::rtc::IChannel *rtcChannel);
    virtual void onStreamInjectedStatus(agora::rtc::IChannel *rtcChannel, char const *url, agora::rtc::uid_t uid, int status);
    virtual void onLocalPublishFallbackToAudioOnly(agora::rtc::IChannel *rtcChannel, bool isFallbackOrRecover);
    virtual void onRemoteSubscribeFallbackToAudioOnly(agora::rtc::IChannel *rtcChannel, agora::rtc::uid_t uid, bool isFallbackOrRecover);
    virtual void onConnectionStateChanged(agora::rtc::IChannel *rtcChannel, agora::rtc::CONNECTION_STATE_TYPE state, agora::rtc::CONNECTION_CHANGED_REASON_TYPE reason);
    virtual void onTestEnd(agora::rtc::IChannel *rtcChannel);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class RtcChannelEventHandlerBase doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[30];
#endif

};


class SwigDirector_VideoFrameObserver : public VideoFrameObserver, public Swig::Director {

public:
    SwigDirector_VideoFrameObserver(PyObject *self);
    virtual ~SwigDirector_VideoFrameObserver();
    virtual void onCaptureVideoFrame(int width, int height, uint64_t ybuffer, uint64_t ubuffer, uint64_t vbuffer);
    virtual void onRenderVideoFrame(unsigned int uid, int width, int height, uint64_t ybuffer, uint64_t ubuffer, uint64_t vbuffer);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class VideoFrameObserver doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[2];
#endif

};


class SwigDirector_AudioFrameObserver : public AudioFrameObserver, public Swig::Director {

public:
    SwigDirector_AudioFrameObserver(PyObject *self);
    virtual ~SwigDirector_AudioFrameObserver();
    virtual void onRecordAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type);
    virtual void onPlaybackAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type);
    virtual void onMixedAudioFrame(unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type);
    virtual void onPlaybackAudioFrameBeforeMixing(unsigned int uid, unsigned int type1, int samples, int bytesPerSample, int channels, int samplesPerSec, uint64_t buffer1, int64_t renderTimeMs, int avsync_type);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class AudioFrameObserver doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[4];
#endif

};


class SwigDirector_APICaseHandler : public agora::common::APICaseHandler, public Swig::Director {

public:
    SwigDirector_APICaseHandler(PyObject *self);
    virtual void handleAPICase(int apiType, char const *paramter);
    virtual ~SwigDirector_APICaseHandler();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class APICaseHandler doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[1];
#endif

};


#endif
