#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include "SerialPortBoundary.h"
#include "FingerPositionDataHandler.h"
#include "VolumeDataHandler.h"
#include "DataBoundaries.h"

class DataHandler : public SerialPortToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override;

    DataToCompressionFeedback * compressionFeedback;
    DataToVentilationFeedback * ventilationFeedback;
    DataToFingerPositionFeedback * fingerPositionFeedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    VolumeDataHandler volumeDataHandler;



};

#endif // DATAHANDLER_H
