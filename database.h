#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlQuery>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void initUserInfoTable();
    void initSoldInfoTable();
    int addUser(QString username, QString password);
    bool isUserExist(QString username, QString password);
    bool addVip(QString username, int grade);
    int isVip(QString username);
    bool addCakeSold(QString username, int vip, int price, int value[]);
    bool addVipSold(QString username, int vip, int price);

private:

signals:

};

#endif // DATABASE_H
