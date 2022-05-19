#ifndef HEADPOSITIONFEEDBACK_H
#define HEADPOSITIONFEEDBACK_H

#include "CprTypes.h"


class HeadPositionFeedback
{
public:
   virtual ~HeadPositionFeedback() = default;
    virtual void handleHeadPosition(HeadPosition headPosition) = 0;
};

#endif // HEADPOSITIONFEEDBACK_H
