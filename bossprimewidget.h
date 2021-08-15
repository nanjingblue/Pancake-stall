#ifndef BOSSPRIMEWIDGET_H
#define BOSSPRIMEWIDGET_H

#include <QWidget>

namespace Ui {
class BossPrimeWidget;
}

class BossPrimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BossPrimeWidget(QWidget *parent = nullptr);
    ~BossPrimeWidget();
    void initLableMoney();

private:
    Ui::BossPrimeWidget *ui;
};

#endif // BOSSPRIMEWIDGET_H
