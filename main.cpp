#include "welcomewidget.h"
#include "loginwindow.h"
#include "bossform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomeWidget w;
    w.show();
//    BossForm w;
//    w.show();
    return a.exec();
}
