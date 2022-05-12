#ifndef COMPRESSIONDATAHANDLER_H
#define COMPRESSIONDATAHANDLER_H

#include "CprTypes.h"
#include <iostream>
#include <vector>

class CompressionDataHandler
{
public:
    CompressionDataHandler();

    Compression handleCompression(std::vector<std::string> compressionData);

};

#endif // COMPRESSIONDATAHANDLER_H
