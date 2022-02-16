#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "QSerialPort"
#include "QSerialPortInfo"

class SerialPort
{
public:
   SerialPort();

   QSerialPort *m_serial = nullptr;

   void openSerialPort();
   void getSerialPortInformation();
};

#endif // SERIALPORT_H
