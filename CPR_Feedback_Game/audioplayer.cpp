#include "audioplayer.h"

Audioplayer::Audioplayer()
{ 
    player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/HelloWorld_Male.mp3"));
    player.setVolume(100);
}

void Audioplayer::giveFeedback()
{
    playSound();

}

void Audioplayer::playSound(){
    player.play();
}
