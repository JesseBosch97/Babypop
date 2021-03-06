/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef VENTILATIONFEEDBACK_H
#define VENTILATIONFEEDBACK_H

#include <iostream>
#include <vector>
#include "CprTypes.h"



class VentilationFeedback
{
public:
    VentilationFeedback();

    FeedbackType handleVolumeIn(Ventilation ventilation);
    FeedbackType handleVolumeOut(Ventilation ventilation);

    int ventilationCount = 0;
    float desiredVolume_ml = 0;
    int ventilationAmount = 0;
    float volumeErrorThreshold = 0;
    float timeErrorThreshold = 0;

    const int DESIRED_TIME_IN_MS = 500;

private:
    void storeVentilation(Ventilation ventilation);
    FeedbackType evaluateVentilation();

    float volumeAccumulatedError = 0;
    float timeAccumulatedError = 0;
};

#endif // VENTILATIONFEEDBACK_H
