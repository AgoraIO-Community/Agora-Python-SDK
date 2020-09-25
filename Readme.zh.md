# Agora-Python-SDK 

*[English](README.md) | 中文*

Agora RTC Python SDK，目前支持 Windows 和 macOS 平台。

## 运行环境

- Xcode (macOS)
- Visual Studio 2017+，需要添加C++支持 (Windows)
- Python 3.6+

## 编译 SDK

1. Clone 仓库
2. （macOS）在 [Agora Video SDK for macOS](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Mac_v3_1_2_FULL.zip) 下载 SDK。解压缩之后，将 `libs` 目录下的 `AograRtcEngineKit.framework` 复制到仓库的根目录。
3. （Windows）在 [Agora Video SDK for Windows](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Windows_v3_1_2_FULL.zip) 下载 SDK。解压缩之后，将 `libs/x86_64` 目录下的 `agora_rtc_sdk.dll` 和 `agora_rtc_sdk.lib` 复制到仓库的根目录。
4. 打开命令行工具，定位到仓库目录，运行命令 `python setup.py build_ext --inplace`

## 运行示例程序

1. 首先在 [Agora.io 注册](https://dashboard.agora.io/cn/signup/) 注册账号，并创建自己的测试项目，获取到 AppID。
2. 运行命令 `pip install PyQt5` 安装 `PyQt5`，`PyQt5` 只是示例程序到依赖项，如果只是编译 SDK，不需要安装。
3. 打开控制台，定位到 `API-Examples/one-to-one-video` 目录，运行命令 `python one2one.py`

