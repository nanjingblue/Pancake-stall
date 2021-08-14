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
    static double bossDiscount;
    static int grade;
    // 配料
    static float QriginalCake;
    static float Sauce;
    static float Cilantro;
    static float Egg;
    static float Crispbread;
    static float Ham;
    static float Potato;
    static float Youtiao;
    static float Loin;

    static void setDiscount();

signals:

};

#endif // GLOBAL_H
