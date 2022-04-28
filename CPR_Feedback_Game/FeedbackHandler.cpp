#include "FeedbackHandler.h"

FeedbackHandler::FeedbackHandler()
{

}

void FeedbackHandler::handleBpmPerformance(int bpm)
{
    if (compressionFeedbackSelected)
    {
        compressionCount++;
        storeBpmSample(bpm);

        if (compressionCount % compressionFeedbackAmount == 0){
            int newBpmPerformanceState = handleBpmPerformanceState();

            if ((PERFECT == bpmPerformanceState) == newBpmPerformanceState){
                //do nothing
            }

            else if (PERFECT == newBpmPerformanceState){
                bpmPerformanceState = newBpmPerformanceState;
                audioPlayer->giveFeedback(bpmPerformanceState);
            }

            else {
                bpmPerformanceState = newBpmPerformanceState;
                audioPlayer->giveFeedback(bpmPerformanceState);
            }
        }
    }
}


void FeedbackHandler::handleFlowPerformance(FlowPerformance flowPerformance)
{
    std::cout << "FeedbackHandler: average flow strength is " << flowPerformance.averageFlowStrength << std::endl;
    std::cout << "FeedbackHandler: max flow strength is " << flowPerformance.maxFlowStrength << std::endl;
    std::cout << "FeedbackHandler: pause time is " << flowPerformance.pauseTime << std::endl;
    std::cout << "FeedbackHandler: ventilation time is " << flowPerformance.ventilationTime << std::endl;

    if (ventilationFeedbackSelected){

        ventilationCount++;

        if (ventilationCount % ventilationFeedbackFrequency == 0)
        {
            if (flowPerformance.maxFlowStrength <= FLOW_STRENGTH_MIN - FLOW_STRENGTH_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_LITTLE);
            }

            else if (flowPerformance.maxFlowStrength > FLOW_STRENGHT_MAX + FLOW_STRENGTH_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_MUCH);
            }

//            else if (flowPerformance.ventilationTime <= DESIRED_VENTILATION_TIME_MS - VENTILATION_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(VENTILATION_TOO_SHORT);
//            }

//            else if (flowPerformance.ventilationTime > DESIRED_VENTILATION_TIME_MS + VENTILATION_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(VENTILATION_TOO_LONG);
//            }

            else if (flowPerformance.pauseTime > DESIRED_PAUSE_TIME_MS + PAUSE_TIME_ALLOWED_ERROR)
            {
                audioPlayer->giveFeedback(PAUSE_TOO_LONG);
            }

//            else if (flowPerformance.pauseTime <= DESIRED_PAUSE_TIME_MS - PAUSE_TIME_ALLOWED_ERROR)
//            {
//                output->giveFeedback(PAUSE_TOO_SHORT);
//            }


        }
    }
}

void FeedbackHandler::setCompressionFeedbackSelected(bool state)
{
    this->compressionFeedbackSelected = state;
   if (state == true) audioPlayer->giveFeedback(START_COMPRESSION);
}

void FeedbackHandler::setVentilationFeedbackSelected(bool state)
{
    this->ventilationFeedbackSelected = state;
    if (state == true) audioPlayer->giveFeedback(START_VENTILATION);
}



void FeedbackHandler::setCompressionFeedbackAmountSelection(float amount)
{
    if (this->compressionFeedbackAmountPercentage != int(amount))
    {
        this->compressionFeedbackAmountPercentage = int(amount);
        std::cout << "Feedback Handler: compressionFeedBackAmountPercentage changed to: " << this->compressionFeedbackAmountPercentage << std::endl;

        this->compressionFeedbackAmount = COMPRESSION_REPETITIONS - int((COMPRESSION_REPETITIONS * (this->compressionFeedbackAmountPercentage*0.01))) + 1;
        std::cout << "Feedback Handler: compressionFeedbackAmount changed to: " << this->compressionFeedbackAmount << std::endl;
    }
}

void FeedbackHandler::setVentilationFeedbackFrequency(int amount)
{
    this->ventilationFeedbackFrequency = amount;
//    if (this->ventilationFeedbackAmountPercentage != int(amount))
//    {
//        this->ventilationFeedbackAmountPercentage = int(amount);
//        std::cout << "Feedback Handler: ventilationFeedBackAmountPercentage changed to: " << this->ventilationFeedbackAmountPercentage << std::endl;

//        this->ventilationFeedbackAmount = VENTILATION_REPETITIONS - int((VENTILATION_REPETITIONS * (this->ventilationFeedbackAmountPercentage*0.01))) + 1;
//        std::cout << "Feedback Handler: ventilationFeedBackAmount changed to: " << this->ventilationFeedbackAmount << std::endl;
//    }
}



void FeedbackHandler::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
}

void FeedbackHandler::fingerPositionPerformance(Fingerposition positionOfFingers)
{
    int fingerPositionPerformance = CORRECT;

    //enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};
    if(pressurePoints(positionOfFingers) < 3)
    {
        switch(locationOfFingers(positionOfFingers))
        {
        case UP_LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            break;
        case UP:
            fingerPositionPerformance = TOO_HIGH;
            break;
        case UP_RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            break;
        case LEFT:
            fingerPositionPerformance = TOO_FAR_LEFT;
            break;
        case MID:
            fingerPositionPerformance = CORRECT;
            break;
        case RIGHT:
            fingerPositionPerformance = TOO_FAR_RIGHT;
            break;
        case BOTTOM_LEFT:
            fingerPositionPerformance = TOO_LOW;
            break;
        case LOW:
            fingerPositionPerformance = TOO_LOW;
            break;
        case BOTTOM_RIGHT:
            fingerPositionPerformance = TOO_LOW;
            break;

        }
    }
    else
    {
        fingerPositionPerformance = TOO_MANY_PRESSURE_POINTS;
    }

    audioPlayer->giveFingerPositionFeedback(fingerPositionPerformance);
}

void FeedbackHandler::handleVolumeInPerformance(VolumePerformance performance)
{
    if (ventilationFeedbackSelected)
    {
        std::cout << "FeedbackHandler: volume in is " << performance.volume << std::endl;
        std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;

        ventilationCount++;

        if (ventilationCount > ventilationAmount)
        {
            audioPlayer->giveFeedback(TOO_MANY);
        }

        else
        {
            if (performance.volume < VOLUME_MIN)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_LITTLE);
            }
            else if (performance.volume > VOLUME_MAX)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_MUCH);
            }

            else if (performance.time > VENTILATION_TIME_MAX)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_LONG);
            }

            else if (performance.time < VENTILATION_TIME_MIN)
            {
                audioPlayer->giveFeedback(VENTILATION_TOO_SHORT);
            }
        }
    }
}

void FeedbackHandler::handleVolumeOutPerformance(VolumePerformance performance)
{
    if (ventilationFeedbackSelected)
    {
        std::cout << "FeedbackHandler: volume out is " << performance.volume << std::endl;
        std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;
    }
}

location FeedbackHandler::locationOfFingers(Fingerposition positionOfFingers)
{
    Coordinates bottomLeft;
    bottomLeft.x = -1 * positionOfFingers.bottomleft;
    bottomLeft.y = -1 * positionOfFingers.bottomleft;

    Coordinates topLeft;
    topLeft.x = -1 * positionOfFingers.topleft;
    topLeft.y = 1 * positionOfFingers.topleft;

    Coordinates topRight;
    topRight.x = 1 * positionOfFingers.topright;
    topRight.y = 1 * positionOfFingers.topright;

    Coordinates mid;
    mid.x = 0 * positionOfFingers.mid;
    mid.y = 0 * positionOfFingers.mid;

    Coordinates bottomRight;
    bottomRight.x = 1 * positionOfFingers.bottomright;
    bottomRight.y = -1 * positionOfFingers.bottomright;

    Coordinates top;
    top.x = 0 * positionOfFingers.top;
    top.y = 1 * positionOfFingers.top;

    Coordinates lowmid;
    lowmid.x = 0 * positionOfFingers.lowmid;
    lowmid.y = -1 * positionOfFingers.lowmid;

    Coordinates thorax;
    thorax.x = 0;
    thorax.y = 0;




    thorax.x = ((bottomLeft.x + topLeft.x + topRight.x + mid.x + bottomRight.x + top.x + lowmid.x) / 4);
    thorax.y = ((bottomLeft.y + topLeft.y + topRight.y + mid.y + bottomRight.y + top.y + lowmid.y) / 6);

    return calculateLocation(thorax);
}

location FeedbackHandler::calculateLocation(Coordinates thorax)
{
    location retval;
    bool up = 0;
    bool midy = 0;
    bool low = 0;
    bool left = 0;
    bool midx = 0;
    bool right = 0;

    if(30 < thorax.y && thorax.y <= 100)
    {
        up = 1;
    }
    if(-30 <= thorax.y && thorax.y <= 30)
    {
        midy = 1;
    }
    if(-100 <= thorax.y && thorax.y < -30)
    {
        low = 1;
    }
    if(-100 <= thorax.x && thorax.x < -30)
    {
        left = 1;
    }
    if(-30 <= thorax.x && thorax.x <= 30)
    {
        midx = 1;
    }
    if(30 < thorax.x && thorax.x <= 100)
    {
        right = 1;
    }


    if(up && left)
    {
        retval = UP_LEFT;
    }
    if(up && midx)
    {
        retval = UP;
    }
    if(up && right)
    {
        retval = UP_RIGHT;
    }
    if(midy && left)
    {
        retval = LEFT;
    }
    if(midy && midx)
    {
        retval = MID;
    }
    if(midy && right)
    {
        retval = RIGHT;
    }
    if(low && left)
    {
        retval = BOTTOM_LEFT;
    }
    if(low && midx)
    {
        retval = LOW;
    }
    if(low && right)
    {
        retval = BOTTOM_RIGHT;
    }

    return retval;
}

int FeedbackHandler::pressurePoints(Fingerposition positionOfFingers)
{
    int pressurePoints = 0;

    if(positionOfFingers.lowmid > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.mid > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.top > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottomleft > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottomright > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.topleft > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.topright > 150)
    {
        pressurePoints++;
    }
    if(positionOfFingers.bottom > 150)
    {
        pressurePoints++;
    }

    return pressurePoints;
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
    if (compressionCount < COMPRESSION_REPETITIONS){
        return checkBPM();
    }
    else {
        compressionCount = 0;
        return TOO_MANY;
    }
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




