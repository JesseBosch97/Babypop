#ifndef FEEDBACKHANDLERBOUNDARIES_H
#define FEEDBACKHANDLERBOUNDARIES_H

enum feedBackTypes {NEUTRAL, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY,
                    CORRECT, WAY_TOO_LOW, TOO_LOW, TOO_HIGH, TOO_FAR_RIGHT, TOO_FAR_LEFT,
                    VENTILATION_TOO_SHORT, VENTILATION_TOO_LONG, VENTILATION_TOO_MUCH, VENTILATION_TOO_LITTLE };

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
