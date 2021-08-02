#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

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


private:
    Ui::welcomeWidget *ui;
    QPoint movePos;
};
#endif // WELCOMEWIDGET_H
