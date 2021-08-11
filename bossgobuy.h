#ifndef BOSSGOBUY_H
#define BOSSGOBUY_H

#include <QWidget>

namespace Ui {
class BossGoBuy;
}

class BossGoBuy : public QWidget
{
    Q_OBJECT

public:
    explicit BossGoBuy(QWidget *parent = nullptr);
    ~BossGoBuy();

private:
    Ui::BossGoBuy *ui;
};

#endif // BOSSGOBUY_H
