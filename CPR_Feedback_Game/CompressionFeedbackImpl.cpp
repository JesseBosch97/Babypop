#include "CompressionFeedbackImpl.h"

CompressionFeedbackImpl::CompressionFeedbackImpl()
{

}

void CompressionFeedbackImpl::setCompressionFeedbackSelected(bool state)
{
    this->compressionFeedbackSelected = state;
    if (state == true) audioPlayer->giveFeedback(START_COMPRESSION);
    compressionCount = 0;
}

void CompressionFeedbackImpl::setBpmError(float percentage)
{
    this->allowedBpmError = DESIRED_BPM * percentage/100;
    std::cout << "CompressionFeedback: allowed bpm error is :" << this->allowedBpmError << std::endl;
}

void CompressionFeedbackImpl::setDepthError(float percentage)
{
    this->allowedDepthError = DESIRED_DEPTH * percentage/100;
    std::cout << "CompressionFeedback: allowed depth error is :" << this->allowedDepthError << std::endl;
}

void CompressionFeedbackImpl::setCompressionFeedbackFrequency(int amount)
{
    this->compressionFeedbackFrequency = amount;
   compressionCount = 0;
}

void CompressionFeedbackImpl::setCompressionAmount(int amount)
{
    this->compressionFeedbackAmount = amount;
   compressionCount = 0;
}


void CompressionFeedbackImpl::handleCompression(Compression compression)
{
    if (compressionFeedbackSelected)
    {
        compressionCount++;
        bpmBuffer.push_back(compression.bpm);
        depthBuffer.push_back(compression.depthInCm);

        uint8_t feedbackType = 0;

        if (compressionCount > compressionFeedbackAmount)
        {
            feedbackType = TOO_MANY;
        }

        else if (compressionCount % compressionFeedbackFrequency == 0){

            int averageBpm = calculateAverageBpm();
            int averageDepth = calculateAverageDepth();

            if (averageDepth > DESIRED_DEPTH  + allowedDepthError )
            {
                feedbackType = TOO_DEEP;
            }

            else if (averageDepth < DESIRED_DEPTH  - allowedDepthError )
            {
                feedbackType = TOO_SHALLOW;
            }

            else if (averageBpm < DESIRED_BPM - allowedBpmError){
                feedbackType = TOO_SLOW;
            }

            else if (averageBpm > DESIRED_BPM + allowedBpmError) {
                feedbackType = TOO_FAST;
            }

            bpmBuffer.clear();
            depthBuffer.clear();
        }

        if (feedbackType > 0) audioPlayer->giveFeedback(feedbackType);
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




