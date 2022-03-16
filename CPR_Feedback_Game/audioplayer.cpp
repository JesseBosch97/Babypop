#include "audioplayer.h"
#include <iostream>

Audioplayer::Audioplayer()
{
    player.setVolume(100);
}


void Audioplayer::giveBpmFeedback(int feedbackType)
{
   player.setMedia(QUrl(createURL(feedbackWordMap.at(feedbackType))));
   playSound();
}

void Audioplayer::voiceSelected(QString voice)
{
    this->selectedVoice = voice;
}

void Audioplayer::giveFingerPositionFeedback(int fingerFeedback)
{
    player.setMedia(QUrl(createURL(feedbackWordMap.at(fingerFeedback))));
    playSound();
}

QString Audioplayer::createURL(QString word)
{
   return QString("qrc:/sounds/%1/audiofiles/%2_%3.mp3").arg(selectedVoice, selectedVoice, word);
}

void Audioplayer::playSound(){
    player.play();
}
