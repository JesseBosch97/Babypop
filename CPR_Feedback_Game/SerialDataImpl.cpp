#include "SerialDataImpl.h"

#include <algorithm>






SerialDataImpl::SerialDataImpl()
{

}


void SerialDataImpl::handleData(std::string validdata)
{
   std::vector<std::string> dataCollection;

   if (detectString(validdata, FINGER_POSITION_HEADER))
   {
       feedbackInteractor->handleFingerPosition(fingerPositionSerialData.handleData(validdata));
   }

   else if (detectString(validdata, VOLUME_IN_HEADER))
   {
       remove(validdata, VOLUME_IN_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleVolumeIn(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, VOLUME_OUT_HEADER))
   {
       remove(validdata, VOLUME_OUT_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleVolumeOut(handleVentilation(dataCollection));
   }

   else if (detectString(validdata, HEAD_POSITION_HEADER))
   {
       remove(validdata, HEAD_POSITION_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleHeadPosition(handleHeadPosition(dataCollection));
   }

   else if (detectString(validdata, COMPRESSION_HEADER))
   {
       remove(validdata, COMPRESSION_HEADER);
       dataCollection = collectData(validdata);
       feedbackInteractor->handleCompression(handleCompression(dataCollection));
   }


   else std::cout << "DataHandler: data not detected!" << std::endl;


}




std::vector<std::string> SerialDataImpl::collectData(std::string & data)
{
    std::cout << "DataHandler: received data: " << data << std::endl;

    std::vector<std::string> dataCollection;

    size_t loopAmount = countCommas(data);

    for (int i = 0; i < static_cast<int>(loopAmount); i++)
    {
        std::string nextData = copyAndRemoveNextValue(data);
        dataCollection.push_back(nextData);
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

size_t SerialDataImpl::countCommas(std::string & data)
{
    size_t amount = std::count(data.begin(), data.end(), ',');
    return amount;
}









