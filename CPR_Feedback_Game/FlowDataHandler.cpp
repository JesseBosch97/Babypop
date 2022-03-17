#include "FlowDataHandler.h"





FlowDataHandler::FlowDataHandler()
{


}

void FlowDataHandler::handleFlowData(std::string flowData)
{

  //std::cout << "FlowDataHandler: handling flow data " << flowData << std::endl;


  std::string parsedFlowData = removeFromString(flowData, "flow: ");


  float flowStrength = std::stof(parsedFlowData);


  //std::cout << "FlowDataHandler: flow strength is " << flowStrength << std::endl;

  if (flowStrength >= FLOW_THRESHOLD && !ventilationLengthTimerRunning)
  {
      flowPerformance.pauseTime = timer.restart();
      ventilationLengthTimerRunning = true;
      pauseLengthTimerRunning = false;
      flowSamples.push_back(flowStrength);
      flowPerformanceCollected = false;
  }

  else if (flowStrength >= FLOW_THRESHOLD && ventilationLengthTimerRunning)
  {
      flowSamples.push_back(flowStrength);
  }

  else if (flowStrength < FLOW_THRESHOLD && !pauseLengthTimerRunning)
  {
      flowPerformance.ventilationTime = timer.restart();
      pauseLengthTimerRunning = true;
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


