#include "bosssolddetails.h"
#include "ui_bosssolddetails.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTableView>
BossSoldDetails::BossSoldDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossSoldDetails)
{
    ui->setupUi(this);
    this->model = new QSqlQueryModel(ui->tableSoldDetails);
    this->initTableSlodDetails();
}

BossSoldDetails::~BossSoldDetails()
{
    delete ui;
}

void BossSoldDetails::initTableSlodDetails()
{
    this->model->setQuery("SELECT USERNAME,VIPGRADE,CAKEPRICE,VIPPRICE,SOLDDATE FROM SOLDINFO");
    model->setHeaderData(0,Qt::Horizontal,tr("UserName"));
    model->setHeaderData(1, Qt::Horizontal, tr("会员等级"));
    model->setHeaderData(2, Qt::Horizontal, tr("煎饼费用"));
    model->setHeaderData(3, Qt::Horizontal, tr("会员费用"));
    model->setHeaderData(4, Qt::Horizontal, tr("购买日期"));

    ui->tableSoldDetails->setModel(model);
    ui->tableSoldDetails->verticalHeader()->setDefaultSectionSize(50);
    ui->tableSoldDetails->setColumnWidth(0, 220);
    ui->tableSoldDetails->setColumnWidth(1, 230);
    ui->tableSoldDetails->setColumnWidth(2, 230);
    ui->tableSoldDetails->setColumnWidth(3, 230);
    ui->tableSoldDetails->setColumnWidth(4, 200);
}
