#include "VentilationFeedbackImpl.h"

VentilationFeedbackImpl::VentilationFeedbackImpl()
{


}



void VentilationFeedbackImpl::handleVolumeIn(Ventilation performance)
{
    if (ventilationFeedbackSelected)
    {
        std::cout << "FeedbackHandler: volume in is " << performance.volume << std::endl;
        std::cout << "FeedbackHandler: ventilation time is " << performance.timeInMs << std::endl;

        volumeInBuffer.push_back(performance.volume);
        timeVolumeInBuffer.push_back(performance.timeInMs);
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


float VentilationFeedbackImpl::calculateAverageVolume()
{
    float total = 0;
    for (auto & el : volumeInBuffer)
    {
        total += el;
    }

    return total/volumeInBuffer.size();
}

float VentilationFeedbackImpl::calculateAverageTime()
{
    float total = 0;
    for (auto & el : timeVolumeInBuffer)
    {
        total += el;
    }

    return total/timeVolumeInBuffer.size();
}


void VentilationFeedbackImpl::handleVolumeOut(Ventilation performance)
{
    if (ventilationFeedbackSelected)
    {
        //std::cout << "FeedbackHandler: volume out is " << performance.volume << std::endl;
        //std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;
    }
}


void VentilationFeedbackImpl::setVentilationFeedbackSelected(bool state)
{
    this->ventilationFeedbackSelected = state;
    if (state == true) audioPlayer->giveFeedback(START_VENTILATION);
}

void VentilationFeedbackImpl::setVentilationFeedbackFrequency(int amount)
{
    this->ventilationFeedbackFrequency = amount;
    ventilationCount = 0;
}

void VentilationFeedbackImpl::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
    ventilationCount = 0;
}
