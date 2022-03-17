#include "DataHandler.h"


DataHandler::DataHandler()
{

}

DataHandler::~DataHandler()
{

}

void DataHandler::handleData(std::string validdata)
{

   if (detectString(validdata, "flow:") && validdata.length() < 14)
   {
      //std::cout << "DataHandler: flow detected!" << std::endl;
      flowDataHandler.handleFlowData(validdata);
      if (flowDataHandler.flowPerformanceCollected){
          flowDataHandler.flowPerformanceCollected = false;
          feedback->handleFlowPerformance(flowDataHandler.flowPerformance);
      }

   }

   else if (detectString(validdata, "["))
   {
      //std::cout << "DataHandler: finger position detected!" << std::endl;
      feedback->fingerPositionPerformance(fingerPositionDataHandler.handleData(validdata));
   }

   else std::cout << "DataHandler: data not detected!" << std::endl;


}






