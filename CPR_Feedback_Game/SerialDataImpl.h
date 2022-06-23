/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef SERIALDATAIMPL_H
#define SERIALDATAIMPL_H

#include <iostream>


#include "SerialData.h"
#include "FeedbackInteractor.h"
#include "FingerPositionSerialData.h"
#include "StringFunctions.h"




class SerialDataImpl : public SerialData
{
public:
    explicit SerialDataImpl();

    void handleData(std::string validdata) override;

    FeedbackInteractor * feedbackInteractor;

private:
    FingerPositionSerialData fingerPositionSerialData;

    std::vector<std::string> collectData(std::string &data);
    std::vector<std::size_t> findDataValueStartLocations(std::string &data, std::string separationCharacters);
    std::string copyDataValue(std::string &data, std::size_t startLocation);

    Compression handleCompression(std::vector<std::string> compressionData);
    Ventilation handleVentilation(std::vector<std::string> ventilationData);
    HeadPosition handleHeadPosition(std::vector<std::string> headPositionData);


};

#endif // SERIALDATAIMPL_H
