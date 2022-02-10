#include "requestmodel.h"


RequestModel::RequestModel(QObject *parent)
{
    Q_UNUSED(parent)

}

void RequestModel::compressionButtonPressed()
{
    qDebug() << "CompressionButtonPressed";
}
