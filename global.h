#ifndef GLOBAL_H
#define GLOBAL_H

#include "database.h"
#include <QObject>

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = nullptr);
    static bool isAdmin;
    static QString username;
    static QString password;
    static Database *database;
    static float discount;
    static int grade;
    // 配料
    static int QriginalCake;
    static int Sauce;
    static int Cilantro;
    static int Egg;
    static int Crispbread;
    static int Ham;
    static int Potato;
    static int Youtiao;
    static int Loin;

    static void setDiscount();

signals:

};

#endif // GLOBAL_H
