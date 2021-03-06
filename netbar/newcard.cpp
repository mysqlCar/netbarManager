#include "newcard.h"
#include "ui_newcard.h"
#include <QMessageBox>

newcard::newcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newcard)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &newcard::upd);
    connect(ui->checkName, &QPushButton::clicked, this, &newcard::getname);
    connect(ui->checkNumber, &QPushButton::clicked,this, &newcard::checkNumber);
    ui->name->setFocusPolicy(Qt::NoFocus);
    card_info.ok_name = true;
    card_info.ok_cardID = true;

}

newcard::~newcard()
{
    delete ui;
}

void newcard::upd()
{
    card_info.charge = ui->charge->text();
    card_info.id = ui->id->text();
    card_info.name = ui->name->text();
    card_info.cardNumber = ui->cardNumber->text();
    int flag = 1;
    string Name;
    flag =dataBase.getUserName(ui->id->text().toStdString(), Name);
    if (!flag)
        card_info.ok_name = true;
    ui->cardNumber->text() = QString::fromStdString(Name);
    flag =dataBase.checkVIPNumber(ui->cardNumber->text().toStdString());
    if (!flag)
        card_info.ok_cardID = true;
    send();
}

void newcard::getname()
{
    string Name;
    int flag;
    flag = dataBase.getUserName(ui->id->text().toStdString(), Name);
    if (!flag)
    {
        ui->name->setText(QString::fromStdString(Name));
        card_info.ok_name = true;
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("查无此人，请先建立对应用户"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        ui->id->clear();
        ui->id->setFocus();
        card_info.ok_name = false;
    }
}

void newcard::checkNumber()
{
    int flag;
    flag = dataBase.checkVIPNumber(ui->cardNumber->text().toStdString());
    if (!flag)
    {
        QMessageBox::information(this, tr("Success"), tr("该卡号可以使用"), QMessageBox::Yes, QMessageBox::Yes);
        card_info.ok_cardID = true;
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("该卡号已被使用"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        card_info.ok_cardID = false;
    }
}
