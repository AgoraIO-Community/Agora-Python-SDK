from distutils.core import setup, Extension
import os
import platform

extra_link_args = []
libraries = []
library_dirs = []
extra_compile_args = []
if platform.system() == 'Darwin':
    extra_link_args = ['-F.', '-Wl,-rpath,@loader_path']
    os.environ['LDFLAGS'] = '-framework AgoraRtcKit'
    extra_compile_args = ['-std=c++14', '-stdlib=libc++']
elif platform.system() == 'Windows':
    libraries = ['agora_rtc_sdk']
    library_dirs = ['.']
    extra_compile_args = ['/std:c++14', '-DNOMINMAX']

agorartc_module = Extension('_agorartc',
                           sources=[
                               'AgoraRtc_wrap.cxx', 
                               'src/AgoraRtc.cpp',
                               'src/cross-platform-sdk-module/rtc/rtcEngine/RtcEngineBridge.cpp',
                               'src/cross-platform-sdk-module/rtc/test/LogJson.cpp',
                               'src/cross-platform-sdk-module/rtc/test/ApiTester.cpp',
                               'src/cross-platform-sdk-module/rtc/test/EventTester.cpp',
                               'src/cross-platform-sdk-module/rtc/rtcChannel/RtcChannelBridge.cpp',
                               'src/cross-platform-sdk-module/rtc/observer/metadata/metadata_observer.cpp',
                               'src/cross-platform-sdk-module/rtc/deviceManager/audioDeviceManager/AudioPlaybackDeviceManager.cpp',
                               'src/cross-platform-sdk-module/rtc/deviceManager/audioDeviceManager/AudioRecordingDeviceManager.cpp',
                               'src/cross-platform-sdk-module/rtc/deviceManager/videoDeviceManager/VideoDeviceManager.cpp',
                               'src/cross-platform-sdk-module/rtc/callback/rtcChannnelCallback/RtcChannelEventHandler.cpp',
                               'src/cross-platform-sdk-module/rtc/callback/rtcEngineCallback/RtcEngineEventHandler.cpp'],
                           include_dirs = ['src/cross-platform-sdk-module', 'src'],
                           extra_link_args = extra_link_args,
                           libraries = libraries,
                           library_dirs = library_dirs,
                           extra_compile_args = extra_compile_args
                           )

setup (name = 'agorartc',
       version = '0.1',
       author      = "Agora.io",
       description = """Agora RTC Python SDK""",
       ext_modules = [agorartc_module],
       py_modules = ["agorartc"],
       )