#ifndef VIEWMODEL_H
#define VIEWMODEL_H





class ViewModel
{
public:
   virtual ~ViewModel() = default;
    virtual void feedbackAmountSelected(int feedbackAmount) = 0;
};


#endif // VIEWMODEL_H
