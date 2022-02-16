#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "QSerialPort"
#include "QSerialPortInfo"

//[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n

class SerialPort
{
public:
   SerialPort();

   QSerialPort *m_serial = nullptr;

   void openSerialPort();
   void getSerialPortInformation();
};

#endif // SERIALPORT_H
