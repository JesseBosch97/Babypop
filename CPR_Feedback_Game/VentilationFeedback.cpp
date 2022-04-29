#include "VentilationFeedback.h"

VentilationFeedback::VentilationFeedback()
{


}

VentilationFeedback::~VentilationFeedback()
{

}





void VentilationFeedback::handleVolumeInPerformance(VolumePerformance performance)
{
    if (ventilationFeedbackSelected)
    {
        std::cout << "FeedbackHandler: volume in is " << performance.volume << std::endl;
        std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;

        volumeInBuffer.push_back(performance.volume);
        timeVolumeInBuffer.push_back(performance.time);
        ventilationCount++;
        uint8_t feedBackType = 0;

        if (ventilationCount > ventilationAmount)
        {
            feedBackType = TOO_MANY;
        }

        else if (ventilationCount % ventilationFeedbackFrequency == 0)
        {

            float averageVolume = calculateAverageVolume();
            float averageTime = calculateAverageTime();

            if (averageVolume < VOLUME_MIN)
            {
                feedBackType = VENTILATION_TOO_LITTLE;
            }
            else if (averageVolume > VOLUME_MAX)
            {
                feedBackType = VENTILATION_TOO_MUCH;
            }

            else if (averageTime > VENTILATION_TIME_MAX)
            {
                feedBackType = VENTILATION_TOO_LONG;
            }

            else if (averageTime < VENTILATION_TIME_MIN)
            {
                feedBackType = VENTILATION_TOO_SHORT;
            }

            volumeInBuffer.clear();
            timeVolumeInBuffer.clear();
        }

        if (feedBackType > 0) audioPlayer->giveFeedback(feedBackType);
    }
}


float VentilationFeedback::calculateAverageVolume()
{
    float total = 0;
    for (auto & el : volumeInBuffer)
    {
        total += el;
    }

    return total/volumeInBuffer.size();
}

float VentilationFeedback::calculateAverageTime()
{
    float total = 0;
    for (auto & el : timeVolumeInBuffer)
    {
        total += el;
    }

    return total/timeVolumeInBuffer.size();
}


void VentilationFeedback::handleVolumeOutPerformance(VolumePerformance performance)
{
    if (ventilationFeedbackSelected)
    {
        //std::cout << "FeedbackHandler: volume out is " << performance.volume << std::endl;
        //std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;
    }
}

void VentilationFeedback::handleFlowPerformance(FlowPerformance flowPerformance)
{
    std::cout << "FeedbackHandler: average flow strength is " << flowPerformance.averageFlowStrength << std::endl;
    std::cout << "FeedbackHandler: max flow strength is " << flowPerformance.maxFlowStrength << std::endl;
    std::cout << "FeedbackHandler: pause time is " << flowPerformance.pauseTime << std::endl;
    std::cout << "FeedbackHandler: ventilation time is " << flowPerformance.ventilationTime << std::endl;

    if (ventilationFeedbackSelected){

        ventilationCount++;

        if (ventilationCount % ventilationFeedbackFrequency == 0)
        {
            if (flowPerformance.maxFlowStrength <= FLOW_STRENGTH_MIN - FLOW_STRENGTH_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_LITTLE);
            }

            else if (flowPerformance.maxFlowStrength > FLOW_STRENGHT_MAX + FLOW_STRENGTH_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_MUCH);
            }

//            else if (flowPerformance.ventilationTime <= DESIRED_VENTILATION_TIME_MS - VENTILATION_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(VENTILATION_TOO_SHORT);
//            }

//            else if (flowPerformance.ventilationTime > DESIRED_VENTILATION_TIME_MS + VENTILATION_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(VENTILATION_TOO_LONG);
//            }

            else if (flowPerformance.pauseTime > DESIRED_PAUSE_TIME_MS + PAUSE_TIME_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(PAUSE_TOO_LONG);
            }

//            else if (flowPerformance.pauseTime <= DESIRED_PAUSE_TIME_MS - PAUSE_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(PAUSE_TOO_SHORT);
//            }


        }
    }
}


void VentilationFeedback::setVentilationFeedbackSelected(bool state)
{
    this->ventilationFeedbackSelected = state;
    if (state == true) audioPlayer->giveFeedback(START_VENTILATION);
}

void VentilationFeedback::setVentilationFeedbackFrequency(int amount)
{
    this->ventilationFeedbackFrequency = amount;
    ventilationCount = 0;
}

void VentilationFeedback::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
    ventilationCount = 0;
}
