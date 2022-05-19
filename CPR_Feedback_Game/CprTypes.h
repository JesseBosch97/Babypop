#ifndef CPRTYPES_H
#define CPRTYPES_H

enum feedBackTypes {NEUTRAL, START_COMPRESSION, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY, TOO_DEEP, TOO_SHALLOW,
                    CORRECT, WAY_TOO_LOW, TOO_LOW, TOO_HIGH, TOO_FAR_RIGHT, TOO_FAR_LEFT, TOO_MANY_PRESSURE_POINTS,
                    START_VENTILATION, VENTILATION_TOO_SHORT, VENTILATION_TOO_LONG, VENTILATION_TOO_MUCH, VENTILATION_TOO_LITTLE, PAUSE_TOO_LONG, PAUSE_TOO_SHORT };

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
    float volume = 0;
    int timeInMs = 0;
};

struct Compression
{
    int bpm = 0;
    int depthInCm = 0;
};

struct HeadPosition
{
    int angleInDegrees = 0;
};


#endif // CPRTYPES_H
