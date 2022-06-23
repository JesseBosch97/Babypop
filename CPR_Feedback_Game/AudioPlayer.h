/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0


#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QString>
#include "CprTypes.h"

class AudioPlayer
{
public:
   virtual ~AudioPlayer() = default;
   virtual void giveFeedback(FeedbackType feedbackType) = 0;
   virtual void voiceSelected(QString voice) = 0;
};

#endif // AUDIOPLAYER_H
