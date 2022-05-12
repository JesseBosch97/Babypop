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
    void handleCompression(Compression compression) override;


private:
    std::vector<int> bpmBuffer;
    std::vector<int> depthBuffer;
    int compressionCount = 0;
    int evaluateCompression();
    bool compressionFeedbackSelected = false;
    int compressionFeedbackFrequency = 0;


    int compressionFeedbackAmountPercentage = 0;
    int bpmPerformanceState = 0;
    int evaluateBpm();
    int calculateAverageBpm();
};

#endif // COMPRESSIONFEEDBACK_H
