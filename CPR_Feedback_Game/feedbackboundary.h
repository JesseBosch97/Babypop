#ifndef FEEDBACKBOUNDARY_H
#define FEEDBACKBOUNDARY_H

enum feedBackType { PERFECT, TOO_SLOW, TOO_FAST };

class FeedbackBoundary
{

public:
    virtual void giveBpmFeedback(int feedbackType) = 0;
};


#endif // FEEDBACKBOUNDARY_H
