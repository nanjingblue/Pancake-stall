#include "gobuyvip.h"
#include "ui_gobuyvip.h"
#include "gobuywidget.h"
#include <QDebug>
#include <QMessageBox>

int GoBuyVip::vipYear = 60;
int GoBuyVip::vipSeason = 18;
int GoBuyVip::vipMonth = 8;

GoBuyVip::GoBuyVip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoBuyVip)
{
    ui->setupUi(this);
    this->initCheckBoxProp();
    this->initConn();
}

GoBuyVip::~GoBuyVip()
{
    delete ui;
}

int GoBuyVip::Cost()
{
    return this->vipCost;
}

void GoBuyVip::initCheckBoxProp()
{
    ui->checkBoxYear->setProperty("isYear", true);
    ui->checkBoxSeason->setProperty("isSeason", true);
    ui->checkBoxMonth->setProperty("isMonth", true);
}

void GoBuyVip::initConn()
{
    connect(this, SIGNAL(CostChanged(int)), this, SLOT(onCostChanged()));
    connect(ui->checkBoxYear, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBoxSeason, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBoxMonth, SIGNAL(clicked()), this, SLOT(onCheckBoxPicked()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(onBtnCasualCliked()));
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
}

void GoBuyVip::setCost(int value)
{
    this->vipCost = value;
    emit(this->CostChanged(this->vipCost));
}

void GoBuyVip::onCheckBoxPicked()
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    bool status = checkBox->isChecked();
    if (status == true) {
        if(checkBox->property("isYear").toBool()) {
            this->setCost(this->vipYear);
            this->grade = 1;
            ui->checkBoxSeason->setChecked(false);
            ui->checkBoxMonth->setChecked(false);
        } else if(checkBox->property("isSeason").toBool()) {
            this->setCost(this->vipSeason);
            this->grade = 2;
            ui->checkBoxYear->setChecked(false);
            ui->checkBoxMonth->setChecked(false);
        } else if(checkBox->property("isMonth").toBool()) {
            this->setCost(this->vipMonth);
            this->grade = 3;
            ui->checkBoxYear->setChecked(false);
            ui->checkBoxSeason->setChecked(false);
        }
//        qDebug() << "??????" << endl;
    } else {
        if(checkBox->property("isYear").toBool()) {
            this->setCost(0);
        } else if(checkBox->property("isSeason").toBool()) {
            this->setCost(0);
        } else if(checkBox->property("isMonth").toBool()) {
            this->setCost(0);
        }
        this->grade = 0;
//        qDebug() << "??????" << endl;
    }
}

void GoBuyVip::onBtnCasualCliked()
{
    ui->checkBoxYear->setChecked(false);
    ui->checkBoxSeason->setChecked(false);
    ui->checkBoxMonth->setChecked(false);
}

void GoBuyVip::onBtnOkClicked()
{
    int vipGrade = Global::database->isVip(Global::username);
    if(vipGrade <= this->grade && vipGrade != 0) {
        QMessageBox::information(this,"buyVip", "?????????????????????????????????????????????");
        return;
    }
    bool echo = Global::database->addVip(Global::username, this->grade);
    if(echo == true) {
        qDebug() << QString("Vip ?????????????????????????????????%1").arg(this->grade);
        QMessageBox::information(this, "BuyVip", "?????????????????????????????????");
    } else {
        qDebug() << "Vip ????????????";
        QMessageBox::information(this, "BuyVip", "????????????????????????????????????");
    }
    // ??????????????????
    Global::grade = this->grade;
    Global::setDiscount();
    // ?????????????????????
    echo = Global::database->addVipSold(Global::username, this->grade, this->vipCost);
    if(echo) {
        qDebug() << "??????Vip??????????????????";
    } else {
        qDebug() << "??????Vip??????????????????";
    }
}

void GoBuyVip::onCostChanged()
{
    ui->labelMoney->setText(QString::asprintf("%d", this->vipCost));
}
