#ifndef DATABASE_H
#define DATABASE_H

#include "goods.h"
#include <QObject>
#include <QSqlQuery>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void initUserInfoTable();
    void initSoldInfoTable();
    void initCommentInfoTable();
    void initBossBuyInfoTable();
    int addUser(QString username, QString password);
    bool isUserExist(QString username, QString password);
    bool addVip(QString username, int grade);
    int isVip(QString username);
    bool addCakeSold(QString username, int vipGrade, float cakePrice, int value[]);
    bool addVipSold(QString username, int vipGrade, int vipPrice);
    bool addComment(QString username, QString comment);
    bool addBossBuy(double price, int value[]);
    double getSales();
    double getMaterialCosts();
    void  getSoldInfo(goods *value);
};

#endif // DATABASE_H
