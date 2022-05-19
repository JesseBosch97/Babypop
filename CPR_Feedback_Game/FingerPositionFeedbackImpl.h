#ifndef FINGERPOSITIONFEEDBACKIMPL_H
#define FINGERPOSITIONFEEDBACKIMPL_H

#include "ViewModel.h"
#include "HeadPositionFeedback.h"
#include "FingerPositionFeedback.h"
#include "AudioPlayer.h"
#include <iostream>
#include <vector>



struct Coordinates
{
    float x;
    float y;
};

enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};

class FingerPositionFeedbackImpl : public FingerPositionFeedback
{
public:
    FingerPositionFeedbackImpl();

    AudioPlayer * audioPlayer;

    void handleFingerPosition(FingerPosition positionOfFingers) override;

private:
    location locationOfFingers(FingerPosition positionOfFingers);
    location calculateLocation(Coordinates);
    int pressurePoints(FingerPosition positionOfFingers);
};

#endif // FINGERPOSITIONFEEDBACKIMPL_H
