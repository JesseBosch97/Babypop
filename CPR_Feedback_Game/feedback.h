#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "requestmodelboundary.h"
#include "feedbackboundary.h"
#include <QElapsedTimer>
#include <iostream>

#define DESIRED_FREQUENCY 100
#define ALLOWED_ERROR 20
#define DESIRED_REPETITIONS 30

class Feedback : public RequestModelBoundary
{
public:
    Feedback();

    FeedbackBoundary * output;

    QElapsedTimer timer;

    void compressionPerformed() override;

private:
    int compressionCount = 0;
    int lastTimeInterval = 0;
    int calculateBPM(int intervalInMs);
    int performanceState = 0;
    int checkBPM(int bpm);
    int handlePerformanceState(int count);
};

#endif // FEEDBACK_H
