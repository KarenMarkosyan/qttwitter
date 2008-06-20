DEPENDPATH += .
FORMS += Ui/login.ui Ui/mainWindow.ui Ui/sendTwit.ui
HEADERS += Http/http.h \
 MainWindow/mainwindowimpl.h \
 mainWindowDerived.h \
 ui_login.h \
 ui_mainWindow.h \
 ui_sendTwit.h \
 twitterbackendinterface.h \
 jsonparser.h \
 http.h \
 HttpDownloadManager.h \
 HttpFetchFile.h
INCLUDEPATH += .
QT += gui svg
RESOURCES += images/images.qrc
SOURCES += Http/http.cpp \
 MainWindow/mainwindowimpl.cpp \
 main.cpp \
 mainWindowDerived.cpp \
 twitterbackendinterface.cpp \
 jsonparser.cpp \
 http.cpp \
 HttpDownloadManager.cpp \
 HttpFetchFile.cpp
TARGET =
TEMPLATE = app
CONFIG += debug_and_release build_all
