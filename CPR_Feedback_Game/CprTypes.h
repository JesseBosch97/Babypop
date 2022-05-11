#ifndef CPRTYPES_H
#define CPRTYPES_H

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
};

struct HeadPosition
{
};


#endif // CPRTYPES_H
