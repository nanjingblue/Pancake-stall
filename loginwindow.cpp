#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "global.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMinimumSize(1164, 729);
    // 初始化数据库
    this->database = new Database;
    this->message = ui->messageLabel;
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnRegister_clicked()
{
    QString username = ui->userEdit->text();
    QString password = ui->pwdEdit->text();
    if (username == "") {
        QMessageBox::information(this, "Register", "Username can't be empty");
    } else if(password=="") {
        QMessageBox::information(this, "Register", "Password can't be empty");
    }
    int echo = this->database->addUser(username, password);
    if(echo==1) {
        QMessageBox::information(this, "Register", "User already exists, please login");
    } else if(echo==0) {
        QMessageBox::information(this, "Register", "User registration successful");
    } else {
        QMessageBox::information(this, "Register", "User registration successful");
    }
}

void LoginWindow::on_btnLoginer_clicked()
{
    QString username = ui->userEdit->text();
    QString password = ui->pwdEdit->text();
    if(username == "") {
        this->message->setText("Username can't be empty");
    } else if(password == "") {
        this->message->setText("Password can't be empty");
    } else {
        if(this->database->isUserExist(username, password)) {
            this->message->setText("Logining");
            // 设置当前用户 使用全局变量
            if(username == "admin") Global::isAdmin = true;
            else Global::isAdmin = false;

            Global::username = username;
            Global::password = password;

            this->customer = new CustomerForm;
            this->close();
            customer->show();

        } else {
            this->message->setText("User does not exist please register");
        }
    }

}
