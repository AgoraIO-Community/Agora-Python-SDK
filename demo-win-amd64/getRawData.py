import IAgoraRtcEngine

appId = b""

Engine = IAgoraRtcEngine.pycreateAgoraRtcEngine()
ctx = IAgoraRtcEngine.pyRtcEngineContext()
ctx.eventHandler = IAgoraRtcEngine.pyEventHandler()
ctx.appId = appId
Engine.initialize(ctx)
Engine.joinChannel(appId, b"123", b"", 0)

Engine.enableVideo()
EngineParam = IAgoraRtcEngine.pyRtcEngineParameters()
EngineParam.construct_3(Engine)
EngineParam.enableLocalVideo(True)
EngineParam.muteLocalVideoStream(False)

MediaEngine = IAgoraRtcEngine.pyGetMediaEngine(Engine)
MediaEngine.registerVideoFrameObserver(IAgoraRtcEngine.pyVideoFrameObserver())

_ = input("press any key to disconnect")
Engine.release(False)
