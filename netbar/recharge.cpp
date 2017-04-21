#include "recharge.h"
#include "ui_recharge.h"

recharge::recharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recharge)
{
    ui->setupUi(this);
    connect(ui -> buttonBox, &QDialogButtonBox::accepted, this, &recharge::upd);
}

recharge::~recharge()
{
    delete ui;
}

void recharge::upd()
{
    cur_charge.cardNumber = ui->cardNumber->text();
    cur_charge.money = ui -> money -> text();
    send();

}
