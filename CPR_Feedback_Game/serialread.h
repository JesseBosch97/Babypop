#ifndef SERIALREAD_H
#define SERIALREAD_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include "iostream"
#include <QDebug>
#include <QStringListModel>
#include <requestmodelboundary.h>

class SerialRead : public QObject
{
public:
    SerialRead(QObject *parent = nullptr);

    char* DisectStringtoCharArray(std::string data);
    void test();

};

#endif // SERIALREAD_H
