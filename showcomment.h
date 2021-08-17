#ifndef SHOWCOMMENT_H
#define SHOWCOMMENT_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class ShowComment;
}

class ShowComment : public QWidget
{
    Q_OBJECT

public:
    explicit ShowComment(QWidget *parent = nullptr);
    ~ShowComment();
    void initTableShowComment();

private:
    Ui::ShowComment *ui;
    QSqlQueryModel * model;
};

#endif // SHOWCOMMENT_H
