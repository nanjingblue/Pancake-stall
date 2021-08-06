#ifndef GOBUYVIP_H
#define GOBUYVIP_H

#include "global.h"
#include <QWidget>

namespace Ui {
class GoBuyVip;
}

class GoBuyVip : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int Cost READ Cost WRITE setCost NOTIFY CostChanged)
public:
    explicit GoBuyVip(QWidget *parent = nullptr);
    ~GoBuyVip();
    int Cost();
    void initCheckBoxProp();
    void initConn();
    void setCost(int value);

signals:
    void CostChanged(int value);

public slots:
    void onCostChanged();
    void onCheckBoxPicked();
    void onBtnCasualCliked();

private:
    Ui::GoBuyVip *ui;
    int vipCost = 0;

public:
    static int vipYear;
    static int vipSeason;
    static int vipMonth;
};

#endif // GOBUYVIP_H
