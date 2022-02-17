#include "ViewModel.h"

ViewModel::ViewModel(QObject *parent) : QObject(parent)
{

}


void ViewModel::setPortList(const QStringList &v)
{
    qDebug() << "in viewmodel: set portlist";
    if (v != m_portList) {
        m_portList = v;
        emit portListChanged();
    }
    qDebug() << "in viewmodel: after set portlist";
}

QStringList ViewModel::portList() const
{
    return m_portList;
}

