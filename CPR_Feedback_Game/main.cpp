#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMediaPlayer>



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/HelloWorld_Male.mp3"));
    player->setVolume(100);
    player->play();


    QQmlApplicationEngine engine;



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
