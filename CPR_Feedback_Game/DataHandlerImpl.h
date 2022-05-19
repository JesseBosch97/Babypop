#ifndef DATAHANDLERIMPL_H
#define DATAHANDLERIMPL_H

#include <iostream>

#include "FingerPositionDataHandler.h"
#include "HeadPositionFeedback.h"
#include "DataHandler.h"
#include "CompressionFeedback.h"
#include "FingerPositionFeedback.h"
#include "VentilationFeedback.h"
#include "DataHandler.h"
#include "StringFunctions.h"


const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";
const std::string COMPRESSION_HEADER = "Compression: ";
const std::string FINGER_POSITION_HEADER = "[";
const std::string HEAD_POSITION_HEADER = "Head Position: ";

class DataHandlerImpl : public DataHandler
{
public:
    explicit DataHandlerImpl();
    ~DataHandlerImpl();

    void handleData(std::string validdata) override;

    CompressionFeedback * compressionFeedback;
    VentilationFeedback * ventilationFeedback;
    FingerPositionFeedback * fingerPositionFeedback;
    HeadPositionFeedback * headPositionFeedback;

private:
    FingerPositionDataHandler fingerPositionDataHandler;
    std::vector<std::string> collectData(std::string &data);
    Compression handleCompression(std::vector<std::string> compressionData);
    Ventilation handleVentilation(std::vector<std::string> ventilationData);
    HeadPosition handleHeadPosition(std::vector<std::string> headPositionData);
};

#endif // DATAHANDLERIMPL_H
