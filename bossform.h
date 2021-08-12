#ifndef BOSSFORM_H
#define BOSSFORM_H

#include "bossgobuy.h"
#include <QWidget>

namespace Ui {
class BossForm;
}

class BossForm : public QWidget
{
    Q_OBJECT

public:
    explicit BossForm(QWidget *parent = nullptr);
    ~BossForm();

private:
    Ui::BossForm *ui;
    BossGoBuy * bossGoBuyPage;
};

#endif // BOSSFORM_H
