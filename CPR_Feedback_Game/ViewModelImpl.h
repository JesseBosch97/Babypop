#ifndef VIEWMODELIMPL_H
#define VIEWMODELIMPL_H

#include <QObject>
#include <QDebug>
#include "ViewModel.h"

class ViewModelImpl : public QObject, public ViewModel
{
   Q_OBJECT
   Q_PROPERTY(QString feedbackAmount READ feedbackAmount NOTIFY feedbackAmountChanged)

public:
   explicit ViewModelImpl(QObject *parent = nullptr);

   void feedbackAmountSelected(int feedbackAmount) override;

   void setFeedbackAmount(const QString &v);

   QString feedbackAmount() const;


private:
   QString m_feedbackAmount = "";


signals:
   void feedbackAmountChanged();

};

#endif // VIEWMODELIMPL_H
