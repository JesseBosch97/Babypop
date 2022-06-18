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
        std::vector<std::size_t> startLocations = findDataValueStartLocations(data, ", ");
        size_t loopAmount = startLocations.size();
        std::vector<std::string> dataCollection;

        for (int i = 0; i < static_cast<int>(loopAmount); i++)
        {
            std::string nextData = copyDataValue(data, startLocations.at(i));
            dataCollection.push_back(nextData);
        }

        return dataCollection;
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

    std::vector<std::size_t> findDataValueStartLocations(std::string & data, std::string separationCharacters)
    {
        std::vector<std::size_t> startLocations = findCharacterLocations(data, separationCharacters);

        for (auto & el : startLocations)
        {
            el += separationCharacters.size();
        }

        startLocations.insert(startLocations.begin(), 0);
        return startLocations;
    }





private slots:
    void VolumeHeaderIsRemovedFromString();
    void DataValueStartLocationsAreFound();
    void ValueIsConvertedToFloat();
    void TheFirstDataValueIsCopied();
    void AllTheDataValuesAreReturned();
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

void SerialDataUTest::DataValueStartLocationsAreFound()
{
    std::string data = "51.88, 377, 123";
    std::vector<std::size_t> startLocations = findDataValueStartLocations(data, ", ");
    QCOMPARE(startLocations.at(0), 0);
    QCOMPARE(startLocations.at(1), 7);
    QCOMPARE(startLocations.at(2), 12);
}



void SerialDataUTest::TheFirstDataValueIsCopied()
{
    std::string data = "51.88, 377, 123";
    std::vector<std::size_t> startLocations = findDataValueStartLocations(data, ", ");
    std::string value = copyDataValue(data, startLocations[0]);

    QCOMPARE(value, "51.88");
}

void SerialDataUTest::AllTheDataValuesAreReturned()
{
    std::string data = "51.88, 377, 123";
    std::vector<std::string> dataValues = collectData(data);

    QCOMPARE(dataValues.at(0), "51.88");
    QCOMPARE(dataValues.at(1), "377");
    QCOMPARE(dataValues.at(2), "123");
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
