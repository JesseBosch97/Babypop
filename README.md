# Babypop
S6 project for the Modular Tetherless Baby Patient Simulator. Developed by Niels van Kessel and Jesse Bosch under the guidance of Johan Korten and Jeroen Veen.

This project is a desktop audio feedback application written in C++ and QML with the Qt Quick framework.

For documentation about the software please see the wiki page of this repository at:
https://github.com/JesseBosch97/Babypop/wiki

# Installation
This software has been developed using Qt 5.15.2 and the MinGW 8.1.0 compiler. 
Download: https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4
![QT tool](https://user-images.githubusercontent.com/78701533/175053143-bcdb167d-bf5b-44c8-baa2-8e04e83a7112.PNG)

# Project structure 
The main project is the CPR_Feedback_Game folder. Inside are the source files and the following folders:
* FingerPositionUnitTests contain the unit tests for handling finger position feedback.
* SerialDataUTest contains the unit tests for collecting data from serial input strings.
* audiofiles contains the audio files used by the application to give feedback.


# Working with QML
QML is a user interface markup language developed by Qt. The code can be found in the main.qml file in the resources section of the project.
The main.cpp file makes the connection between the user interface and the c++ classes through the ViewModel and RequestModel.
The SerialPort has a portListModel that is also available to the user interface to show the found serial ports on screen.
For more information about QML read Qt's extensive documentation. For example:
https://doc.qt.io/qt-6/qtqml-cppintegration-overview.html



# Adding sound files

The sounds are taken from https://voicemaker.in/

When adding a file, it should be put in the CPR_Feedback_Game/sounds folder and have the following naming convention: "VoiceType_word"
For example MaleTTS_fingers and FemaleTTS_fingers.

Next navigate to the sounds.qrc in Qt Creator.

![SoundFiles1](https://user-images.githubusercontent.com/78701533/175053088-8645ab39-064a-45cb-a943-948131d1d8d6.PNG)


Right click on sound.qrc and click "Open in editor".

Click on the MaleTTS folder and click add files. Navigate to the file you placed in CPR_Feedback_Game/sounds folder and add it.
Click on the FemaleTTS folder and do the same thing.

Go to AudioPlayerImpl.h and add your word to the feedbackWordMap. This will map a certain feedbackType (see enum in CprTypes.h) to the string of the new word that is the same as the word part in "VoiceType_word" file that was added earlier. 

The function createSoundURL will now create the correct URL to find the soundfile that will be loaded
into the audio player.



# Bugs
When trying to connect to a samd board the application will show no communication. 
To fix this, first connect a different terminal like tera term or arduino ide terminal to the samd. 
Verify that communication is indeed happening. Then close the terminal and restart the feedback application. 
Connect to the serial port of the samd device and now the communication should work.



