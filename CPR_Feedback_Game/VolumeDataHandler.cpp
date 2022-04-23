#include "VolumeDataHandler.h"



VolumeDataHandler::VolumeDataHandler()
{

}

void VolumeDataHandler::handleData(std::string * volumeData)
{
    removeFrom(volumeData, "Volume: ");

    std::string volumeIn = copyAndRemoveNextValue(volumeData);
    std::string volumeOut = copyAndRemoveNextValue(volumeData);
    std::string ventilationTime = *volumeData;

    volumePerformance.volumeIn = stof(volumeIn);
    volumePerformance.volumeOut = stof(volumeOut);
    volumePerformance.ventilationTime = stoi(ventilationTime);
}


std::string VolumeDataHandler::copyAndRemoveNextValue(std::string * volumeData)
{
    std::string string = copyUntil(*volumeData, ',');

    removeFrom(volumeData, string);
    removeFrom(volumeData, ", ");

    return string;
}


