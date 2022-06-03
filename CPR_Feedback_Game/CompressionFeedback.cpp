#include "CompressionFeedback.h"

CompressionFeedbackImpl::CompressionFeedbackImpl()
{

}



void CompressionFeedbackImpl::setBpmErrorThreshold(float percentage)
{
    this->bpmErrorThreshold = DESIRED_BPM * percentage/100;
    std::cout << "CompressionFeedback: allowed bpm error high is :" << this->bpmErrorThreshold << std::endl;
}


void CompressionFeedbackImpl::setDepthErrorThreshold(float percentage)
{
    this->depthErrorThreshold = DESIRED_DEPTH * percentage/100;
    std::cout << "CompressionFeedback: allowed depth error high is :" << this->depthErrorThreshold << std::endl;
}


void CompressionFeedbackImpl::setCompressionAmount(int amount)
{
    this->compressionAmount = amount;
   compressionCount = 0;
}



uint8_t CompressionFeedbackImpl::handleCompression(Compression compression)
{
    uint8_t feedbackType = 0;
    storeCompression(compression);
    feedbackType = evaluateCompression();
    return feedbackType;
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

   if (compressionCount > compressionAmount)
   {
      feedbackType = TOO_MANY;
   }

//   else if (depthAccumulatedError > depthErrorThreshold)
//   {
//      feedbackType = TOO_DEEP;
//      depthAccumulatedError = 0;
//   }

//   else if (depthAccumulatedError < -depthErrorThreshold)
//   {
//      feedbackType = TOO_SHALLOW;
//      depthAccumulatedError = 0;
//   }

   else if (bpmAccumulatedError > bpmErrorThreshold)
   {
      feedbackType = TOO_FAST;
      bpmAccumulatedError = 0;
   }

   else if (bpmAccumulatedError < -bpmErrorThreshold)
   {
      feedbackType = TOO_SLOW;
      bpmAccumulatedError = 0;
   }

   return feedbackType;

}






