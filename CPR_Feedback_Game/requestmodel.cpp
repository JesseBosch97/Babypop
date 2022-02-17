#include "requestmodel.h"


RequestModel::RequestModel(QObject *parent)
{
    Q_UNUSED(parent)
}

void RequestModel::compressionButtonPressed()
{
    qDebug() << "RequestModel: Compression button pressed";
    processor->compressionPerformed();
}

void RequestModel::serialPortSelected(QString portName)
{
    serialPort->serialPortSelected(portName);
}

void RequestModel::serialConnectButtonPressed()
{
    qDebug() << "RequestModel: Serial connect button pressed";
    serialPort->serialConnectButtonPressed();
}


