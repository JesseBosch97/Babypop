#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <QQmlContext>

#include "requestmodel.h"
#include "feedback.h"
#include "audioplayer.h"
#include "interactionprocessor.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //create objects
    Audioplayer audioplayer;
    Feedback feedback;
    RequestModel requestModel;
    InteractionProcessor interactionProcessor;

    //connect objects
    requestModel.output = &interactionProcessor;
    interactionProcessor.output = &feedback;
    feedback.output = &audioplayer;

    //create application
    QQmlApplicationEngine engine;

    //connect application to c++ classes
    engine.rootContext()->setContextProperty("RequestModel", &requestModel);


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
