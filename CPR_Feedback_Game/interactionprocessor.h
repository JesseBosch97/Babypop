#ifndef INTERACTIONPROCESSOR_H
#define INTERACTIONPROCESSOR_H

#include "requestmodel.h"
#include "InteractionProcessorBoundary.h"
#include <QElapsedTimer>
#include <iostream>

class InteractionProcessor : public RequestModelBoundary
{
public:
    InteractionProcessor();

    InteractionProcessorBoundary * output;

    void compressionPerformed() override;

private:
    QElapsedTimer timer;
    int compressionCount = 0;
    int lastTimeInterval = 0;
    int calculateBPM(int intervalInMs);
};

#endif // INTERACTIONPROCESSOR_H
