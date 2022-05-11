#ifndef VENTILATIONFEEDBACK_H
#define VENTILATIONFEEDBACK_H

#include "DataBoundaries.h"
#include "RequestModelBoundaries.h"
#include "FeedbackBoundaries.h"
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


class VentilationFeedback : public DataToVentilationFeedback, public RequestModelToVentilationFeedback
{
public:
    VentilationFeedback();
    ~VentilationFeedback();

    FeedbackToAudio * audioPlayer;

    void setVentilationFeedbackSelected(bool state) override;
    void setVentilationAmount(int amount) override;
    void setVentilationFeedbackFrequency(int amount) override;
    void handleVolumeInPerformance(VentilationPerformance performance) override;
    void handleVolumeOutPerformance(VentilationPerformance performance) override;




private:
    int ventilationFeedbackAmountPercentage = 0;
    int ventilationFeedbackFrequency = 0;
    int ventilationAmount = 0;
    bool ventilationFeedbackSelected = false;
    int ventilationCount = 0;

    std::vector<float> volumeInBuffer;
    std::vector<int> timeVolumeInBuffer;

    float calculateAverageVolume();
    float calculateAverageTime();
};

#endif // VENTILATIONFEEDBACK_H
