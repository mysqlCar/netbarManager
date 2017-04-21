#ifndef ASSIGN_H
#define ASSIGN_H

#include <QDialog>
#include <QString>

namespace Ui {
class assign;
}

struct assignInfo
{
    QString comNumber, userName, idNumber, endTime, cardNumber;
    bool useCash;
};

class assign : public QDialog
{
    Q_OBJECT

public:
    explicit assign(QWidget *parent = 0);
    ~assign();
    void send()
    {
        emit assigned(cur_info);
    }

signals:
    void assigned(const assignInfo &);

private:
    Ui::assign *ui;
    assignInfo cur_info;
    void upd();
    void disCard();
    void enCard();
};

#endif // ASSIGN_H
