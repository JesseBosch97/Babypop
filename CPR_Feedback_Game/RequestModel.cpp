#include "RequestModel.h"


RequestModel::RequestModel(QObject *parent)
{
   Q_UNUSED(parent)
}

void RequestModel::compressionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: compression checkbox is" << state;
   compressionFeedback->setCompressionFeedbackSelected(state);
}

void RequestModel::ventilationCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: ventilation checkbox is" << state;
   ventilationFeedback->setVentilationFeedbackSelected(state);
}

void RequestModel::airwayCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: airway checkbox is" << state;
   //TODO
}

void RequestModel::compressionButtonPressed()
{
   lastTimeInterval = timer.restart();
   int bpm = calculateBPM(lastTimeInterval);
   int depth = 3; //not yet implemented

   qDebug() << "RequestModel: Compression button pressed";
   qDebug() << "RequestModel: Time interval is " << lastTimeInterval;
   qDebug() << "RequestModel: BPM is " << bpm;

   std::string compression = "Compression: ";
   compression.append(std::to_string(bpm));
   compression.append(", ");
   compression.append(std::to_string(depth));
   dataHandler->handleData(compression);
}

void RequestModel::serialPortSelected(QString portName)
{
   serialPort->serialPortSelected(portName);
}

void RequestModel::voiceSelected(QString voice)
{
   audioPlayer->voiceSelected(voice);
   qDebug() << "RequestModel: selected voice is: " << voice;

}

void RequestModel::serialConnectButtonPressed()
{
   qDebug() << "RequestModel: Serial connect button pressed";
   serialPort->serialConnectButtonPressed();
}

void RequestModel::compressionSliderMoved(float value)
{
   compressionFeedback->setCompressionFeedbackAmountSelection(value);
}

void RequestModel::ventilationAmountChanged(int value)
{
    qDebug() << "RequestModel: Ventilation amount changed to " << value;
    ventilationFeedback->setVentilationAmount(value);
}

void RequestModel::ventilationFeedbackFrequencyChanged(int value)
{
    qDebug() << "RequestModel: Ventilation feedback frequency changed to " << value;
    ventilationFeedback->setVentilationFeedbackFrequency(value);
}

void RequestModel::airwaySliderMoved(float value)
{
   qDebug() << "RequestModel: Airway slider is: " << value;
   //TODO
}



int RequestModel::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    return beatsPerMinute;
}



