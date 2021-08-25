#include "qboss.h"
#include "global.h"
#include <QDebug>

QBoss::QBoss(QString username, QString password)
{
    QPerson::username = username;
    QPerson::password = password;
    Global::isAdmin = true;
    this->materialCosts = Global::database->getMaterialCosts();
    this->sales = Global::database->getSales();
    this->profits = this->sales - this->materialCosts;
    this->value = new goods[10];
    Global::database->getSoldInfo(value);
}

QBoss::~QBoss()
{
    delete [] value;
}

void QBoss::display() const
{
    qDebug() << "This is QBoss";
}

void QBoss::outputClassInfo() const
{
    qDebug() << "类型：QBoss";
    qDebug() << "用户名：" << QPerson::username;
    qDebug() << "销售额：" << this->sales;
    qDebug() << "原料费：" << this->materialCosts;
    qDebug() << "利润：" << this->profits;
}
