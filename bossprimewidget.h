#ifndef BOSSPRIMEWIDGET_H
#define BOSSPRIMEWIDGET_H

#include "goods.h"
#include "qperson.h"
#include <QWidget>

namespace Ui {
class BossPrimeWidget;
}

class BossPrimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BossPrimeWidget(QWidget *parent = nullptr);
    ~BossPrimeWidget();
    void initLableMoney();
    void initSlodInfo();

private:
    Ui::BossPrimeWidget *ui;
    QPerson * user;
    goods * value;
};

#endif // BOSSPRIMEWIDGET_H
