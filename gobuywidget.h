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
signals:
    void checkBoxPicked();

public slots:
    void onCheckBoxPicked();
    void onCostChanged();


private:
    Ui::goBuyWidget *ui;
    QPerson *user;
    Cake * cake;

public:
    bool isAdmin;
private slots:
    void on_pushButton_clicked();
};

#endif // GOBUYWIDGET_H
