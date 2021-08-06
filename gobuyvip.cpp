#include "gobuyvip.h"
#include "ui_gobuyvip.h"

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
    connect(ui->checkBoxYear, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBoxSeason, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->checkBoxMonth, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxPicked()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(onBtnCasualCliked()));
}

void GoBuyVip::setCost(int value)
{
    this->vipCost += value;
    emit(this->CostChanged(this->vipCost));
}

void GoBuyVip::onCheckBoxPicked()
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    bool status = checkBox->isChecked();
    if (status == true) {
        if(checkBox->property("isYear").toBool()) {
            this->setCost(this->vipYear);
            ui->checkBoxSeason->setChecked(false);
            ui->checkBoxMonth->setChecked(false);
        } else if(checkBox->property("isSeason").toBool()) {
            this->setCost(this->vipSeason);
            ui->checkBoxYear->setChecked(false);
            ui->checkBoxMonth->setChecked(false);
        } else if(checkBox->property("isMonth").toBool()) {
            this->setCost(this->vipMonth);
            ui->checkBoxYear->setChecked(false);
            ui->checkBoxSeason->setChecked(false);
        }
    } else {
        if(checkBox->property("isYear").toBool()) {
            this->setCost(-this->vipYear);
        } else if(checkBox->property("isSeason").toBool()) {
            this->setCost(-this->vipSeason);
        } else if(checkBox->property("isMonth").toBool()) {
            this->setCost(-this->vipMonth);
        }
    }
}

void GoBuyVip::onBtnCasualCliked()
{
    ui->checkBoxYear->setChecked(false);
    ui->checkBoxSeason->setChecked(false);
    ui->checkBoxMonth->setChecked(false);
}

void GoBuyVip::onCostChanged()
{
    ui->labelMoney->setText(QString::asprintf("%d", this->vipCost));
}
