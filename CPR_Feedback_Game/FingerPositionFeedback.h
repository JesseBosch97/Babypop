#ifndef FINGERPOSITIONFEEDBACK_H
#define FINGERPOSITIONFEEDBACK_H


#include <iostream>
#include <vector>
#include "CprTypes.h"



struct Coordinates
{
    float x;
    float y;
};

enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};

class FingerPositionFeedbackImpl
{
public:
    FingerPositionFeedbackImpl();

    uint8_t handleFingerPosition(FingerPosition positionOfFingers);

private:
    location locationOfFingers(FingerPosition positionOfFingers);
    location calculateLocation(Coordinates);
    int pressurePoints(FingerPosition positionOfFingers);
};

#endif // FINGERPOSITIONFEEDBACK_H
