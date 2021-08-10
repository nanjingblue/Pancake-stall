#ifndef GOCOMMENT_H
#define GOCOMMENT_H

#include <QWidget>

namespace Ui {
class GoComment;
}

class GoComment : public QWidget
{
    Q_OBJECT

public:
    explicit GoComment(QWidget *parent = nullptr);
    ~GoComment();

private slots:
    void onBtnYesClicked();

private:
    Ui::GoComment *ui;
};

#endif // GOCOMMENT_H
