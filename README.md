# Agora Python SDK
*[中文](Readme.zh.md) | English*

Use Agora RTC SDK with Python! 

## Prerequisites

- Xcode (macOS)
- Visual Studio 2017+ with C++(Windows)
- Python 3.6+

## Compile SDK

1. Clone the repository.
2. (macOS) Download SDK [Agora Video SDK for macOS](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Mac_v3_1_2_FULL.zip). Unzip the downloaded SDK package and copy the `AograRtcEngineKit.framework` from `libs` folder into repository root folder.
3. (Windows) Download SDK [Agora Video SDK for Windows](https://download.agora.io/sdk/release/Agora_Native_SDK_for_Windows_v3_1_2_FULL.zip). Unzip the downloaded SDK package and copy the `agora_rtc_sdk.dll` and `agora_rtc_sdk.lib` files from `libs/x86_64` into repository root folder.
4. Open Terminal and cd to repository root folder. run `python setup.py build_ext --inplace`

## Create an Account and Obtain an App ID
To run the sample application, you must obtain an app ID: 

1. Create a developer account at [agora.io](https://dashboard.agora.io/signin/). Once you finish the sign-up process, you are redirected to the dashboard.
2. Navigate in the dashboard tree on the left to **Projects** > **Project List**.
3. Copy the app ID that you obtained from the dashboard into a text file. You will use this when you launch the app.

## Run demo

1. run `pip install PyQt5` to install demo dependency.
2. Go to `API-Examples/one-to-one-video` folder, run `python one2one.py`

