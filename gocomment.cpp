#include "gocomment.h"
#include "ui_gocomment.h"

GoComment::GoComment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoComment)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground,true);
}

GoComment::~GoComment()
{
    delete ui;
}
