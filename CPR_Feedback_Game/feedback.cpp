#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;
    output->giveBpmFeedback(calculateBPM(lastTimeInterval));
}

int Feedback::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    std::cout << "BPM is " << beatsPerMinute << std::endl;
    return beatsPerMinute;
}
