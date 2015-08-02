#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T16:49:54
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = ./app/tietuku
CONFIG   += console
CONFIG   -= app_bundle
unix:OBJECTS_DIR = ./tietuku/tmp
win32:OBJECTS_DIR = ./tietuku/tmp
TEMPLATE = app


SOURCES += main.cpp \
    Ctietuku.cpp \
    Uploadapi.cpp

HEADERS += \
    Common.h \
    Ctietuku.h \
    Uploadapi.h
