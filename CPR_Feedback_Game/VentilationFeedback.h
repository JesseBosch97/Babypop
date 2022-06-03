#ifndef VENTILATIONFEEDBACK_H
#define VENTILATIONFEEDBACK_H

#include <iostream>
#include <vector>
#include "CprTypes.h"


#define FLOW_STRENGTH_ALLOWED_ERROR 1
#define FLOW_STRENGTH_MIN 10
#define FLOW_STRENGHT_MAX 20

#define DESIRED_PAUSE_TIME_MS 1500
#define PAUSE_TIME_ALLOWED_ERROR 500




class VentilationFeedbackImpl
{
public:
    VentilationFeedbackImpl();



    void setVentilationAmount(int amount);
    void setVolumeErrorThreshold(float percentage);
    void setTimeErrorThreshold(float percentage);
    void setBabyWeight(float babyWeightInKg);

    uint8_t handleVolumeIn(Ventilation performance);
    uint8_t handleVolumeOut(Ventilation performance);



    int ventilationCount = 0;


private:
    int ventilationAmount = 0;


    int volumeAccumulatedError = 0;
    int timeAccumulatedError = 0;

    float volumeErrorThreshold = 0;
    float timeErrorThreshold = 0;


    void storeVentilation(Ventilation ventilation);
    uint8_t evaluateVentilation();

    //a baby should be ventilated with 6 to 8 ml per kg of bodyweight
    // thebag contains 125 mil
    //top value for the bag used is 140

    float babyWeightInKg = 0;
    float desiredVolume = 0;
    const int DESIRED_TIME_IN_MS = 500;
    const int ML_PER_KG_BABY_WEIGHT = 7;
};

#endif // VENTILATIONFEEDBACK_H
