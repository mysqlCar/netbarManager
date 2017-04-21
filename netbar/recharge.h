#ifndef RECHARGE_H
#define RECHARGE_H

#include <QDialog>
#include <QString>

namespace Ui {
class recharge;
}

struct rechargeInfo
{
    QString cardNumber, money;
};

class recharge : public QDialog
{
    Q_OBJECT

public:
    explicit recharge(QWidget *parent = 0);
    ~recharge();
    void send()
    {
        emit(cur_charge);
    }

signals:
    void charge(const rechargeInfo &);

private:
    Ui::recharge *ui;
    rechargeInfo cur_charge;

    void upd();
};

#endif // RECHARGE_H
