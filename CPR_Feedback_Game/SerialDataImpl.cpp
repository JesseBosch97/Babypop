#include "SerialDataImpl.h"


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
    std::vector<std::size_t> startLocations = findDataValueStartLocations(data, SEPARATION_CHARACTER);
    size_t loopAmount = startLocations.size();
    std::vector<std::string> dataCollection;

    for (int i = 0; i < static_cast<int>(loopAmount); i++)
    {
        std::string nextData = copyDataValue(data, startLocations.at(i));
        dataCollection.push_back(nextData);
    }

    return dataCollection;
}


std::vector<std::size_t> SerialDataImpl::findDataValueStartLocations(std::string & data, std::string separationCharacters)
{
    std::vector<std::size_t> startLocations = findCharacterLocations(data, separationCharacters);

    for (auto & el : startLocations)
    {
        el += separationCharacters.size();
    }

    startLocations.insert(startLocations.begin(), 0);
    return startLocations;
}


std::string SerialDataImpl::copyDataValue(std::string & data, std::size_t startLocation)
{
    std::string value;
    char c;
    std::size_t length = data.length();

    for (auto i = startLocation; i<length; i++)
    {
        c = data.at(i);

        if (c == ',')
        {
            break;
        }
        value+=c;
    }
    return value;
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

