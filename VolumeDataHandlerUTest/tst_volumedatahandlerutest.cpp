#include <QtTest>
#include "StringFunctions.h"

// add necessary includes here



//Volume: 36.55, 40.47, 563

// Remove header Volume:
// Add 36.55 to VolumePerformance.volumeIn
// Add 40.37 to VolumePerformance.volumeOut
// Add 563 to VolumePerformance.ventilationTime

struct VolumePerformance
{
    float volumeIn = 0;
    float volumeOut = 0;
    int ventilationTime = 0;
};

class VolumeDataHandlerUTest : public QObject
{
    Q_OBJECT

public:
    VolumeDataHandlerUTest();
    ~VolumeDataHandlerUTest();

    VolumePerformance volumePerformance;

    void handleVolumeData(std::string * volumeData)
    {
        removeFrom(volumeData, "Volume: ");

        std::string volumeIn = copyAndClean(volumeData);
        std::string volumeOut = copyAndClean(volumeData);
        std::string ventilationTime = *volumeData;

        volumePerformance.volumeIn = stof(volumeIn);
        volumePerformance.volumeOut = stof(volumeOut);
        volumePerformance.ventilationTime = stoi(ventilationTime);
    }


    std::string copyAndClean(std::string * volumeData)
    {
        std::string string = copyUntil(*volumeData, ',');

        removeFrom(volumeData, string);
        removeFrom(volumeData, ", ");

        return string;
    }



private slots:
    void VolumeHeaderIsRemovedFromString();
    void ValueUntilCommaIsCopied();
    void StringIsCleanedFromValueAndCommaAndSpace();
    void ValueIsConvertedToFloat();
    void VolumeDataIsStoredInVolumePerformance();
};

VolumeDataHandlerUTest::VolumeDataHandlerUTest()
{

}

VolumeDataHandlerUTest::~VolumeDataHandlerUTest()
{

}

void VolumeDataHandlerUTest::VolumeDataIsStoredInVolumePerformance()
{
    std::string volumeData = "Volume: 36.55, 40.47, 563";
    handleVolumeData(&volumeData);

    QVERIFY(qFuzzyCompare(volumePerformance.volumeIn, 36.55f));
    QVERIFY(qFuzzyCompare(volumePerformance.volumeOut, 40.47f));
    QCOMPARE(volumePerformance.ventilationTime, 563);

}

void VolumeDataHandlerUTest::VolumeHeaderIsRemovedFromString()
{
    std::string volumeData = "Volume: 36.55, 40.47, 563";
    removeFrom(&volumeData, "Volume: ");
    QCOMPARE(volumeData, "36.55, 40.47, 563");
}

void VolumeDataHandlerUTest::ValueUntilCommaIsCopied()
{
    std::string parsedVolumeData = "36.55, 40.47, 563";
    QCOMPARE(copyUntil(parsedVolumeData, ','), "36.55");
}


void VolumeDataHandlerUTest::StringIsCleanedFromValueAndCommaAndSpace()
{
    std::string parsedVolumeData = "36.55, 40.47, 563";
    copyAndClean(&parsedVolumeData);
    QCOMPARE(parsedVolumeData, "40.47, 563");
}

void VolumeDataHandlerUTest::ValueIsConvertedToFloat()
{
    std::string value = "36.55";
    QVERIFY(qFuzzyCompare(std::stof(value), 36.55f));
}











QTEST_APPLESS_MAIN(VolumeDataHandlerUTest)

#include "tst_volumedatahandlerutest.moc"
