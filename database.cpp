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
    QString cmd = "create table if not exists userinfo(username varchar(64), password varchar(64))";
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
        QString cmd  = QString("insert into userinfo values('%1', '%2')").arg(username).arg(password);
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
    model->setFilter(QString("username='%1',password='%2'").arg(username).arg(password));
    model->select();
    if(model->rowCount() > 0) {
        qDebug() << "当前用户存在";
        return true;
    } else {
        qDebug() << "当前用户不存在";
        return false;
    }
}
