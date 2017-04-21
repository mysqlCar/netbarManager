#ifndef CPUINFO_H
#define CPUINFO_H

#include <QDialog>
#include <QString>

namespace Ui {
class cpuinfo;
}

struct infocpu
{
    QString number, model;
};

class cpuinfo : public QDialog
{
    Q_OBJECT

public:
    explicit cpuinfo(QWidget *parent = 0);
    ~cpuinfo();
    void send()
    {
        emit cpu(cpu_info);
    }

signals:
    void cpu(const infocpu &);

private:
    Ui::cpuinfo *ui;
    infocpu cpu_info;

    void upd();
};

#endif // CPUINFO_H
