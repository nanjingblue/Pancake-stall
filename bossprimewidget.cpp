#include "bossprimewidget.h"
#include "ui_bossprimewidget.h"

BossPrimeWidget::BossPrimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossPrimeWidget)
{
    ui->setupUi(this);
}

BossPrimeWidget::~BossPrimeWidget()
{
    delete ui;
}
