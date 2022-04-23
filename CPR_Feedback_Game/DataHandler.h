#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <SerialPortBoundary.h>
#include "FingerPositionDataHandler.h"
#include "FlowDataHandler.h"
#include "VolumeDataHandler.h"
#include "FeedbackHandlerInput.h"

class DataHandler : public SerialPortToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override;

    FeedbackHandlerInput *feedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    FlowDataHandler flowDataHandler;
    VolumeDataHandler volumeDataHandler;



};

#endif // DATAHANDLER_H
