/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#ifndef VIEWMODELIMPL_H
#define VIEWMODELIMPL_H

#include <QObject>
#include <QDebug>

class ViewModelImpl : public QObject
{
   Q_OBJECT
   Q_PROPERTY(float babyWeight_mg READ babyWeight_mg NOTIFY babyWeightChanged)


public:
   explicit ViewModelImpl(QObject *parent = nullptr);

   void setBabyWeight_mg(const float &v);
   float babyWeight_mg() const;

private:
   float m_babyWeight_mg = 3000;

signals:
   void babyWeightChanged();

};

#endif // VIEWMODELIMPL_H
