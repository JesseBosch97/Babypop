#ifndef COMPRESSIONFEEDBACK_H
#define COMPRESSIONFEEDBACK_H

#include "CprTypes.h"

class CompressionFeedback
{
public:
   virtual ~CompressionFeedback() = default;
   virtual void handleCompression(Compression compression) = 0;

   virtual void setCompressionFeedbackSelected(bool state) = 0;
    virtual void setCompressionFeedbackFrequency(int amount) = 0;
    virtual void setCompressionAmount(int amount) = 0;

    virtual void setBpmError(float percentage) = 0;
    virtual void setDepthError(float percentage) = 0;
};

#endif // COMPRESSIONFEEDBACK_H
