#include "qcustomer.h"

QCustomer::QCustomer(QString username, QString password, QPerson *parent)
    : QPerson(username, password, parent)
{

}