# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainWindow.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 486)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.channelEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.channelEdit.setGeometry(QtCore.QRect(530, 70, 231, 31))
        font = QtGui.QFont()
        font.setFamily("微软雅黑 Light")
        self.channelEdit.setFont(font)
        self.channelEdit.viewport().setProperty("cursor", QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.channelEdit.setObjectName("channelEdit")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(530, 40, 111, 16))
        font = QtGui.QFont()
        font.setFamily("微软雅黑 Light")
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.joinButton = QtWidgets.QPushButton(self.centralwidget)
        self.joinButton.setGeometry(QtCore.QRect(540, 120, 93, 28))
        self.joinButton.setObjectName("joinButton")
        self.leaveButton = QtWidgets.QPushButton(self.centralwidget)
        self.leaveButton.setGeometry(QtCore.QRect(660, 120, 93, 28))
        self.leaveButton.setObjectName("leaveButton")
        self.gridLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(530, 250, 251, 171))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setHorizontalSpacing(7)
        self.gridLayout.setObjectName("gridLayout")
        self.gridLayoutWidget_2 = QtWidgets.QWidget(self.centralwidget)
        self.gridLayoutWidget_2.setGeometry(QtCore.QRect(20, 30, 471, 391))
        self.gridLayoutWidget_2.setObjectName("gridLayoutWidget_2")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.gridLayoutWidget_2)
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.disableButton = QtWidgets.QPushButton(self.centralwidget)
        self.disableButton.setGeometry(QtCore.QRect(560, 200, 171, 28))
        self.disableButton.setObjectName("disableButton")
        self.enableButton = QtWidgets.QPushButton(self.centralwidget)
        self.enableButton.setGeometry(QtCore.QRect(560, 160, 171, 28))
        self.enableButton.setObjectName("enableButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Channel Name:"))
        self.joinButton.setText(_translate("MainWindow", "join"))
        self.leaveButton.setText(_translate("MainWindow", "leave"))
        self.disableButton.setText(_translate("MainWindow", "disableLocalVideo"))
        self.enableButton.setText(_translate("MainWindow", "enableLocalVideo"))

