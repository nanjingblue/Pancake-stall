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
    ui->stackedWidget->addWidget(goBuyPage);
    ui->stackedWidget->setCurrentWidget(goBuyPage);
}

CustomerForm::~CustomerForm()
{
    delete ui;
}
