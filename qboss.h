#ifndef QBOSS_H
#define QBOSS_H

#include <QObject>

class QBoss : public QObject
{
    Q_OBJECT
public:
    explicit QBoss(QObject *parent = nullptr);

signals:

};

#endif // QBOSS_H
