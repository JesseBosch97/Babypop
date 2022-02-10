#include "requestmodel.h"


RequestModel::RequestModel(QObject *parent)
{
    Q_UNUSED(parent)
}

void RequestModel::compressionButtonPressed()
{
    std::cout << "RequestModel: Compression button pressed" << std::endl;
    output->compressionPerformed();
}


