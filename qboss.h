#ifndef QBOSS_H
#define QBOSS_H

#include "qperson.h"
#include <QObject>

class QBoss : public QPerson
{
    Q_OBJECT
public:
    explicit QBoss(QString username, QString password, QPerson *parent = nullptr);

signals:

};

#endif // QBOSS_H
