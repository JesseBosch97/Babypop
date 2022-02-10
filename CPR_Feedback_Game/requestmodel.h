#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QDebug>

class RequestModel : public QObject
{
    Q_OBJECT
public:
    RequestModel(QObject* parent = nullptr);

public slots:
    void compressionButtonPressed();
};

#endif // REQUESTMODEL_H
