#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "requestmodelboundary.h"
#include "feedbackboundary.h"
#include <QElapsedTimer>
#include <iostream>

class Feedback : public RequestModelBoundary
{
public:
    Feedback();

    FeedbackBoundary * output;

    QElapsedTimer timer;

    void compressionPerformed() override;

private:
    int lastTimeInterval = 0;
};

#endif // FEEDBACK_H
