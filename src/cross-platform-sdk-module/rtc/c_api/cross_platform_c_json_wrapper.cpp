//
// Created by 张涛 on 2020-08-18.
//

#include "cross_platform_c_json_wrapper.h"
#include "../deviceManager/IAudioDeviceManagerBridge.h"
#include "../deviceManager/IVideoDeviceManagerBridge.h"
#include "../rtcChannel/IRtcChannelBridge.h"
#include "../rtcEngine/IRtcEngineBridge.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IRtcEngineBridge static_cast<agora::common::IRtcEngineBridge*>(apiBridge)
#define IRtcChannelBridge static_cast<agora::common::IRtcChannelBridge*>(apiBridge)
#define IVideoDeviceManagerBridge static_cast<agora::common::IVideoDeviceManagerBridge*>(apiBridge)
#define IAudioDeviceManagerBridge static_cast<agora::common::IAudioDeviceManagerBridge*>(apiBridge)

IRtcEngineBridge_ptr
createRtcBridge()
{
    return agora::common::createRtcEngineBridge();
}

enum ERROR_CODE
callApi_rtc_engine(IRtcEngineBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters)
{
    if (apiBridge) {
        return ERROR_CODE(IRtcEngineBridge->callApi(agora::common::API_TYPE(apiType), std::string(parameters)));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi2_rtc_engine(IRtcEngineBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters, void* ptr)
{
    if (apiBridge) {
        return ERROR_CODE(IRtcEngineBridge->callApi(agora::common::API_TYPE(apiType), std::string(parameters), ptr));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

const char*
callApi_str_rtc_engine(IRtcEngineBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters)
{
    if (apiBridge) {
        return IRtcEngineBridge->callApi_str(agora::common::API_TYPE(apiType), std::string(parameters));
    }

    return "No Engine";
}

enum ERROR_CODE
callApi_audioEffect_rtc_engine(IRtcEngineBridge_ptr apiBridge, enum API_TYPE_AUDIO_EFFECT apiType, const char* parameters)
{
    if (apiBridge) {
        return ERROR_CODE(IRtcEngineBridge->callApi_audioEffect(agora::common::API_TYPE_AUDIO_EFFECT(apiType), std::string(parameters)));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_rtc_engine_bridge(IRtcEngineBridge_ptr apiBridge, BOOL sync)
{
    if (apiBridge) {
        IRtcEngineBridge->release(sync);
        apiBridge = NULL;
    }
}

IRtcChannelBridge_ptr
createChannelBridge(IRtcEngineBridge_ptr apiBridge, const char* channelId)
{
    if (apiBridge) {
        return IRtcEngineBridge->createChannel(channelId);
    }

    return NULL;
}

enum ERROR_CODE
callApi_channel(IRtcChannelBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters)
{
    if (apiBridge) {
        return ERROR_CODE(IRtcChannelBridge->callApi(agora::common::API_TYPE(apiType), std::string(parameters)));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

const char*
callApi_str_channel(IRtcChannelBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters)
{
    if (apiBridge) {
        return IRtcChannelBridge->callApi_str(agora::common::API_TYPE(apiType), std::string(parameters));
    }

    return "NO ENGINE";
}

enum ERROR_CODE
callApi2_channel(IRtcChannelBridge_ptr apiBridge, enum API_TYPE apiType, const char* parameters, void* ptr)
{
    if (apiBridge) {
        return ERROR_CODE(IRtcChannelBridge->callApi(agora::common::API_TYPE(apiType), std::string(parameters), ptr));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_channel_bridge(IRtcChannelBridge_ptr apiBridge)
{
    if (apiBridge) {
        IRtcChannelBridge->release();
        apiBridge = NULL;
    }
}

IVideoDeviceManagerBridge_ptr
createVideoDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge, enum ERROR_CODE* errorCode)
{
    agora::common::ERROR_CODE error_code = agora::common::ERROR_CODE::ERROR_OK;

    if (apiBridge) {
        IVideoDeviceManagerBridge_ptr videoDeviceManagerBridge_ptr = IRtcEngineBridge->createVideoDeviceManager(
            error_code);
        *errorCode = ERROR_CODE(error_code);
        return videoDeviceManagerBridge_ptr;
    }

    return NULL;
}

enum ERROR_CODE
callApi_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge, enum API_TYPE_DEVICE_MANAGER apiType, const char* parameters, void* ptr)
{
    if (apiBridge) {
        return ERROR_CODE(IVideoDeviceManagerBridge->callApi(agora::common::API_TYPE_DEVICE_MANAGER(apiType), std::string(parameters), ptr));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi2_video_device_manager(IVideoDeviceManagerBridge_ptr apiBridge, enum API_TYPE_DEVICE_MANAGER apiType, const char* parameters, void* ptr, void* ptr2)
{
    if (apiBridge) {
        return ERROR_CODE(IVideoDeviceManagerBridge->callApi(agora::common::API_TYPE_DEVICE_MANAGER(apiType), std::string(parameters), ptr, ptr2));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_video_device_manager_bridge(IVideoDeviceManagerBridge_ptr apiBridge)
{
    if (apiBridge) {
        IVideoDeviceManagerBridge->release();
    }
}

IAudioDeviceManagerBridge_ptr
createDeviceManagerBridge(IRtcEngineBridge_ptr apiBridge, enum DEVICE_TYPE device_type, enum ERROR_CODE* errorCode)
{
    agora::common::ERROR_CODE error_code = agora::common::ERROR_CODE::ERROR_OK;
    if (apiBridge) {
        IAudioDeviceManagerBridge_ptr audioDeviceManagerBridge = IRtcEngineBridge->createAudioDeviceManager(
            agora::common::DEVICE_TYPE(device_type), error_code);

        *errorCode = ERROR_CODE(error_code);

        return audioDeviceManagerBridge;
    }

    return NULL;
}

enum ERROR_CODE
callApi_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge, enum API_TYPE_DEVICE_MANAGER apiType, const char* parameters)
{
    if (apiBridge) {
        return ERROR_CODE(IAudioDeviceManagerBridge->callApi(agora::common::API_TYPE_DEVICE_MANAGER(apiType), std::string(parameters)));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi2_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge, enum API_TYPE_DEVICE_MANAGER apiType, const char* parameters, void* ptr)
{
    if (apiBridge) {
        return ERROR_CODE(IAudioDeviceManagerBridge->callApi(agora::common::API_TYPE_DEVICE_MANAGER(apiType), std::string(parameters), ptr));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

enum ERROR_CODE
callApi3_audio_device_manager(IAudioDeviceManagerBridge_ptr apiBridge, enum API_TYPE_DEVICE_MANAGER apiType, const char* parameters, void* ptr, void* ptr2)
{
    if (apiBridge) {
        return ERROR_CODE(IAudioDeviceManagerBridge->callApi(agora::common::API_TYPE_DEVICE_MANAGER(apiType), std::string(parameters), ptr, ptr2));
    }

    return ERROR_CODE::ERROR_NO_ENGINE;
}

void release_audio_device_manager_bridge(IAudioDeviceManagerBridge_ptr apiBridge)
{
    if (apiBridge) {
        IAudioDeviceManagerBridge->release();
        apiBridge = NULL;
    }
}

#ifdef __cplusplus
};
#endif