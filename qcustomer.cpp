#include "qcustomer.h"
#include <QDebug>

QCustomer::QCustomer(QString username, QString password)
{
    QPerson::username = username;
    QPerson::password = password;
}

void QCustomer::display() const
{
    qDebug() << "QCustomer::display()" << endl;
}
