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
    virtual void handleVolumeIn(Ventilation ventilation) = 0;
    virtual void handleVolumeOut(Ventilation ventilation) = 0;
};

#endif // DATABOUNDARIES_H
