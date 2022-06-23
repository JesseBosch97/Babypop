/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#include "AudioPlayerImpl.h"
#include <iostream>

AudioPlayerImpl::AudioPlayerImpl()
{
    player.setVolume(100);
}


void AudioPlayerImpl::giveFeedback(FeedbackType feedbackType)
{
   if (feedbackType)
   {
      if (player.state() == QMediaPlayer::StoppedState)
      {
         player.setMedia(QUrl(createSoundURL(feedbackWordMap.at(feedbackType))));
         player.play();
      }
   }
}

void AudioPlayerImpl::voiceSelected(QString voice)
{
    this->selectedVoice = voice;
}

QString AudioPlayerImpl::createSoundURL(QString word)
{
   return QString("qrc:/sounds/%1/audiofiles/%2_%3.mp3").arg(selectedVoice, selectedVoice, word);
}


