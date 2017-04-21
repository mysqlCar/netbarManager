#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void send()
    {
        emit success();
    }

signals:
    void success();

private:
    Ui::login *ui;
    void check();
};

#endif // LOGIN_H
