/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef SERIALPORTIMPL_H
#define SERIALPORTIMPL_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include <iostream>
#include <QDebug>
#include <QStringListModel>
#include "SerialData.h"
#include "SerialPort.h"



class SerialPortImpl : public QObject, public SerialPort
{
    Q_OBJECT

public:
   explicit SerialPortImpl(QObject *parent = nullptr);

   void serialPortSelected(QString portName) override;
   void serialConnectButtonPressed() override;
   void openSerialPort();
   void getSerialPortInformation();


   QStringListModel portListModel;
   SerialData *serialData;

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
