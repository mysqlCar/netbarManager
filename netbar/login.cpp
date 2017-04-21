#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pswd->setEchoMode(QLineEdit::Password);
    connect(ui->login_2, &QPushButton::clicked, this, &login::check);
    connect(ui->pswd, &QLineEdit::returnPressed, this, &login::check);
}

login::~login()
{
    delete ui;
}

void login::check()
{
    if (ui->usr->text() == tr("boss") && ui->pswd->text() == tr("123456"))
    {
        this->hide();
        send();
        delete this;
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("用户名或密码不对！"),QMessageBox::Yes);
        ui->usr->clear();
        ui->pswd->clear();
        ui->usr->setFocus();
    }
}
