#ifndef REQUESTMODELBOUNDARIES_H
#define REQUESTMODELBOUNDARIES_H

#include <QString>

class RequestModelToInteractionProcessor
{
public:
    virtual void compressionPerformed() = 0;
};

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

class RequestModelToFeedbackHandler
{
public:
   virtual void compressionFeedbackAmountSelected(float amount) = 0;
};



#endif // REQUESTMODELBOUNDARIES_H
