/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H


#include <iostream>
#include <vector>
#include "CprTypes.h"


class CompressionFeedback
{
public:
    CompressionFeedback();

    FeedbackType handleCompression(Compression compression);
    int compressionCount = 0;
    int compressionAmount = 0;
    int bpmErrorThreshold = 0;
    int depthErrorThreshold = 0;

    const int DESIRED_DEPTH = 30;
    const int DESIRED_BPM = 120;

private: 
    void storeCompression(Compression compression);
    FeedbackType evaluateCompression();

    int bpmAccumulatedError = 0;
    int depthAccumulatedError = 0;
};

#endif // COMPRESSIONFEEDBACK_H
