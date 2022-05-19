#include "AudioPlayerImpl.h"
#include <iostream>

AudioPlayerImpl::AudioPlayerImpl()
{
    player.setVolume(100);
}


void AudioPlayerImpl::giveFeedback(int feedbackType)
{
   player.setMedia(QUrl(createSoundURL(feedbackWordMap.at(feedbackType))));
   playSound();
}

void AudioPlayerImpl::voiceSelected(QString voice)
{
    this->selectedVoice = voice;
}

void AudioPlayerImpl::giveFingerPositionFeedback(int fingerFeedback)
{
    player.setMedia(QUrl(createSoundURL(feedbackWordMap.at(fingerFeedback))));
    playSound();
}

QString AudioPlayerImpl::createSoundURL(QString word)
{
   return QString("qrc:/sounds/%1/audiofiles/%2_%3.mp3").arg(selectedVoice, selectedVoice, word);
}

void AudioPlayerImpl::playSound(){
    player.play();
}
