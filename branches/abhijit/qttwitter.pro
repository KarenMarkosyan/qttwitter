# #####################################################################
# Automatically generated by qmake (2.01a) Tue Dec 9 16:38:46 2008
# #####################################################################
TEMPLATE = app
TARGET = 
DEPENDPATH += . \
    blog \
    debug \
    images \
    MainWindow \
    twitlib \
    Ui
INCLUDEPATH += . \
    MainWindow \
    twitlib
QT += gui \
    network \
    xml

# Input
HEADERS += blog.h \
    mainWindowDerived.h \
    twitterbackendinterface.h \
    blog/blog.h \
    MainWindow/mainwindowimpl.h \
    twitlib/Core.h \
    twitlib/Decipher.h \
    twitlib/QTwitLib.h \
    twitlib/Returnables.h \
    twitlib/Server.h \
    Ui/imageBrowser.h \
    Ui/login.h \
    Ui/mainWindow.h \
    Ui/sendTwit.h \
    sendTwitDerived.h \
    loginDerived.h
FORMS += Ui/imageBrowser.ui \
    Ui/login.ui \
    Ui/mainWindow.ui \
    Ui/sendTwit.ui
SOURCES += main.cpp \
    mainWindowDerived.cpp \
    twitterbackendinterface.cpp \
    MainWindow/mainwindowimpl.cpp \
    twitlib/Core.cpp \
    twitlib/Decipher.cpp \
    twitlib/QTwitLib.cpp \
    loginDerived.cpp \
    sendTwitDerived.cpp
RESOURCES += images/images.qrc
