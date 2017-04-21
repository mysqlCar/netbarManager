#ifndef REPAIR_H
#define REPAIR_H

#include <QDialog>

namespace Ui {
class repair;
}

struct repairInfo
{
    QString comNumber, errNumber;
};

class repair : public QDialog
{
    Q_OBJECT

public:
    explicit repair(QWidget *parent = 0);
    ~repair();
    void send()
    {
        emit mendSig(mendInfo);
    }

signals:
    void mendSig(const repairInfo &);

private:
    Ui::repair *ui;
    repairInfo mendInfo;

    void upd();
};

#endif // REPAIR_H
