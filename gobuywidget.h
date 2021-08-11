#ifndef GOBUYWIDGET_H
#define GOBUYWIDGET_H

#include "qperson.h"
#include "cake.h"
#include <QWidget>

namespace Ui {
class goBuyWidget;
}

class goBuyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit goBuyWidget(QWidget *parent = nullptr);
    ~goBuyWidget();
    void initCheckBoxProp();
    void initCheckBoxConn();
    void initLabelVipInfo();
    void initObject();
    void clearCheckBox();
signals:
    void checkBoxPicked();

private slots:
    void onCheckBoxPicked();
    void onCostChanged();
    void onBtnGoBuyClicked();

private:
    Ui::goBuyWidget *ui;
    QPerson *user;
    Cake * cake;

public:
    bool isAdmin;
};

#endif // GOBUYWIDGET_H
