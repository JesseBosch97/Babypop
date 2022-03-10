#ifndef FEEDBACKHANDLERBOUNDARIES_H
#define FEEDBACKHANDLERBOUNDARIES_H

enum feedBackType {NEUTRAL, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY };

class FeedbackHandlerOutput
{
public:
    virtual void giveBpmFeedback(int feedbackType) = 0;
};

class FeedbackHandlerToViewModel
{
public:
    virtual void feedbackAmountSelected(int feedbackAmount) = 0;
};


#endif // FEEDBACKHANDLERBOUNDARIES_H
