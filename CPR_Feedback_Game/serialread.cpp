#include "serialread.h"
#include "SerialPort.h"

SerialRead::SerialRead(QObject *parent)
{
    Q_UNUSED(parent)
    test();
    std::cout << "waddup" << std::endl;
}

void SerialPort::readData()
{
   const QByteArray data = serialPort.readAll();

}

char* SerialRead::DisectStringtoCharArray(std::string data)
{
    char stringDesectedtoChars_array[data.length() + 1];

    strcpy(stringDesectedtoChars_array, data.c_str());

    return stringDesectedtoChars_array;

    std::cout << "here" << std::endl;

}

void SerialRead::test()
{
    std::string teststring = "test";
    DisectStringtoCharArray(teststring);
    std::string string;
    for(int i = 0; i < 4; i++)
    {
        string += DisectStringtoCharArray(teststring)[i];
    }
    std::cout << "string is:" << string << std::endl;

}

