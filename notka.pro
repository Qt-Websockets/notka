#-------------------------------------------------
#
# Project created by QtCreator 2017-08-24T20:28:37
#
#-------------------------------------------------

QT       += core gui websockets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notka
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/notka.cpp \
    src/endpointwebsocket.cpp \
    src/msghandler.cpp \
    src/msg.cpp \
    src/websocketsession.cpp \
    src/globals.cpp \
    src/task.cpp

HEADERS  += \
    inc/notka.h \
    inc/endpointwebsocket.h \
    inc/notkaendpoint.h \
    inc/msghandler.h \
    inc/msg.h \
    inc/websocketsession.h \
    inc/globals.h \
    inc/task.h

FORMS    += \
    ui/notka.ui

DISTFILES += \
    html/webclient.html
