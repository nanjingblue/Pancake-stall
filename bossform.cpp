#include "bossform.h"
#include "ui_bossform.h"

BossForm::BossForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

BossForm::~BossForm()
{
    delete ui;
}
