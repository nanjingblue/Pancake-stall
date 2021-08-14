#include "bossform.h"
#include "ui_bossform.h"

BossForm::BossForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->initConn();

    this->bossHomePage = new BossPrimeWidget;
    this->bossGoBuyPage = new BossGoBuy;
    ui->stackedWidget->addWidget(bossHomePage);
    ui->stackedWidget->addWidget(bossGoBuyPage);
    ui->stackedWidget->setCurrentWidget(bossHomePage);
}

BossForm::~BossForm()
{
    delete ui;
}

void BossForm::initConn()
{
    connect(ui->btnHome, SIGNAL(clicked()), this, SLOT(onBtnHomeClicked()));
    connect(ui->btnBuy, SIGNAL(clicked()), this, SLOT(onBtnBuyClicked()));
}

void BossForm::onBtnHomeClicked()
{
    ui->stackedWidget->setCurrentWidget(this->bossHomePage);
}

void BossForm::onBtnBuyClicked()
{
    ui->stackedWidget->setCurrentWidget(this->bossGoBuyPage);
}
