#ifndef REQUESTMODELBOUNDARIES_H
#define REQUESTMODELBOUNDARIES_H

#include <QString>


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
   virtual void handleBpmPerformance(int bpm) = 0;
};

class RequestModelToVentilationFeedback
{
public:
   virtual void setVentilationFeedbackFrequency(int amount) = 0;
   virtual void setVentilationAmount(int amount) = 0;
   virtual void setVentilationFeedbackSelected(bool state) = 0;
};



#endif // REQUESTMODELBOUNDARIES_H
