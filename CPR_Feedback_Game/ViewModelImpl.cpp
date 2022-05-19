#include "ViewModelImpl.h"

ViewModelImpl::ViewModelImpl(QObject *parent) : QObject(parent)
{

}

void ViewModelImpl::feedbackAmountSelected(int feedbackAmount)
{
    setFeedbackAmount(QString::number(feedbackAmount) + "%");
}

void ViewModelImpl::setFeedbackAmount(const QString &v)
{
    if (v != m_feedbackAmount) {
        m_feedbackAmount = v;
        emit feedbackAmountChanged();
    }
}

QString ViewModelImpl::feedbackAmount() const
{
    return m_feedbackAmount;
}




