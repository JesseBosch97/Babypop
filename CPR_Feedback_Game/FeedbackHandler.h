#ifndef FEEDBACKHANDLER_H
#define FEEDBACKHANDLER_H

#include "FeedbackHandlerOutput.h"
#include "FeedbackHandlerInput.h"
#include <iostream>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 20
#define DESIRED_REPETITIONS 30

class FeedbackHandler : public FeedbackHandlerInput
{
public:
    FeedbackHandler();

    FeedbackHandlerOutput * output;
    void handleBpmPerformance(int bpm) override;
    void handleCompressionCountPerformance(int count) override;

private:
    int compressionCount = 0;
    int bpmPerformanceState = 0;
    int checkBPM(int bpm);
    int handleBpmPerformanceState(int bpm);
};

#endif // FEEDBACKHANDLER_H
