#ifndef COMPRESSIONDATAHANDLER_H
#define COMPRESSIONDATAHANDLER_H

#include "CprTypes.h"
#include "StringFunctions.h"
#include <iostream>

class CompressionDataHandler
{
public:
    CompressionDataHandler();

    Compression compression;
    void handleCompression(std::string & compressionData, std::string header);

};

#endif // COMPRESSIONDATAHANDLER_H
