#include "bossgobuy.h"
#include "ui_bossgobuy.h"
#include "global.h"

BossGoBuy::BossGoBuy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossGoBuy)
{
    ui->setupUi(this);
    this->initSpinBoxProp();
    this->initSpinBoxConn();
}

BossGoBuy::~BossGoBuy()
{
    delete ui;
}

double BossGoBuy::Cost()
{
    return this->materialsCost;
}

void BossGoBuy::setCost(double value)
{
    Q_UNUSED(value);
    this->materialsCost = 0;
    for(int i=1; i<=9; ++i) {
        this->materialsCost += this->value[i];
    }
    emit(this->CostChanged(materialsCost));
}

void BossGoBuy::initSpinBoxProp()
{
    ui->OriginalCakeSpinBox->setProperty("isOriginalCake", true);
    ui->OriginalCakeSpinBox->setMaximum(9999);
    ui->SauceSpinBox->setProperty("isSauce", true);
    ui->SauceSpinBox->setMaximum(9999);
    ui->CilantroSpinBox->setProperty("isCilantro", true);
    ui->CilantroSpinBox->setMaximum(9999);
    ui->EggSpinBox->setProperty("isEgg", true);
    ui->EggSpinBox->setMaximum(9999);
    ui->CrispbreadSpinBox->setProperty("isCrispbread", true);
    ui->CrispbreadSpinBox->setMaximum(9999);
    ui->HamSpinBox->setProperty("isHam", true);
    ui->HamSpinBox->setMaximum(9999);
    ui->PotatoSpinBox->setProperty("isPotato", true);
    ui->PotatoSpinBox->setMaximum(9999);
    ui->LoinSpinBox->setProperty("isLoin", true);
    ui->LoinSpinBox->setMaximum(9999);
    ui->YoutiaoSpinBox->setProperty("isYoutiao", true);
    ui->YoutiaoSpinBox->setMaximum(9999);
}

void BossGoBuy::initSpinBoxConn()
{
    connect(this, SIGNAL(CostChanged(double)), this, SLOT(onCostChanged(double)));
    connect(ui->OriginalCakeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->SauceSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->CilantroSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->EggSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->CrispbreadSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->HamSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->PotatoSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->LoinSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
    connect(ui->YoutiaoSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSet()));
}

void BossGoBuy::onSpinBoxSet()
{
    QSpinBox *spinbox = qobject_cast<QSpinBox *>(sender());
    if(spinbox->property("isOriginalCake").toBool()) {
        this->value[1] = spinbox->text().toInt() * Global::QriginalCake;
        this->setCost(value[1]);
    } else if(spinbox->property("isSauce").toBool()) {
        this->value[2] = spinbox->text().toInt() * Global::Sauce;
        this->setCost(value[2]);
    } else if(spinbox->property("isCilantro").toBool()) {
        this->value[3] = spinbox->text().toInt() * Global::Cilantro;
        this->setCost(value[3]);
    } else if(spinbox->property("isEgg").toBool()) {
        this->value[4] = spinbox->text().toInt() * Global::Egg;
        this->setCost(value[4]);
    } else if(spinbox->property("isCrispbread").toBool()) {
        this->value[5] = spinbox->text().toInt() * Global::Crispbread;
        this->setCost(value[5]);
    } else if(spinbox->property("isHam").toBool()) {
        this->value[6] = spinbox->text().toInt() * Global::Ham;
        this->setCost(value[6]);
    } else if(spinbox->property("isPotato").toBool()) {
        this->value[7] = spinbox->text().toInt() * Global::Potato;
        this->setCost(value[7]);
    } else if(spinbox->property("isLoin").toBool()) {
        this->value[8] = spinbox->text().toInt() * Global::Loin;
        this->setCost(value[8]);
    } else if(spinbox->property("isYoutiao").toBool()) {
        this->value[9] = spinbox->text().toInt() * Global::Youtiao;
        this->setCost(value[9]);
    }
}

void BossGoBuy::onCostChanged(double value)
{
    Q_UNUSED(value);
    ui->labelMoney->setText(QString::asprintf("%.2lf", this->materialsCost));
}
