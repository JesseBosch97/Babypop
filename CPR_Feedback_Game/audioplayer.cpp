#include "audioplayer.h"

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

QString Audioplayer::createURL(QString word)
{
   return QString("qrc:/sounds/%1/audiofiles/%2_%3.mp3").arg(selectedVoice, selectedVoice, word);
}

void Audioplayer::playSound(){
    player.play();
}
