#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <iostream>
#include "requestmodelboundary.h"

class RequestModel : public QObject
{
    Q_OBJECT
public:
    RequestModel(QObject* parent = nullptr);
    RequestModelBoundary * output;

public slots:
    void compressionButtonPressed();
};

#endif // REQUESTMODEL_H
