#ifndef PERFORMANCETYPES_H
#define PERFORMANCETYPES_H

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

struct Ventilation
{
    float volume = 0;
    int time = 0;
};


#endif // PERFORMANCETYPES_H
