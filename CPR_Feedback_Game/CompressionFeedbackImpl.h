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


    void setCompressionAmount(int amount) override;
    void setCompressionFeedbackSelected(bool state) override;
    void setBpmErrorHigh(float percentage) override;
    void setBpmErrorLow(float percentage) override;
    void setDepthErrorHigh(float percentage) override;
    void setDepthErrorLow(float percentage) override;

    void handleCompression(Compression compression) override;



private:
    int compressionCount = 0;

    int bpmErrorThresholdHigh = 0;
    int bpmErrorThresholdLow = 0;
    int depthErrorThresholdHigh = 0; // unimplemented
    int depthErrorThresholdLow = 0;  // unimplemented

    int bpmAccumulatedError = 0;
    int depthAccumulatedError = 0;

    bool compressionFeedbackSelected = false;
    int compressionFeedbackAmount = 0;

    void storeCompression(Compression compression);
    uint8_t evaluateCompression();

    const int DESIRED_DEPTH = 30;
    const int DESIRED_BPM = 120;



};

#endif // COMPRESSIONFEEDBACKIMPL_H
