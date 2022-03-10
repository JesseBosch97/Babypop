#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include "RequestModelBoundaries.h"
#include "interactionprocessor.h"

class RequestModel : public QObject
{
    Q_OBJECT
public:
    RequestModel(QObject* parent = nullptr);
    RequestModelToInteractionProcessor * processor;
    RequestModelToSerialPort * serialPort;
    RequestModelToAudioPlayer * audioPlayer;
    RequestModelToFeedbackHandler * feedbackHandler;

    InteractionProcessor interactionProcessor;



public slots:
    void compressionButtonPressed();
    void serialPortSelected(QString portName);
    void voiceSelected(QString voice);
    void serialConnectButtonPressed();
    void sliderMoved(float value);
};

#endif // REQUESTMODEL_H
