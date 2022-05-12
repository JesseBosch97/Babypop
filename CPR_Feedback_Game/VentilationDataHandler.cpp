#include "VentilationDataHandler.h"



VentilationDataHandler::VentilationDataHandler()
{

}


void VentilationDataHandler::handleVolume(std::string & volumeData, std::string header)
{
    removeFrom(volumeData, header);

    std::string volume = copyAndRemoveNextValue(volumeData);
    std::string ventilationTime = volumeData;

    ventilation.volume = stof(volume);
    ventilation.time = stoi(ventilationTime);
}




