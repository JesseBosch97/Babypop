#ifndef FEEDBACKBOUNDARY_H
#define FEEDBACKBOUNDARY_H

enum feedBackType {NEUTRAL, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY };

class FeedbackBoundary
{

public:
    virtual void giveBpmFeedback(int feedbackType) = 0;
};


#endif // FEEDBACKBOUNDARY_H
