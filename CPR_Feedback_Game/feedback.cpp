#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::compressionPerformed()
{
    lastTimeInterval = timer.restart();
    std::cout << "time interval is " << lastTimeInterval << std::endl;

    int newPerformanceState = handlePerformanceState(compressionCount);

    compressionCount++;

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

int Feedback::checkBPM(int bpm)
{
    int bpmPerformance = NEUTRAL;

    if (bpm < DESIRED_FREQUENCY - ALLOWED_ERROR){
        bpmPerformance = TOO_SLOW;
    }
    else if (bpm > DESIRED_FREQUENCY + ALLOWED_ERROR) {
        bpmPerformance = TOO_FAST;
    }
    else {
        bpmPerformance = PERFECT;
    }
    return bpmPerformance;
}

int Feedback::handlePerformanceState(int count){
    if (count > 0){
        if (count < DESIRED_REPETITIONS){
            return checkBPM(calculateBPM(lastTimeInterval));
        }
        else return TOO_MANY;
    }
    else return NEUTRAL;
}


