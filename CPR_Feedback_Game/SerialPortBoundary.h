#ifndef SERIALPORTBOUNDARY_H
#define SERIALPORTBOUNDARY_H

#include <QStringList>

class SerialPortBoundary
{
public:
    virtual void addPortList(QStringList portList) = 0;
};

class SerialPortToDataHandler
{
public:
    virtual void handleData(std::string validdata);
};

#endif // SERIALPORTBOUNDARY_H
