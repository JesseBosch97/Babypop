#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include "FeedbackHandlerOutput.h"

class Audioplayer : public FeedbackHandlerOutput
{
public:
    Audioplayer();

    void giveBpmFeedback(int feedbackType) override;

private:
    QMediaPlayer player;
    void playSound();

};

#endif // AUDIOPLAYER_H
