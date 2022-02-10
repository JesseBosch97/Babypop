#include "feedback.h"

Feedback::Feedback()
{

}

void Feedback::handleBpmPerformance(int bpm)
{
    int newBpmPerformanceState = handleBpmPerformanceState(bpm);

    if (newBpmPerformanceState != bpmPerformanceState){
        bpmPerformanceState = newBpmPerformanceState;
        output->giveBpmFeedback(bpmPerformanceState);
    }

}

void Feedback::handleCompressionCountPerformance(int count)
{
    compressionCount = count;
}


int Feedback::checkBPM(int bpm)
{
    int bpmPerformance = NEUTRAL;

    if (bpm < DESIRED_BPM - ALLOWED_ERROR){
        bpmPerformance = TOO_SLOW;
    }
    else if (bpm > DESIRED_BPM + ALLOWED_ERROR) {
        bpmPerformance = TOO_FAST;
    }
    else {
        bpmPerformance = PERFECT;
    }
    return bpmPerformance;
}

int Feedback::handleBpmPerformanceState(int bpm){
    if (compressionCount > 0){
        if (compressionCount <= DESIRED_REPETITIONS){
            return checkBPM(bpm);
        }
        else return TOO_MANY;
    }
    else return NEUTRAL;
}


