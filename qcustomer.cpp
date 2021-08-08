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

bool QCustomer::isVip()
{
       QSqlTableModel *model = new QSqlTableModel;
       model->setTable("userinfo");
       return false;
}
