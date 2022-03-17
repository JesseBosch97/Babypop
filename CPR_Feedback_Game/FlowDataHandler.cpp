#include "FlowDataHandler.h"

FlowDataHandler::FlowDataHandler()
{


}

int FlowDataHandler::handleFlowData(std::string flowData)
{
  std::string parsedFlowData = removeFromString(flowData, "flow: ");

  return stoi(parsedFlowData);
}


