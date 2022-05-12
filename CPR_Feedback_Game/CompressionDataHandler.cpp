#include "CompressionDataHandler.h"

CompressionDataHandler::CompressionDataHandler()
{

}

Compression CompressionDataHandler::handleCompression(std::vector<std::string> compressionData)
{
    Compression compression;
    compression.bpm = stoi(compressionData.at(0));
    compression.depth = stoi(compressionData.at(1));
    return compression;
}



//void CompressionDataHandler::handleCompression(, std::string header)
//{
//    std::cout << "CompressionDataHandler: received compression: " << compressionData << std::endl;

//    removeFrom(compressionData, header);

//    std::string bpm = copyAndRemoveNextValue(compressionData);
//    std::string depth = compressionData;

//    compression.bpm = stoi(bpm);
//    compression.depth = stoi(depth);
//}



