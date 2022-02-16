#include "SerialPort.h"


SerialPort::SerialPort()
{

}

void SerialPort::openSerialPort()
{
   m_serial->setPortName("COM9");
   m_serial->setBaudRate(9600);
   m_serial->setDataBits(QSerialPort::Data8);
   m_serial->setParity(QSerialPort::NoParity);
   m_serial->setStopBits(QSerialPort::OneStop);
   m_serial->setFlowControl(QSerialPort::NoFlowControl);
}

void SerialPort::getSerialPortInformation()
{
   const auto infos = QSerialPortInfo::availablePorts();

   for (const QSerialPortInfo &info : infos) {
       QStringList list;
       list << info.portName();
   }

}
