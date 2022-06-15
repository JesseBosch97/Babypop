#include "CompressionFeedback.h"

CompressionFeedback::CompressionFeedback()
{

}



FeedbackType CompressionFeedback::handleCompression(Compression compression)
{
    uint8_t feedbackType = 0;
    storeCompression(compression);
    feedbackType = evaluateCompression();
    return feedbackType;
}


void CompressionFeedback::storeCompression(Compression compression)
{
   if (compression.bpm && compression.depthInMm)
   {
      compressionCount++;
      bpmAccumulatedError += compression.bpm - DESIRED_BPM;
      depthAccumulatedError += compression.depthInMm - DESIRED_DEPTH;

      std::cout << "CompressionFeedback: bpm is: " << compression.bpm << std::endl;
      std::cout << "CompressionFeedback: accumulated bpm error is: " << bpmAccumulatedError << std::endl;
      std::cout << "CompressionFeedback: accumulated depth error is: " << depthAccumulatedError << std::endl;
   }
}

FeedbackType CompressionFeedback::evaluateCompression()
{
   uint8_t feedbackType = 0;

   if (compressionCount > compressionAmount)
   {
      feedbackType = TOO_MANY;
   }

   else if (depthAccumulatedError > depthErrorThreshold)
   {
      feedbackType = TOO_DEEP;
      depthAccumulatedError = 0;
   }

   else if (depthAccumulatedError < -depthErrorThreshold)
   {
      feedbackType = TOO_SHALLOW;
      depthAccumulatedError = 0;
   }

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






