#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QString>
#include "CprTypes.h"

class AudioPlayer
{
public:
   virtual ~AudioPlayer() = default;
   virtual void giveFeedback(int feedbackType) = 0;
   virtual void voiceSelected(QString voice) = 0;
};

#endif // AUDIOPLAYER_H
