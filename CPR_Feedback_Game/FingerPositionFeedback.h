#ifndef FINGERPOSITIONFEEDBACK_H
#define FINGERPOSITIONFEEDBACK_H

#include "FeedbackBoundaries.h"
#include "DataBoundaries.h"
#include "RequestModelBoundaries.h"
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

class FingerPositionFeedback : public DataToFingerPositionFeedback
{
public:
    FingerPositionFeedback();

    FeedbackToAudio * audioPlayer;

    void fingerPositionPerformance(FingerPosition positionOfFingers) override;

private:
    location locationOfFingers(FingerPosition positionOfFingers);
    location calculateLocation(Coordinates);
    int pressurePoints(FingerPosition positionOfFingers);
};

#endif // FINGERPOSITIONFEEDBACK_H
