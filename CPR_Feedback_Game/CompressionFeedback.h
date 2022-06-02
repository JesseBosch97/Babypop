#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H

#include "CprTypes.h"

class CompressionFeedback
{
public:
   virtual ~CompressionFeedback() = default;
   virtual void handleCompression(Compression compression) = 0;

   virtual void setCompressionFeedbackSelected(bool state) = 0;
    virtual void setCompressionAmount(int amount) = 0;

    virtual void setBpmErrorHigh(float percentage) = 0;
   virtual void setBpmErrorLow(float percentage) = 0;

    virtual void setDepthErrorHigh(float percentage) = 0;
   virtual void setDepthErrorLow(float percentage) = 0;
};

#endif // COMPRESSIONFEEDBACK_H
