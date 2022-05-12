#ifndef HEADPOSITIONDATAHANDLER_H
#define HEADPOSITIONDATAHANDLER_H

#include "CprTypes.h"

class HeadPositionDataHandler
{
public:
    HeadPositionDataHandler();

    HeadPosition headPosition;

    void handleHeadPosition();
};

#endif // HEADPOSITIONDATAHANDLER_H
