#include "audioplayer.h"

Audioplayer::Audioplayer()
{ 
    player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/HelloWorld_Male.mp3"));
    player.setVolume(100);
}

void Audioplayer::giveBpmFeedback(int feedbackType)
{
    switch(feedbackType){
    case PERFECT: player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/perfect_male.mp3"));
        break;
    case TOO_SLOW: player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/more_speed_male.mp3"));
        break;
    case TOO_FAST: player.setMedia(QUrl::fromLocalFile("C:/Users/Niels/Documents/GitHub/Babypop/CPR_Feedback_Game/less_speed_male.mp3"));
        break;
    default: {} //nothing yet
        break;
    }

    playSound();
}

void Audioplayer::playSound(){
    player.play();
}
