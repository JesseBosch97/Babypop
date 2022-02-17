#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include "iostream"
#include <QDebug>
#include <QStringListModel>
#include <requestmodelboundary.h>

//[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n

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

private:
   QString selectedPortName;
   QStringList portList;
   QSerialPort serialPort;

private slots:
   void readData();
   void handleError();
};

#endif // SERIALPORT_H
