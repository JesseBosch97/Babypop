#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include <QDebug>
#include "FeedbackHandlerBoundaries.h"

class ViewModel : public QObject, public FeedbackHandlerToViewModel
{
   Q_OBJECT
   Q_PROPERTY(QString feedbackAmount READ feedbackAmount NOTIFY feedbackAmountChanged)

public:
   explicit ViewModel(QObject *parent = nullptr);

   void feedbackAmountSelected(int feedbackAmount) override;

   void setFeedbackAmount(const QString &v);

   QString feedbackAmount() const;


private:
   QString m_feedbackAmount = "";


signals:
   void feedbackAmountChanged();

};

#endif // VIEWMODEL_H
