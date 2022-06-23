/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QString>

class SerialPort
{
public:
   virtual ~SerialPort() = default;
    virtual void serialPortSelected(QString portName) = 0;
    virtual void serialConnectButtonPressed() = 0;
};

#endif // SERIALPORT_H
