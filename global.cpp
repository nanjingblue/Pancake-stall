#include "global.h"

Global::Global(QObject *parent) : QObject(parent)
{

}

// 此函数登录是调用 以配置初始化
void Global::setDiscount()
{
    int echo = database->isVip(username);
    // 更新会员等级
    Global::grade = echo;
    switch (echo) {
    case 0:
        discount = 1.00; grade = 0; break;
    case 1:
        discount = 0.80; grade = 1; break;
    case 2:
        discount = 0.85; grade = 2; break;
    case 3:
        discount = 0.90; grade = 3; break;
    default:
        discount = 1; grade = 0;
    }
}

bool Global::isAdmin = false;
QString Global::username = "";
QString Global::password = "";
Database * Global::database = new Database;
float Global::discount = 1;
int Global::grade =0;

// 配料
int Global::QriginalCake = 3;
int Global::Sauce = 0;
int Global::Cilantro = 0;
int Global::Egg = 1;
int Global::Crispbread = 1;
int Global::Ham = 1;
int Global::Potato = 1;
int Global::Youtiao = 1;
int Global::Loin = 1;
