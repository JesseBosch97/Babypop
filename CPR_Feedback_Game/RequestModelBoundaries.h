#ifndef REQUESTMODELBOUNDARIES_H
#define REQUESTMODELBOUNDARIES_H

#include "CprTypes.h"
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
