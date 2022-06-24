/// @date 23-6-2022
/// @author Jesse Bosch
/// @version 1.0

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
