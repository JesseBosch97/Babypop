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
    Compression handleCompression(std::vector<std::string> compressionData);
    Ventilation handleVentilation(std::vector<std::string> ventilationData);
    HeadPosition handleHeadPosition(std::vector<std::string> headPositionData);
    size_t countCommas(std::string &data);
};

#endif // SERIALDATAIMPL_H
