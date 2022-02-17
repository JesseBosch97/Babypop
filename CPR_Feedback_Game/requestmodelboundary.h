#ifndef REQUESTMODELBOUNDARY_H
#define REQUESTMODELBOUNDARY_H

#include <QString>

class RequestModelToProcessor
{
public:
    virtual void compressionPerformed() = 0;
};

class RequestModelToSerialPort
{
public:
    virtual void serialPortSelected(QString portName) = 0;
    virtual void serialConnectButtonPressed() = 0;

};


#endif // REQUESTMODELBOUNDARY_H
