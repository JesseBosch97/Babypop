#ifndef COMPRESSIONFEEDBACKIMPL_H
#define COMPRESSIONFEEDBACKIMPL_H

#include "ViewModel.h"
#include "HeadPositionFeedback.h"
#include "DataHandler.h"
#include "CompressionFeedback.h"
#include <iostream>
#include <vector>
#include "AudioPlayer.h"

#define DESIRED_BPM 100
#define ALLOWED_ERROR 10
#define COMPRESSION_REPETITIONS 30
#define BPM_SAMPLE_AMOUNT 5 //should be const




class CompressionFeedbackImpl : public CompressionFeedback
{
public:
    CompressionFeedbackImpl();

    AudioPlayer * audioPlayer;
    ViewModel * viewModel;

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
    int calculateAverageDepth();
    int evaluateDepth();
};

#endif // COMPRESSIONFEEDBACKIMPL_H
