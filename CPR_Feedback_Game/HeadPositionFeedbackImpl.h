#ifndef HEADPOSITIONFEEDBACKIMPL_H
#define HEADPOSITIONFEEDBACKIMPL_H

#include "HeadPositionFeedback.h"

class HeadPositionFeedbackImpl : public HeadPositionFeedback
{
public:
    HeadPositionFeedbackImpl();

    void handleHeadPosition(HeadPosition headPosition) override;
};

#endif // HEADPOSITIONFEEDBACKIMPL_H
