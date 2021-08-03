#include "welcomewidget.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomeWidget w;
    w.show();
    return a.exec();
}
