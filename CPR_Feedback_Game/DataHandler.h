#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include "SerialPortBoundary.h"
#include "FingerPositionDataHandler.h"

#include "DataBoundaries.h"
#include "RequestModelBoundaries.h"
#include "CompressionFeedback.h"
#include "FingerPositionFeedback.h"
#include "StringFunctions.h"


const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";
const std::string COMPRESSION_HEADER = "Compression: ";
const std::string FINGER_POSITION_HEADER = "[";
const std::string HEAD_POSITION_HEADER = "Head Position: ";

class DataHandler : public SerialPortToDataHandler, public RequestModelToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override; // from serial port
    void handleSimulatedData(std::string simulatedData) override; // from request model

    CompressionFeedback * compressionFeedback;
    DataToVentilationFeedback * ventilationFeedback;
    FingerPositionFeedback * fingerPositionFeedback;
    DataToHeadPositionFeedback * headPositionFeedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    std::vector<std::string> collectData(std::string &data);
    Compression handleCompression(std::vector<std::string> compressionData);
    Ventilation handleVentilation(std::vector<std::string> ventilationData);
    HeadPosition handleHeadPosition(std::vector<std::string> headPositionData);
};

#endif // DATAHANDLER_H
