#include "RequestModel.h"


RequestModel::RequestModel(QObject *parent)
{
   Q_UNUSED(parent)
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


void RequestModel::voiceSelected(QString voice)
{
   audioPlayer->voiceSelected(voice);
   qDebug() << "RequestModel: selected voice is: " << voice;

}







void RequestModel::ventilationCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: ventilation checkbox is" << state;
   ventilationFeedback->setVentilationFeedbackSelected(state);
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

void RequestModel::volumeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Volume error slider moved to " << value;
   ventilationFeedback->setVolumeError(value);
}

void RequestModel::ventilationTimeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Ventilation time error slider moved to " << value;
   ventilationFeedback->setVentilationTimeError(value);

}




void RequestModel::headPositionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: head position checkbox is" << state;
   //TODO
}

void RequestModel::fingerCheckboxSelected(bool state)
{
    qDebug() << "RequestModel: finger position checkbox is" << state;

}





void RequestModel::compressionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: Compression checkbox is" << state;
   compressionFeedback->setCompressionFeedbackSelected(state);
}

void RequestModel::compressionAmountChanged(int value)
{
    qDebug() << "RequestModel: Compression amount changed to " << value;
    compressionFeedback->setCompressionAmount(value);
}


void RequestModel::bpmErrorHighSliderMoved(float value)
{
    qDebug() << "RequestModel: Bpm error high slider moved to " << value;
    compressionFeedback->setBpmErrorHigh(value);
}

void RequestModel::bpmErrorLowSliderMoved(float value)
{
    qDebug() << "RequestModel: Bpm error low slider moved to " << value;
    compressionFeedback->setBpmErrorLow(value);
}

void RequestModel::depthErrorHighSliderMoved(float value)
{
    qDebug() << "RequestModel: Depth error high slider moved to " << value;
    compressionFeedback->setDepthErrorHigh(value);
}

void RequestModel::depthErrorLowSliderMoved(float value)
{
    qDebug() << "RequestModel: Depth error low slider moved to " << value;
    compressionFeedback->setDepthErrorLow(value);
}





void RequestModel::compressionButtonPressed()
{
   lastTimeInterval = timer.restart();
   int bpm = calculateBPM(lastTimeInterval);
   int depth = 30; //not yet implemented

   qDebug() << "RequestModel: Compression button pressed";
   qDebug() << "RequestModel: Time interval is " << lastTimeInterval;
   qDebug() << "RequestModel: BPM is " << bpm;

   std::string compression = "Compression: ";
   compression.append(std::to_string(bpm));
   compression.append(", ");
   compression.append(std::to_string(depth));
   dataHandler->handleData(compression);
}


int RequestModel::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    return beatsPerMinute;
}


