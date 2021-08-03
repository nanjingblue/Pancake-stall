#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include "loginwindow.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class welcomeWidget; }
QT_END_NAMESPACE

class welcomeWidget : public QWidget
{
    Q_OBJECT

public:
    welcomeWidget(QWidget *parent = nullptr);
    ~welcomeWidget();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private slots:
    void on_pushButton_clicked();

private:
    Ui::welcomeWidget *ui;
    QPoint movePos;
    LoginWindow *login;
};
#endif // WELCOMEWIDGET_H
