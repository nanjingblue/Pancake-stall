#include "global.h"

Global::Global(QObject *parent) : QObject(parent)
{

}

void Global::setDiscount()
{
    int echo = database->isVip(username);
    switch (echo) {
    case 0:
        discount = 1.00; grade = 0; break;
    case 1:
        discount = 0.80; grade = 1; break;
    case 2:
        discount = 0.85; grade = 2; break;
    case 3:
        discount = 0.90; grade = 3; break;
    default:
        discount = 1; grade = 0;
    }
}

bool Global::isAdmin = false;
QString Global::username = "";
QString Global::password = "";
Database * Global::database = new Database;
float Global::discount = 1;
int Global::grade = 0;
