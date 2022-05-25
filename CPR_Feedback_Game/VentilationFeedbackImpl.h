#ifndef VENTILATIONFEEDBACKIMPL_H
#define VENTILATIONFEEDBACKIMPL_H

#include "HeadPositionFeedback.h"
#include "DataHandler.h"
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

const int VOLUME_MIN = 50;
const int VOLUME_MAX = 70;
const int VENTILATION_TIME_MIN = 800;
const int VENTILATION_TIME_MAX = 1200;
const int DESIRED_VOLUME = 60;
const int DESIRED_TIME_IN_MS = 1000;


class VentilationFeedbackImpl : public VentilationFeedback
{
public:
    VentilationFeedbackImpl();

    AudioPlayer * audioPlayer;

    void setVentilationFeedbackSelected(bool state) override;
    void setVentilationAmount(int amount) override;
    void setVentilationFeedbackFrequency(int amount) override;
    void setVolumeError(float percentage) override;
    void setVentilationTimeError(float percentage) override;

    void handleVolumeIn(Ventilation performance) override;
    void handleVolumeOut(Ventilation performance) override;





private:
    int ventilationFeedbackAmountPercentage = 0;
    int ventilationFeedbackFrequency = 0;
    int ventilationAmount = 0;
    bool ventilationFeedbackSelected = false;
    int ventilationCount = 0;

    float allowedVolumeError = 0;
    float allowedTimeError = 0;

    std::vector<float> volumeInBuffer;
    std::vector<int> timeVolumeInBuffer;

    float calculateAverageVolume();
    float calculateAverageTime();

};

#endif // VENTILATIONFEEDBACKIMPL_H
