#ifndef CUSTOMERFORM_H
#define CUSTOMERFORM_H

#include "gobuywidget.h"
#include "gobuyvip.h"
#include "gocomment.h"
#include "showcomment.h"
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
    void initBtnConn();

public slots:
    void onBtnHome();
    void onBtnVip();
    void onBtnComment();
    void onBtnShowComment();
private:
    Ui::CustomerForm *ui;
    goBuyWidget * goBuyPage;
    GoBuyVip *goBuyVip;
    GoComment * comment;
    ShowComment * showCommentPage;

};

#endif // CUSTOMERFORM_H
