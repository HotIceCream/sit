#-------------------------------------------------
#
# Project created by QtCreator 2012-03-24T21:28:29
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = DictionaryServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    clientuser.cpp \
    connection.cpp

HEADERS += \
    myserver.h \
    clientuser.h \
    connection.h
