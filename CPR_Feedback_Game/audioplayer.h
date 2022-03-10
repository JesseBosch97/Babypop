#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include "FeedbackHandlerBoundaries.h"
#include "RequestModelBoundaries.h"
#include "unordered_map"



class Audioplayer : public FeedbackHandlerOutput, public RequestModelToAudioPlayer
{
public:
    Audioplayer();

   void giveBpmFeedback(int feedbackType) override;
   void voiceSelected(QString voice) override;

   QString createURL(QString word);
private:
    QMediaPlayer player;
    QString selectedVoice = "maleTTS";
    void playSound();

    std::unordered_map<std::string, std::string> u = {
            {"RED","#FF0000"},
            {"GREEN","#00FF00"},
            {"BLUE","#0000FF"}
        };

    std::unordered_map<int, QString> feedbackWordMap
    {
       {PERFECT, "perfect"},
       {TOO_FAST, "slower"},
       {TOO_SLOW, "faster"},
       {TOO_MANY, "too_many"}
    };

};

#endif // AUDIOPLAYER_H
