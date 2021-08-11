#include "bossgobuy.h"
#include "ui_bossgobuy.h"

BossGoBuy::BossGoBuy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossGoBuy)
{
    ui->setupUi(this);
}

BossGoBuy::~BossGoBuy()
{
    delete ui;
}
