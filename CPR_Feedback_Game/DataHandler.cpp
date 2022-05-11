#include "DataHandler.h"


DataHandler::DataHandler()
{

}

DataHandler::~DataHandler()
{

}

//Volume: 36.55, 40.47, 563
//[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n


void DataHandler::handleData(std::string validdata)
{

   if (detectString(validdata, "["))
   {
      //std::cout << "DataHandler: finger position detected!" << std::endl;
      fingerPositionFeedback->fingerPositionPerformance(fingerPositionDataHandler.handleData(validdata));
   }

   else if (detectString(validdata, VOLUME_IN_HEADER))
   {
      //std::cout << "DataHandler: volume in detected!" << std::endl;
      volumeDataHandler.handleVolume(validdata, VOLUME_IN_HEADER);
      ventilationFeedback->handleVolumeIn(volumeDataHandler.ventilation);
   }

   else if (detectString(validdata, VOLUME_OUT_HEADER))
   {
      //std::cout << "DataHandler: volume out detected!" << std::endl;
      volumeDataHandler.handleVolume(validdata, VOLUME_OUT_HEADER);
      ventilationFeedback->handleVolumeOut(volumeDataHandler.ventilation);
   }

   else std::cout << "DataHandler: data not detected!" << std::endl;


}






