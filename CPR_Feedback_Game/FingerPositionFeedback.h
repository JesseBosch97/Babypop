#ifndef FINGERPOSITIONFEEDBACK_H
#define FINGERPOSITIONFEEDBACK_H

#include "CprTypes.h"

class FingerPositionFeedback
{
public:
   virtual ~FingerPositionFeedback() = default;
    virtual void handleFingerPosition(FingerPosition fingerPosition) = 0;
};

#endif // FINGERPOSITIONFEEDBACK_H
