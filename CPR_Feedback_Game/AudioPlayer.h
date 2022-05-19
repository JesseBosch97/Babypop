#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QString>

class AudioPlayer
{
public:
   virtual void giveFeedback(int feedbackType) = 0;
   virtual void giveFingerPositionFeedback(int fingerFeedback) = 0;
   virtual void voiceSelected(QString voice) = 0;
};

#endif // AUDIOPLAYER_H
