#include "FlowDataHandler.h"





FlowDataHandler::FlowDataHandler()
{


}

void FlowDataHandler::handleFlowData(std::string flowData)
{
  std::string parsedFlowData = removeFromString(flowData, "flow: ");

  std::cout << parsedFlowData << std::endl;

  float flowStrength = std::stof(parsedFlowData);

  if (flowStrength >= FLOW_THRESHOLD && !ventilationLengthTimerRunning)
  {
      flowPerformance.pauseTime = timer.restart();
      ventilationLengthTimerRunning = true;
      flowSamples.push_back(flowStrength);
      flowPerformanceCollected = false;
  }

  else if (ventilationLengthTimerRunning)
  {

      if (flowStrength >= FLOW_THRESHOLD)
      {
          flowSamples.push_back(flowStrength);
      }

      else
      {
          flowPerformance.ventilationTime = timer.restart();
          ventilationLengthTimerRunning = false;

          for (unsigned long long i = 0; i<flowSamples.size(); i++)
          {
              this->sampleTotal += flowSamples.at(i);
          }

          if (flowSamples.size() > 0)
          {
              flowPerformance.averageFlowStrength = sampleTotal / flowSamples.size();
              flowPerformanceCollected = true;
          }

          sampleTotal = 0;
          flowSamples.clear();
      }
  }
}


