#ifndef VENTILATIONDATAHANDLER_H
#define VENTILATIONDATAHANDLER_H

#include "StringFunctions.h"
#include "CprTypes.h"



class VentilationDataHandler
{
public:
    VentilationDataHandler();

    Ventilation ventilation;

    void handleVolume(std::string & volumeData, std::string header);

};

#endif // VENTILATIONDATAHANDLER_H
