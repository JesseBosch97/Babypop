#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include "FeedbackBoundaries.h"
#include "RequestModelBoundaries.h"
#include "unordered_map"



class Audioplayer : public FeedbackToAudio, public RequestModelToAudioPlayer
{
public:
    Audioplayer();

   void giveFeedback(int feedbackType) override;
   void voiceSelected(QString voice) override;
   void giveFingerPositionFeedback(int fingerFeedback) override;

   QString createURL(QString word);
private:
    QMediaPlayer player;
    QString selectedVoice = "maleTTS";
    void playSound();

    std::unordered_map<int, QString> feedbackWordMap
    {
        {START_COMPRESSION, "chest_compression"},
        {PERFECT, "perfect"},
        {TOO_FAST, "slower"},
        {TOO_SLOW, "faster"},
        {TOO_MANY, "too_many"},

        {TOO_FAR_LEFT, "little_to_the_right"},
        {TOO_FAR_RIGHT, "little_to_the_left"},
        {WAY_TOO_LOW, "higher"},
        {TOO_LOW, "little_higher"},
        {TOO_HIGH, "little lower"},

        {START_VENTILATION, "ventilate"},
        {VENTILATION_TOO_SHORT, "blow_longer"},
        {VENTILATION_TOO_LONG, "blow_shorter"},
        {VENTILATION_TOO_LITTLE, "more"},
        {VENTILATION_TOO_MUCH, "less"},
        {PAUSE_TOO_SHORT, "faster"},
        {PAUSE_TOO_LONG, "pause_shorter"}
    };

};

#endif // AUDIOPLAYER_H
