#ifndef SERIALPORTBOUNDARY_H
#define SERIALPORTBOUNDARY_H

#include <QStringList>

class SerialPortBoundary
{
public:
    virtual void addPortList(QStringList portList) = 0;
};

#endif // SERIALPORTBOUNDARY_H
