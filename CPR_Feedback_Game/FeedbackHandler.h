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

#define DESIRED_PAUSE_TIME_MS 1500
#define PAUSE_TIME_ALLOWED_ERROR 500

#define DESIRED_VENTILATION_TIME_MS 1000
#define VENTILATION_TIME_ALLOWED_ERROR 200

#define FLOW_STRENGTH_ALLOWED_ERROR 1
#define FLOW_STRENGTH_MIN 10
#define FLOW_STRENGHT_MAX 20

const int VOLUME_MIN = 50;
const int VOLUME_MAX = 70;
const int VENTILATION_TIME_MIN = 800;
const int VENTILATION_TIME_MAX = 1200;

struct Coordinates
{
    float x;
    float y;
};

enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};

class FeedbackHandler : public FeedbackHandlerInput, public RequestModelToFeedbackHandler
{
public:
    FeedbackHandler();

    FeedbackHandlerOutput * audioPlayer;
    FeedbackHandlerToViewModel * viewModel;

    void setCompressionFeedbackAmountSelection(float amount) override;
    void setVentilationFeedbackFrequency(int amount) override;
    void setCompressionFeedbackSelected(bool state) override;
    void setVentilationFeedbackSelected(bool state) override;
    void setVentilationAmount(int amount) override;


    void handleBpmPerformance(int bpm) override;
    void handleFlowPerformance(FlowPerformance flowPerformance) override;
    void fingerPositionPerformance(Fingerposition positionOfFingers) override;
    void handleVolumeInPerformance(VolumePerformance performance) override;
    void handleVolumeOutPerformance(VolumePerformance performance) override;



private:
    int bpmSamples[BPM_SAMPLE_AMOUNT] = {DESIRED_BPM}; //should be dynamic array

    //std::vector<int> bpmSamples;


    int compressionFeedbackAmountPercentage = 0;
    int ventilationFeedbackAmountPercentage = 0;

    int ventilationFeedbackFrequency = 0;
    int compressionFeedbackAmount = 0;

    int ventilationAmount = 0;

    bool compressionFeedbackSelected = false;
    bool ventilationFeedbackSelected = false;

    int ventilationCount = 0;
    int compressionCount = 0;

    int bpmPerformanceState = 0;

    location locationOfFingers(Fingerposition positionOfFingers);
    location calculateLocation(Coordinates);
    int pressurePoints(Fingerposition positionOfFingers);

    int checkBPM();
    int handleBpmPerformanceState();

    void storeBpmSample(int bpm);
    int averageBpm();


};

#endif // FEEDBACKHANDLER_H
