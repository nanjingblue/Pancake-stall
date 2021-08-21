#include "bossprimewidget.h"
#include "ui_bossprimewidget.h"
#include "global.h"
#include "qboss.h"
#include "goods.h"

BossPrimeWidget::BossPrimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossPrimeWidget)
{
    ui->setupUi(this);
    this->value = new goods[10];
    this->initLableMoney();
    this->initSlodInfo();
}

BossPrimeWidget::~BossPrimeWidget()
{
    delete ui;
    delete []value;
}

void BossPrimeWidget::initLableMoney()
{
    QBoss boss(Global::username, Global::password);
    ui->labelSales->setText(QString::asprintf("%.2lf", boss.sales));
    ui->labelMaterialCosts->setText(QString::asprintf("%.2lf", boss.materialCosts));
    ui->labelProfits->setText(QString::asprintf("%.2lf", boss.profits));
}

void BossPrimeWidget::initSlodInfo()
{
    Global::database->getSoldInfo(this->value);
    ui->OriginalCakeSales->setText(QString::asprintf("%d", value[1].Sales));
    ui->OriginalCakeHave->setText(QString::asprintf("%d", value[1].Inventory));
    ui->SauceSales->setText(QString::asprintf("%d", value[2].Sales));
    ui->SauceHave->setText(QString::asprintf("%d", value[2].Inventory));
    ui->CilantroSales->setText(QString::asprintf("%d", value[3].Sales));
    ui->CilantroHave->setText(QString::asprintf("%d", value[3].Inventory));
    ui->EggSales->setText(QString::asprintf("%d", value[4].Sales));
    ui->EggHave->setText(QString::asprintf("%d", value[4].Inventory));
    ui->CrispbreadSales->setText(QString::asprintf("%d", value[5].Sales));
    ui->CrispbreadHave->setText(QString::asprintf("%d", value[5].Inventory));
    ui->HamSales->setText(QString::asprintf("%d", value[6].Sales));
    ui->HamHave->setText(QString::asprintf("%d", value[6].Inventory));
    ui->PotatoSales->setText(QString::asprintf("%d", value[7].Sales));
    ui->PotatoHave->setText(QString::asprintf("%d", value[7].Inventory));
    ui->LoinSales->setText(QString::asprintf("%d", value[8].Sales));
    ui->LoinHave->setText(QString::asprintf("%d", value[8].Inventory));
    ui->YoutiaoSales->setText(QString::asprintf("%d", value[9].Sales));
    ui->YoutiaoHave->setText(QString::asprintf("%d", value[9].Inventory));
}
