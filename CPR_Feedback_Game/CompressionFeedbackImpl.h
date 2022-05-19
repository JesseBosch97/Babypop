#ifndef COMPRESSIONFEEDBACKIMPL_H
#define COMPRESSIONFEEDBACKIMPL_H

#include "ViewModel.h"
#include "HeadPositionFeedback.h"
#include "DataHandler.h"
#include "CompressionFeedback.h"
#include <iostream>
#include <vector>
#include "AudioPlayer.h"








class CompressionFeedbackImpl : public CompressionFeedback
{
public:
    CompressionFeedbackImpl();

    AudioPlayer * audioPlayer;
    ViewModel * viewModel;

    void setCompressionFeedbackFrequency(int amount) override;
    void setCompressionAmount(int amount) override;
    void setCompressionFeedbackSelected(bool state) override;
    void setBpmError(float percentage) override;
    void setDepthError(float percentage) override;


    void handleCompression(Compression compression) override;


private:
    std::vector<int> bpmBuffer;
    std::vector<int> depthBuffer;
    int compressionCount = 0;
    float allowedBpmError = 0;
    float allowedDepthError = 0;

    bool compressionFeedbackSelected = false;
    int compressionFeedbackFrequency = 0;
    int compressionFeedbackAmount = 0;

    int evaluateCompression();
    int calculateAverageBpm();
    int calculateAverageDepth();

    const float DESIRED_DEPTH = 3;
    const float DESIRED_BPM = 120;

};

#endif // COMPRESSIONFEEDBACKIMPL_H
