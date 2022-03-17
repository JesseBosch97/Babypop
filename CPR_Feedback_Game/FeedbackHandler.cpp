#include "FeedbackHandler.h"

FeedbackHandler::FeedbackHandler()
{

}

void FeedbackHandler::handleBpmPerformance(int bpm)
{
    storeBpmSample(bpm);


    if (compressionCount % feedbackAmount == 0){
        int newBpmPerformanceState = handleBpmPerformanceState();

        if ((PERFECT == bpmPerformanceState) == newBpmPerformanceState){
            //do nothing
        }

        else if (PERFECT == newBpmPerformanceState){
            bpmPerformanceState = newBpmPerformanceState;
            output->giveFeedback(bpmPerformanceState);
        }

        else {
            bpmPerformanceState = newBpmPerformanceState;
            output->giveFeedback(bpmPerformanceState);
        }
    }

}

void FeedbackHandler::handleCompressionCountPerformance(int count)
{
    compressionCount = count;
}

void FeedbackHandler::handleFlowPerformance(FlowPerformance flowPerformance)
{
    std::cout << "FeedbackHandler: average flow strength is " << flowPerformance.averageFlowStrength << std::endl;
    std::cout << "FeedbackHandler: pause time is " << flowPerformance.pauseTime << std::endl;
    std::cout << "FeedbackHandler: ventilation time is " << flowPerformance.ventilationTime << std::endl;


    if (flowPerformance.averageFlowStrength <= DESIRED_FLOW_STRENGTH - FLOW_STRENGTH_ALLOWED_ERROR)
    {
        output->giveFeedback(VENTILATION_TOO_LITTLE);
    }

    else if (flowPerformance.averageFlowStrength > DESIRED_FLOW_STRENGTH + FLOW_STRENGTH_ALLOWED_ERROR)
    {
        output->giveFeedback(VENTILATION_TOO_MUCH);
    }

    else if (flowPerformance.ventilationTime <= DESIRED_VENTILATION_TIME_MS - VENTILATION_TIME_ALLOWED_ERROR)
    {
        output->giveFeedback(VENTILATION_TOO_SHORT);
    }

    else if (flowPerformance.ventilationTime > DESIRED_VENTILATION_TIME_MS + VENTILATION_TIME_ALLOWED_ERROR)
    {
        output->giveFeedback(VENTILATION_TOO_LONG);
    }

    else if (flowPerformance.pauseTime <= DESIRED_PAUSE_TIME_MS - PAUSE_TIME_ALLOWED_ERROR)
    {
        output->giveFeedback(PAUSE_TOO_SHORT);
    }

    else if (flowPerformance.pauseTime > DESIRED_PAUSE_TIME_MS + PAUSE_TIME_ALLOWED_ERROR)
    {
        output->giveFeedback(PAUSE_TOO_LONG);
    }

}



void FeedbackHandler::compressionFeedbackAmountSelected(float amount)
{
    if (this->feedbackAmountPercentage != int(amount))
    {
        this->feedbackAmountPercentage = int(amount);
        std::cout << "Feedback Handler: feedBackAmountPercentage changed to: " << this->feedbackAmountPercentage << std::endl;

        this->feedbackAmount = DESIRED_REPETITIONS - int((DESIRED_REPETITIONS * (this->feedbackAmountPercentage*0.01))) + 1;
        std::cout << "Feedback Handler: feedBackAmount changed to: " << this->feedbackAmount << std::endl;

        viewModel->feedbackAmountSelected(this->feedbackAmountPercentage);
    }
}

void FeedbackHandler::fingerPositionPerformance(Fingerposition positionOfFingers)
{
    int fingerPositionPerformance = CORRECT;

    if (positionOfFingers.bottom > 200)
    {
        fingerPositionPerformance = WAY_TOO_LOW;
    }
    if (positionOfFingers.lowmid > 200)
    {
        fingerPositionPerformance = TOO_LOW;
    }
    if (positionOfFingers.top > 200)
    {
        fingerPositionPerformance = TOO_HIGH;
    }
    if (positionOfFingers.bottomright > 200)
    {
        fingerPositionPerformance = TOO_FAR_RIGHT;
    }
    if (positionOfFingers.mid > 200)
    {
        fingerPositionPerformance = PERFECT;
    }
    if (positionOfFingers.topright > 200)
    {
        fingerPositionPerformance = TOO_FAR_RIGHT;
    }
    if (positionOfFingers.topleft > 200)
    {
        fingerPositionPerformance = TOO_FAR_LEFT;
    }
    if (positionOfFingers.bottomleft > 200)
    {
        fingerPositionPerformance = TOO_FAR_LEFT;
    }

    output->giveFingerPositionFeedback(fingerPositionPerformance);
    //std::cout << positionOfFingers.bottom << std::endl;
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
    for (int i=BPM_SAMPLE_AMOUNT-1; i>0; i--) {  //should be dynamic array
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




