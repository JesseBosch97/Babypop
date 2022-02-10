#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMediaPlayer>
#include <QElapsedTimer>
#include <iostream>
#include <QQmlContext>

#include "requestmodel.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    RequestModel requestModel;


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("RequestModel", &requestModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    //play sound
    QMediaPlayer player;
    player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/HelloWorld_Male.mp3"));
    player.setVolume(100);
    player.play();


    //measure time
    QElapsedTimer timer;
    timer.start();
    std::cout << "timer started " << std::endl;

    while (timer.elapsed() < 2000){
        //wait
    }

    std::cout << "time elapsed: " << timer.elapsed() << std::endl;



    return app.exec();
}
