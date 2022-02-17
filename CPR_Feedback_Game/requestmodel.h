#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include "requestmodelboundary.h"

class RequestModel : public QObject
{
    Q_OBJECT
public:
    RequestModel(QObject* parent = nullptr);
    RequestModelToProcessor * processor;
    RequestModelToSerialPort * serialPort;


public slots:
    void compressionButtonPressed();
    void serialPortSelected(QString portName);
    void serialConnectButtonPressed();
};

#endif // REQUESTMODEL_H
