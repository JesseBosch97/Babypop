#include "FeedbackHandler.h"

FeedbackHandler::FeedbackHandler()
{

}

void FeedbackHandler::handleBpmPerformance(int bpm)
{
    int newBpmPerformanceState = handleBpmPerformanceState(bpm);

    if (newBpmPerformanceState != bpmPerformanceState){
        bpmPerformanceState = newBpmPerformanceState;
        output->giveBpmFeedback(bpmPerformanceState);
    }

}

void FeedbackHandler::handleCompressionCountPerformance(int count)
{
    compressionCount = count;
}


int FeedbackHandler::checkBPM(int bpm)
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

int FeedbackHandler::handleBpmPerformanceState(int bpm){
    if (compressionCount > 1){
        if (compressionCount <= DESIRED_REPETITIONS){
            return checkBPM(bpm);
        }
        else return TOO_MANY;
    }
    else return NEUTRAL;
}


