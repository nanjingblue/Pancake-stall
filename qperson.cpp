#include "qperson.h"

QPerson::QPerson(QString username, QString password, QObject *parent) : QObject(parent)
{
    this->username = username;
    this->password = password;
}

int QPerson::cost()
{
    return this->m_cost;
}

void QPerson::setCost(int value)
{
    this->m_cost = value;
    emit(this->costChanged(value));
}
