/// @date 23-6-2022
/// @author Jesse Bosch
/// @version 1.0

#ifndef FINGERPOSITIONDATAHANDLER_H
#define FINGERPOSITIONDATAHANDLER_H

#include <string>
#include <vector>
#include <cstring>
#include "CprTypes.h"

class FingerPositionSerialData
{
public:
    explicit FingerPositionSerialData();
    ~FingerPositionSerialData();
    void putFingerPositionsInStruct(std::vector<std::string> value);
    FingerPosition handleData(std::string validdata);

    std::vector<char> DisectStringtoChar(std::string data);
    std::vector<std::string> BuildNewStringFromDisected(std::vector<char> Disectedstring);
    std::vector<std::string> parseData(std::string data);

    FingerPosition positionOfFingers;
};

#endif // FINGERPOSITIONDATAHANDLER_H
