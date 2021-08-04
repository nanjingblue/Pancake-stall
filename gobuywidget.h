#ifndef GOBUYWIDGET_H
#define GOBUYWIDGET_H

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

private:
    Ui::goBuyWidget *ui;
};

#endif // GOBUYWIDGET_H
