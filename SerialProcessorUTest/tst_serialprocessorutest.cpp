#include <QtTest>

#include "serialprocessor.h"
#include <vector>
#include <QVector>
#include <iostream>
#include <cstring>
//#include "string.h"

// add necessary includes here
#define THRESHOLD 100;

class SerialProcessorUTest : public QObject
{
    Q_OBJECT

public:
    SerialProcessorUTest();
    ~SerialProcessorUTest();

    int handleInput(std::string inputSample){
        return 0;
    }

    std::vector<std::string> StringDesect(std::string inputSample)
    {
        std::vector<std::string> DesectedString;
        std::vector<std::string> fault;
        std::string temp;
        int stringlength = inputSample.length();
        char stringDesectedtoChars_array[stringlength + 1];

        strcpy(stringDesectedtoChars_array, inputSample.c_str());

        for(int i = 0; i < (int)inputSample.length(); i++)
        {
            if(std::isdigit(stringDesectedtoChars_array[i]))
            {
                temp += (inputSample.substr(i, 1));
            }
            else if(stringDesectedtoChars_array[i] == ',')
            {
                DesectedString.push_back(temp);
                temp = "";
            }
            else if(stringDesectedtoChars_array[i] == ']')
            {
                DesectedString.push_back(temp);
                return DesectedString;
            }


        }
        return fault;

    }

    std::string findValue(std::string inputSample){

        return inputSample.substr(1, 4);
    }
    std::string FindValueX(std::string inputSample, int start, int size)
    {
        return inputSample.substr(start, size);
    }

    std::string copyString(std::string input){
        std::string copy;
        for (int i = 0; i <(int)input.length(); i++){
            copy += input[i];
        }
        return copy;
    }

    std::vector<char> disecttochars(std::string teststring)
    {
        std::vector<char> desected;
        char stringDesectedtoChars_array[teststring.length() + 1];

        strcpy(stringDesectedtoChars_array, teststring.c_str());

        for(int i = 0; i < (int)teststring.length(); i++)
        {
            desected.push_back(stringDesectedtoChars_array[i]);
        }


        return desected;
    }

private slots:
    void InputBelowThresholdDoesNotTriggerACompression();

    void InputAboveThresholdDoesTriggerACompression();
    void TheFirstValueIsFound();
    void ValueXisFound();
    void AllValuesAreFound();
    void StringIsCopied();
    void disect();
};

SerialProcessorUTest::SerialProcessorUTest()
{

}

SerialProcessorUTest::~SerialProcessorUTest()
{

}

void SerialProcessorUTest::disect()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::vector<char> inputSampleinChar {'[', '1', '0', '2', '0',};

    for(int i = 0; i < 5; i++)
    {
        QCOMPARE(disecttochars(inputSample)[i], inputSampleinChar[i]);

    }
}
void SerialProcessorUTest::TheFirstValueIsFound()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::string subString = findValue(inputSample);
    QCOMPARE(subString, "1020");
}

void SerialProcessorUTest::StringIsCopied()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::string copy = copyString(inputSample);
    QCOMPARE(copy, "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n");
}

void SerialProcessorUTest::AllValuesAreFound()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::vector<std::string> inputSampledesect {"1020", "1020", "1020", "1020", "14", "13", "13", "13"};


    for(int i = 0; i < 8; i++)
    {
        QCOMPARE(StringDesect(inputSample)[i], inputSampledesect[i]);
    }
}

void SerialProcessorUTest::ValueXisFound()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    int start = 1;
    int size = 4;

    for(int i = 0; i < 8; i++)
    {
        if(i<4)
        {
            std::string subString = FindValueX(inputSample, start, size);
            QCOMPARE(subString, "1020");
        }
        else if(i == 4)
        {
            size = 2;
            std::string subString = FindValueX(inputSample, start, size);
            QCOMPARE(subString, "14");
        }
        else
        {
            std::string subString = FindValueX(inputSample, start, size);
            QCOMPARE(subString, "13");
        }
        start = start + size + 2;
    }
}



void SerialProcessorUTest::InputBelowThresholdDoesNotTriggerACompression()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    QCOMPARE(handleInput(inputSample), 0);
}

void SerialProcessorUTest::InputAboveThresholdDoesTriggerACompression()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 101, 13, 13, 13]\r\n";
    QCOMPARE(handleInput(inputSample), 1);
}


QTEST_APPLESS_MAIN(SerialProcessorUTest)

#include "tst_serialprocessorutest.moc"
