#ifndef VENTILATIONFEEDBACK_H
#define VENTILATIONFEEDBACK_H

#include "CprTypes.h"

class VentilationFeedback
{
public:
   virtual ~VentilationFeedback() = default;
   virtual void handleVolumeIn(Ventilation ventilation) = 0;
   virtual void handleVolumeOut(Ventilation ventilation) = 0;

   virtual void setVentilationAmount(int amount) = 0;
   virtual void setVentilationFeedbackSelected(bool state) = 0;
   virtual void setVolumeErrorThreshold(float percentage) = 0;
   virtual void setTimeErrorThreshold(float percentage) = 0;
   virtual void setBabyWeight(float babyWeightInKg) = 0;
};

#endif // VENTILATIONFEEDBACK_H
