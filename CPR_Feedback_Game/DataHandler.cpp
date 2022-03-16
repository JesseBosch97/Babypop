#include "DataHandler.h"


DataHandler::DataHandler()
{

}

DataHandler::~DataHandler()
{

}
void DataHandler::handleData(std::string validdata)
{
   if (detectString(validdata, "flow:"))
   {
      std::cout << "DataHandler: flow detected!" << std::endl;
      flowDataHandler.handleFlowData(validdata);
   }

   else if (detectString(validdata, "["))
   {
      std::cout << "DataHandler: finger position detected!" << std::endl;
      fingerPositionDataHandler.handleData(validdata);
   }

   else std::cout << "DataHandler: data not detected!" << std::endl;

}






