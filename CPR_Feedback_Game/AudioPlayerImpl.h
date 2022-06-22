#ifndef AUDIOPLAYERIMPL_H
#define AUDIOPLAYERIMPL_H

#include <QMediaPlayer>
#include <unordered_map>
#include "AudioPlayer.h"




class AudioPlayerImpl : public AudioPlayer
{
public:
    AudioPlayerImpl();


    void giveFeedback(FeedbackType feedbackType) override;
    void voiceSelected(QString voice) override;


private:
    QString createSoundURL(QString word);
    QMediaPlayer player;
    QString selectedVoice = "maleTTS";

    std::unordered_map<int, QString> feedbackWordMap{
        //{START_COMPRESSION, "chest_compression"},
        {START_COMPRESSION, "fingers"},
        {PERFECT, "perfect"},
        {TOO_FAST, "slower"},
        {TOO_SLOW, "faster"},
        {TOO_DEEP, "less"},
        {TOO_SHALLOW, "more"},
        {TOO_MANY, "too_many"},

        {TOO_FAR_LEFT, "fingers"},
        {TOO_FAR_RIGHT, "fingers"},
        {WAY_TOO_LOW, "fingers"},
        {TOO_LOW, "fingers"},
        {TOO_HIGH, "fingers"},

        {START_VENTILATION, "ventilate"},
        {TOO_SHORT, "blow_longer"},
        {TOO_LONG, "blow_shorter"},
        {TOO_LITTLE, "more"},
        {TOO_MUCH, "less"}};
};

#endif // AUDIOPLAYERIMPL_H
