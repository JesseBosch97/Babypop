/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef HEADPOSITIONFEEDBACK_H
#define HEADPOSITIONFEEDBACK_H

#include "CprTypes.h"
#include <cstdint>

class HeadPositionFeedbackImpl
{
public:
    HeadPositionFeedbackImpl();


    uint8_t handleHeadPosition(HeadPosition headPosition);
};

#endif // HEADPOSITIONFEEDBACK_H
