/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#include "VentilationFeedback.h"

VentilationFeedback::VentilationFeedback()
{


}


void VentilationFeedback::storeVentilation(Ventilation ventilation)
{
   if (ventilation.volumeInMl > 0 && ventilation.timeInMs)
   {
      ventilationCount++;
      volumeAccumulatedError += ventilation.volumeInMl - desiredVolume_ml;
      timeAccumulatedError += static_cast<float>(ventilation.timeInMs - DESIRED_TIME_IN_MS);

      std::cout << "VentilationFeedback: volume is: " << ventilation.volumeInMl << std::endl;
      std::cout << "VentilationFeedback: accumulated volume error is: " << volumeAccumulatedError << std::endl;
      std::cout << "VentilationFeedback: time is: " << ventilation.timeInMs << std::endl;
      std::cout << "VentilationFeedback: accumulated time error is: " << timeAccumulatedError << std::endl;
   }
}

FeedbackType VentilationFeedback::evaluateVentilation()
{
   uint8_t feedbackType = 0;

   if (ventilationCount > ventilationAmount)
   {
      feedbackType = TOO_MANY;
      volumeAccumulatedError = 0;
      timeAccumulatedError = 0;
   }

   else if (volumeAccumulatedError > volumeErrorThreshold)
   {
      feedbackType = TOO_MUCH;
      volumeAccumulatedError = 0;
   }

   else if (volumeAccumulatedError < -volumeErrorThreshold)
   {
      feedbackType = TOO_LITTLE;
      volumeAccumulatedError = 0;
   }

   else if (timeAccumulatedError > timeErrorThreshold)
   {
       feedbackType = TOO_LONG;
       timeAccumulatedError = 0;
   }

   else if (timeAccumulatedError < -timeErrorThreshold)
   {
       feedbackType = TOO_SHORT;
       timeAccumulatedError = 0;
   }

   else feedbackType = NEUTRAL;

   return feedbackType;

}


FeedbackType VentilationFeedback::handleVolumeIn(Ventilation ventilation)
{
    uint8_t feedbackType = 0;
    storeVentilation(ventilation);
    feedbackType = evaluateVentilation();
    return feedbackType;
}


FeedbackType VentilationFeedback::handleVolumeOut(Ventilation ventilation)
{
    uint8_t feedbackType = 0;
    return feedbackType;
}



