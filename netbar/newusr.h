#ifndef NEWUSR_H
#define NEWUSR_H

#include <QDialog>
#include <QString>

namespace Ui {
class newusr;
}

struct infousr
{
    QString name,id;
};

class newusr : public QDialog
{
    Q_OBJECT

public:
    explicit newusr(QWidget *parent = 0);
    ~newusr();
    void send()
    {
        emit usr(usr_info);
    }

signals:
    void usr(const infousr &);

private:
    Ui::newusr *ui;
    infousr usr_info;
    void upd();

};

#endif // NEWUSR_H
