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
      removeFrom(validdata, VOLUME_IN_HEADER);
      dataCollection = collectData(validdata);
      ventilationFeedback->handleVolumeIn(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, VOLUME_OUT_HEADER))
   {
       removeFrom(validdata, VOLUME_OUT_HEADER);
       dataCollection = collectData(validdata);
       ventilationFeedback->handleVolumeIn(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, HEAD_POSITION_HEADER))
   {
       removeFrom(validdata, HEAD_POSITION_HEADER);
       dataCollection = collectData(validdata);

      headPositionFeedback->handleHeadPosition(handleHeadPosition(dataCollection));
   }

   else if (detectString(validdata, COMPRESSION_HEADER))
   {
      removeFrom(validdata, COMPRESSION_HEADER);
      dataCollection = collectData(validdata);
      compressionFeedback->handleCompression(handleCompression(dataCollection));
   }


   else std::cout << "DataHandler: data not detected!" << std::endl;


}

void DataHandler::handleSimulatedData(std::string simulatedData)
{
    handleData(simulatedData);
}


std::vector<std::string> DataHandler::collectData(std::string & data)
{
    std::cout << "DataHandler: received data: " << data << std::endl;

    std::vector<std::string> dataCollection;

    dataCollection.push_back(copyAndRemoveNextValue(data));
    dataCollection.push_back(data);

    return dataCollection;
}

Compression DataHandler::handleCompression(std::vector<std::string> compressionData)
{
    Compression compression;
    compression.bpm = stoi(compressionData.at(0));
    compression.depth = stoi(compressionData.at(1));
    return compression;
}

Ventilation DataHandler::handleVentilation(std::vector<std::string> ventilationData)
{
    Ventilation ventilation;
    ventilation.volume = stof(ventilationData.at(0));
    ventilation.time = stoi(ventilationData.at(1));
    return ventilation;
}

HeadPosition DataHandler::handleHeadPosition(std::vector<std::string> headPositionData)
{
    HeadPosition headPosition;
    return headPosition;
}







