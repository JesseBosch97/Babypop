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

struct FlowPerformance
{
    int ventilationTime = 0;
    int pauseTime = 0;
    int averageFlowStrength = 0;
    int maxFlowStrength = 0;
};

struct VolumePerformance
{
    float volumeIn = 0;
    float volumeOut = 0;
    int ventilationTime = 0;
};

#endif // PERFORMANCETYPES_H
