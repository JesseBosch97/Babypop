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

   if (detectString(validdata, FINGER_POSITION_HEADER))
   {
      fingerPositionFeedback->handleFingerPosition(fingerPositionDataHandler.handleData(validdata));
   }

   else if (detectString(validdata, VOLUME_IN_HEADER))
   {
      volumeDataHandler.handleVolume(validdata, VOLUME_IN_HEADER);
      ventilationFeedback->handleVolumeIn(volumeDataHandler.ventilation);
   }

   else if (detectString(validdata, VOLUME_OUT_HEADER))
   {
      volumeDataHandler.handleVolume(validdata, VOLUME_OUT_HEADER);
      ventilationFeedback->handleVolumeOut(volumeDataHandler.ventilation);
   }

   else if (detectString(validdata, HEAD_POSITION_HEADER))
   {
      headPositionDataHandler.handleHeadPosition();
      headPositionFeedback->handleHeadPosition(headPositionDataHandler.headPosition);
   }

   else if (detectString(validdata, COMPRESSION_HEADER))
   {
      std::cout << "DataHandler: received compression: " << validdata << std::endl;
      compressionDataHandler.handleCompression(validdata, COMPRESSION_HEADER);
      compressionFeedback->handleCompression(compressionDataHandler.compression);
   }




   else std::cout << "DataHandler: data not detected!" << std::endl;


}

void DataHandler::handleSimulatedData(std::string simulatedData)
{
    handleData(simulatedData);
}






