#include "SerialPort.h"


SerialPort::SerialPort(QObject *parent)
{
    Q_UNUSED(parent)
    getSerialPortInformation();
    connect(&serialPort, &QSerialPort::errorOccurred, this, &SerialPort::handleError);
    connect(&serialPort, &QSerialPort::readyRead, this, &SerialPort::readData);
}

SerialPort::~SerialPort()
{
}

void SerialPort::serialPortSelected(QString portName)
{
    this->selectedPortName = portName;
}

void SerialPort::serialConnectButtonPressed()
{
    openSerialPort();
}

void SerialPort::openSerialPort()
{
   serialPort.setPortName(selectedPortName);
   serialPort.setBaudRate(9600);
   serialPort.setDataBits(QSerialPort::Data8);
   serialPort.setParity(QSerialPort::NoParity);
   serialPort.setStopBits(QSerialPort::OneStop);
   serialPort.setFlowControl(QSerialPort::NoFlowControl);
   serialPort.open(QIODevice::ReadWrite);
}

void SerialPort::getSerialPortInformation()
{
   const auto infos = QSerialPortInfo::availablePorts();

   for (const QSerialPortInfo &info : infos) {
       portList << info.portName();
   }

   portListModel.setStringList(portList);
}

void SerialPort::readData()
{
    const QByteArray data = serialPort.readAll();
    //m_console->putData(data);
    qDebug() << data;
}

void SerialPort::handleError()
{
    std::cout << "error occured" << std::endl;
}
