#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include "requestmodelboundary.h"
#include "interactionprocessor.h"

class RequestModel : public QObject
{
    Q_OBJECT
public:
    RequestModel(QObject* parent = nullptr);
    RequestModelToInteractionProcessor * processor;
    RequestModelToSerialPort * serialPort;
    RequestModelToAudioPlayer * audioPlayer;

    InteractionProcessor interactionProcessor;



public slots:
    void compressionButtonPressed();
    void serialPortSelected(QString portName);
    void voiceSelected(QString voice);
    void serialConnectButtonPressed();
};

#endif // REQUESTMODEL_H
