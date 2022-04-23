#ifndef VOLUMEDATAHANDLER_H
#define VOLUMEDATAHANDLER_H

#include "StringFunctions.h"
#include "PerformanceTypes.h"


class VolumeDataHandler
{
public:
    VolumeDataHandler();
    void handleData(std::string *volumeData);
    VolumePerformance volumePerformance;

private:
    std::string copyAndRemoveNextValue(std::string *volumeData);

};

#endif // VOLUMEDATAHANDLER_H
