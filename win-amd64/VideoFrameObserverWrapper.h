#pragma once
#include "include/IAgoraMediaEngine.h"
#include <iostream>
#include <string>
#include "utility.h"
using namespace agora::media;




class VideoFrameObserver : public IVideoFrameObserver
{
public:
	VideoFrameObserver() {
		initialize();
	}
    virtual bool onCaptureVideoFrame(VideoFrame& videoFrame){
        ensureGILstate GILScope;
        PyObject* pRet = PyObject_CallMethod(pClass, "onCaptureVideoFrame",
			"(i, i, i, i, i, K, K, K, i, L, i)", videoFrame.width, videoFrame.height, videoFrame.yStride,
			videoFrame.uStride, videoFrame.vStride, (unsigned long long)videoFrame.yBuffer,
			(unsigned long long)videoFrame.uBuffer, (unsigned long long)videoFrame.vBuffer,
			videoFrame.rotation, videoFrame.renderTimeMs, videoFrame.avsync_type);
		if (!pRet) {
			std::cout << "Cant find function onCaptureVideoFrame in VideoFrameObserver" << std::endl;
		}
        return true;
    }
    virtual bool onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame){
        ensureGILstate GILScope;
        PyObject* pRet = PyObject_CallMethod(pClass, "onRenderVideoFrame",
			"(I, i, i, i, i, i, K, K, K, i, L, i)", uid, videoFrame.width, videoFrame.height, videoFrame.yStride,
			videoFrame.uStride, videoFrame.vStride, (unsigned long long)videoFrame.yBuffer,
			(unsigned long long)videoFrame.uBuffer, (unsigned long long)videoFrame.vBuffer,
			videoFrame.rotation, videoFrame.renderTimeMs, videoFrame.avsync_type);
		if (!pRet) {
			std::cout << "Cant find function onRenderVideoFrame in VideoFrameObserver" << std::endl;
		}
        return true;
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
			pClass = PyDict_GetItemString(pDict, "VideoFrameObserver");
			if (!pClass) {
				std::cout << "Cant find class VideoFrameObserver.\n" << std::endl;
				return;
			}
			std::cout << "Load python callBack \'VideoFrameObserver\' successfully\n" << std::endl;
			isInitilized = true;
		}
	}
	static bool isInitilized;
	static PyObject* pClass;
};

PyObject* VideoFrameObserver::pClass = NULL;
bool VideoFrameObserver::isInitilized = false;