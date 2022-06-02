#ifndef COMPRESSIONFEEDBACKIMPL_H
#define COMPRESSIONFEEDBACKIMPL_H

#include "ViewModel.h"
#include "HeadPositionFeedback.h"
#include "SerialData.h"
#include "CompressionFeedback.h"
#include <iostream>
#include <vector>
#include "AudioPlayer.h"




class CompressionFeedbackImpl : public CompressionFeedback
{
public:
    CompressionFeedbackImpl();

    AudioPlayer * audioPlayer;


    void setCompressionAmount(int amount) override;
    void setCompressionFeedbackSelected(bool state) override;
    void setBpmErrorThreshold(float percentage) override;
    void setDepthErrorThreshold(float percentage) override;


    void handleCompression(Compression compression) override;



private:
    bool compressionFeedbackSelected = false;
    int compressionAmount = 0;

    int compressionCount = 0;
    int bpmErrorThreshold = 0;
    int depthErrorThreshold = 0;
    int bpmAccumulatedError = 0;
    int depthAccumulatedError = 0;

    void storeCompression(Compression compression);
    uint8_t evaluateCompression();

    const int DESIRED_DEPTH = 30;
    const int DESIRED_BPM = 120;

};

#endif // COMPRESSIONFEEDBACKIMPL_H
