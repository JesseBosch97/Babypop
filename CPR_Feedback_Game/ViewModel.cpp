#include "ViewModel.h"

ViewModel::ViewModel(QObject *parent) : QObject(parent)
{

}

void ViewModel::feedbackAmountSelected(int feedbackAmount)
{
    setFeedbackAmount(QString::number(feedbackAmount) + "%");
}

void ViewModel::setFeedbackAmount(const QString &v)
{
    if (v != m_feedbackAmount) {
        m_feedbackAmount = v;
        emit feedbackAmountChanged();
    }
}

QString ViewModel::feedbackAmount() const
{
    return m_feedbackAmount;
}




