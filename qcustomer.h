#ifndef QCUSTOMER_H
#define QCUSTOMER_H

#include <QObject>

class QCustomer : public QObject
{
    Q_OBJECT
public:
    explicit QCustomer(QObject *parent = nullptr);

signals:

};

#endif // QCUSTOMER_H
