#include <QtTest>
#include "../StringFunctions.h"
// add necessary includes here

struct VolumePerformance
{
    float volume = 0;
    int time = 0;
};

class SerialDataUTest : public QObject
{
    Q_OBJECT

public:
    SerialDataUTest();
    ~SerialDataUTest();

    VolumePerformance volumePerformance;


//    void handleVolume(std::string & volumeData, std::string header)
//    {
//        remove(volumeData, header);

//        std::string volume = copyAndRemoveNextValue(volumeData);
//        std::string ventilationTime = volumeData;

//        volumePerformance.volume = stof(volume);
//        volumePerformance.time = stoi(ventilationTime);
//    }





private slots:
    //void VolumeInDataIsStoredInVolumeInPerformance();
    //void VolumeOutDataIsStoredInVolumeOutPerformance();
    void VolumeHeaderIsRemovedFromString();
    void ValueUntilCommaIsCopied();
    //void StringIsCleanedFromValueAndCommaAndSpace();
    void ValueIsConvertedToFloat();
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

void SerialDataUTest::ValueUntilCommaIsCopied()
{
    std::string parsedVolumeData = "51.88, 377";
    QCOMPARE(copyUntil(parsedVolumeData, ','), "51.88");
}


//void SerialDataUTest::StringIsCleanedFromValueAndCommaAndSpace()
//{
//    std::string parsedVolumeData = "51.88, 377";
//    remove(parsedVolumeData, "51.88");
//    remove(parsedVolumeData, ", ");
//    QCOMPARE(parsedVolumeData, "377");
//}

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
