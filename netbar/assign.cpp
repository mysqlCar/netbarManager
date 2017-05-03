#include "assign.h"
#include "ui_assign.h"

assign::assign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assign)
{
    ui->setupUi(this);
    ui->endTime->setDateTime(QDateTime::currentDateTime());
    ui->endTime->setDateTimeRange(QDateTime::currentDateTime(), NULL);
    connect(ui->cash, &QCheckBox::toggled, this, &assign::enCard);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &assign::upd);
}

assign::~assign()
{
    delete ui;
}

void assign::upd()
{
    cur_info.comNumber = ui->number->text();
    cur_info.userName = ui->name->text();
    cur_info.idNumber = ui->id->text();
    cur_info.endTime = ui -> endTime ->dateTime();
    cur_info.cardNumber = ui ->cardnum ->text();
    cur_info.useCash = ui->cash->isChecked();
    send();
}


void assign::enCard()
{
    ui->cardnum->setDisabled(ui -> cash -> isChecked());
}
