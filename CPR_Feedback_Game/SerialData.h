#ifndef SERIALDATA_H
#define SERIALDATA_H

#include <string>




class SerialData
{
public:
   virtual ~SerialData() = default;
   virtual void handleData(std::string validdata) = 0;
};




#endif // SERIALDATA_H
