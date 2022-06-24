/// @date 23-6-2022
/// @author Jesse Bosch
/// @version 1.0

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

struct Fingerposition
{
    int top;
    int mid;
    int lowmid;
    int bottom;
    int topleft;
    int bottomleft;
    int topright;
    int bottomright;
};

struct Coordinates
{
    float x;
    float y;
};



enum location {UP_LEFT, UP, UP_RIGHT, LEFT, MID, RIGHT, BOTTOM_LEFT, LOW, BOTTOM_RIGHT};

    Fingerposition posFing;

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

    std::string copyString(std::string input)
    {
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

    location calculatelocation(Coordinates thorax)
    {
        location retval;

        bool up = 0;
        bool midy = 0;
        bool low = 0;
        bool left = 0;
        bool midx = 0;
        bool right = 0;

        if(30 < thorax.y && thorax.y <= 100)
        {
            up = 1;
        }
        if(-30 <= thorax.y && thorax.y <= 30)
        {
            midy = 1;
        }
        if(-100 <= thorax.y && thorax.y < -30)
        {
            low = 1;
        }
        if(-100 <= thorax.x && thorax.x < -30)
        {
            left = 1;
        }
        if(-30 <= thorax.x && thorax.x <= 30)
        {
            midx = 1;
        }
        if(30 < thorax.x && thorax.x <= 100)
        {
            right = 1;
        }


        if(up && left)
        {
            retval = UP_LEFT;
        }
        if(up && midx)
        {
            retval = UP;
        }
        if(up && right)
        {
            retval = UP_RIGHT;
        }
        if(midy && left)
        {
            retval = LEFT;
        }
        if(midy && midx)
        {
            retval = MID;
        }
        if(midy && right)
        {
            retval = RIGHT;
        }
        if(low && left)
        {
            retval = BOTTOM_LEFT;
        }
        if(low && midx)
        {
            retval = LOW;
        }
        if(low && right)
        {
            retval = BOTTOM_RIGHT;
        }

        return retval;
    }
    Fingerposition fillFingerPositions(std::string validdata)
    {
        putFingerPositionsInStruct(BuildStringfromdesectedString(disecttochars(validdata)));
        //std::cout << posFing.bottom << std::endl;
        return posFing;
    }
int pressurepoints()
{
    int pressurePoints = 0;

    if(posFing.lowmid > 150)
    {
        pressurePoints++;
    }
    if(posFing.mid > 150)
    {
        pressurePoints++;
    }
    if(posFing.top > 150)
    {
        pressurePoints++;
    }
    if(posFing.bottomleft > 150)
    {
        pressurePoints++;
    }
    if(posFing.bottomright > 150)
    {
        pressurePoints++;
    }
    if(posFing.topleft > 150)
    {
        pressurePoints++;
    }
    if(posFing.topright > 150)
    {
        pressurePoints++;
    }
    if(posFing.bottom > 150)
    {
        pressurePoints++;
    }

    return pressurePoints;
}

    void putFingerPositionsInStruct(std::vector<std::string> value)
    {
        posFing.bottomleft    = std::stoi(value[0]);
        posFing.topleft       = std::stoi(value[1]);
        posFing.topright      = std::stoi(value[2]);
        posFing.mid           = std::stoi(value[3]);
        posFing.bottomright   = std::stoi(value[4]);
        posFing.top           = std::stoi(value[5]);
        posFing.bottom        = std::stoi(value[6]);
        posFing.lowmid        = std::stoi(value[7]);
    }

    location positionOfFingers(Fingerposition posFing)
    {
        Coordinates bottomLeft;
        bottomLeft.x = -1 * posFing.bottomleft;
        bottomLeft.y = -1 * posFing.bottomleft;

        Coordinates topLeft;
        topLeft.x = -1 * posFing.topleft;
        topLeft.y = 1 * posFing.topleft;

        Coordinates topRight;
        topRight.x = 1 * posFing.topright;
        topRight.y = 1 * posFing.topright;

        Coordinates mid;
        mid.x = 0 * posFing.mid;
        mid.y = 0 * posFing.mid;

        Coordinates bottomRight;
        bottomRight.x = 1 * posFing.bottomright;
        bottomRight.y = -1 * posFing.bottomright;

        Coordinates top;
        top.x = 0 * posFing.top;
        top.y = 1 * posFing.top;

        Coordinates lowmid;
        lowmid.x = 0 * posFing.lowmid;
        lowmid.y = -1 * posFing.lowmid;

        Coordinates thorax;
        thorax.x = 0;
        thorax.y = 0;




        thorax.x = ((bottomLeft.x + topLeft.x + topRight.x + mid.x + bottomRight.x + top.x + lowmid.x) / 4);
        thorax.y = ((bottomLeft.y + topLeft.y + topRight.y + mid.y + bottomRight.y + top.y + lowmid.y) / 6);
        //std::cout << "x= " << thorax.x << std::endl;
        //std::cout << "y= " << thorax.y << std::endl;
        //std::cout << std::endl;

        return calculatelocation(thorax);
    }


private slots:

    void StringIsCopied();
    void disect();
    void BuildingStringsFromChars();
    void FingerPositionTest();
    void FingerPositionAbsoluteTest();
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

void SerialProcessorUTest::FingerPositionTest()
{
    //[botleft, topleft, topright, mid, botright, top, bot, low]
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";

    for(int i = 0; i < 9; i++)
    {
        switch(i)
        {
        case UP_LEFT:
            inputSample = "[100, 220, 15, 50, 15, 100, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case UP:
            inputSample = "[15, 100, 100, 100, 15, 220, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case UP_RIGHT:
            inputSample = "[15, 15, 220, 50, 100, 100, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case LEFT:
            inputSample = "[100, 100, 15, 50, 15, 15, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case MID:
            inputSample = "[15, 15, 15, 220, 15, 100, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case RIGHT:
            inputSample = "[15, 15, 100, 100, 100, 15, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case BOTTOM_LEFT:
            inputSample = "[220, 50, 15, 30, 15, 15, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case LOW:
            inputSample = "[15, 15, 15, 100, 15, 15, 15, 220]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        case BOTTOM_RIGHT:
            inputSample = "[15, 15, 50, 35, 220, 15, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            positionOfFingers(posFing);
            break;
        }
        QCOMPARE(positionOfFingers(posFing), i);
    }
}
void SerialProcessorUTest::FingerPositionAbsoluteTest()
{
    //[botleft, topleft, topright, mid, botright, top, bot, low]
    std::string inputSample = "[1020, 1020, 1020, 1020, 14, 13, 13, 13]\r\n";

    for(int i = 0; i < 10; i++)
    {
        switch(i)
        {
        case UP_LEFT:
            inputSample = "[100, 220, 15, 50, 15, 100, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case UP:
            inputSample = "[15, 100, 100, 100, 15, 220, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case UP_RIGHT:
            inputSample = "[15, 15, 220, 50, 100, 100, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case LEFT:
            inputSample = "[100, 100, 15, 50, 15, 15, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 0);
            break;
        case MID:
            inputSample = "[15, 15, 15, 220, 15, 100, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case RIGHT:
            inputSample = "[15, 15, 100, 100, 100, 15, 15, 15]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 0);
            break;
        case BOTTOM_LEFT:
            inputSample = "[220, 50, 15, 30, 15, 15, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case LOW:
            inputSample = "[15, 15, 15, 100, 15, 15, 15, 220]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        case BOTTOM_RIGHT:
            inputSample = "[15, 15, 50, 35, 220, 15, 15, 50]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 1);
            break;
        default:
            inputSample = "[200, 200, 200, 200, 200, 200, 215, 250]\r\n";
            fillFingerPositions(inputSample);
            QCOMPARE(pressurepoints(), 8);
            break;
        }
    }


}

QTEST_APPLESS_MAIN(SerialProcessorUTest)

#include "tst_serialprocessorutest.moc"
