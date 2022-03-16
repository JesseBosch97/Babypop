#ifndef FEEDBACKHANDLERINPUT_H
#define FEEDBACKHANDLERINPUT_H

#include "FingerPositionStruct.h"

class FeedbackHandlerInput
{
public:
    virtual void handleBpmPerformance(int bpm) = 0;
    virtual void handleCompressionCountPerformance(int count) = 0;
    virtual void fingerPositionPerformance(Fingerposition posistionOfFingers) = 0;
};

#endif // FEEDBACKHANDLERINPUT_H
