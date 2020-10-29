# Agora Python SDK
*[中文](Readme.zh.md) | English*

Use Agora RTC SDK with Python! 

## Prerequisites

- Xcode (macOS)
- Visual Studio 2017+ with C++(Windows)
- Python 3.6+

## Installation

Either can you install this module from PyPI using `pip3` or compile the SDK yourself using the code in this repository.

### Method 1: Use PyPI (Recommended)

```bash
pip3 install agora-python-sdk
```

### Method 2: Compile SDK

1. Clone the repository.

   ```bash
   git clone https://github.com/AgoraIO-Community/Agora-Python-SDK.git
   ```

2. Download the required SDK.

   - (macOS) Download SDK [Agora Video SDK for macOS](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Mac_v3_1_2_FULL.zip). Unzip the downloaded SDK package and copy the `AograRtcEngineKit.framework` from `libs` folder into the repository root folder.
   - (Windows) Download SDK [Agora Video SDK for Windows](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Windows_v3_1_2_FULL.zip). Unzip the downloaded SDK package and copy the `agora_rtc_sdk.dll` and `agora_rtc_sdk.lib` files from `libs/x86_64` into repository root folder.

3. Compile SDK.

   Open Terminal and user `cd` to go to the repository root folder. Then compile using:

   ```bash
   python3 setup.py build_ext --inplace
   ```

4. (Optional) Add `agorartc` module to `site-packages` folder.

   If you would like to use our SDK globally, you need to copy the related files and folder to your python site-packages folder. You can find the path using:

   ```bash
   python3 -c 'import site; print(site.getsitepackages())'
   ```

   Copy `_agorartc.cpython-38-darwin.so`, `agorartc.py` and `AgoraRtcKit.framework` or `agora_rtc_sdk.dll` and `agora_rtc_sdk.lib` to your `site-packages` path.

   - macOS (Terminal)

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

## Usage

**Visit [Agora-Python-QuickStart](https://github.com/AgoraIO-Community/Agora-Python-QuickStart) to obtain some existed GUI demo.**

You can also write a simple demo yourself by the following instructins.

1. Open a Python3 console in Terminal (macOS) or PowerShell (Windows).

   ```bash
   python3
   ```

2. Write a simple demo in Python console.

   ```python
   >>> import agorartc
   >>> rtc = agorartc.createRtcEngineBridge()
   >>> eventHandler = agorartc.RtcEngineEventHandlerBase()
   >>> rtc.initEventHandler(eventHandler)
   0 (Success)
   >>> rtc.initialize("your-appID", None, agorartc.AREA_CODE_GLOB & 0xFFFFFFFF)  # If you do not have an App ID, see Appendix (TODO).
   0 (Success)
   >>> rtc.enableVideo()
   0 (Success)
   >>> rtc.joinChannel("", "channel-name", "", 0)
   0 (Success)
   >>> rtc.leaveChannel()  # Leave channel
   0 (Success)
   ```



## Appendix

### Create an Account and Obtain an App ID

To use our SDK, you must obtain an app ID: 

1. Create a developer account at [agora.io](https://dashboard.agora.io/signin/). Once you finish the sign-up process, you are redirected to the dashboard.
2. Navigate in the dashboard tree on the left to **Projects** > **Project List**.
3. Copy the app ID that you obtained from the dashboard into a text file. You will use it when you call our SDK.
