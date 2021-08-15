#ifndef BOSSFORM_H
#define BOSSFORM_H

#include "bossprimewidget.h"
#include "bossgobuy.h"
#include "bosssolddetails.h"
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

    void initConn();

private slots:
    void onBtnHomeClicked();
    void onBtnBuyClicked();
    void onBtnSoldDetailsClicked();

private:
    Ui::BossForm *ui;
    BossPrimeWidget * bossHomePage;
    BossGoBuy * bossGoBuyPage;
    BossSoldDetails * soldDetailsPage;
};

#endif // BOSSFORM_H
