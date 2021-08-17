#include "showcomment.h"
#include "ui_showcomment.h"
#include <QTableView>

ShowComment::ShowComment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowComment)
{
    ui->setupUi(this);
    this->model = new QSqlQueryModel(ui->tableShowComment);
    this->initTableShowComment();
}

ShowComment::~ShowComment()
{
    delete ui;
}

void ShowComment::initTableShowComment()
{
    this->model->setQuery("SELECT USERNAME,COMMENT, SOLDDATE FROM COMMENTINFO");
    model->setHeaderData(0,Qt::Horizontal,tr("UserName"));
    model->setHeaderData(1, Qt::Horizontal, tr("CommentDetails"));
    model->setHeaderData(2, Qt::Horizontal, tr("CommetDate"));

    ui->tableShowComment->setModel(model);
    // 设置默认行高
    ui->tableShowComment->verticalHeader()->setDefaultSectionSize(50);
    ui->tableShowComment->setColumnWidth(0, 130);
    ui->tableShowComment->setColumnWidth(1, 500);
    ui->tableShowComment->setColumnWidth(2, 160);
    //设置列宽不可变动，即不能通过鼠标拖动增加列宽
    ui->tableShowComment->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    // 设置隔行变色
    ui->tableShowComment->setAlternatingRowColors(true);
    // 设置文字居中

    // 设置自适应列宽
//ui->tableShowComment->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableShowComment->setSelectionBehavior(QAbstractItemView::SelectRows); // 选中时整行选中
}
