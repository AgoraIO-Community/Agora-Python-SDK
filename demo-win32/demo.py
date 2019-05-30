import IAgoraRtcEngine
from PyQt5 import QtWidgets, QtCore
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QTextCursor
from PyQt5.QtWidgets import QFileDialog, QMessageBox, QTableWidgetItem
import MainWindow
import sys
from PyQt5 import QtOpenGL
from PyQt5.QtWidgets import QApplication
from PyQt5.QtCore import QThread, pyqtSignal
from callBack import EventHandlerData

appId = b""

Engine = IAgoraRtcEngine.pycreateAgoraRtcEngine()
ctx = IAgoraRtcEngine.pyRtcEngineContext()
ctx.eventHandler = IAgoraRtcEngine.pyEventHandler()
ctx.appId = appId
Engine.initialize(ctx)
EngineParam = IAgoraRtcEngine.pyRtcEngineParameters()

class joinChannelThread(QThread):
    def __init__(self):
        super(joinChannelThread, self).__init__()
        self.localWinId = -1
        self.remoteWinId = -1
        self.channel = ""
    def run(self):
        Engine.joinChannel(appId, self.channel, b"", 0)
        while (EventHandlerData.localUid == -1): pass
        LocalCanvas = IAgoraRtcEngine.pyVideoCanvas()
        LocalCanvas.construct_2(self.localWinId,
                                IAgoraRtcEngine.pyRENDER_MODE_TYPE.RENDER_MODE_HIDDEN, EventHandlerData.localUid)
        Engine.setupLocalVideo(LocalCanvas)
        Engine.enableVideo()
        EngineParam.construct_3(Engine)
        EngineParam.enableLocalVideo(True)
        EngineParam.muteLocalVideoStream(False)
        while (EventHandlerData.remoteUid == -1): pass
        RemoteCanvas = IAgoraRtcEngine.pyVideoCanvas()
        RemoteCanvas.construct_2(self.remoteWinId, IAgoraRtcEngine.pyRENDER_MODE_TYPE.RENDER_MODE_HIDDEN, EventHandlerData.remoteUid)
        Engine.setupRemoteVideo(RemoteCanvas)

class leaveChannelThread(QThread):
    def __init__(self):
        super(leaveChannelThread, self).__init__()
    def run(self):
        Engine.leaveChannel()

class enableLocalVideoThread(QThread):
    def __init__(self):
        super(enableLocalVideoThread, self).__init__()
    def run(self):
        EngineParam.enableLocalVideo(True)

class disableLocalVideoThread(QThread):
    def __init__(self):
        super(disableLocalVideoThread, self).__init__()
    def run(self):
        EngineParam.enableLocalVideo(False)

class MyWindow(QtWidgets.QMainWindow, MainWindow.Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        MainWindow.Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.window1 = window1()
        self.window2 = window2()
        self.gridLayout.addWidget(self.window1)
        self.gridLayout_2.addWidget(self.window2)
        self.joinButton.clicked.connect(self.joinChannel)
        self.leaveButton.clicked.connect(self.leaveChannel)
        self.enableButton.clicked.connect(self.enableLocalVideo)
        self.disableButton.clicked.connect(self.disableLocalVideo)

    def joinChannel(self):
        if EventHandlerData.joinChannelSuccess == False:
            self.joinThread = joinChannelThread()
            self.joinThread.channel = bytes(self.channelEdit.toPlainText(), 'ascii')
            if self.joinThread.channel == b'':
                return
            self.joinThread.localWinId = self.window1.effectiveWinId().__int__()
            self.joinThread.remoteWinId = self.window2.effectiveWinId().__int__()
            self.joinThread.start()

    def leaveChannel(self):
        if EventHandlerData.joinChannelSuccess == True:
            self.leaveThread = leaveChannelThread()
            self.leaveThread.start()

    def enableLocalVideo(self):
        if EventHandlerData.joinChannelSuccess == True:
            self.enableThread = enableLocalVideoThread()
            self.enableThread.start()

    def disableLocalVideo(self):
        if EventHandlerData.joinChannelSuccess == True:
            self.disableThread = disableLocalVideoThread()
            self.disableThread.start()

class window1(QtOpenGL.QGLWidget):
    def __init__(self):
        QtOpenGL.QGLWidget.__init__(self)
class window2(QtOpenGL.QGLWidget):
    def __init__(self):
        QtOpenGL.QGLWidget.__init__(self)


if __name__ == '__main__':

    app = QApplication(sys.argv)
    window = MyWindow()
    window.show()
    sys.exit(app.exec_())
