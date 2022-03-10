#ifndef SERIALREAD_H
#define SERIALREAD_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include "iostream"
#include <QDebug>
#include <QStringListModel>
#include <RequestModelBoundaries.h>

class SerialRead : public QObject
{
public:
    SerialRead(QObject *parent = nullptr);

    std::vector<char> DisectStringtoChar(std::string data);
    std::vector<std::string> BuildNewStringFromDisected(std::vector<char> Disectedstring);
    std::vector<std::string> BuildNewStringFromOldString(std::string data);
};

#endif // SERIALREAD_H
