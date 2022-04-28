#include <QtTest>
#include "StringFunctions.h"

// add necessary includes here


//Volume In: 51.88, 377
//Volume Out: 45.94, 690


// Remove header Volume:
// Add 36.55 to VolumePerformance.volumeIn
// Add 40.37 to VolumePerformance.volumeOut
// Add 563 to VolumePerformance.ventilationTime


const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";


struct VolumePerformance
{
    float volume = 0;
    int time = 0;
};

class VolumeDataHandlerUTest : public QObject
{
    Q_OBJECT

public:
    VolumeDataHandlerUTest();
    ~VolumeDataHandlerUTest();

    VolumePerformance volumePerformance;


    void handleVolume(std::string * volumeData, std::string header)
    {
        removeFrom(volumeData, header);

        std::string volume = copyAndRemoveNextValue(volumeData);
        std::string ventilationTime = *volumeData;

        volumePerformance.volume = stof(volume);
        volumePerformance.time = stoi(ventilationTime);
    }


    std::string copyAndRemoveNextValue(std::string * volumeData)
    {
        std::string string = copyUntil(*volumeData, ',');

        removeFrom(volumeData, string);
        removeFrom(volumeData, ", ");

        return string;
    }



private slots:
    void VolumeInDataIsStoredInVolumeInPerformance();
    void VolumeOutDataIsStoredInVolumeOutPerformance();
    void VolumeHeaderIsRemovedFromString();
    void ValueUntilCommaIsCopied();
    void StringIsCleanedFromValueAndCommaAndSpace();
    void ValueIsConvertedToFloat();
};

VolumeDataHandlerUTest::VolumeDataHandlerUTest()
{

}

VolumeDataHandlerUTest::~VolumeDataHandlerUTest()
{

}

void VolumeDataHandlerUTest::VolumeInDataIsStoredInVolumeInPerformance()
{
    std::string volumeData = "Volume In: 51.88, 377";
    handleVolume(&volumeData, VOLUME_IN_HEADER);

    QVERIFY(qFuzzyCompare(volumePerformance.volume, 51.88f));
    QCOMPARE(volumePerformance.time, 377);
}

void VolumeDataHandlerUTest::VolumeOutDataIsStoredInVolumeOutPerformance()
{
    std::string volumeData = "Volume Out: 45.94, 690";
    handleVolume(&volumeData, VOLUME_OUT_HEADER);

    QVERIFY(qFuzzyCompare(volumePerformance.volume, 45.94f));
    QCOMPARE(volumePerformance.time, 690);
}

void VolumeDataHandlerUTest::VolumeHeaderIsRemovedFromString()
{
    std::string volumeData = "Volume In: 51.88, 377";
    removeFrom(&volumeData, "Volume In: ");
    QCOMPARE(volumeData, "51.88, 377");
}

void VolumeDataHandlerUTest::ValueUntilCommaIsCopied()
{
    std::string parsedVolumeData = "51.88, 377";
    QCOMPARE(copyUntil(parsedVolumeData, ','), "51.88");
}


void VolumeDataHandlerUTest::StringIsCleanedFromValueAndCommaAndSpace()
{
    std::string parsedVolumeData = "51.88, 377";
    copyAndRemoveNextValue(&parsedVolumeData);
    QCOMPARE(parsedVolumeData, "377");
}

void VolumeDataHandlerUTest::ValueIsConvertedToFloat()
{
    std::string value = "51.88";
    QVERIFY(qFuzzyCompare(std::stof(value), 51.88f));
}


QTEST_APPLESS_MAIN(VolumeDataHandlerUTest)

#include "tst_volumedatahandlerutest.moc"
