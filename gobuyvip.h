#ifndef GOBUYVIP_H
#define GOBUYVIP_H

#include <QWidget>

namespace Ui {
class GoBuyVip;
}

class GoBuyVip : public QWidget
{
    Q_OBJECT

public:
    explicit GoBuyVip(QWidget *parent = nullptr);
    ~GoBuyVip();

private:
    Ui::GoBuyVip *ui;
};

#endif // GOBUYVIP_H
