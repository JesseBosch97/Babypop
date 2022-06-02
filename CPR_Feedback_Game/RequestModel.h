#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include "DataHandler.h"
#include "CompressionFeedback.h"
#include "VentilationFeedback.h"
#include "AudioPlayer.h"
#include "SerialPort.h"

class RequestModel : public QObject
{
   Q_OBJECT

public:
    RequestModel(QObject* parent = nullptr);
    SerialPort * serialPort;
    AudioPlayer * audioPlayer;
    CompressionFeedback * compressionFeedback;
    VentilationFeedback * ventilationFeedback;
    DataHandler * dataHandler;




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
    void ventilationFeedbackFrequencyChanged(int value);
    void volumeErrorSliderMoved(float value);
    void ventilationTimeErrorSliderMoved(float value);

    void compressionAmountChanged(int value);

    void bpmErrorHighSliderMoved(float value);
    void bpmErrorLowSliderMoved(float value);

    void depthErrorHighSliderMoved(float value);
    void depthErrorLowSliderMoved(float value);
};

#endif // REQUESTMODEL_H
