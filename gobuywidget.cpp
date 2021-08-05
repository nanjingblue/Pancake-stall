#include "gobuywidget.h"
#include "ui_gobuywidget.h"
#include "qcustomer.h"
#include <QSqlTableModel>

goBuyWidget::goBuyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goBuyWidget)
{
    ui->setupUi(this);
}

goBuyWidget::~goBuyWidget()
{
    delete ui;
}

void goBuyWidget::initCheckBoxProp()
{
    ui->checkBox->setProperty("isOriginalCake", true);
    ui->checkBox_2->setProperty("isSauce", true);
    ui->frame_4->setProperty("isEgg", true);
}

int goBuyWidget::userType(QString username)
{
//    QSqlTableModel *model = new QSqlTableModel;
//   model->setTable("userinfo");
//   model->setFilter(QString("username='%1'").arg(username));
//   model->select();
    if (username=="admin") return 1;
    else return 0;
}
