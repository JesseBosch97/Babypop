#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>




class DataHandler
{
public:
   virtual ~DataHandler() = default;
   virtual void handleData(std::string validdata) = 0;
};




#endif // DATAHANDLER_H
