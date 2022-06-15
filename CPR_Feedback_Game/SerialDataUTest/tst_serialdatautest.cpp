#include <QtTest>
#include "../StringFunctions.h"
// add necessary includes here



class SerialDataUTest : public QObject
{
    Q_OBJECT

public:
    SerialDataUTest();
    ~SerialDataUTest();

private:

    std::vector<std::string> collectData(std::string & data)
    {
        std::vector<std::string> dataCollection;

        size_t loopAmount = countCommas(data);

        for (int i = 0; i < static_cast<int>(loopAmount); i++)
        {
            std::string nextData = copyDataValue(data, i);
            dataCollection.push_back(nextData);
        }

        return dataCollection;
    }

    size_t countCommas(std::string & data)
    {
        size_t amount = std::count(data.begin(), data.end(), ',');
        return amount;
    }

    std::vector<std::size_t> findCommaLocations(std::string & data)
    {
        std::size_t amountOfCommas = countCommas(data);
        std::vector<std::size_t> commaLocations;
        std::size_t lastCommaLocation = 0;

        for (unsigned long long i = 0; i<amountOfCommas; i++)
        {
            lastCommaLocation = data.find(',', lastCommaLocation + 1);
            commaLocations.push_back(lastCommaLocation);
        }

        return commaLocations;
    }


    std::string copyDataValue(std::string & data, std::size_t startLocation)
    {
        std::string value;
        char c;
        std::size_t length = data.length();


        for (auto i = startLocation; i<length; i++)
        {

            c = data.at(i);

            if (c == ',')
            {
                break;
            }

            value+=c;
        }

        return value;
    }



private slots:

    void VolumeHeaderIsRemovedFromString();
    void CommaLocationIsFound();
    void ValueUntilCommaIsCopied();
    void NextCommaLocationIsFound();
    void LengthOfDataCharactersIsFound();
    void NextValueUntilCommaIsCopied();
    void ValueIsConvertedToFloat();
    void NextDataValueIsReturned();
};

SerialDataUTest::SerialDataUTest()
{

}

SerialDataUTest::~SerialDataUTest()
{

}



void SerialDataUTest::VolumeHeaderIsRemovedFromString()
{
    std::string volumeData = "Volume In: 51.88, 377";
    remove(volumeData, "Volume In: ");
    QCOMPARE(volumeData, "51.88, 377");
}



void SerialDataUTest::NextDataValueIsReturned()
{
    std::string data = "51.88, 377, 123";

    std::vector<std::size_t> commaLocations = findCommaLocations(data);
    std::string nextValue = copyDataValue(data, 0);

    QCOMPARE(nextValue, "51.88");

    nextValue = copyDataValue(data, 5+2);
    qDebug() << QString::fromStdString(nextValue);
    QCOMPARE(nextValue, "377");

}



void SerialDataUTest::CommaLocationIsFound()
{
    std::string data = "51.88, 377, 123";
    std::vector<std::size_t> commaLocations = findCommaLocations(data);
    QCOMPARE(commaLocations.at(0), 5);
    QCOMPARE(commaLocations.at(1), 10);
}



void SerialDataUTest::ValueUntilCommaIsCopied()
{
    std::string data = "51.88, 377, 123";
    std::size_t commaLocation = data.find(',');
    std::string newString = data.substr(0, commaLocation);

    QCOMPARE(newString, "51.88");
}

void SerialDataUTest::NextCommaLocationIsFound()
{
    std::string data = "51.88, 377, 123";
    std::size_t first = data.find(',');
    std::size_t next = data.find(',', first + 1);
    QCOMPARE(next, 10);
}

void SerialDataUTest::LengthOfDataCharactersIsFound()
{
    std::string data = "51.88, 377, 123";
    std::size_t begin = data.find(',');
    std::size_t beginOfData = begin+2;
    std::size_t end = data.find(',', beginOfData);
    std::size_t length = end - beginOfData;
    QCOMPARE(length, 3);
}


void SerialDataUTest::NextValueUntilCommaIsCopied()
{
    std::string data = "51.88, 377, 123";
    std::size_t begin = data.find(',');
    std::size_t beginOfData = begin+2;
    std::size_t end = data.find(',', beginOfData);
    std::size_t length = end - beginOfData;
    std::string newString = data.substr(beginOfData, length);
    QCOMPARE(newString, "377");
}


void SerialDataUTest::ValueIsConvertedToFloat()
{
    std::string value = "51.88";
    QVERIFY(qFuzzyCompare(std::stof(value), 51.88f));
}

//void VolumeDataHandlerUTest::VolumeInDataIsStoredInVolumeInPerformance()
//{
//    std::string volumeData = "Volume In: 51.88, 377";
//    handleVolume(volumeData, VOLUME_IN_HEADER);

//    QVERIFY(qFuzzyCompare(volumePerformance.volume, 51.88f));
//    QCOMPARE(volumePerformance.time, 377);
//}

//void VolumeDataHandlerUTest::VolumeOutDataIsStoredInVolumeOutPerformance()
//{
//    std::string volumeData = "Volume Out: 45.94, 690";
//    handleVolume(volumeData, VOLUME_OUT_HEADER);

//    QVERIFY(qFuzzyCompare(volumePerformance.volume, 45.94f));
//    QCOMPARE(volumePerformance.time, 690);
//}

QTEST_APPLESS_MAIN(SerialDataUTest)

#include "tst_serialdatautest.moc"
