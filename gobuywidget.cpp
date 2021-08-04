#include "gobuywidget.h"
#include "ui_gobuywidget.h"

goBuyWidget::goBuyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goBuyWidget)
{
    ui->setupUi(this);
}

goBuyWidget::~goBuyWidget()
{
    delete ui;
}
