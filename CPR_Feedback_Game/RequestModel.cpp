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
   feedbackInteractor->setVentilationFeedbackSelected(state);
}


void RequestModel::ventilationAmountChanged(int value)
{
    qDebug() << "RequestModel: Ventilation amount changed to " << value;
    feedbackInteractor->setVentilationAmount(value);
}


void RequestModel::volumeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Volume error slider moved to " << value;
   feedbackInteractor->setVolumeErrorThreshold(value);
}

void RequestModel::timeErrorSliderMoved(float value)
{
   qDebug() << "RequestModel: Ventilation time error slider moved to " << value;
   feedbackInteractor->setTimeErrorThreshold(value);

}

void RequestModel::babyWeightChanged(int weight_mg)
{
    qDebug() << "RequestModel: BabyWeight changed to to " << weight_mg;
   feedbackInteractor->setDesiredVentilationVolumeFromBabyWeight(weight_mg);
}




void RequestModel::headPositionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: head position checkbox is" << state;
   //TODO
}

void RequestModel::fingerCheckboxSelected(bool state)
{
    qDebug() << "RequestModel: finger position checkbox is" << state;
    feedbackInteractor->setFingerPositionFeedbackSelected(state);
}





void RequestModel::compressionCheckboxSelected(bool state)
{
   qDebug() << "RequestModel: Compression checkbox is" << state;
   feedbackInteractor->setCompressionFeedbackSelected(state);
}

void RequestModel::compressionAmountChanged(int value)
{
    qDebug() << "RequestModel: Compression amount changed to " << value;
    feedbackInteractor->setCompressionAmount(value);
}


void RequestModel::bpmErrorSliderMoved(float value)
{
    qDebug() << "RequestModel: Bpm error high slider moved to " << value;
    feedbackInteractor->setBpmErrorThreshold(value);
}


void RequestModel::depthErrorSliderMoved(float value)
{
    qDebug() << "RequestModel: Depth error high slider moved to " << value;
    feedbackInteractor->setDepthErrorThreshold(value);
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
   serialData->handleData(compression);
}


int RequestModel::calculateBPM(int intervalInMs){
    int beatsPerMinute = 60000/intervalInMs;
    return beatsPerMinute;
}



