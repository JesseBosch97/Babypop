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
   std::vector<std::string> dataCollection;

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
      dataCollection = handleData(validdata, COMPRESSION_HEADER);
      compressionFeedback->handleCompression(compressionDataHandler.handleCompression(dataCollection));
   }




   else std::cout << "DataHandler: data not detected!" << std::endl;


}

void DataHandler::handleSimulatedData(std::string simulatedData)
{
    handleData(simulatedData);
}


std::vector<std::string> DataHandler::handleData(std::string & data, std::string header)
{
    std::cout << "CompressionDataHandler: received compression: " << data << std::endl;

    std::vector<std::string> dataCollection;

    removeFrom(data, header);

    std::string bpm = copyAndRemoveNextValue(data);
    std::string depth = data;

    dataCollection.push_back(bpm);
    dataCollection.push_back(depth);

    return dataCollection;
}







