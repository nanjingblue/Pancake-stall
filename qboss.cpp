#include "qboss.h"
#include "global.h"
#include <QDebug>

QBoss::QBoss(QString username, QString password)
{
    QPerson::username = username;
    QPerson::password = password;
    Global::isAdmin = true;
    this->materialCosts = Global::database->getMaterialCosts();
    this->sales = Global::database->getSales();
    this->profits = this->sales - this->materialCosts;
}

void QBoss::display() const
{
    qDebug() << "this is QBoss";
}
