#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include "SerialData.h"
#include "AudioPlayer.h"
#include "SerialPort.h"
#include "FeedbackInteractor.h"

class RequestModel : public QObject
{
   Q_OBJECT

public:
    RequestModel(QObject* parent = nullptr);
    SerialPort * serialPort;
    AudioPlayer * audioPlayer;
    FeedbackInteractor * feedbackInteractor;
    SerialData * serialData;

private:
    QElapsedTimer timer;
    int compressionCount = 0;
    int lastTimeInterval = 0;
    int calculateBPM(int intervalInMs);


public slots:
    void compressionCheckboxSelected(bool state);
    void ventilationCheckboxSelected(bool state);
    void headPositionCheckboxSelected(bool state);
    void fingerCheckboxSelected(bool state);

    void compressionButtonPressed();
    void serialPortSelected(QString portName);
    void voiceSelected(QString voice);
    void serialConnectButtonPressed();

    void ventilationAmountChanged(int value);
    void volumeErrorSliderMoved(float value);
    void timeErrorSliderMoved(float value);
    void babyWeightChanged(int weight_mg);

    void compressionAmountChanged(int value);

    void bpmErrorSliderMoved(float value);
    void depthErrorSliderMoved(float value);


};

#endif // REQUESTMODEL_H
