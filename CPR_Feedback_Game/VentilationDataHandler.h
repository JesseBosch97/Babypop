#ifndef VOLUMEDATAHANDLER_H
#define VOLUMEDATAHANDLER_H

#include "StringFunctions.h"
#include "CprTypes.h"



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
