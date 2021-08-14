#ifndef BOSSGOBUY_H
#define BOSSGOBUY_H

#include <QWidget>

namespace Ui {
class BossGoBuy;
}

class BossGoBuy : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double Cost READ Cost WRITE setCost NOTIFY CostChanged)

public:
    explicit BossGoBuy(QWidget *parent = nullptr);
    ~BossGoBuy();
    double Cost();
    void setCost(double value);
    void initSpinBoxProp();
    void initConn();
signals:
    void CostChanged(double value);

public  slots:
    void onSpinBoxSet();
    void onCostChanged(double value);
    void onBtnBossGoBuyClicked();

private:
    Ui::BossGoBuy *ui;
    double materialsCost = 0;
    double value[10] = {0};
    int num[10] = {0};
};

#endif // BOSSGOBUY_H
