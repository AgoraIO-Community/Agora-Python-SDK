# Agora-Python-SDK 

*[English](README.md) | 中文*

Agora RTC Python SDK，目前支持 Windows 和 macOS 平台。

## 运行环境

- Xcode (macOS)
- Visual Studio 2017+，需要添加C++支持 (Windows)
- Python 3.6+

## 安装

您可以用`pip3`指令从PyPI上下载并安装，也可以使用本仓库的代码编译SDK。

### 方法一：使用PyPI（推荐）

*仅支持64位操作系统，32位操作系统请使用方法二。*

```bash
pip3 install agora-python-sdk
```

### 方法二：编译SDK

1. Clone当前仓库。

   ```bash
   git clone https://github.com/AgoraIO-Community/Agora-Python-SDK.git
   ```

2. 下载所需的SDK。

   - （macOS）在 [Agora Video SDK for macOS](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Mac_v3_1_2_FULL.zip) 下载 SDK。解压缩之后，将 `libs` 目录下的 `AograRtcEngineKit.framework` 复制到仓库的根目录。
   - （Windows）在 [Agora Video SDK for Windows](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Windows_v3_1_2_FULL.zip) 下载 SDK。解压缩之后，将 `libs/x86_64`（64位）或`libs/x86`（32位） 目录下的 `agora_rtc_sdk.dll` 和 `agora_rtc_sdk.lib` 复制到仓库的根目录。

3. 编译SDK。

   打开命令行工具，定位到仓库目录，运行命令

   ```bash
   python3 setup.py build_ext --inplace
   ```

4. （可选）将`agorartc`添加到`site-packages`文件夹中。

   若想要在任何路径下都可直接使用SDK，需要将相关的文件拷贝到`site-packages`路径下。可以通过如下命令找到其路径：

   ```bash
   python3 -c 'import site; print(site.getsitepackages())'
   ```

   将`_agorartc.cpython-38-darwin.so`、`agorartc.py`和`AgoraRtcKit.framework`或`agora_rtc_sdk.dll`和`agora_rtc_sdk.lib`复制到`site-packages`文件夹里。

   - macOS（终端）

     ```bash
     cp _agorartc.cpython-38-darwin.so [your-site-packages-folder-path]
     cp agorartc.py [your-site-packages-folder-path]
     cp -r AgoraRtcKit.framework [your-site-packages-folder-path]
     ```

   - Windows (PowerShell)

     ```bash
     cp _agorartc.cpython-38-darwin.so [your-site-packages-folder-path]
     cp agorartc.py [your-site-packages-folder-path]
     cp agora_rtc_sdk.dll [your-site-packages-folder-path]
     cp agora_rtc_sdk.lib [your-site-packages-folder-path]
     ```

## 使用方法

**您可以通过访问[Agora-Python-QuickStart](https://github.com/AgoraIO-Community/Agora-Python-QuickStart)获取现有的示例。**

您也可以根据如下教程完成一个简单的示例。

1. 在终端（macOS）或PowerShell（Windows）中打开一个Python3控制台。

   ```bash
   python3
   ```

2. 在Python控制台中完成示例。

   ```python
   >>> import agorartc
   >>> rtc = agorartc.createRtcEngineBridge()
   >>> eventHandler = agorartc.RtcEngineEventHandlerBase()
   >>> rtc.initEventHandler(eventHandler)
   0 （成功）
   >>> rtc.initialize("您的appID", None, agorartc.AREA_CODE_GLOB & 0xFFFFFFFF)  # 如您还未获取App ID，您可以查看附录(https://github.com/AgoraIO-Community/Agora-Python-SDK/blob/master/Readme.zh.md#%E9%99%84%E5%BD%95)。
   0 （成功）
   >>> rtc.enableVideo()
   0 （成功）
   >>> rtc.joinChannel("", "channel-name", "", 0)
   0 （成功）
   >>> rtc.leaveChannel()  # 离开频道
   0 （成功）
   ```

## 帮助

如您需要了解关于我们API的更多信息，请参考[Agora C++ API](https://docs.agora.io/cn/Video/API%20Reference/cpp/v3.1.2/index.html)。

Python的API文档还在推进中，但我们已有的C++ API是相似的。*

## 附录

### 创建Agora账户并获取App ID

如果想要使用我们的SDK，您需要先获得一个App ID：

1. 在[agora.io](https://dashboard.agora.io/signin/)中注册一个账号。当您完成注册后，您将被链接至控制台。
2. 在控制台左侧点击**Projects** > **Project List**。
3. 请将您从控制台中获取的App ID保存，您将会在调用SDK时使用。