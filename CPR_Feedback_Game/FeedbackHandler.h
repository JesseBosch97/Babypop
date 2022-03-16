#ifndef FEEDBACKHANDLER_H
#define FEEDBACKHANDLER_H

#include "FeedbackHandlerBoundaries.h"
#include "FeedbackHandlerInput.h"
#include "RequestModelBoundaries.h"
#include <iostream>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define DESIRED_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5 //should be const
//#define FEEDBACK_FREQUENCY 5

class FeedbackHandler : public FeedbackHandlerInput, public RequestModelToFeedbackHandler
{
public:
    FeedbackHandler();

    FeedbackHandlerOutput * output;
    FeedbackHandlerToViewModel * viewModel;

    void handleBpmPerformance(int bpm) override;
    void handleCompressionCountPerformance(int count) override;
    void feedbackAmountSelected(float amount) override;
    void fingerPositionPerformance(Fingerposition positionOfFingers) override;

private:
    int bpmSamples[BPM_SAMPLE_AMOUNT] = {DESIRED_BPM}; //should be dynamic array

    int feedbackAmountPercentage = 0;
    int feedbackAmount = 5;

    int compressionCount = 0;
    int bpmPerformanceState = 0;
    int checkBPM();
    int handleBpmPerformanceState();
    void storeBpmSample(int bpm);
    int averageBpm();


};

#endif // FEEDBACKHANDLER_H
