#include "qboss.h"
#include "global.h"
#include <QDebug>

QBoss::QBoss(QString username, QString password)
{
    QPerson::username = username;
    QPerson::password = password;
    Global::isAdmin = true;
}

void QBoss::display() const
{
    qDebug() << "this is QBoss";
}
