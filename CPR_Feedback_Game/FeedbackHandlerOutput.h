#ifndef FEEDBACKHANDLEROUTPUT_H
#define FEEDBACKHANDLEROUTPUT_H

enum feedBackType {NEUTRAL, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY };

class FeedbackHandlerOutput
{

public:
    virtual void giveBpmFeedback(int feedbackType) = 0;
};


#endif // FEEDBACKHANDLEROUTPUT_H
