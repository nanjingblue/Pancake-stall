#include "bossprimewidget.h"
#include "ui_bossprimewidget.h"
#include "global.h"

BossPrimeWidget::BossPrimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossPrimeWidget)
{
    ui->setupUi(this);
    ui->labelSales->setText(QString::asprintf("%.2lf", Global::database->getSales()));
}

BossPrimeWidget::~BossPrimeWidget()
{
    delete ui;
}
