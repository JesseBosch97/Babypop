#include "CompressionFeedbackImpl.h"

CompressionFeedbackImpl::CompressionFeedbackImpl()
{

}


void CompressionFeedbackImpl::handleCompression(Compression compression)
{
    if (compressionFeedbackSelected)
    {
        compressionCount++;
        bpmBuffer.push_back(compression.bpm);
        depthBuffer.push_back(compression.depth);

        if (compressionCount % compressionFeedbackFrequency == 0){
            int newBpmPerformanceState = evaluateCompression();

            if ((PERFECT == bpmPerformanceState) == newBpmPerformanceState){
                //do nothing
            }

            else if (PERFECT == newBpmPerformanceState){
                bpmPerformanceState = newBpmPerformanceState;
                audioPlayer->giveFeedback(bpmPerformanceState);
            }

            else {
                bpmPerformanceState = newBpmPerformanceState;
                audioPlayer->giveFeedback(bpmPerformanceState);
            }
        }
    }
}


void CompressionFeedbackImpl::setCompressionFeedbackSelected(bool state)
{
    this->compressionFeedbackSelected = state;
   if (state == true) audioPlayer->giveFeedback(START_COMPRESSION);
}


void CompressionFeedbackImpl::setCompressionFeedbackAmountSelection(float amount)
{
    if (this->compressionFeedbackAmountPercentage != int(amount))
    {
        this->compressionFeedbackAmountPercentage = int(amount);
        std::cout << "Feedback Handler: compressionFeedBackAmountPercentage changed to: " << this->compressionFeedbackAmountPercentage << std::endl;

        this->compressionFeedbackFrequency = COMPRESSION_REPETITIONS - int((COMPRESSION_REPETITIONS * (this->compressionFeedbackAmountPercentage*0.01))) + 1;
        std::cout << "Feedback Handler: compressionFeedbackAmount changed to: " << this->compressionFeedbackFrequency << std::endl;
    }
}


int CompressionFeedbackImpl::evaluateBpm()
{
    int bpmPerformance = NEUTRAL;
    int averageBpm = calculateAverageBpm();

    if (averageBpm < DESIRED_BPM - ALLOWED_ERROR){
        bpmPerformance = TOO_SLOW;
    }
    else if (averageBpm > DESIRED_BPM + ALLOWED_ERROR) {
        bpmPerformance = TOO_FAST;
    }
    else {
        bpmPerformance = PERFECT;
    }

    bpmBuffer.clear();

    return bpmPerformance;
}

int CompressionFeedbackImpl::evaluateDepth()
{
    int depthPerformance = NEUTRAL;
    int averageDepth = calculateAverageDepth();

//    if (averageBpm < DESIRED_BPM - ALLOWED_ERROR){
//        depthPerformance = TOO_SLOW;
//    }
//    else if (averageBpm > DESIRED_BPM + ALLOWED_ERROR) {
//        depthPerformance = TOO_FAST;
//    }
//    else {
//        depthPerformance = PERFECT;
//    }

    bpmBuffer.clear();

    return depthPerformance;
}

int CompressionFeedbackImpl::evaluateCompression()
{
    if (compressionCount < COMPRESSION_REPETITIONS){
        return evaluateBpm();
    }
    else {
        compressionCount = 0;
        return TOO_MANY;
    }
}


int CompressionFeedbackImpl::calculateAverageBpm()
{
    int total = 0;
    for (auto & el : bpmBuffer)
    {
        total += el;
    }

    return total/bpmBuffer.size();
}

int CompressionFeedbackImpl::calculateAverageDepth()
{
    int total = 0;
    for (auto & el : depthBuffer)
    {
        total += el;
    }

    return total/depthBuffer.size();
}



