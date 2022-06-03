#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H



#include <iostream>
#include <vector>
#include "CprTypes.h"





class CompressionFeedbackImpl
{
public:
    CompressionFeedbackImpl();

    void setCompressionAmount(int amount);
    void setBpmErrorThreshold(float percentage);
    void setDepthErrorThreshold(float percentage);


    uint8_t handleCompression(Compression compression);

    int compressionCount = 0;



private:
    int compressionAmount = 0;


    int bpmErrorThreshold = 0;
    int depthErrorThreshold = 0;
    int bpmAccumulatedError = 0;
    int depthAccumulatedError = 0;

    void storeCompression(Compression compression);
    uint8_t evaluateCompression();

    const int DESIRED_DEPTH = 30;
    const int DESIRED_BPM = 120;

};

#endif // COMPRESSIONFEEDBACK_H
