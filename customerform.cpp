#include "customerform.h"
#include "ui_customerform.h"
#include "gobuywidget.h"

CustomerForm::CustomerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->goBuyPage = new goBuyWidget(ui->stackedWidget);
    this->goBuyVip = new GoBuyVip(ui->stackedWidget);
    this->comment = new GoComment(ui->stackedWidget);

    this->initBtnConn();

    ui->stackedWidget->addWidget(goBuyPage);
    ui->stackedWidget->addWidget(goBuyVip);
    ui->stackedWidget->addWidget(comment);
    ui->stackedWidget->setCurrentWidget(goBuyPage);
}

CustomerForm::~CustomerForm()
{
    delete ui;
}

void CustomerForm::initBtnConn()
{
    connect(ui->btnHome, SIGNAL(clicked()), this, SLOT(onBtnHome()));
    connect(ui->btnVip, SIGNAL(clicked()), this, SLOT(onBtnVip()));
    connect(ui->btnComment, SIGNAL(clicked()), this, SLOT(onBtnComment()));
}

void CustomerForm::onBtnHome()
{
    ui->stackedWidget->setCurrentWidget(this->goBuyPage);
}

void CustomerForm::onBtnVip()
{
    ui->stackedWidget->setCurrentWidget(this->goBuyVip);
}

void CustomerForm::onBtnComment()
{
    ui->stackedWidget->setCurrentWidget(this->comment);
}
