#include "global.h"

Global::Global(QObject *parent) : QObject(parent)
{

}

bool Global::isAdmin = false;
QString Global::username = "";
QString Global::password = "";
