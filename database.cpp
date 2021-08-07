#include "database.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

Database::Database(QObject *parent) : QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("PancakeStall.db");
    if (db.open()) {
        qDebug() << "Open database suc";
    } else {
        qDebug() << "Open database fail";
    }
    // 初始化用户表
    this->initUserInfoTable();
}

void Database::initUserInfoTable()
{
    QString cmd = "CREATE TABLE IF NOT EXISTS USERINFO(\
            USERNAME           VARCHAR(64)    NOT NULL,\
            PASSWORD            VARCHAR(64)     NOT NULL,\
            VIP                  int    NOT NULL\
         )";
    // 执行
    QSqlQuery query;
    if (query.exec(cmd)) {
        qDebug() << "userinfo table suc";
    } else {
        qDebug() << "userinfo table fail";
    }
    this->addUser("admin", "123456");
}

int Database::addUser(QString username, QString password)
{
    QSqlTableModel * model = new QSqlTableModel;
    model->setTable("userinfo");
    model->setFilter(QString("username='%1'").arg(username));
    model->select();
    if (model->rowCount() > 0) {
        qDebug() << "用户已经存在";
        return 1;
    } else {
        QSqlQuery query;
        QString cmd  = QString("insert into userinfo values('%1', '%2', %3)").arg(username).arg(password).arg(0);
        if (query.exec(cmd)) {
            qDebug() << "用户创建成功";
            return 0;
        } else {
            qDebug() << "用户创建失败";
            return -1;
        }
    }
    delete model;
}

bool Database::isUserExist(QString username, QString password)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("userinfo");
    model->setFilter(QString("username='%1' and password='%2'").arg(username).arg(password));
    model->select();
    if(model->rowCount() > 0) {
        qDebug() << "当前用户存在";
        return true;
    } else {
        qDebug() << "当前用户不存在";
        return false;
    }
}

bool Database::addVip(QString username, int grade)
{
   // 三个等级 grade=1 年卡 | grade=2 季卡 | grade=3 | 月卡
    QSqlQuery query;
    QString cmd = QString("UPDATE USERINFO SET VIP=%1 WHERE USERNAME='%2'").arg(grade).arg(username);
    if(query.exec(cmd)) {
        qDebug() << "Vip 设置成功" << endl;
        return true;
    } else {
        qDebug() << "Vip 设置失败" << endl;
        return false;
    }
}

int Database::isVip(QString username)
{
    QSqlQuery query;
    QString cmd = QString("select vip from userinfo where username='%1'").arg(username);
    query.prepare(cmd);
    if(query.exec(cmd) && query.first()) { // 此处必须要执行 query.first() 才是第一条数据 如果有很多条可以循环使用 query.next()
        return query.value(0).toInt();
    } else {
        qDebug() << "查询Vip出错";
        return 0;
    }
}
