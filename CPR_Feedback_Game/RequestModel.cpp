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


void RequestModel::volumeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Volume error slider moved to " << value;
   ventilationFeedback->setVolumeErrorThreshold(value);
}

void RequestModel::timeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Ventilation time error slider moved to " << value;
   ventilationFeedback->setTimeErrorThreshold(value);

}

void RequestModel::babyWeightChanged(int weight)
{
    qDebug() << "RequestModel: BabyWeight changed to to " << weight;
    float weightInKg = static_cast<float>(weight) / 100;
   ventilationFeedback->setBabyWeight(weightInKg);
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


void RequestModel::bpmErrorSliderMoved(float value)
{
    qDebug() << "RequestModel: Bpm error high slider moved to " << value;
    compressionFeedback->setBpmErrorThreshold(value);
}


void RequestModel::depthErrorSliderMoved(float value)
{
    qDebug() << "RequestModel: Depth error high slider moved to " << value;
    compressionFeedback->setDepthErrorThreshold(value);
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



