#ifndef DATABOUNDARIES_H
#define DATABOUNDARIES_H

#include "PerformanceTypes.h"



class DataToCompressionFeedback
{
public:
    virtual void handleBpmPerformance(int bpm) = 0;
    virtual void fingerPositionPerformance(Fingerposition posistionOfFingers) = 0;
};

class DataToVentilationFeedback
{
public:
    virtual void handleFlowPerformance(FlowPerformance flowPerformance) = 0;
    virtual void handleVolumeInPerformance(VolumePerformance performance) = 0;
    virtual void handleVolumeOutPerformance(VolumePerformance performance) = 0;
};

#endif // DATABOUNDARIES_H
