#ifndef DATABOUNDARIES_H
#define DATABOUNDARIES_H

#include "CprTypes.h"



class DataToCompressionFeedback
{
public:
    virtual void handleCompression(Compression compression) = 0;
};

class DataToVentilationFeedback
{
public:
    virtual void handleVolumeIn(Ventilation ventilation) = 0;
    virtual void handleVolumeOut(Ventilation ventilation) = 0;
};

class DataToFingerPositionFeedback
{
public:
    virtual void handleFingerPosition(FingerPosition fingerPosition) = 0;
};

class DataToHeadPositionFeedback
{
public:
    virtual void handleHeadPosition(HeadPosition headPosition) = 0;
};

#endif // DATABOUNDARIES_H
