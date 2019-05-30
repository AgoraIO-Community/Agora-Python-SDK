#pragma once
#include "include/IAgoraRtcEngine.h"
#include <iostream>
#include <string>
#include "utility.h"


using namespace agora::rtc;

class EventHandler : public IRtcEngineEventHandler
{
public:
	EventHandler() {
		initialize();
	}
	virtual void onJoinChannelSuccess(const char* channel, uid_t uid, int elapsed) {
		ensureGILstate GILScope;
		std::string local_channel = channel;
		PyObject* pRet = PyObject_CallMethod(pClass, "onJoinChannelSuccess",
			"(s, I, i)", local_channel.c_str(), uid, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onJoinChannelSuccess in EventHandler" << std::endl;
		}
	}
	virtual void onRejoinChannelSuccess(const char* channel, uid_t uid, int elapsed) {
	    ensureGILstate GILScope;
	    std::string local_channel = channel;
		PyObject* pRet = PyObject_CallMethod(pClass, "onRejoinChannelSuccess",
			"(s, I, i)", local_channel.c_str(), uid, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onRejoinChannelSuccess in EventHandler" << std::endl;
		}
	}
	virtual void onLeaveChannel(const RtcStats& stats) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onLeaveChannel", "(I, I, I, H, H, H, H, H, H, H, I, d, d)",
			stats.duration, stats.txBytes, stats.rxBytes, stats.txKBitRate,
			stats.rxKBitRate, stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate,
			stats.txVideoKBitRate, stats.lastmileDelay, stats.userCount, stats.cpuAppUsage,
			stats.cpuTotalUsage);
		if (!pRet) {
			std::cout << "Cant find function onLeaveChannel in EventHandler" << std::endl;
		}
	}
	virtual void onUserJoined(uid_t uid, int elapsed) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onUserJoined",
			"(I, i)", uid, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onUserJoined in EventHandler" << std::endl;
		}
	}

	virtual void onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onClientRoleChanged",
			"(i, i)", (int)oldRole, (int)newRole);
		if (!pRet) {
			std::cout << "Cant find function onClientRoleChanged in EventHandler" << std::endl;
		}
	}

	virtual void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onUserOffline",
			"(i, i)", uid, (int)reason);
		if (!pRet) {
			std::cout << "Cant find function onUserOffline in EventHandler" << std::endl;
		}
	}

	virtual void onLastmileQuality(int quality) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onLastmileQuality",
			"(i)", quality);
		if (!pRet) {
			std::cout << "Cant find function onLastmileQuality in EventHandler" << std::endl;
		}
	}

	virtual void onConnectionInterrupted() {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onConnectionInterrupted", NULL);
		if (!pRet) {
			std::cout << "Cant find function onConnectionInterrupted in EventHandler" << std::endl;
		}
	}

	virtual void onConnectionLost() {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onConnectionLost", NULL);
		if (!pRet) {
			std::cout << "Cant find function onConnectionLost in EventHandler" << std::endl;
		}
	}

	virtual void onApiCallExecuted(int err, const char* api, const char* result) {
	    ensureGILstate GILScope;
	    std::string local_api = api;
	    std::string local_result = result;
		PyObject* pRet = PyObject_CallMethod(pClass, "onApiCallExecuted", "(i, s, s)",
			err, local_api.c_str(), local_result.c_str());
		if (!pRet) {
			std::cout << "Cant find function onApiCallExecuted in EventHandler" << std::endl;
		}
	}

	virtual void onRequestToken() {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onRequestToken", NULL);
		if (!pRet) {
			std::cout << "Cant find function onRequestToken in EventHandler" << std::endl;
		}
	}

	virtual void onTokenPrivilegeWillExpire(const char* token) {
	    ensureGILstate GILScope;
	    std::string local_token = token;
		PyObject* pRet = PyObject_CallMethod(pClass, "ontokenPrivilegeWillExpire",
			"(s)", local_token.c_str());
		if (!pRet) {
			std::cout << "Cant find function ontokenPrivilegeWillExpire in EventHandler" << std::endl;
		}
	}

	virtual void onAudioQuality(uid_t uid, int quality, unsigned short delay, unsigned short lost) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onAudioQuality",
			"(I, i, H, H)", uid, quality, delay, lost);
		if (!pRet) {
			std::cout << "Cant find function onAudioQuality in EventHandler" << std::endl;
		}
	}

	virtual void onRtcStats(const RtcStats& stats) {
	    ensureGILstate GILScope;
		RtcStats local_stats = stats;
		PyObject* pRet = PyObject_CallMethod(pClass, "onRtcStats", "(I, I, I, H, H, H, H, H, H, H, I, d, d)",
			local_stats.duration, local_stats.txBytes, local_stats.rxBytes, local_stats.txKBitRate,
			local_stats.rxKBitRate, local_stats.rxAudioKBitRate, local_stats.txAudioKBitRate, local_stats.rxVideoKBitRate,
			local_stats.txVideoKBitRate, local_stats.lastmileDelay, local_stats.userCount, local_stats.cpuAppUsage,
			local_stats.cpuTotalUsage);
		if (!pRet) {
			std::cout << "Cant find function onRtcStats in EventHandler" << std::endl;
		}
	}
	virtual void onNetworkQuality(uid_t uid, int txQuality, int rxQuality) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onNetworkQuality",
			"(I, i, i)", uid, txQuality, rxQuality);
		if (!pRet) {
			std::cout << "Cant find function onNetworkQuality in EventHandler" << std::endl;
		}
	}
	virtual void onLocalVideoStats(const LocalVideoStats& stats) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onLocalVideoStats",
			"(i, i)", stats.sentBitrate, stats.sentFrameRate);
		if (!pRet) {
			std::cout << "Cant find function onLocalVideoStats in EventHandler" << std::endl;
		}
	}
	virtual void onRemoteVideoStats(const RemoteVideoStats& stats) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onRemoteVideoStats",
			"(I, i, i, i, i, i, i)", stats.uid, stats.delay,
			stats.width, stats.height, stats.receivedBitrate,
			stats.receivedFrameRate, (int)stats.rxStreamType);
		if (!pRet) {
			std::cout << "Cant find function onRemoteVideoStats in EventHandler" << std::endl;
		}
	}
	virtual void onRemoteAudioStats(const RemoteAudioStats& stats) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onRemoteAudioStats",
			"(I, i, i, i, i)", stats.uid, stats.quality,
			stats.networkTransportDelay, stats.jitterBufferDelay,
			stats.audioLossRate);
		if (!pRet) {
			std::cout << "Cant find function onRemoteAudioStats in EventHandler" << std::endl;
		}
	}
	virtual void onAudioVolumeIndication(const AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onAudioVolumeIndication",
			"(I, i, I, i)", speakers->uid, speakers->volume, speakerNumber, totalVolume);
		if (!pRet) {
			std::cout << "Cant find function onAudioVolumeIndication in EventHandler" << std::endl;
		}
	}
	virtual void onActiveSpeaker(uid_t uid) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onActiveSpeaker",
			"(I)", uid);
		if (!pRet) {
			std::cout << "Cant find function onActiveSpeaker in EventHandler" << std::endl;
		}
	}
	virtual void onVideoStopped() {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onVideoStopped", NULL);
		if (!pRet) {
			std::cout << "Cant find function onVideoStopped in EventHandler" << std::endl;
		}
	}
	virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onFirstLocalVideoFrame", "(i, i, i)",
			width, height, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onFirstLocalVideoFrame in EventHandler" << std::endl;
		}
	}
	virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onFirstRemoteVideoDecoded",
			"(I, i, i, i)", uid, width, height, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onFirstRemoteVideoDecoded in EventHandler" << std::endl;
		}
	}
	virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onFirstRemoteVideoFrame",
			"(I, i, i, i)", uid, width, height, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onFirstRemoteVideoFrame in EventHandler" << std::endl;
		}
	}
	virtual void onUserMuteAudio(uid_t uid, bool muted) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onUserMuteAudio",
			"(I, i)", uid, (int)muted);
		if (!pRet) {
			std::cout << "Cant find function onUserMuteAudio in EventHandler" << std::endl;
		}
	}
	virtual void onUserMuteVideo(uid_t uid, bool muted) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onUserMuteVideo",
			"(I, i)", uid, (int)muted);
		if (!pRet) {
			std::cout << "Cant find function onUserMuteVideo in EventHandler" << std::endl;
		}
	}
	virtual void onUserEnableVideo(uid_t uid, bool enabled) {
	    ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onUserEnableVideo",
			"(I, i)", uid, (int)enabled);
		if (!pRet) {
			std::cout << "Cant find function onUserEnableVideo in EventHandler" << std::endl;
		}
	}
	virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) {
	    ensureGILstate GILScope;
	    std::string local_deviceId = deviceId;
		PyObject* pRet = PyObject_CallMethod(pClass, "onAudioDeviceStateChanged",
			"(s, i, i)", local_deviceId.c_str(), deviceType, deviceState);
		if (!pRet) {
			std::cout << "Cant find function onAudioDeviceStateChanged in EventHandler" << std::endl;
		}
	}
	virtual void onCameraReady() {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onCameraReady", NULL);
		if (!pRet) {
			std::cout << "Cant find function onCameraReady in EventHandler" << std::endl;
		}
	}
	virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) {
		ensureGILstate GILScope;
		std::string local_deviceId = deviceId;
		PyObject* pRet = PyObject_CallMethod(pClass, "onVideoDeviceStateChanged",
			"(s, i, i)", local_deviceId.c_str(), deviceType, deviceState);
		if (!pRet) {
			std::cout << "Cant find function onVideoDeviceStateChanged in EventHandler" << std::endl;
		}
	}
	virtual void onStreamMessage(uid_t uid, int streamId, const char* data, size_t length) {
		ensureGILstate GILScope;
		std::string local_data = data;
		PyObject* pRet = PyObject_CallMethod(pClass, "onStreamMessage",
			"(I, i, s, I)", uid, streamId, local_data.c_str(), length);
		if (!pRet) {
			std::cout << "Cant find function onStreamMessage in EventHandler" << std::endl;
		}
	}
	virtual void onConnectionStateChanged(
		CONNECTION_STATE_TYPE state, CONNECTION_CHANGED_REASON_TYPE reason) {
		ensureGILstate GILScope;
		PyObject* pRet = PyObject_CallMethod(pClass, "onConnectionStateChanged",
			"(i, i)", (int)state, reason);
		if (!pRet) {
			std::cout << "Cant find function onConnectionStateChanged in EventHandler" << std::endl;
		}
	}

	virtual void onFirstLocalAudioFrame(int elapsed){
	    ensureGILstate GILScope;
	    PyObject* pRet = PyObject_CallMethod(pClass, "onFirstLocalAudioFrame",
			"(i)", elapsed);
		if (!pRet) {
			std::cout << "Cant find function onFirstLocalAudioFrame in EventHandler" << std::endl;
		}
	}
	virtual void onMicrophoneEnabled(bool enabled){
	    ensureGILstate GILScope;
	    PyObject* pRet = PyObject_CallMethod(pClass, "onMicrophoneEnabled",
			"(i)", enabled);
		if (!pRet) {
			std::cout << "Cant find function onMicrophoneEnabled in EventHandler" << std::endl;
		}
	}
	virtual void onRemoteVideoStateChanged(uid_t uid, REMOTE_VIDEO_STATE state){
	    ensureGILstate GILScope;
	    PyObject* pRet = PyObject_CallMethod(pClass, "onRemoteVideoStateChanged",
			"(I, i)", uid, (int)state);
		if (!pRet) {
			std::cout << "Cant find function onRemoteVideoStateChanged in EventHandler" << std::endl;
		}
	}
	virtual void onUserEnableLocalVideo(uid_t uid, bool enabled){
	    ensureGILstate GILScope;
	    PyObject* pRet = PyObject_CallMethod(pClass, "onUserEnableLocalVideo",
			"(I, i)", uid, (int)enabled);
		if (!pRet) {
			std::cout << "Cant find function onUserEnableLocalVideo in EventHandler" << std::endl;
		}
	}
	virtual void onFirstRemoteAudioFrame(uid_t uid, int elapsed){
	    ensureGILstate GILScope;
	    PyObject* pRet = PyObject_CallMethod(pClass, "onFirstRemoteAudioFrame",
			"(I, i)", uid, elapsed);
		if (!pRet) {
			std::cout << "Cant find function onFirstRemoteAudioFrame in EventHandler" << std::endl;
		}
	}
    virtual void onRemoteAudioTransportStats(uid_t uid, unsigned short delay, unsigned short lost,
        unsigned short rxKBitRate){
        ensureGILstate GILScope;
        PyObject* pRet = PyObject_CallMethod(pClass, "onRemoteAudioTransportStats",
			"(I, H, H, H)", uid, delay, lost, rxKBitRate);
		if (!pRet) {
			std::cout << "Cant find function onRemoteAudioTransportStats in EventHandler" << std::endl;
		}
    }
    virtual void onRemoteVideoTransportStats(uid_t uid, unsigned short delay, unsigned short lost,
        unsigned short rxKBitRate){
        ensureGILstate GILScope;
        PyObject* pRet = PyObject_CallMethod(pClass, "onRemoteVideoTransportStats",
			"(I, H, H, H)", uid, delay, lost, rxKBitRate);
		if (!pRet) {
			std::cout << "Cant find function onRemoteVideoTransportStats in EventHandler" << std::endl;
		}
    }


private:
	static void initialize() {
		if (!isInitilized) {

			Py_Initialize();
			if (!Py_IsInitialized())
				return;
			PyEval_InitThreads();
			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append(\".\")");
			PyObject * pModule = PyImport_ImportModule("callBack");
			if (!pModule) {
				std::cout << "Cant import callBack.py\n" << std::endl;
				return;
			}
			PyObject* pDict = PyModule_GetDict(pModule);
			if (!pDict) {
				std::cout << "Cant find dictionary in callBack.py\n" << std::endl;
				return;
			}
			pClass = PyDict_GetItemString(pDict, "EventHandler");
			if (!pClass) {
				std::cout << "Cant find class EventHandler.\n" << std::endl;
				return;
			}
			std::cout << "Load python callBack \'EventHandler\' successfully\n" << std::endl;
			isInitilized = true;
		}
	}
	static bool isInitilized;
	static PyObject* pClass;
};

PyObject* EventHandler::pClass = NULL;
bool EventHandler::isInitilized = false;
