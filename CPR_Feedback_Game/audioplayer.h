#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include "FeedbackHandlerBoundaries.h"
#include "RequestModelBoundaries.h"
#include "unordered_map"



class Audioplayer : public FeedbackHandlerOutput, public RequestModelToAudioPlayer
{
public:
    Audioplayer();

   void giveBpmFeedback(int feedbackType) override;
   void voiceSelected(QString voice) override;
   void giveFingerPositionFeedback(int fingerFeedback) override;

   QString createURL(QString word);
private:
    QMediaPlayer player;
    QString selectedVoice = "maleTTS";
    void playSound();

    std::unordered_map<int, QString> feedbackWordMap
    {
        {PERFECT, "perfect"},
        {TOO_FAST, "slower"},
        {TOO_SLOW, "faster"},
        {TOO_MANY, "too_many"},
        {TOO_FAR_LEFT, "little_to_the_right"},
        {TOO_FAR_RIGHT, "little_to_the_left"},
        {WAY_TOO_LOW, "higher"},
        {TOO_LOW, "little_higher"},
        {TOO_HIGH, "little lower"}

    };

};

#endif // AUDIOPLAYER_H
