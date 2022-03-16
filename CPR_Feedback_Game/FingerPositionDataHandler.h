#ifndef FINGERPOSITIONDATAHANDLER_H
#define FINGERPOSITIONDATAHANDLER_H

#include <string>
#include <vector>
#include <cstring>

class FingerPositionDataHandler
{
public:
    explicit FingerPositionDataHandler();
    ~FingerPositionDataHandler();
    void PutFingerpositionsinstruct(std::vector<std::string> value);
    void handleData(std::string validdata);

    std::vector<char> DisectStringtoChar(std::string data);
    std::vector<std::string> BuildNewStringFromDisected(std::vector<char> Disectedstring);
    std::vector<std::string> BuildNewStringFromOldString(std::string data);

    struct Fingerposition
    {
        int top;
        int mid;
        int lowmid;
        int bottom;
        int topleft;
        int bottomleft;
        int topright;
        int bottomright;
    };
};

#endif // FINGERPOSITIONDATAHANDLER_H
