#include "login.h"
#include "mysqlmanager.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *w;
    w = new login;
    mysqlManager *m;
    m = new mysqlManager;
    QObject::connect(w, &login::success, m, &mysqlManager::show);
    w -> show();

    return a.exec();
}
