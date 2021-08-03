#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
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
        } else {
            this->message->setText("User does not exist please register");
        }
    }
}
