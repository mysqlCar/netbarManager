#ifndef NEWCARD_H
#define NEWCARD_H

#include <QDialog>
#include <QString>

namespace Ui {
class newcard;
}

struct infocard
{
    QString name,id,charge;
};

class newcard : public QDialog
{
    Q_OBJECT

public:
    explicit newcard(QWidget *parent = 0);
    ~newcard();
    void send()
    {
        emit card(card_info);
    }

signals:
    void card(const infocard &);

private:
    Ui::newcard *ui;
    infocard card_info;

    void upd();
    void getname();
};

#endif // NEWCARD_H
