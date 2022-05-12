#include "CompressionDataHandler.h"

CompressionDataHandler::CompressionDataHandler()
{

}



void CompressionDataHandler::handleCompression(std::string & compressionData, std::string header)
{
    std::cout << "CompressionDataHandler: received compression: " << compressionData << std::endl;

    removeFrom(compressionData, header);

    std::string bpm = copyAndRemoveNextValue(compressionData);
    std::string depth = compressionData;

    compression.bpm = stoi(bpm);
    compression.depth = stoi(depth);
}



