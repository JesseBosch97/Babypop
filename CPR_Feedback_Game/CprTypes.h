#ifndef CPRTYPES_H
#define CPRTYPES_H

#include <cstdint>
#include <string>


const std::string VOLUME_IN_HEADER = "Volume In: ";
const std::string VOLUME_OUT_HEADER = "Volume Out: ";
const std::string COMPRESSION_HEADER = "Compression: ";
const std::string FINGER_POSITION_HEADER = "[";
const std::string HEAD_POSITION_HEADER = "Head Position: ";


enum FeedBackTypes {NEUTRAL, START_COMPRESSION, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY, TOO_DEEP, TOO_SHALLOW,
                    CORRECT, WAY_TOO_LOW, TOO_LOW, TOO_HIGH, TOO_FAR_RIGHT, TOO_FAR_LEFT, TOO_MANY_PRESSURE_POINTS, NO_TOUCH,
                    START_VENTILATION, TOO_MUCH, TOO_LITTLE, TOO_LONG, TOO_SHORT };

typedef uint8_t FeedbackType;

struct FingerPosition
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

struct Ventilation
{
    float volumeInMl = 0;
    int timeInMs = 0;
};

struct Compression
{
    int bpm = 0;
    int depthInMm = 0;
};

struct HeadPosition
{
    int angleInDegrees = 0;
};


#endif // CPRTYPES_H
