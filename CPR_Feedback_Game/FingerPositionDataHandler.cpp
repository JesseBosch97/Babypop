#include "FingerPositionDataHandler.h"
#include <iostream>

FingerPositionDataHandler::FingerPositionDataHandler()
{

}
FingerPositionDataHandler::~FingerPositionDataHandler()
{

}
void FingerPositionDataHandler::putFingerPositionsInStruct(std::vector<std::string> value)
{

    positionOfFingers.bottomleft    = std::stoi(value[0]);
    positionOfFingers.bottomleft    = std::stoi(value[1]);
    positionOfFingers.bottomleft    = std::stoi(value[2]);
    positionOfFingers.mid           = std::stoi(value[3]);
    positionOfFingers.bottomright   = std::stoi(value[4]);
    positionOfFingers.top           = std::stoi(value[5]);
    positionOfFingers.bottom        = std::stoi(value[6]);
    positionOfFingers.lowmid        = std::stoi(value[7]);

}
void FingerPositionDataHandler::handleData(std::string validdata)
{
    putFingerPositionsInStruct(parseData(validdata));
    std::cout << positionOfFingers.bottomright << " " << positionOfFingers.top << " " << positionOfFingers.bottom << " " << positionOfFingers.lowmid << std::endl;
}

std::vector<char> FingerPositionDataHandler::DisectStringtoChar(std::string data)
{
    std::vector<char> desected;
    char stringDesectedtoChars_array[data.length() + 1];

    strncpy(stringDesectedtoChars_array, data.c_str(), sizeof(stringDesectedtoChars_array));

    for(int i = 0; i < (int)data.length(); i++)
    {
        desected.push_back(stringDesectedtoChars_array[i]);
    }
    return desected;

}

std::vector<std::string> FingerPositionDataHandler::BuildNewStringFromDisected(std::vector<char> Disectedstring)
{
    std::vector<std::string> rebuildstring;
    std::vector<std::string> fault = {""};
    std::string temp;

    for(int i = 0; i < (int)Disectedstring.size(); i++)
    {
        if(std::isdigit(Disectedstring[i]))
        {
            temp += Disectedstring[i];
        }
        else if(Disectedstring[i] == ',')
        {
            rebuildstring.push_back(temp);
            temp = "";
        }
        else if(Disectedstring[i] == ']')
        {

            rebuildstring.push_back(temp);
            return rebuildstring;
            break;
        }
    }
    return fault;
}

std::vector<std::string> FingerPositionDataHandler::parseData(std::string data)
{
    std::vector<std::string> rebuildstring;
    std::vector<std::string> fault = {""};
    std::string temp;
    std::vector<char> Disectedstring = DisectStringtoChar(data);

    for(int i = 0; i < (int)Disectedstring.size(); i++)
    {
        if(std::isdigit(Disectedstring[i]))
        {
            temp += Disectedstring[i];
        }
        else if(Disectedstring[i] == ',')
        {
            rebuildstring.push_back(temp);
            temp = "";
        }
        else if(Disectedstring[i] == ']')
        {

            rebuildstring.push_back(temp);
            return rebuildstring;
            break;
        }
    }
    return fault;
}
