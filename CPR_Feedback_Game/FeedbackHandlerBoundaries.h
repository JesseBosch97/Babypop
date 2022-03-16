#ifndef FEEDBACKHANDLERBOUNDARIES_H
#define FEEDBACKHANDLERBOUNDARIES_H

enum compressionFeedBackType {NEUTRAL, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY, CORRECT, WAY_TOO_LOW, TOO_LOW, TOO_HIGH, TOO_FAR_RIGHT, TOO_FAR_LEFT };

//enum fingerPositionFeedBackType {CORRECT, WAY_TOO_LOW, TOO_LOW, TOO_HIGH, TOO_FAR_RIGHT, TOO_FAR_LEFT};

class FeedbackHandlerOutput
{
public:
    virtual void giveBpmFeedback(int feedbackType) = 0;
    virtual void giveFingerPositionFeedback(int fingerFeedback) = 0;
};

class FeedbackHandlerToViewModel
{
public:
    virtual void feedbackAmountSelected(int feedbackAmount) = 0;
};


#endif // FEEDBACKHANDLERBOUNDARIES_H
