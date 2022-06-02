#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringListModel>

#include "RequestModel.h"
#include "FingerPositionFeedbackImpl.h"
#include "CompressionFeedbackImpl.h"
#include "AudioPlayerImpl.h"
#include "ViewModelImpl.h"
#include "SerialPortImpl.h"
#include "SerialDataImpl.h"
#include "VentilationFeedbackImpl.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //create objects
    AudioPlayerImpl audioplayer;
    CompressionFeedbackImpl compressionFeedback;
    VentilationFeedbackImpl ventilationFeedback;
    FingerPositionFeedbackImpl fingerPositionFeedback;
    RequestModel requestModel;
    ViewModelImpl viewModel;
    SerialPortImpl serialPort;
    SerialDataImpl serialData;


    //connect objects
    requestModel.serialPort = &serialPort;
    requestModel.audioPlayer = &audioplayer;
    requestModel.compressionFeedback = &compressionFeedback;
    requestModel.ventilationFeedback = &ventilationFeedback;
    requestModel.dataHandler = &serialData;
    compressionFeedback.audioPlayer = &audioplayer;
    ventilationFeedback.audioPlayer = &audioplayer;
    serialPort.serialData = &serialData;
    serialData.compressionFeedback = &compressionFeedback;
    serialData.ventilationFeedback = &ventilationFeedback;
    serialData.fingerPositionFeedback = &fingerPositionFeedback;

    //create application
    QQmlApplicationEngine engine;

    //make qml aware of used types
    qmlRegisterType <QStringListModel> ( "StringListModel", 1, 0, "QStringListModel" );

    //connect application to c++ classes
    engine.rootContext()->setContextProperty("RequestModel", &requestModel);
    engine.rootContext()->setContextProperty("ViewModel", &viewModel);
    engine.rootContext()->setContextProperty("PortListModel", &serialPort.portListModel);




    //generated QT business
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
