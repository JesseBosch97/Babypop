#ifndef DATABOUNDARIES_H
#define DATABOUNDARIES_H

#include "CprTypes.h"





class DataToVentilationFeedback
{
public:
    virtual void handleVolumeIn(Ventilation ventilation) = 0;
    virtual void handleVolumeOut(Ventilation ventilation) = 0;
};



class DataToHeadPositionFeedback
{
public:
    virtual void handleHeadPosition(HeadPosition headPosition) = 0;
};

#endif // DATABOUNDARIES_H
