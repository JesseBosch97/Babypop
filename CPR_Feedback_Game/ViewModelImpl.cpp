/// @date 23-6-2022
/// @author Niels van Kessel
/// @version 1.0

#include "ViewModelImpl.h"

ViewModelImpl::ViewModelImpl(QObject *parent) : QObject(parent)
{

}



void ViewModelImpl::setBabyWeight_mg(const float &v)
{
    if (v != m_babyWeight_mg) {
        m_babyWeight_mg = v;
        emit babyWeightChanged();
    }
}

float ViewModelImpl::babyWeight_mg() const
{
    return m_babyWeight_mg;
}






