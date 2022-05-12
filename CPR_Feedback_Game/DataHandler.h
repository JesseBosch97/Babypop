#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include "SerialPortBoundary.h"
#include "FingerPositionDataHandler.h"
#include "VentilationDataHandler.h"
#include "HeadPositionDataHandler.h"
#include "CompressionDataHandler.h"
#include "DataBoundaries.h"
#include "RequestModelBoundaries.h"

//const static std::string VOLUME_IN_HEADER = "Volume In: ";
//const static std::string VOLUME_OUT_HEADER = "Volume Out: ";
//const static std::string COMPRESSION_HEADER = "Compression: ";
//const static std::string FINGER_POSITION_HEADER = "[";
//const static std::string HEAD_POSITION_HEADER = "Head Position: ";


class DataHandler : public SerialPortToDataHandler, public RequestModelToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override; // from serial port
    void handleSimulatedData(std::string simulatedData) override; // from request model

    DataToCompressionFeedback * compressionFeedback;
    DataToVentilationFeedback * ventilationFeedback;
    DataToFingerPositionFeedback * fingerPositionFeedback;
    DataToHeadPositionFeedback * headPositionFeedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    VentilationDataHandler volumeDataHandler;
    CompressionDataHandler compressionDataHandler;
    HeadPositionDataHandler headPositionDataHandler;

    std::vector<std::string> collectData(std::string &data, std::string header);
};

#endif // DATAHANDLER_H
