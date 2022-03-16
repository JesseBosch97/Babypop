#include "FingerPositionDataHandler.h"

FingerPositionDataHandler::FingerPositionDataHandler()
{

}
FingerPositionDataHandler::~FingerPositionDataHandler()
{

}
void FingerPositionDataHandler::PutFingerpositionsinstruct(std::vector<std::string> value)
{
    Fingerposition pos;
}
void FingerPositionDataHandler::handleData(std::string validdata)
{
    //return validdata;
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

std::vector<std::string> FingerPositionDataHandler::BuildNewStringFromOldString(std::string data)
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
