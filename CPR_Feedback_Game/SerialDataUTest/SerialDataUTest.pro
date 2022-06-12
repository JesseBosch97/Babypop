QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_serialdatautest.cpp \
    ../StringFunctions.cpp

HEADERS += \
    ../StringFunctions.h
