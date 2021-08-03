#include "welcomewidget.h"
#include "ui_welcomewidget.h"
#include <QMouseEvent>

welcomeWidget::welcomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcomeWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMinimumSize(1164,729);
}

welcomeWidget::~welcomeWidget()
{
    delete ui;
}

void welcomeWidget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    QPoint mousePos = event->globalPos();
    QPoint windowsPos = mousePos - this->movePos;
    this->move(windowsPos);
}

void welcomeWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QPoint windowPos = this->geometry().topLeft();
    QPoint mousePos = event->globalPos();
    this->movePos = mousePos - windowPos;
}

void welcomeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->movePos = QPoint();
}


void welcomeWidget::on_pushButton_clicked()
{
    this->login = new LoginWindow;
    this->hide();
    this->login->show();
}
