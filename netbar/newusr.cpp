#include "newusr.h"
#include "ui_newusr.h"

newusr::newusr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newusr)
{
    ui->setupUi(this);
    connect(ui -> buttonBox, &QDialogButtonBox::accepted, this, &newusr::upd);
}

newusr::~newusr()
{
    delete ui;
}

void newusr::upd()
{
    usr_info.id = ui->id->text();
    usr_info.name = ui->name->text();
    send();
}
