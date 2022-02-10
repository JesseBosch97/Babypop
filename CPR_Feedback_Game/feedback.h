#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "feedbackboundary.h"
#include "InteractionProcessorBoundary.h"
#include <iostream>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 20
#define DESIRED_REPETITIONS 30

class Feedback : public InteractionProcessorBoundary
{
public:
    Feedback();

    FeedbackBoundary * output;
    void handleBpmPerformance(int bpm) override;
    void handleCompressionCountPerformance(int count) override;

private:
    int compressionCount = 0;
    int bpmPerformanceState = 0;
    int checkBPM(int bpm);
    int handleBpmPerformanceState(int bpm);
};

#endif // FEEDBACK_H
