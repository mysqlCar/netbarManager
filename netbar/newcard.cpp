#include "newcard.h"
#include "ui_newcard.h"

newcard::newcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newcard)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &newcard::upd);
    connect(ui->id, &QLineEdit::editingFinished, this, &newcard::getname);
    ui->name->setFocusPolicy(Qt::NoFocus);
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
    send();
}

void newcard::getname()
{
    ui->name->setText(tr("储振东"));
}
