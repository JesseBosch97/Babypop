#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include "RequestModelBoundaries.h"
#include "CompressionFeedback.h"

class RequestModel : public QObject
{
   Q_OBJECT

public:
    RequestModel(QObject* parent = nullptr);
    RequestModelToSerialPort * serialPort;
    RequestModelToAudioPlayer * audioPlayer;
    CompressionFeedback * compressionFeedback;
    RequestModelToVentilationFeedback * ventilationFeedback;
    RequestModelToDataHandler * dataHandler;


private:
    QElapsedTimer timer;
    int compressionCount = 0;
    int lastTimeInterval = 0;
    int calculateBPM(int intervalInMs);


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
