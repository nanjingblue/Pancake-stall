#ifndef QBOSS_H
#define QBOSS_H

#include "qperson.h"
#include <QObject>

class QBoss : public QPerson
{
    Q_OBJECT
public:
    explicit QBoss(QString username, QString password);
    void display() const override;

signals:

public:
    double materialCosts = 0;
    double sales = 0;
    double profits = 0;
};

#endif // QBOSS_H
