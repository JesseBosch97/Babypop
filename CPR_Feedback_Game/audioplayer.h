#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>

class Audioplayer
{
public:
    Audioplayer();

    QMediaPlayer player;
    void playSound();

};

#endif // AUDIOPLAYER_H
