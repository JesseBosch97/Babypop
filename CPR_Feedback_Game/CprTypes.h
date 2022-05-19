#ifndef CPRTYPES_H
#define CPRTYPES_H

enum feedBackTypes {NEUTRAL, START_COMPRESSION, PERFECT, TOO_SLOW, TOO_FAST, TOO_MANY,
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
    int time = 0;
};

struct Compression
{
    int bpm = 0;
    int depth = 0;
};

struct HeadPosition
{
};


#endif // CPRTYPES_H
