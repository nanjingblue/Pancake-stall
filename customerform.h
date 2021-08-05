#ifndef CUSTOMERFORM_H
#define CUSTOMERFORM_H

#include "gobuywidget.h"
#include <QWidget>

namespace Ui {
class CustomerForm;
}

class CustomerForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerForm(QWidget *parent = nullptr);
    ~CustomerForm();

private:
    Ui::CustomerForm *ui;
    goBuyWidget * goBuyPage;
};

#endif // CUSTOMERFORM_H
