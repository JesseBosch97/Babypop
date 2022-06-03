#ifndef SERIALDATAIMPL_H
#define SERIALDATAIMPL_H

#include <iostream>


#include "SerialData.h"
#include "FeedbackInteractor.h"
#include "FingerPositionDataHandler.h"
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

    const std::string VOLUME_IN_HEADER = "Volume In: ";
    const std::string VOLUME_OUT_HEADER = "Volume Out: ";
    const std::string COMPRESSION_HEADER = "Compression: ";
    const std::string FINGER_POSITION_HEADER = "[";
    const std::string HEAD_POSITION_HEADER = "Head Position: ";
};

#endif // SERIALDATAIMPL_H
