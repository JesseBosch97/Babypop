#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include "SerialPortBoundary.h"
#include "FingerPositionDataHandler.h"
#include "VolumeDataHandler.h"
#include "DataBoundaries.h"

const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";

class DataHandler : public SerialPortToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override;

    DataToCompressionFeedback * compressionFeedback;
    DataToVentilationFeedback * ventilationFeedback;
    DataToFingerPositionFeedback * fingerPositionFeedback;
    DataToHeadPositionFeedback * headPositionFeedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    VolumeDataHandler volumeDataHandler;

};

#endif // DATAHANDLER_H
