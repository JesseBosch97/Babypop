#include "DataHandlerImpl.h"

#include <algorithm>






DataHandlerImpl::DataHandlerImpl()
{

}

DataHandlerImpl::~DataHandlerImpl()
{

}

//Volume: 36.55, 40.47, 563
//[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n


void DataHandlerImpl::handleData(std::string validdata)
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




std::vector<std::string> DataHandlerImpl::collectData(std::string & data)
{
    std::cout << "DataHandler: received data: " << data << std::endl;

    std::vector<std::string> dataCollection;

    size_t numberOfDataPoints = std::count(data.begin(), data.end(), ',');

    std::cout << "DataHandler: number of data is: " << numberOfDataPoints << std::endl;

    for (int i = 0; i < static_cast<int>(numberOfDataPoints); i++)
    {
        dataCollection.push_back(copyAndRemoveNextValue(data));
    }

    dataCollection.push_back(data); // last remaining value

    return dataCollection;
}

Compression DataHandlerImpl::handleCompression(std::vector<std::string> compressionData)
{
    Compression compression;
    compression.bpm = stoi(compressionData.at(0));
    compression.depth = stoi(compressionData.at(1));
    return compression;
}

Ventilation DataHandlerImpl::handleVentilation(std::vector<std::string> ventilationData)
{
    Ventilation ventilation;
    ventilation.volume = stof(ventilationData.at(0));
    ventilation.time = stoi(ventilationData.at(1));
    return ventilation;
}

HeadPosition DataHandlerImpl::handleHeadPosition(std::vector<std::string> headPositionData)
{
    HeadPosition headPosition;
    return headPosition;
}







