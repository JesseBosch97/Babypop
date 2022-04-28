#ifndef FEEDBACKHANDLERINPUT_H
#define FEEDBACKHANDLERINPUT_H

#include "PerformanceTypes.h"



class FeedbackHandlerInput
{
public:
    virtual void handleBpmPerformance(int bpm) = 0;
    virtual void fingerPositionPerformance(Fingerposition posistionOfFingers) = 0;
    virtual void handleFlowPerformance(FlowPerformance flowPerformance) = 0;
    virtual void handleVolumeInPerformance(VolumePerformance performance) = 0;
    virtual void handleVolumeOutPerformance(VolumePerformance performance) = 0;
};

#endif // FEEDBACKHANDLERINPUT_H
