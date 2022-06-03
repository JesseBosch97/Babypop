#include "SerialDataImpl.h"

#include <algorithm>






SerialDataImpl::SerialDataImpl()
{

}



//Volume: 36.55, 40.47, 563
//[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n


void SerialDataImpl::handleData(std::string validdata)
{
   std::vector<std::string> dataCollection;

   if (detectString(validdata, FINGER_POSITION_HEADER))
   {
       feedbackInteractor->handleFingerPosition(fingerPositionSerialData.handleData(validdata));
   }

   else if (detectString(validdata, VOLUME_IN_HEADER))
   {
       removeFrom(validdata, VOLUME_IN_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleVolumeIn(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, VOLUME_OUT_HEADER))
   {
       removeFrom(validdata, VOLUME_OUT_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleVolumeOut(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, HEAD_POSITION_HEADER))
   {
       removeFrom(validdata, HEAD_POSITION_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleHeadPosition(handleHeadPosition(dataCollection));
   }

   else if (detectString(validdata, COMPRESSION_HEADER))
   {
       removeFrom(validdata, COMPRESSION_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleCompression(handleCompression(dataCollection));
   }


   else std::cout << "DataHandler: data not detected!" << std::endl;


}




std::vector<std::string> SerialDataImpl::collectData(std::string & data)
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

Compression SerialDataImpl::handleCompression(std::vector<std::string> compressionData)
{
    Compression compression;
    compression.bpm = stoi(compressionData.at(0));
    compression.depthInMm = stoi(compressionData.at(1));
    return compression;
}

Ventilation SerialDataImpl::handleVentilation(std::vector<std::string> ventilationData)
{
    Ventilation ventilation;
    ventilation.volumeInMl = stof(ventilationData.at(0));
    ventilation.timeInMs = stoi(ventilationData.at(1));
    return ventilation;
}

HeadPosition SerialDataImpl::handleHeadPosition(std::vector<std::string> headPositionData)
{
    HeadPosition headPosition;
    return headPosition;
}






