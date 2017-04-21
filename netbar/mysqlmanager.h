#ifndef MYSQLMANAGER_H
#define MYSQLMANAGER_H

#include <QMainWindow>
#include "cpuinfo.h"
#include "newusr.h"
#include "newcard.h"
#include "assign.h"
#include "recharge.h"
#include "repair.h"
#include "myManager.hpp"


namespace Ui {
class mysqlManager;
}

class mysqlManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit mysqlManager(QWidget *parent = 0);
    ~mysqlManager();
/*
protected:
    bool eventFilter(QObject *obj, QEvent *eve);
*/
private:
    Ui::mysqlManager *ui;

    int comCount;

    cpuinfo *cpu;
    newusr *usr;
    newcard *card;
    assign *asign;
    recharge *charge;
    repair *mend;
    myManager dataBase;

    void addCom();
    void dealCom(infocpu);
    void addUsr();
    void dealUsr(infousr);
    void addCard();
    void dealCard(infocard);
    void assignCom();
    void dealAssign(assignInfo);
    void beStrong();
    void dealStrong(rechargeInfo);
    void repairCom();
    void dealRepair(repairInfo);
    void getRecord();

    void removeComputer();
    void sortStatus(int);
    void statusUp();
    void statusDown();
    void refreshStatus();

};

#endif // MYSQLMANAGER_H
