#ifndef QBOSS_H
#define QBOSS_H

#include "qperson.h"
#include "goods.h"
#include <QObject>

class QBoss : public QPerson
{
    Q_OBJECT
public:
    explicit QBoss(QString username, QString password);
    ~QBoss();
    void display() const override;
    void outputClassInfo() const override;
public:
    double m_cost = 0;
    double materialCosts = 0;
    double sales = 0;
    double profits = 0;
    goods * value;
};

#endif // QBOSS_H
