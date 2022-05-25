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
        std::cout << "FeedbackHandler: ventilation count is " << ventilationCount << std::endl;
        uint8_t feedBackType = 0;

        if (ventilationCount > ventilationAmount)
        {
            feedBackType = TOO_MANY;
        }

        else if (ventilationCount % ventilationFeedbackFrequency == 0)
        {

            float averageVolume = calculateAverageVolume();
            float averageTime = calculateAverageTime();

            if (averageVolume < DESIRED_VOLUME - allowedVolumeError)
            {
                feedBackType = VENTILATION_TOO_LITTLE;
            }

            else if (averageVolume > DESIRED_VOLUME + allowedVolumeError)
            {
                feedBackType = VENTILATION_TOO_MUCH;
            }

            else if (averageTime > DESIRED_TIME_IN_MS + allowedTimeError)
            {
                feedBackType = VENTILATION_TOO_LONG;
            }

            else if (averageTime < DESIRED_TIME_IN_MS - allowedTimeError)
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
    ventilationCount = 0;
}

void VentilationFeedbackImpl::setVentilationFeedbackFrequency(int amount)
{
    this->ventilationFeedbackFrequency = amount;
   ventilationCount = 0;
}


void VentilationFeedbackImpl::setVolumeError(float percentage)
{
   this->allowedVolumeError = DESIRED_VOLUME * percentage/100;
   std::cout << "VentilationFeedback: allowed volume error is :" << this->allowedVolumeError << std::endl;
}

void VentilationFeedbackImpl::setVentilationTimeError(float percentage)
{
   this->allowedTimeError = DESIRED_TIME_IN_MS * percentage/100;
   std::cout << "VentilationFeedback: allowed time error is :" << this->allowedTimeError << std::endl;
}


void VentilationFeedbackImpl::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
    ventilationCount = 0;
}
