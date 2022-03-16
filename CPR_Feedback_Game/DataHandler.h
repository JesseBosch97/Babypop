#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <SerialPortBoundary.h>

class DataHandler : public SerialPortToDataHandler
{
public:
    explicit DataHandler();
    ~DataHandler();
    void PutFingerpositionsinstruct(std::vector<std::string> value);
    void handleData(std::string validdata) override;


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

#endif // DATAHANDLER_H
