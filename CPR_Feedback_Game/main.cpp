#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringListModel>

#include "requestmodel.h"
#include "FeedbackHandler.h"
#include "audioplayer.h"
#include "interactionprocessor.h"
#include "ViewModel.h"
#include "SerialPort.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //create objects
    Audioplayer audioplayer;
    FeedbackHandler feedback;
    RequestModel requestModel;
    InteractionProcessor interactionProcessor;
    ViewModel viewModel;
    SerialPort serialPort;

    //connect objects
    requestModel.processor = &interactionProcessor;
    requestModel.serialPort = &serialPort;
    interactionProcessor.output = &feedback;
    feedback.output = &audioplayer;

    //create application
    QQmlApplicationEngine engine;

    //make qml aware of used types
    qmlRegisterType <QStringListModel> ( "StringListModel", 1, 0, "QStringListModel" );

    //connect application to c++ classes
    engine.rootContext()->setContextProperty("RequestModel", &requestModel);
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
