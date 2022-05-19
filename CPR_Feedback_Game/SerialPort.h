#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QString>

class SerialPort
{
public:
    virtual void serialPortSelected(QString portName) = 0;
    virtual void serialConnectButtonPressed() = 0;
};

#endif // SERIALPORT_H
