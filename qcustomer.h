#ifndef QCUSTOMER_H
#define QCUSTOMER_H

#include "qperson.h"
#include "cake.h"
#include <QObject>

class QCustomer :public QPerson
{
    Q_OBJECT
public:
    explicit QCustomer(QString username, QString password);
    void display() const override;
    bool isVip();

signals:

public:
    Cake * cake;
    bool vip = false;
};

#endif // QCUSTOMER_H
