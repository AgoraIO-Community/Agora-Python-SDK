# Agora 1-to-1 Python Demo on macOS

*[English](README.md) | 中文*

这个开源示例项目演示了如何在 MacOS 环境快速集成 Agora 视频 SDK，实现 1 对 1 视频通话。（本开源项目使用 **Python** 语言）

在这个示例项目中包含了以下功能：

- 加入通话和离开通话；
- 静音和解除静音；
- 关闭摄像头和开启摄像头；


Agora 视频 SDK 支持 iOS / Android / Windows / macOS 等多个平台，你可以查看对应各平台的示例项目：

- [Agora-Android-Tutorial-1to1](https://github.com/AgoraIO/Agora-Android-Tutorial-1to1)
- [Agora-iOS-Tutorial-Swift-1to1](https://github.com/AgoraIO/Agora-iOS-Tutorial-Swift-1to1)
- [Agora-macOS-Tutorial-Swift-1to1](https://github.com/AgoraIO/Agora-macOS-Tutorial-Swift-1to1)

## 环境准备

- Python 3.6
- PyQt 5
- numpy, pillow, opencv-python (为了下载 raw data)

## 运行示例程序

这个段落主要讲解了如何编译和运行实例程序。

### 创建Agora账号并获取AppId

在编译和启动实例程序前，您需要首先获取一个可用的App ID:
1. 在[agora.io](https://dashboard.agora.io/signin/)创建一个开发者账号
2. 前往后台页面，点击左部导航栏的 **项目 > 项目列表** 菜单
3. 复制后台的 **App ID** 并备注，稍后启动应用时会用到它

### 集成 Agora 视频 SDK

1. 下载本项目到本地仓库

2. 用Pycharm等工具打开文件，根据提示安装相关环境（如命令行 pip install pillow），替换 demo.py 文件中 appid

3. 运行该项目即可

### Getting Raw Data

1. 替换 getRawData.py 文件中 appid 并运行

2. raw data 会被保存在该文件夹下的 ./rawData


## 联系我们

- 完整的 API 文档见 [文档中心](https://docs.agora.io/cn/)
- 如果在集成中遇到问题, 你可以到 [开发者社区](https://dev.agora.io/cn/) 提问
- 如果有售前咨询问题, 可以拨打 400 632 6626，或加入官方Q群 12742516 提问
- 如果需要售后技术支持, 你可以在 [Agora Dashboard](https://dashboard.agora.io) 提交工单
- 如果发现了示例代码的 bug, 欢迎提交 [issue](https://github.com/AgoraIO/Basic-Video-Call/issues)

## 代码许可

The MIT License (MIT)
