######################################################################
# Automatically generated by qmake (2.01a) Sat Jun 6 02:49:48 2009
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . blog images MainWindow twitlib Ui
INCLUDEPATH += . MainWindow twitlib

# Input
HEADERS += blog.h \
           derivedconfigdialog.h \
           lineedit.h \
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
           twitlib/Server.h
FORMS += Ui/config.ui \
         Ui/imageBrowser.ui \
         Ui/login.ui \
         Ui/mainWindow.ui \
         Ui/sendTwit.ui
SOURCES += derivedconfigdialog.cpp \
           lineedit.cpp \
           loginDerived.cpp \
           main.cpp \
           mainWindowDerived.cpp \
           sendTwitDerived.cpp \
           twitterbackendinterface.cpp \
           MainWindow/mainwindowimpl.cpp \
           twitlib/Core.cpp \
           twitlib/Decipher.cpp \
           twitlib/QTwitLib.cpp
RESOURCES += images/images.qrc
QT += network xml
