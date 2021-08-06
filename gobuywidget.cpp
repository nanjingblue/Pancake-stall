#include "gobuywidget.h"
#include "ui_gobuywidget.h"
#include "qcustomer.h"
#include "global.h"
#include "cake.h"


goBuyWidget::goBuyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goBuyWidget)
{
    ui->setupUi(this);
    this->user = new QCustomer(Global::username, Global::password);
    this->cake = new Cake;
    // 为菜单设置属性
   this->initCheckBoxProp();
    this->initCheckBoxConn();
}

goBuyWidget::~goBuyWidget()
{
    delete ui;
}

void goBuyWidget::initCheckBoxProp()
{
    ui->OriginalCake->setProperty("isQriginalCake", true);
    ui->Sauce->setProperty("isSauce", true);
    ui->Egg->setProperty("isEgg", true);
    ui->Cilantro->setProperty("isCilantro", true);
    ui->Crispbread->setProperty("isCrispbread", true);
    ui->Ham->setProperty("isHam", true);
    ui->Potato->setProperty("isPotato", true);
    ui->Loin->setProperty("isLoin", true);
}

void goBuyWidget::initCheckBoxConn()
{
    connect(this->cake, &Cake::CostChanged, this, &goBuyWidget::onCostChanged);
    connect(ui->OriginalCake, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Sauce, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Egg, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Cilantro, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Crispbread, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Ham, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Potato, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->Loin, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
}

void goBuyWidget::onCheckBoxPicked()
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    bool status = checkBox->isChecked();
    if (status ==true ) {
        if(checkBox->property("isQriginalCake").toBool()) {
            cake->setCost(Cake::QriginalCake);
        } else if(checkBox->property("isSauce").toBool()) {
            cake->setCost(Cake::Sauce);
        } else if(checkBox->property("isEgg").toBool()) {
            cake->setCost(Cake::Egg);
        } else if(checkBox->property("isCilantro").toBool()) {
            cake->setCost(Cake::Cilantro);
        } else if(checkBox->property("isCrispbread").toBool()) {
            cake->setCost(Cake::Crispbread);
        } else if(checkBox->property("isHam").toBool()) {
            cake->setCost(Cake::Ham);
        } else if(checkBox->property("isPotato").toBool()) {
            cake->setCost(Cake::Potato);
        } else if(checkBox->property("isLoin").toBool()) {
            cake->setCost(Cake::Loin);
        }
    } else {
        if(checkBox->property("isQriginalCake").toBool()) {
            cake->setCost(-Cake::QriginalCake);
        } else if(checkBox->property("isSauce").toBool()) {
            cake->setCost(-Cake::Sauce);
        } else if(checkBox->property("isEgg").toBool()) {
            cake->setCost(-Cake::Egg);
        } else if(checkBox->property("isCilantro").toBool()) {
            cake->setCost(-Cake::Cilantro);
        } else if(checkBox->property("isCrispbread").toBool()) {
            cake->setCost(-Cake::Crispbread);
        } else if(checkBox->property("isHam").toBool()) {
            cake->setCost(-Cake::Ham);
        } else if(checkBox->property("isPotato").toBool()) {
            cake->setCost(-Cake::Potato);
        } else if(checkBox->property("isLoin").toBool()) {
            cake->setCost(-Cake::Loin);
        }
    }
}

void goBuyWidget::onCostChanged()
{
    Cake * aCake= qobject_cast<Cake *>(sender());
    int aCost = aCake->Cost();
    ui->label->setText(QString::asprintf("%d", aCost));
}

void goBuyWidget::on_pushButton_clicked()
{
    user->cake = this->cake;
}
