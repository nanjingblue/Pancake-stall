#include "gobuywidget.h"
#include "ui_gobuywidget.h"
#include "qcustomer.h"
#include "qboss.h"
#include "global.h"


goBuyWidget::goBuyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goBuyWidget)
{
    ui->setupUi(this);
    if(Global::isAdmin){
        user = new QBoss(Global::username, Global::password);
    } else {
        user = new QCustomer(Global::username, Global::password);
    }
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
    ui->checkBox->setProperty("isCake", true);
    ui->checkBox_2->setProperty("isSauce", true);
    ui->checkBox_3->setProperty("isEgg", true);
}

void goBuyWidget::initCheckBoxConn()
{
    connect(this->user, &QPerson::costChanged, this, &goBuyWidget::onCostChanged);
    connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBox_2, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBox_3, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxPicked()));
}

void goBuyWidget::onCheckBoxPicked()
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    if(checkBox->property("isCake").toBool()) {
        user->setCost(3);
    } else if(checkBox->property("isSauce").toBool()) {
        user->setCost(1);
    } else if(checkBox->property("isEgg").toBool()) {
        user->setCost(1);
    }
}

void goBuyWidget::onCostChanged()
{
    QPerson * aPerson = qobject_cast<QPerson *>(sender());
    int aCost = aPerson->cost();
    ui->label->setText(QString::asprintf("%d", aCost));
}

