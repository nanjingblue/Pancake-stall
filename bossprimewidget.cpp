#include "bossprimewidget.h"
#include "ui_bossprimewidget.h"
#include "global.h"
#include "qboss.h"

BossPrimeWidget::BossPrimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossPrimeWidget)
{
    ui->setupUi(this);
    this->initLableMoney();
}

BossPrimeWidget::~BossPrimeWidget()
{
    delete ui;
}

void BossPrimeWidget::initLableMoney()
{
    QBoss boss(Global::username, Global::password);
    ui->labelSales->setText(QString::asprintf("%.2lf", boss.sales));
    ui->labelMaterialCosts->setText(QString::asprintf("%.2lf", boss.materialCosts));
    ui->labelProfits->setText(QString::asprintf("%.2lf", boss.profits));
}
