#ifndef QCUSTOMER_H
#define QCUSTOMER_H

#include "qperson.h"
#include <QObject>

class QCustomer :public QPerson
{
    Q_OBJECT
public:
    explicit QCustomer(QString username, QString password, QPerson *parent = nullptr);

signals:

private:

};

#endif // QCUSTOMER_H