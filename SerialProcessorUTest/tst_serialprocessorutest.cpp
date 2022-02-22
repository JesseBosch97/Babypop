#include <QtTest>

#include "serialprocessor.h"
#include <vector>
#include <QVector>
#include <iostream>
#include <cstring>
//#include "string.h"

// add necessary includes here
#define THRESHOLD 100;
#define CompleteInputSampleinChar '[', '1', '0', '2', '0', ',', ' ', '1', '0', '2', '0', ',', ' ', '1', '0', '2', '0', ',', ' ', '1', '0', '2', '0', ',', ' ', '1', '4', ' ', '1', '3', ' ', '1', '3', ' ', '1', '3', ']'

class SerialProcessorUTest : public QObject
{
    Q_OBJECT

public:
    SerialProcessorUTest();
    ~SerialProcessorUTest();

    int handleInput(std::string inputSample)
    {
        if(inputSample != "")
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

    std::vector<std::string> BuildStringfromdesectedString(std::vector<char> DesectedString)
    {
        std::vector<std::string> rebuildstring;
        std::vector<std::string> fault = {""};
        std::string temp;

        for(int i = 0; i < (int)DesectedString.size(); i++)
        {
            if(std::isdigit(DesectedString[i]))
            {
                temp += DesectedString[i];
            }
            else if(DesectedString[i] == ',')
            {
                rebuildstring.push_back(temp);
                temp = "";
            }
            else if(DesectedString[i] == ']')
            {

                rebuildstring.push_back(temp);
                return rebuildstring;
                break;
            }
        }
        return fault;
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

        strncpy(stringDesectedtoChars_array, teststring.c_str(), sizeof(stringDesectedtoChars_array));

        for(int i = 0; i < (int)teststring.length(); i++)
        {
            desected.push_back(stringDesectedtoChars_array[i]);
        }

        return desected;
    }

private slots:

    void StringIsCopied();
    void disect();
    void BuildingStringsFromChars();
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
    std::vector<char> inputSampleinChar {CompleteInputSampleinChar};

    for(int i = 0; i < (int)sizeof(inputSampleinChar); i++)
    {
        QCOMPARE(disecttochars(inputSample)[i], inputSampleinChar[i]);

    }
}

void SerialProcessorUTest::StringIsCopied()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::string copy = copyString(inputSample);
    QCOMPARE(copy, "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n");
}

void SerialProcessorUTest::BuildingStringsFromChars()
{
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";
    std::vector<std::string> inputSampledesect {"1020", "1020", "1020", "1020", "14", "13", "13", "13"};


    for(int i = 0; i < 8; i++)
    {
        QCOMPARE(BuildStringfromdesectedString(disecttochars(inputSample))[i], inputSampledesect[i]);
    }
}


QTEST_APPLESS_MAIN(SerialProcessorUTest)

#include "tst_serialprocessorutest.moc"
