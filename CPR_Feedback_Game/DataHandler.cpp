#include "DataHandler.h"


DataHandler::DataHandler()
{

}
DataHandler::~DataHandler()
{

}
void DataHandler::handleData(std::string validdata)
{
    fingerPositionDataHandler.handleData(validdata);
    //return validdata;
}



