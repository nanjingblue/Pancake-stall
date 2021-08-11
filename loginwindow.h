#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include "database.h"
#include "customerform.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_btnRegister_clicked();
    void on_btnLoginer_clicked();
private:
    Ui::LoginWindow *ui;
    QLabel * message;
    CustomerForm * customer;
};

#endif // LOGINWINDOW_H
