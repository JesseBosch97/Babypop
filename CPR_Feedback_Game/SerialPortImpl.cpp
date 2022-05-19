#include "SerialPortImpl.h"


SerialPortImpl::SerialPortImpl(QObject *parent)
{
    Q_UNUSED(parent)
    getSerialPortInformation();
    connect(&serialPort, &QSerialPort::errorOccurred, this, &SerialPortImpl::handleError);
    connect(&serialPort, &QSerialPort::readyRead, this, &SerialPortImpl::readData);
}


void SerialPortImpl::serialPortSelected(QString portName)
{
    this->selectedPortName = portName;
}

void SerialPortImpl::serialConnectButtonPressed()
{
    openSerialPort();
}

void SerialPortImpl::openSerialPort()
{
   serialPort.setPortName(selectedPortName);
   serialPort.setBaudRate(9600);
   serialPort.setDataBits(QSerialPort::Data8);
   serialPort.setParity(QSerialPort::NoParity);
   serialPort.setStopBits(QSerialPort::OneStop);
   serialPort.setFlowControl(QSerialPort::NoFlowControl);
   serialPort.open(QIODevice::ReadWrite);
}

void SerialPortImpl::getSerialPortInformation()
{
   const auto infos = QSerialPortInfo::availablePorts();

   for (const QSerialPortInfo &info : infos) {
       portList << info.portName();
   }

   portListModel.setStringList(portList);
}

void SerialPortImpl::readData()
{
    validData.append(serialPort.readAll());

    if (validData.contains('\n'))
    {
        //qDebug() << "SerialPort: " + validData;

        datahandler->handleData(validData.toStdString());
        validData.clear();
    }
}

void SerialPortImpl::handleError()
{
    std::cout << "error occured" << std::endl;
}
