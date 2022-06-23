#ifndef SERIALPROCESSOR_H
#define SERIALPROCESSOR_H

#include <QObject>

class SerialProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SerialProcessor(QObject *parent = nullptr);

signals:

};

#endif // SERIALPROCESSOR_H
