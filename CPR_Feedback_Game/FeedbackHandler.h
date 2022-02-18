#ifndef FEEDBACKHANDLER_H
#define FEEDBACKHANDLER_H

#include "FeedbackHandlerOutput.h"
#include "FeedbackHandlerInput.h"
#include <iostream>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define DESIRED_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5
#define FEEDBACK_FREQUENCY 5

class FeedbackHandler : public FeedbackHandlerInput
{
public:
    FeedbackHandler();

    FeedbackHandlerOutput * output;
    void handleBpmPerformance(int bpm) override;
    void handleCompressionCountPerformance(int count) override;

private:

    int bpmSamples[BPM_SAMPLE_AMOUNT] = {DESIRED_BPM};

    int compressionCount = 0;
    int bpmPerformanceState = 0;
    int checkBPM();
    int handleBpmPerformanceState();
    void storeBpmSample(int bpm);
    int averageBpm();
};

#endif // FEEDBACKHANDLER_H
