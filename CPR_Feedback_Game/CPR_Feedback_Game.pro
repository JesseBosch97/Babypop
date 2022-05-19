QT += quick multimedia serialport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CompressionFeedbackImpl.cpp \
        DataHandler.cpp \
        FingerPositionDataHandler.cpp \
        FingerPositionFeedback.cpp \
        HeadPositionFeedback.cpp \
        SerialPort.cpp \
        StringFunctions.cpp \
        VentilationFeedback.cpp \
        ViewModel.cpp \
        audioplayer.cpp \
        main.cpp \
        requestmodel.cpp

RESOURCES += qml.qrc \
   sounds.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CompressionFeedback.h \
    CompressionFeedbackImpl.h \
    CprTypes.h \
    DataBoundaries.h \
    DataHandler.h \
    FeedbackBoundaries.h \
    FingerPositionDataHandler.h \
    FingerPositionFeedback.h \
    HeadPositionFeedback.h \
    RequestModelBoundaries.h \
    SerialPort.h \
    SerialPortBoundary.h \
    StringFunctions.h \
    VentilationFeedback.h \
    ViewModel.h \
    audioplayer.h \
    requestmodel.h
