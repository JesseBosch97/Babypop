#ifndef INTERACTIONPROCESSOR_H
#define INTERACTIONPROCESSOR_H

#include "RequestModelBoundaries.h"
#include "DataHandlerBoundaries.h"
#include <QElapsedTimer>
#include <iostream>

class InteractionProcessor : public RequestModelToInteractionProcessor
{
public:
    InteractionProcessor();

    DataToCompressionFeedback * output;

    void compressionPerformed() override;


private:
    QElapsedTimer timer;
    int compressionCount = 0;
    int lastTimeInterval = 0;
    int calculateBPM(int intervalInMs);
};

#endif // INTERACTIONPROCESSOR_H
