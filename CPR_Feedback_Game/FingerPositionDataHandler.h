#ifndef FINGERPOSITIONDATAHANDLER_H
#define FINGERPOSITIONDATAHANDLER_H

#include <string>
#include <vector>
#include <cstring>
#include "PerformanceTypes.h"

class FingerPositionDataHandler
{
public:
    explicit FingerPositionDataHandler();
    ~FingerPositionDataHandler();
    void putFingerPositionsInStruct(std::vector<std::string> value);
    Fingerposition handleData(std::string validdata);

    std::vector<char> DisectStringtoChar(std::string data);
    std::vector<std::string> BuildNewStringFromDisected(std::vector<char> Disectedstring);
    std::vector<std::string> parseData(std::string data);

    Fingerposition positionOfFingers;
};

#endif // FINGERPOSITIONDATAHANDLER_H
