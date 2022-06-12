QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../CPR_Feedback_Game/StringFunctions.cpp \
    tst_SerialData.cpp

HEADERS += \
    ../CPR_Feedback_Game/StringFunctions.h
