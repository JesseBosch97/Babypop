#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H

#include "CprTypes.h"

class CompressionFeedback
{
public:
   virtual void handleCompression(Compression compression) = 0;
   virtual void setCompressionFeedbackAmountSelection(float amount) = 0;
   virtual void setCompressionFeedbackSelected(bool state) = 0;
};

#endif // COMPRESSIONFEEDBACK_H
