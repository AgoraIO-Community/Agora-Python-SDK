#pragma once
#include "Python.h"
class ensureGILstate{
public:
    ensureGILstate(){
        _state = PyGILState_Ensure();
    }
    ~ensureGILstate(){
        PyGILState_Release(_state);
    }
private:
    PyGILState_STATE _state;
};
/*
agora::rtc::IRtcEngine *createAgoraRtcEngine_t() {
    HMODULE h = LoadLibraryA("agora_rtc_sdk.dll");
    typedef agora::rtc::IRtcEngine* (*createAgoraRtcEngine_fp)();
    createAgoraRtcEngine_fp fp = (createAgoraRtcEngine_fp)GetProcAddress(h, "createAgoraRtcEngine");
    return fp();
}

char *getAgoraSdkErrorDescription_t(int err) {
    HMODULE h = LoadLibraryA("agora_rtc_sdk.dll");
    typedef char* (*getAgoraSdkErrorDescription_fp)(int);
    getAgoraSdkErrorDescription_fp fp = (getAgoraSdkErrorDescription_fp)GetProcAddress(h, "getAgoraSdkErrorDescription");
    return fp(err);
}

char *getAgoraSdkVersion_t(int* build) {
    HMODULE h = LoadLibraryA("agora_rtc_sdk.dll");
    typedef char* (*getAgoraSdkVersion_fp)(int*);
    getAgoraSdkVersion_fp fp = (getAgoraSdkVersion_fp)GetProcAddress(h, "getAgoraSdkVersion");
    return fp(build);
}

agora::base::IAgoraService* createAgoraService_t() {
    HMODULE h = LoadLibraryA("agora_rtc_sdk.dll");
    typedef agora::base::IAgoraService* (*createAgoraService_fp)();
    createAgoraService_fp fp = (createAgoraService_fp)GetProcAddress(h, "createAgoraService");
    return fp();
}
*/