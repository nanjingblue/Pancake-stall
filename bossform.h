#ifndef BOSSFORM_H
#define BOSSFORM_H

#include <QWidget>

namespace Ui {
class BossForm;
}

class BossForm : public QWidget
{
    Q_OBJECT

public:
    explicit BossForm(QWidget *parent = nullptr);
    ~BossForm();

private:
    Ui::BossForm *ui;
};

#endif // BOSSFORM_H
