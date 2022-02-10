#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;

    if (compressionCount > 0){
        int newPerformanceState = handlePerformanceState(compressionCount);

        if (newPerformanceState != performanceState){
            performanceState = newPerformanceState;
            output->giveBpmFeedback(performanceState);
        }
    }
    compressionCount++;
}

int Feedback::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    std::cout << "BPM is " << beatsPerMinute << std::endl;
    return beatsPerMinute;
}

int Feedback::checkBPM(int bpm)
{
    int bpmPerformance = NEUTRAL;

    if (bpm < 90){
        bpmPerformance = TOO_SLOW;
    }
    else if (bpm > 110) {
        bpmPerformance = TOO_FAST;
    }
    else {
        bpmPerformance = PERFECT;
    }
    return bpmPerformance;
}

int Feedback::handlePerformanceState(int count){
    if (count < 31){
        return checkBPM(calculateBPM(lastTimeInterval));
    }
    else return TOO_MANY;
}


