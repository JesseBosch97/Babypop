#include "FeedbackHandler.h"

FeedbackHandler::FeedbackHandler()
{

}

void FeedbackHandler::handleBpmPerformance(int bpm)
{
    storeBpmSample(bpm);

    if (compressionCount % FEEDBACK_FREQUENCY == 0){
        int newBpmPerformanceState = handleBpmPerformanceState();

        if (PERFECT == bpmPerformanceState == newBpmPerformanceState){
            //do nothing
        }
        else {
            bpmPerformanceState = newBpmPerformanceState;
            output->giveBpmFeedback(bpmPerformanceState);
        }
    }
}

void FeedbackHandler::handleCompressionCountPerformance(int count)
{
    compressionCount = count;
}


int FeedbackHandler::checkBPM()
{
    int bpmPerformance = NEUTRAL;

    if (averageBpm() < DESIRED_BPM - ALLOWED_ERROR){
        bpmPerformance = TOO_SLOW;
    }
    else if (averageBpm() > DESIRED_BPM + ALLOWED_ERROR) {
        bpmPerformance = TOO_FAST;
    }
    else {
        bpmPerformance = PERFECT;
    }
    return bpmPerformance;
}

int FeedbackHandler::handleBpmPerformanceState()
{
    if (compressionCount < DESIRED_REPETITIONS){
        return checkBPM();
    }
    else return TOO_MANY;
}

void FeedbackHandler::storeBpmSample(int bpm)
{
    for (int i=BPM_SAMPLE_AMOUNT-1; i>0; i--) {
        bpmSamples[i] = bpmSamples[i-1];
    }
    bpmSamples[0] = bpm;
}

int FeedbackHandler::averageBpm()
{
    int total = 0;
    int count = 0;
    for (int bpm: bpmSamples){
        total += bpm;
        count++;
    }

    int average = total/count;
    std::cout << "Feedback Handler: Average bpm is: " << average << std::endl;
    return total/count;
}




