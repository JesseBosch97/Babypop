#ifndef INTERACTIONPROCESSORBOUNDARY_H
#define INTERACTIONPROCESSORBOUNDARY_H

class InteractionProcessorBoundary
{
public:
    virtual void handleBpmPerformance(int bpm) = 0;
    virtual void handleCompressionCountPerformance(int count) = 0;
};

#endif // INTERACTIONPROCESSORBOUNDARY_H
