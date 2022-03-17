#include "requestmodel.h"


RequestModel::RequestModel(QObject *parent)
{
   Q_UNUSED(parent)
}

void RequestModel::compressionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: compression checkbox is" << state;
   //TODO
}

void RequestModel::ventilationCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: ventilation checkbox is" << state;
   //TODO
}

void RequestModel::airwayCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: airway checkbox is" << state;
   //TODO
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
   qDebug() << "RequestModel: Compression slider is: " << value;
   feedbackHandler->compressionFeedbackAmountSelected(value);
}

void RequestModel::ventilationSliderMoved(float value)
{
   qDebug() << "RequestModel: Ventilation slider is: " << value;

}

void RequestModel::airwaySliderMoved(float value)
{
   qDebug() << "RequestModel: Airway slider is: " << value;
}


