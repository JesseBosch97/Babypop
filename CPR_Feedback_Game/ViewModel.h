#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include <QDebug>
#include <SerialPortBoundary.h>

class ViewModel : public QObject
{
   Q_OBJECT
   Q_PROPERTY(QStringList portList READ portList NOTIFY portListChanged)

public:
   explicit ViewModel(QObject *parent = nullptr);


   void setPortList(const QStringList &v);

   QStringList portList() const;



private:
   QStringList m_portList;


signals:
   void portListChanged();

};

#endif // VIEWMODEL_H
