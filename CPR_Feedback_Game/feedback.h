#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "requestmodelboundary.h"
#include <QElapsedTimer>
#include <iostream>

class Feedback : public RequestModelBoundary
{
public:
    Feedback();

    QElapsedTimer timer;

    void compressionPerformed() override;

private:
    int lastTimeInterval = 0;
};

#endif // FEEDBACK_H
