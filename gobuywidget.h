#ifndef GOBUYWIDGET_H
#define GOBUYWIDGET_H

#include "qperson.h"
#include <QWidget>

namespace Ui {
class goBuyWidget;
}

class goBuyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit goBuyWidget(QWidget *parent = nullptr);
    ~goBuyWidget();
    void initCheckBoxProp();

signals:
    void checkBoxPick();

public slots:
    int userType(QString username);

private:
    Ui::goBuyWidget *ui;
    QPerson *user;

public:
    bool isAdmin;
};

#endif // GOBUYWIDGET_H