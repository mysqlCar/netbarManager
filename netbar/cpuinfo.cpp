#include "cpuinfo.h"
#include "ui_cpuinfo.h"

cpuinfo::cpuinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cpuinfo)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &cpuinfo::upd);
}

cpuinfo::~cpuinfo()
{
    delete ui;
}

void cpuinfo::upd()
{
    cpu_info.number = ui->number->text();
    cpu_info.model = ui->model->text();
    send();
}
