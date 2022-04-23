#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include "iostream"
#include <QDebug>
#include <QStringListModel>
#include <RequestModelBoundaries.h>
#include <SerialPortBoundary.h>



class SerialPort : public QObject, public RequestModelToSerialPort
{
    Q_OBJECT

public:
   explicit SerialPort(QObject *parent = nullptr);
   ~SerialPort();

   void serialPortSelected(QString portName) override;
   void serialConnectButtonPressed() override;
   void openSerialPort();
   void getSerialPortInformation();


   QStringListModel portListModel;
   SerialPortToDataHandler *datahandler;

private:
   QString selectedPortName;
   QStringList portList;
   QSerialPort serialPort;
   QString validData;

private slots:
   void readData();
   void handleError();
};

#endif // SERIALPORT_H
