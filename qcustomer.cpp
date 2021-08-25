#include "qcustomer.h"
#include "global.h"
#include <QDebug>
#include <QSqlTableModel>

QCustomer::QCustomer(QString username, QString password)
{
    QPerson::username = username;
    QPerson::password = password;
    this->grade = Global::grade;
}

void QCustomer::display() const
{
    qDebug() << "QCustomer::display()" << endl;
}

void QCustomer::outputClassInfo() const
{
    qDebug() << "类型：QCustiomer";
    qDebug() << "用户名：" << QPerson::username;
    qDebug() << "会员等级：" << this->grade;
}

bool QCustomer::isVip()
{
       QSqlTableModel *model = new QSqlTableModel;
       model->setTable("userinfo");
       return false;
}
