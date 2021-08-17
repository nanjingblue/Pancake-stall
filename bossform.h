#ifndef BOSSFORM_H
#define BOSSFORM_H

#include "bossprimewidget.h"
#include "bossgobuy.h"
#include "bosssolddetails.h"
#include "showcomment.h"
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
    void onBtnCommentClicked();

private:
    Ui::BossForm *ui;
    BossPrimeWidget * bossHomePage;
    BossGoBuy * bossGoBuyPage;
    BossSoldDetails * soldDetailsPage;
    ShowComment * commentPage;
};

#endif // BOSSFORM_H
