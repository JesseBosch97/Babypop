#ifndef SERIALPORTIMPL_H
#define SERIALPORTIMPL_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include <iostream>
#include <QDebug>
#include <QStringListModel>
#include "DataHandler.h"
#include "SerialPort.h"



class SerialPortImpl : public QObject, public SerialPort
{
    Q_OBJECT

public:
   explicit SerialPortImpl(QObject *parent = nullptr);
   ~SerialPortImpl();

   void serialPortSelected(QString portName) override;
   void serialConnectButtonPressed() override;
   void openSerialPort();
   void getSerialPortInformation();


   QStringListModel portListModel;
   DataHandler *datahandler;

private:
   QString selectedPortName;
   QStringList portList;
   QSerialPort serialPort;
   QString validData;

private slots:
   void readData();
   void handleError();
};

#endif // SERIALPORTIMPL_H
