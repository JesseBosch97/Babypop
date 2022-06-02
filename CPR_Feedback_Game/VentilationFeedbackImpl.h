#ifndef VENTILATIONFEEDBACKIMPL_H
#define VENTILATIONFEEDBACKIMPL_H

#include "HeadPositionFeedback.h"
#include "SerialData.h"
#include "VentilationFeedback.h"
#include "ViewModel.h"
#include "AudioPlayer.h"
#include <iostream>
#include <vector>


#define FLOW_STRENGTH_ALLOWED_ERROR 1
#define FLOW_STRENGTH_MIN 10
#define FLOW_STRENGHT_MAX 20

#define DESIRED_PAUSE_TIME_MS 1500
#define PAUSE_TIME_ALLOWED_ERROR 500




class VentilationFeedbackImpl : public VentilationFeedback
{
public:
    VentilationFeedbackImpl();

    AudioPlayer * audioPlayer;

    void setVentilationFeedbackSelected(bool state) override;
    void setVentilationAmount(int amount) override;
    void setVolumeErrorThreshold(float percentage) override;
    void setTimeErrorThreshold(float percentage) override;
    void setBabyWeight(float babyWeightInKg) override;

    void handleVolumeIn(Ventilation performance) override;
    void handleVolumeOut(Ventilation performance) override;





private:
    int ventilationAmount = 0;
    bool ventilationFeedbackSelected = false;
    int ventilationCount = 0;

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

#endif // VENTILATIONFEEDBACKIMPL_H
