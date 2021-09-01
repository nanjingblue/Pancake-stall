#include "gobuywidget.h"
#include "ui_gobuywidget.h"
#include "qcustomer.h"
#include "global.h"
#include "cake.h"
#include <QDebug>
#include <QMessageBox>


goBuyWidget::goBuyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goBuyWidget)
{
    ui->setupUi(this);
    this->initObject();
    this->value = new goods[10];
    Global::database->getSoldInfo(value);
}

goBuyWidget::~goBuyWidget()
{
    delete ui;
    delete this->cake;
    delete this->user;
    delete [] value;
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
    ui->Youtiao->setProperty("isYoutiao", true);
}

void goBuyWidget::initCheckBoxConn()
{
    connect(this->cake, &Cake::CostChanged, this, &goBuyWidget::onCostChanged);
    connect(ui->OriginalCake, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Sauce, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Egg, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Cilantro, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Crispbread, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Ham, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Potato, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Loin, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->Youtiao, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->btnGoBuy, SIGNAL(clicked()), this, SLOT(onBtnGoBuyClicked()));
}

void goBuyWidget::initLabelVipInfo()
{
    int echo = Global::database->isVip(Global::username);
    if(echo ==0) {
        ui->labelVipInfo->setText("普通用户");
    } else if(echo == 1) {
        ui->labelVipInfo->setText("皇冠年卡会员，享受 8 折优惠");
    } else if(echo == 2) {
        ui->labelVipInfo->setText("钻石季卡会员，享受 8.5 折优惠");
    } else if(echo == 3) {
        ui->labelVipInfo->setText("普通月卡会员，享受 9 折优惠");
    }
}

void goBuyWidget::initObject()
{
    this->user = new QCustomer(Global::username, Global::password);
    this->cake = new Cake;
    // 为菜单设置属性
    this->initCheckBoxProp();
    this->initCheckBoxConn();
    this->initLabelVipInfo();
     //ui->OriginalCake->setChecked(true); // Default QriginalCake
}

void goBuyWidget::clearCheckBox()
{
    ui->OriginalCake->setChecked(false);
    ui->Sauce->setChecked(false);
    ui->Cilantro->setChecked(false);
    ui->Egg->setChecked(false);
    ui->Crispbread->setChecked(false);
    ui->Ham->setChecked(false);
    ui->Potato->setChecked(false);
    ui->Loin->setChecked(false);
    ui->Youtiao->setChecked(false);
}

void goBuyWidget::onCheckBoxPicked()
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    bool status = checkBox->isChecked();
    if (status == true ) {
        if(checkBox->property("isQriginalCake").toBool()) {
            if(value[1].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::QriginalCake);
            cake->value[1]++;
        } else if(checkBox->property("isSauce").toBool()) {
            if(value[2].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setCheckable(false);
                return;
            }
            cake->setCost(Global::Sauce);
            cake->value[2]++;
        } else if(checkBox->property("isEgg").toBool()) {
            if(value[3].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Egg);
            cake->value[3]++;
        } else if(checkBox->property("isCilantro").toBool()) {
            if(value[4].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Cilantro);
            cake->value[4]++;
        } else if(checkBox->property("isCrispbread").toBool()) {
            if(value[5].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Crispbread);
            cake->value[5]++;
        } else if(checkBox->property("isHam").toBool()) {
            if(value[6].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Ham);
            cake->value[6]++;
        } else if(checkBox->property("isPotato").toBool()) {
            if(value[7].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Potato);
            cake->value[7]++;
        } else if(checkBox->property("isLoin").toBool()) {
            if(value[8].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Loin);
            cake->value[8]++;
        } else if(checkBox->property("isYoutiao").toBool()) {
            if(value[9].Inventory < 1) {
                QMessageBox::information(this, "GoBuyGoods", "库存不足, 请登录店主账号购买");
                checkBox->setChecked(false);
                return;
            }
            cake->setCost(Global::Youtiao);
            cake->value[9]++;
        }
    } else {
        if(checkBox->property("isQriginalCake").toBool()) {
            cake->setCost(-Global::QriginalCake);
            cake->value[1]--;
        } else if(checkBox->property("isSauce").toBool()) {
            cake->setCost(-Global::Sauce);
            cake->value[2]--;
        } else if(checkBox->property("isEgg").toBool()) {
            cake->setCost(-Global::Egg);
            cake->value[3]--;
        } else if(checkBox->property("isCilantro").toBool()) {
            cake->setCost(-Global::Cilantro);
            cake->value[4]--;
        } else if(checkBox->property("isCrispbread").toBool()) {
            cake->setCost(-Global::Crispbread);
            cake->value[5]--;
        } else if(checkBox->property("isHam").toBool()) {
            cake->setCost(-Global::Ham);
            cake->value[6]--;
        } else if(checkBox->property("isPotato").toBool()) {
            cake->setCost(-Global::Potato);
            cake->value[7]--;
        } else if(checkBox->property("isLoin").toBool()) {
            cake->setCost(-Global::Loin);
            cake->value[8]--;
        } else if(checkBox->property("isYoutiao").toBool()) {
            cake->setCost(-Global::Youtiao);
            cake->value[9]--;
        }
    }
}

void goBuyWidget::onCostChanged()
{
    Cake * aCake= qobject_cast<Cake *>(sender());
    float aCost = aCake->Cost();
    ui->label->setText(QString::asprintf("%.2f", aCost*Global::discount));
}

void goBuyWidget::onBtnGoBuyClicked()
{
    user->grade = Global::grade;
    this->cake->setC_Cost(this->cake->Cost()*Global::discount);
    user->cake = this->cake;
    bool echo = Global::database->addCakeSold(Global::username, user->grade, user->cake->Cost(), user->cake->value);
    if(echo) {
        qDebug() << "Cake购买成功";
        QMessageBox::information(this, "GOBUY", "购买成功");
    } else {
        qDebug() << "Cake购买失败";
        QMessageBox::information(this, "GOBUY", "购买失败");
    }
    this->clearCheckBox();
    this->cake->setC_Cost(0);
    ui->label->setText("0");
}


