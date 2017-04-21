#include "repair.h"
#include "ui_repair.h"

repair::repair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::repair)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, repair::upd);
}

repair::~repair()
{
    delete ui;
}

void repair::upd()
{
    mendInfo.comNumber = ui ->comNumber ->text();
    mendInfo.errNumber = ui ->errNum ->text();
    send();
}
