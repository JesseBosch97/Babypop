#include "VolumeDataHandler.h"



VolumeDataHandler::VolumeDataHandler()
{

}


void VolumeDataHandler::handleVolume(std::string * volumeData, std::string header)
{
    removeFrom(volumeData, header);

    std::string volume = copyAndRemoveNextValue(volumeData);
    std::string ventilationTime = *volumeData;

    volumePerformance.volume = stof(volume);
    volumePerformance.time = stoi(ventilationTime);
}


std::string VolumeDataHandler::copyAndRemoveNextValue(std::string * volumeData)
{
    std::string string = copyUntil(*volumeData, ',');

    removeFrom(volumeData, string);
    removeFrom(volumeData, ", ");

    return string;
}


