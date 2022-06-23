/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringListModel>

#include "RequestModel.h"
#include "AudioPlayerImpl.h"
#include "SerialPortImpl.h"
#include "SerialDataImpl.h"
#include "FeedbackInteractorImpl.h"
#include "ViewModelImpl.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //create objects
    AudioPlayerImpl audioplayer;
    FeedbackInteractorImpl feedbackInteractor;
    RequestModel requestModel;
    ViewModelImpl viewModel;
    SerialPortImpl serialPort;
    SerialDataImpl serialData;


    //connect objects
    requestModel.serialPort = &serialPort;
    requestModel.audioPlayer = &audioplayer;
    requestModel.feedbackInteractor = &feedbackInteractor;
    requestModel.serialData = &serialData;
    feedbackInteractor.audioPlayer = &audioplayer;
    feedbackInteractor.viewModel = &viewModel;
    serialPort.serialData = &serialData;
    serialData.feedbackInteractor = &feedbackInteractor;

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
