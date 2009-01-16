######################################################################
# Automatically generated by qmake (2.01a) Thu Jan 15 10:12:23 2009
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . blog debug images MainWindow twitlib Ui
INCLUDEPATH += . MainWindow twitlib

# Input
HEADERS += blog.h \
           loginDerived.h \
           mainWindowDerived.h \
           sendTwitDerived.h \
           styleSheet.h \
           twitterbackendinterface.h \
           blog/blog.h \
           MainWindow/mainwindowimpl.h \
           twitlib/Core.h \
           twitlib/Decipher.h \
           twitlib/ITwitReply.h \
           twitlib/QTwitLib.h \
           twitlib/Returnables.h \
           twitlib/Server.h \
           Ui/imageBrowser.h \
           Ui/login.h \
           Ui/mainWindow.h \
           Ui/sendTwit.h
FORMS += Ui/imageBrowser.ui Ui/login.ui Ui/mainWindow.ui Ui/sendTwit.ui
SOURCES += loginDerived.cpp \
           main.cpp \
           mainWindowDerived.cpp \
           sendTwitDerived.cpp \
           twitterbackendinterface.cpp \
           MainWindow/mainwindowimpl.cpp \
           twitlib/Core.cpp \
           twitlib/Decipher.cpp \
           twitlib/QTwitLib.cpp
RESOURCES += images/images.qrc

QT += gui \
    network \
    xml

