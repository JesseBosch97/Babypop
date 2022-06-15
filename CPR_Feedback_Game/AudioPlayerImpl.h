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
        {START_COMPRESSION, "chest_compression"},
        {PERFECT, "perfect"},
        {TOO_FAST, "slower"},
        {TOO_SLOW, "faster"},
        {TOO_DEEP, "less"},
        {TOO_SHALLOW, "more"},
        {TOO_MANY, "too_many"},

        {TOO_FAR_LEFT, "little_to_the_right"},
        {TOO_FAR_RIGHT, "little_to_the_left"},
        {WAY_TOO_LOW, "higher"},
        {TOO_LOW, "little_higher"},
        {TOO_HIGH, "little lower"},

        {START_VENTILATION, "ventilate"},
        {TOO_SHORT, "blow_longer"},
        {TOO_LONG, "blow_shorter"},
        {TOO_LITTLE, "more"},
        {TOO_MUCH, "less"}};
};

#endif // AUDIOPLAYERIMPL_H
