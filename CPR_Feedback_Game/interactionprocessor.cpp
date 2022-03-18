#include "interactionprocessor.h"

InteractionProcessor::InteractionProcessor()
{

}

void InteractionProcessor::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "InteractionProcessor: Time interval is " << lastTimeInterval << std::endl;
    output->handleBpmPerformance(calculateBPM(lastTimeInterval));
}

int InteractionProcessor::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    std::cout << "InteractionProcessor: BPM is " << beatsPerMinute << std::endl;
    return beatsPerMinute;
}


