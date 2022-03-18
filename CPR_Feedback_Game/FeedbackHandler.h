#ifndef FEEDBACKHANDLER_H
#define FEEDBACKHANDLER_H

#include "FeedbackHandlerBoundaries.h"
#include "FeedbackHandlerInput.h"
#include "RequestModelBoundaries.h"
#include <iostream>
#include <vector>
#include "CircularBuffer.hpp"

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define COMPRESSION_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5 //should be const
//#define FEEDBACK_FREQUENCY 5


#define VENTILATION_REPETITIONS 10

#define DESIRED_PAUSE_TIME_MS 1000
#define PAUSE_TIME_ALLOWED_ERROR 500

#define DESIRED_VENTILATION_TIME_MS 1000
#define VENTILATION_TIME_ALLOWED_ERROR 500

#define DESIRED_FLOW_STRENGTH 10
#define FLOW_STRENGTH_ALLOWED_ERROR 5



class FeedbackHandler : public FeedbackHandlerInput, public RequestModelToFeedbackHandler
{
public:
    FeedbackHandler();

    FeedbackHandlerOutput * output;
    FeedbackHandlerToViewModel * viewModel;

    void setCompressionFeedbackAmountSelection(float amount) override;
    void setVentilationFeedbackAmountSelection(float amount) override;
    void setCompressionFeedbackSelected(bool state) override;
    void setVentilationFeedbackSelected(bool state) override;

    void handleBpmPerformance(int bpm) override;
    void handleFlowPerformance(FlowPerformance flowPerformance) override;
    void fingerPositionPerformance(Fingerposition positionOfFingers) override;



private:
    int bpmSamples[BPM_SAMPLE_AMOUNT] = {DESIRED_BPM}; //should be dynamic array

    //std::vector<int> bpmSamples;


    int compressionFeedbackAmountPercentage = 0;
    int ventilationFeedbackAmountPercentage = 0;

    int ventilationFeedbackAmount = 0;
    int compressionFeedbackAmount = 0;

    bool compressionFeedbackSelected = false;
    bool ventilationFeedbackSelected = false;

    int ventilationCount = 0;
    int compressionCount = 0;

    int bpmPerformanceState = 0;


    int checkBPM();
    int handleBpmPerformanceState();

    void storeBpmSample(int bpm);
    int averageBpm();


};

#endif // FEEDBACKHANDLER_H
