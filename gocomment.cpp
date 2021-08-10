#include "gocomment.h"
#include "ui_gocomment.h"
#include "global.h"
#include <QMessageBox>

GoComment::GoComment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoComment)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground,true);

    connect(ui->btnYes, SIGNAL(clicked()), this, SLOT(onBtnYesClicked()));
}

GoComment::~GoComment()
{
    delete ui;
}

void GoComment::onBtnYesClicked()
{
    QString comment = ui->commentEdit->toPlainText();
    bool echo = Global::database->addComment(Global::username, comment);
    if(echo) {
        QMessageBox::information(this, "GOCOMMENT", "评论成功");
        ui->commentEdit->clear();
    }   else {
        QMessageBox::information(this, "GOCOMMENT", "评论失败");
    }
}
