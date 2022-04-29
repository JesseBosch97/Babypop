#include "VentilationFeedback.h"

VentilationFeedback::VentilationFeedback()
{

}





void VentilationFeedback::handleVolumeInPerformance(VolumePerformance performance)
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

void VentilationFeedback::handleVolumeOutPerformance(VolumePerformance performance)
{
    if (ventilationFeedbackSelected)
    {
        std::cout << "FeedbackHandler: volume out is " << performance.volume << std::endl;
        std::cout << "FeedbackHandler: ventilation time is " << performance.time << std::endl;
    }
}

void VentilationFeedback::handleFlowPerformance(FlowPerformance flowPerformance)
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


void VentilationFeedback::setVentilationFeedbackSelected(bool state)
{
    this->ventilationFeedbackSelected = state;
    if (state == true) audioPlayer->giveFeedback(START_VENTILATION);
}

void VentilationFeedback::setVentilationFeedbackFrequency(int amount)
{
    this->ventilationFeedbackFrequency = amount;
}

void VentilationFeedback::setVentilationAmount(int amount)
{
    this->ventilationAmount = amount;
}
