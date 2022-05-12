#ifndef REQUESTMODELBOUNDARIES_H
#define REQUESTMODELBOUNDARIES_H

#include <QString>

const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";
const std::string COMPRESSION_HEADER = "Compression: ";
const std::string FINGER_POSITION_HEADER = "[";
const std::string HEAD_POSITION_HEADER = "Head Position: ";



class RequestModelToSerialPort
{
public:
    virtual void serialPortSelected(QString portName) = 0;
    virtual void serialConnectButtonPressed() = 0;
};

class RequestModelToAudioPlayer
{
public:
   virtual void voiceSelected(QString voice) = 0;
};

class RequestModelToCompressionFeedback
{
public:
   virtual void setCompressionFeedbackAmountSelection(float amount) = 0;
   virtual void setCompressionFeedbackSelected(bool state) = 0;
};

class RequestModelToVentilationFeedback
{
public:
   virtual void setVentilationFeedbackFrequency(int amount) = 0;
   virtual void setVentilationAmount(int amount) = 0;
   virtual void setVentilationFeedbackSelected(bool state) = 0;
};

class RequestModelToDataHandler
{
public:
    virtual void handleSimulatedData(std::string simulatedData) = 0;
};




#endif // REQUESTMODELBOUNDARIES_H
