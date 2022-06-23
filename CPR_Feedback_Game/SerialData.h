/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

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
