#ifndef BOSSSOLDDETAILS_H
#define BOSSSOLDDETAILS_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>

namespace Ui {
class BossSoldDetails;
}

class BossSoldDetails : public QWidget
{
    Q_OBJECT

public:
    explicit BossSoldDetails(QWidget *parent = nullptr);
    ~BossSoldDetails();
    void initTableSlodDetails();

private:
    Ui::BossSoldDetails *ui;
    QSqlQueryModel * model;
};

#endif // BOSSSOLDDETAILS_H
