#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <SerialPortBoundary.h>
#include "FingerPositionDataHandler.h"

class DataHandler : public SerialPortToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();

    void handleData(std::string validdata) override;

private:
    FingerPositionDataHandler fingerPositionDataHandler;

};

#endif // DATAHANDLER_H
