#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void initUserInfoTable();
    int addUser(QString username, QString password);
    bool isUserExist(QString username, QString password);
    bool addVip(QString username, int grade);
    int isVip(QString username);

signals:

};

#endif // DATABASE_H
