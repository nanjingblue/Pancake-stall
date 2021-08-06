#include "gobuyvip.h"
#include "ui_gobuyvip.h"

GoBuyVip::GoBuyVip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoBuyVip)
{
    ui->setupUi(this);
}

GoBuyVip::~GoBuyVip()
{
    delete ui;
}
