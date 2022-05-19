#ifndef FINGERPOSITIONFEEDBACKIMPL_H
#define FINGERPOSITIONFEEDBACKIMPL_H

#include "FeedbackBoundaries.h"
#include "DataBoundaries.h"
#include "FingerPositionFeedback.h"
#include <iostream>
#include <vector>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define COMPRESSION_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5 //should be const



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

    FeedbackToAudio * audioPlayer;

    void handleFingerPosition(FingerPosition positionOfFingers) override;

private:
    location locationOfFingers(FingerPosition positionOfFingers);
    location calculateLocation(Coordinates);
    int pressurePoints(FingerPosition positionOfFingers);
};

#endif // FINGERPOSITIONFEEDBACKIMPL_H
