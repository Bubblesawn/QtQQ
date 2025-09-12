QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatClient
TEMPLATE = app

CONFIG += c++14

SOURCES += \
    main.cpp \
    UserLogin.cpp \
    CCMainWindow.cpp \
    BasicWindow.cpp

HEADERS += \
    UserLogin.h \
    CCMainWindow.h \
    BasicWindow.h

FORMS += \
    userlogin.ui \
    ccmainwindow.ui


RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
