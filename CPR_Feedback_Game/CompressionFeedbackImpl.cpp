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

void CompressionFeedbackImpl::setBpmErrorHigh(float percentage)
{
    this->bpmErrorThresholdHigh = DESIRED_BPM * percentage/100;
    std::cout << "CompressionFeedback: allowed bpm error high is :" << this->bpmErrorThresholdHigh << std::endl;
}

void CompressionFeedbackImpl::setBpmErrorLow(float percentage)
{
    this->bpmErrorThresholdLow = -(DESIRED_BPM * percentage/100);
    std::cout << "CompressionFeedback: allowed bpm error low is :" << this->bpmErrorThresholdLow << std::endl;
}

void CompressionFeedbackImpl::setDepthErrorHigh(float percentage)
{
    this->depthErrorThresholdHigh = DESIRED_DEPTH * percentage/100;
    std::cout << "CompressionFeedback: allowed depth error high is :" << this->depthErrorThresholdHigh << std::endl;
}

void CompressionFeedbackImpl::setDepthErrorLow(float percentage)
{
    this->depthErrorThresholdLow = -DESIRED_DEPTH * percentage/100;
    std::cout << "CompressionFeedback: allowed depth error low is :" << this->depthErrorThresholdLow << std::endl;
}


void CompressionFeedbackImpl::setCompressionAmount(int amount)
{
    this->compressionFeedbackAmount = amount;
   compressionCount = 0;
}

//6 to 8 ml per kg

void CompressionFeedbackImpl::handleCompression(Compression compression)
{
   if (compressionFeedbackSelected)
   {
      storeCompression(compression);
      audioPlayer->giveFeedback(evaluateCompression());
   }

}


void CompressionFeedbackImpl::storeCompression(Compression compression)
{
   if (compression.bpm && compression.depthInMm)
   {
      compressionCount++;
      bpmAccumulatedError += compression.bpm - DESIRED_BPM;
      depthAccumulatedError += compression.depthInMm - DESIRED_DEPTH;

      std::cout << "CompressionFeedback: bpm is: " << compression.bpm << std::endl;
      std::cout << "CompressionFeedback: accumulated bpm error is: " << bpmAccumulatedError << std::endl;
   }
}

uint8_t CompressionFeedbackImpl::evaluateCompression()
{
   uint8_t feedbackType = 0;

   if (compressionCount > compressionFeedbackAmount)
   {
      feedbackType = TOO_MANY;
   }

//   else if (depthAccumulatedError > depthErrorThresholdHigh)
//   {
//      feedbackType = TOO_DEEP;
//      depthAccumulatedError = 0;
//   }

//   else if (depthAccumulatedError < depthErrorThresholdLow)
//   {
//      feedbackType = TOO_SHALLOW;
//      depthAccumulatedError = 0;
//   }

   else if (bpmAccumulatedError > bpmErrorThresholdHigh)
   {
      feedbackType = TOO_FAST;
      bpmAccumulatedError = 0;
   }

   else if (bpmAccumulatedError < bpmErrorThresholdLow)
   {
      feedbackType = TOO_SLOW;
      bpmAccumulatedError = 0;
   }

   return feedbackType;

}






