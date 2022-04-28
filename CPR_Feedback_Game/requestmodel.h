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
    void compressionCheckboxSelected(bool state);
    void ventilationCheckboxSelected(bool state);
    void airwayCheckboxSelected(bool state);
    void compressionButtonPressed();
    void serialPortSelected(QString portName);
    void voiceSelected(QString voice);
    void serialConnectButtonPressed();
    void compressionSliderMoved(float value);
    void ventilationAmountChanged(int value);
    void ventilationFeedbackFrequencyChanged(int value);

    void airwaySliderMoved(float value);
};

#endif // REQUESTMODEL_H
