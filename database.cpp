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
    // 初始化销售表
    this->initSoldInfoTable();
    // 初始化评论表
    this->initCommentInfoTable();
    // 初始化 BossBuy
    this->initBossBuyInfoTable();
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

void Database::initSoldInfoTable()
{
    QString cmd = "CREATE TABLE IF NOT EXISTS SOLDINFO(\
            ID                          INTEGER                 PRIMARY KEY  AUTOINCREMENT,\
            USERNAME           VARCHAR(64)          NOT NULL,\
            VIPGRADE              INT                         DEFAULT 0,\
            CAKEPRICE            FLOAT                      DEFAULT 0,\
            VIPPRICE                INT                         DEFAULT 0,\
            ORIGINCAKE         INT                         DEFAULT 0,\
            SAUCE                    INT                         DEFAULT 0,\
            CILANTRO             INT                          DEFAULT 0,\
            EGG                         INT                         DEFAULT 0,\
            CRISPBREAD          INT                          DEFAULT 0,\
            HAM                         INT                        DEFAULT 0,\
            POTATO                  INT                         DEFAULT 0,\
            LOIN                        INT                         DEFAULT 0,\
            YOUTIAO                 INT                         DEFAULT 0,\
            SOLDDATE             TIMESTAMP             DEFAULT (datetime('now','localtime'))\
            )";

    QSqlQuery query;
    if(query.exec(cmd)) {
        qDebug() << "SlodInfoTabel suc";
    } else {
        qDebug() << "SlodInfoTable fail";
    }
}

void Database::initCommentInfoTable()
{
    QString cmd = "CREATE TABLE IF NOT EXISTS COMMENTINFO(\
            ID                          INTEGER                 PRIMARY KEY  AUTOINCREMENT,\
            USERNAME           VARCHAR(64)          NOT NULL,\
            COMMENT             TEXT                       DEFAULT '', \
            SOLDDATE             TIMESTAMP             DEFAULT (datetime('now','localtime'))\
            )";
    QSqlQuery query;
    if(query.exec(cmd)) {
        qDebug() << "CommrntInfoTable suc";
    } else {
        qDebug() << "CommentInfoTable fail";
    }
}

void Database::initBossBuyInfoTable()
{
    QString cmd = "CREATE TABLE IF NOT EXISTS BOSSBUYINFO(\
            ID                 INTEGER primary key  AUTOINCREMENT,\
            USERNAME           VARCHAR(64)    NOT NULL,\
            PRICE                INT    DEFAULT 0,\
            ORIGINCAKE           INT    DEFAULT 0,\
            SAUCE                INT    DEFAULT 0,\
            CILANTRO             INT    DEFAULT 0,\
            EGG                  INT    DEFAULT 0,\
            CRISPBREAD           INT    DEFAULT 0,\
            HAM                  INT    DEFAULT 0,\
            POTATO               INT    DEFAULT 0,\
            LOIN                 INT    DEFAULT 0,\
            YOUTIAO              INT    DEFAULT 0,\
            SOLDDATE             timestamp default (datetime('now','localtime'))\
            )";
    QSqlQuery query;
    if(query.exec(cmd)) {
        qDebug() << "BossBuyInfo suc";
    } else {
        qDebug() << "BossBuyInfo fail";
    }
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
        qDebug() << "Vip 设置成功";
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

bool Database::addCakeSold(QString username, int vipGrade, float cakePrice, int value[])
{
    QString cmd = QString("INSERT INTO SOLDINFO \
                          (ID,USERNAME,VIPGRADE,CAKEPRICE,ORIGINCAKE,SAUCE,\
                          CILANTRO,EGG,CRISPBREAD,HAM,POTATO,LOIN,YOUTIAO) \
                          VALUES(NULL,'%1',%2,%3, %4,%5,%6,%7,%8,%9,%10,%11,%12)")
                          .arg(username).arg(vipGrade).arg(cakePrice)
                          .arg(value[1]).arg(value[2]).arg(value[3]).arg(value[4]).arg(value[5])
                          .arg(value[6]).arg(value[7]).arg(value[8]).arg(value[9]);
    QSqlQuery query;
    if(query.exec(cmd)) {
        qDebug() << "Cake销售成功，添加至数据库";
        return true;
    } else {
        qDebug() << "Cake销售失败，无法添加至数据库";
        return false;
    }
}

bool Database::addVipSold(QString username, int vipGrade, int vipPrice)
{
    QString cmd = QString("INSERT INTO SOLDINFO (ID, USERNAME, VIPGRADE, VIPPRICE)VALUES(NULL, '%1', %2, %3)")
                          .arg(username).arg(vipGrade).arg(vipPrice);
    QSqlQuery query;
    if(query.exec(cmd)) {
         qDebug() << "Vip购买成功，添加至数据库";
        return true;
    } else {
        qDebug() << "Vip购买失败，无法添加至数据库";
        return false;
    }
}

bool Database::addComment(QString username, QString comment)
{
    QString cmd = QString("INSERT INTO COMMENTINFO (ID, USERNAME,  COMMENT) VALUES(NULL, '%1', '%2')")
                          .arg(username).arg(comment);
    QSqlQuery query;
    if(query.exec(cmd)) {
       qDebug() << "评论记录添加成功";
       return true;
    } else {
        qDebug() << "评论记录添加失败";
        return false;
    }
}

bool Database::addBossBuy(double price, int value[])
{
    QString cmd = QString("INSERT INTO BOSSBUYINFO (ID,USERNAME,PRICE,ORIGINCAKE,SAUCE,CILANTRO,EGG,CRISPBREAD,HAM,POTATO,LOIN,YOUTIAO)VALUES(NULL, \"admin\", %1,%2,%3,%4,%5,%6,%7,%8,%9,%10)")
                                        .arg(price).arg(value[1]).arg(value[2]).arg(value[3]).arg(value[4]).arg(value[5]).arg(value[6])
                                        .arg(value[7]).arg(value[8]).arg(value[9]);
    QSqlQuery query;
    if(query.exec(cmd)) {
        qDebug() << "BossBuy 添加记录成功";
        return true;
    } else {
        qDebug() << "BossBuy 添加记录失败";
        return false;
    }
}

double Database::getSales()
{
    double value = 0;
    QString cmd1 = "SELECT SUM(CAKEPRICE) FROM SOLDINFO";
    QString cmd2 = "SELECT SUM(VIPPRICE) FROM SOLDINFO";
    QSqlQuery query;
    if(query.exec(cmd1) && query.first()) {
        value = query.value(0).toDouble();
        qDebug() << "Sum CAKEPRICE sc";
    } else {
        qDebug() << "Sum CAKEPRICE fail";
        return -1;
    }
    if(query.exec(cmd2) && query.first()) {
        value += query.value(0).toDouble();
        qDebug() << "Get Sales Suc";
        return  value;
    } else {
        qDebug() << "Get Sales fail";
        return -1;
    }
}

double Database::getMaterialCosts()
{
    QString cmd = "SELECT SUM(PRICE) FROM BOSSBUYINFo";
    QSqlQuery query;
    if(query.exec(cmd) && query.first()) {
        qDebug() << "Get materialCosts suc";
        return query.value(0).toDouble();
    } else {
        qDebug() << "Get materialCosts fail";
        return -1;
    }
}

void Database::getSoldInfo(goods *value)
{
    QSqlQuery query;
    QString goodsName[10] = {
        "", "ORIGINCAKE", "SAUCE", "CILANTRO", "EGG", "CRISPBREAD", "HAM", "POTATO", "LOIN", "YOUTIAO"
    };
    QString tableName[3] = {
        "", "SOLDINFO", "BOSSBUYINFO"
    };
    for(int i=1; i<=9; ++i) {
        for(int j=1; j<=2; ++j){
            QString cmd = QString("SELECT SUM(%1) FROM %2").arg(goodsName[i]).arg(tableName[j]);
            if(query.exec(cmd) && query.first()) {
                if(j==1) value[i].Sales = query.value(0).toInt();
                else value[i].Inventory =query.value(0).toInt() - value[i].Sales;
            }
        }
    }
}
