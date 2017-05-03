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
#include "global.h"
#include <QTimerEvent>


namespace Ui {
class mysqlManager;
}

class mysqlManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit mysqlManager(QWidget *parent = 0);
    ~mysqlManager();

protected:
    void timerEvent(QTimerEvent *event);


private:
    Ui::mysqlManager *ui;

    int comCount;

    cpuinfo *cpu;
    newusr *usr;
    newcard *card;
    assign *asign;
    recharge *charge;
    repair *mend;

    void queryCom();
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
    void queryRecord();
    void queryRepair();
    void modifyRepair();

    void removeComputer();
    void sortStatus(int);
    void sortRecord(int);
    void sortRepair(int);
    void statusUp();
    void statusDown();
    void refreshStatus();
    void resetdata();

    void successinfo(QString);
    void warninginfo(QString);
};

#endif // MYSQLMANAGER_H
