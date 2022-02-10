#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;

    int bpm = calculateBPM(lastTimeInterval);
    int newPerformanceState = 0;

    if (bpm < 90){
        newPerformanceState = TOO_SLOW;
    }
    else if (bpm > 110) {
        newPerformanceState = TOO_FAST;
    }
    else {
        newPerformanceState = PERFECT;
    }


    if (newPerformanceState != performanceState){
        performanceState = newPerformanceState;
        output->giveBpmFeedback(performanceState);
    }

}

int Feedback::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    std::cout << "BPM is " << beatsPerMinute << std::endl;
    return beatsPerMinute;
}
