#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include "feedbackboundary.h"

class Audioplayer : public FeedbackBoundary
{
public:
    Audioplayer();

    void giveBpmFeedback(int bpm) override;

private:
    QMediaPlayer player;
    void playSound();

};

#endif // AUDIOPLAYER_H
