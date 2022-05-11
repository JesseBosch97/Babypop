#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H

#include "FeedbackBoundaries.h"
#include "DataBoundaries.h"
#include "RequestModelBoundaries.h"
#include <iostream>
#include <vector>

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define COMPRESSION_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5 //should be const




class CompressionFeedback : public DataToCompressionFeedback, public RequestModelToCompressionFeedback
{
public:
    CompressionFeedback();

    FeedbackToAudio * audioPlayer;
    FeedbackToViewModel * viewModel;

    void setCompressionFeedbackAmountSelection(float amount) override;  
    void setCompressionFeedbackSelected(bool state) override;
    void handleBpmPerformance(int bpm) override;





private:
    int bpmSamples[BPM_SAMPLE_AMOUNT] = {DESIRED_BPM}; //should be dynamic array

    //std::vector<int> bpmSamples;

    int compressionFeedbackAmountPercentage = 0;
    int compressionFeedbackAmount = 0;
    bool compressionFeedbackSelected = false;
    int compressionCount = 0;
    int bpmPerformanceState = 0;

    int checkBPM();
    int handleBpmPerformanceState();

    void storeBpmSample(int bpm);
    int averageBpm();


};

#endif // COMPRESSIONFEEDBACK_H
