#include "VentilationFeedbackImpl.h"

VentilationFeedbackImpl::VentilationFeedbackImpl()
{


}


void VentilationFeedbackImpl::storeVentilation(Ventilation ventilation)
{
   if (ventilation.volumeInMl && ventilation.timeInMs)
   {
      ventilationCount++;
      volumeAccumulatedError += ventilation.volumeInMl - desiredVolume;
      timeAccumulatedError += ventilation.timeInMs - DESIRED_TIME_IN_MS;

      std::cout << "VentilationFeedback: volume is: " << ventilation.volumeInMl << std::endl;
      std::cout << "VentilationFeedback: accumulated volume error is: " << volumeAccumulatedError << std::endl;
      std::cout << "VentilationFeedback: time is: " << ventilation.timeInMs << std::endl;
      std::cout << "VentilationFeedback: accumulated time error is: " << timeAccumulatedError << std::endl;
   }
}

uint8_t VentilationFeedbackImpl::evaluateVentilation()
{
   uint8_t feedbackType = 0;

   if (ventilationCount > ventilationAmount)
   {
      feedbackType = TOO_MANY;
   }

   else if (volumeAccumulatedError > volumeErrorThreshold)
   {
      feedbackType = VENTILATION_TOO_MUCH;
      volumeAccumulatedError = 0;
   }

   else if (volumeAccumulatedError < -volumeErrorThreshold)
   {
      feedbackType = VENTILATION_TOO_LITTLE;
      volumeAccumulatedError = 0;
   }

   else if (timeAccumulatedError > timeErrorThreshold)
   {
       feedbackType = VENTILATION_TOO_LONG;
       timeAccumulatedError = 0;
   }

   else if (timeAccumulatedError < -timeErrorThreshold)
   {
       feedbackType = VENTILATION_TOO_SHORT;
       timeAccumulatedError = 0;
   }

   return feedbackType;

}


void VentilationFeedbackImpl::handleVolumeIn(Ventilation ventilation)
{
    if (ventilationFeedbackSelected)
    {
       storeVentilation(ventilation);
       audioPlayer->giveFeedback(evaluateVentilation());
    }
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



void VentilationFeedbackImpl::setVolumeErrorThreshold(float percentage)
{
   this->volumeErrorThreshold = desiredVolume * percentage/100;
   std::cout << "VentilationFeedback: allowed volume error is :" << this->volumeErrorThreshold << std::endl;
}

void VentilationFeedbackImpl::setTimeErrorThreshold(float percentage)
{
   this->timeErrorThreshold = DESIRED_TIME_IN_MS * percentage/100;
    std::cout << "VentilationFeedback: allowed time error is :" << this->timeErrorThreshold << std::endl;
}

void VentilationFeedbackImpl::setBabyWeight(float babyWeightInKg)
{
    this->babyWeightInKg = babyWeightInKg;
    std::cout << "VentilationFeedback: babyWeight is :" << this->babyWeightInKg << std::endl;

    this->desiredVolume = babyWeightInKg * ML_PER_KG_BABY_WEIGHT;
    std::cout << "VentilationFeedback: desired volume is :" << this->desiredVolume << std::endl;
}


void VentilationFeedbackImpl::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
    ventilationCount = 0;
}
