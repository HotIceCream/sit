#-------------------------------------------------
#
# Project created by QtCreator 2012-03-24T22:53:16
#
#-------------------------------------------------

QT       += core gui network

TARGET = DictionaryClient
TEMPLATE = app


SOURCES += main.cpp \
    logindialog.cpp \
    ../DictionaryServer/connection.cpp \
    userwindow.cpp

HEADERS  += \
    logindialog.h \
    ../DictionaryServer/connection.h \
    userwindow.h

FORMS    += \
    logindialog.ui \
    userwindow.ui
