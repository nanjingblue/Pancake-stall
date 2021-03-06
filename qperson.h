#ifndef QPERSON_H
#define QPERSON_H

#include "cake.h"
#include "goods.h"
#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
public:
    virtual void display() const = 0;
    virtual void outputClassInfo() const = 0;
protected:
    QString username;
    QString password;
    double m_cost = 0;

public:
    // customer
     Cake * cake;
     int grade;
     // boss
     double materialCosts = 0;
     double sales = 0;
     double profits = 0;
     goods * value;
};

#endif // QPERSON_H
