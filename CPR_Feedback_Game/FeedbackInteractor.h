#ifndef FEEDBACKINTERACTOR_H
#define FEEDBACKINTERACTOR_H

#include "CprTypes.h"

class FeedbackInteractor
{
public:
    virtual ~FeedbackInteractor() = default;
    virtual void handleFingerPosition(FingerPosition fingerPosition) = 0;
    virtual void handleCompression(Compression compression) = 0;
    virtual void handleHeadPosition(HeadPosition headPosition) = 0;
    virtual void handleVolumeIn(Ventilation ventilation) = 0;
    virtual void handleVolumeOut(Ventilation ventilation) = 0;

    virtual void setCompressionFeedbackSelected(bool state) = 0;
    virtual void setCompressionAmount(int amount) = 0;
    virtual void setBpmErrorThreshold(float percentage) = 0;
    virtual void setDepthErrorThreshold(float percentage) = 0;

    virtual void setVentilationAmount(int amount) = 0;
    virtual void setVentilationFeedbackSelected(bool state) = 0;
    virtual void setVolumeErrorThreshold(float percentage) = 0;
    virtual void setTimeErrorThreshold(float percentage) = 0;
    virtual void setDesiredVentilationVolumeFromBabyWeight(float babyWeightInKg) = 0;

};

#endif // FEEDBACKINTERACTOR_H
