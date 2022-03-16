#include "FlowDataHandler.h"

FlowDataHandler::FlowDataHandler()
{


}

void FlowDataHandler::handleFlowData(std::string flowData)
{
  std::string parsedFlowData = removeFromString(flowData, "flow: ");
  //std::string cleanedFlowData = removeFromString(parsedFlowData, "\n");
  std::cout << parsedFlowData;
}


