#ifndef QPERSON_H
#define QPERSON_H

#include "cake.h"
#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
public:
    virtual void display() const = 0;
signals:

protected:
    QString username;
    QString password;
    int m_cost = 0;
public:
     Cake * cake;
};

#endif // QPERSON_H
