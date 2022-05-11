#ifndef VOLUMEDATAHANDLER_H
#define VOLUMEDATAHANDLER_H

#include "StringFunctions.h"
#include "PerformanceTypes.h"

const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";

class VolumeDataHandler
{
public:
    VolumeDataHandler();

    Ventilation ventilation;

    void handleVolume(std::string & volumeData, std::string header);

private:
    std::string copyAndRemoveNextValue(std::string & volumeData);
};

#endif // VOLUMEDATAHANDLER_H
