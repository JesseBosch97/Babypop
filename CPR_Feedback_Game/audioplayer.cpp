#include "audioplayer.h"

Audioplayer::Audioplayer()
{
    player.setVolume(100);
}

void Audioplayer::giveBpmFeedback(int feedbackType)
{
   switch(feedbackType){
      case PERFECT: player.setMedia(QUrl("qrc:/sounds/perfect_male.mp3"));
         break;
      case TOO_SLOW: player.setMedia(QUrl("qrc:/sounds/more_speed_male.mp3"));
         break;
      case TOO_FAST: player.setMedia(QUrl("qrc:/sounds/less_speed_male.mp3"));
         break;
      case TOO_MANY: player.setMedia(QUrl("qrc:/sounds/too_many_male.mp3"));
         break;
      default: {} //nothing yet
         break;
   }

    playSound();
}

void Audioplayer::playSound(){
    player.play();
}
