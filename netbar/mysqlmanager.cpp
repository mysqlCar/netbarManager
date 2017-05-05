#include "mysqlmanager.h"
#include "ui_mysqlmanager.h"
#include <bits/stdc++.h>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QTime>
#include <QDate>


mysqlManager::mysqlManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mysqlManager)
{
    ui->setupUi(this);
    connect(ui->addComputer, &QAction::triggered, this, &mysqlManager::addCom);
    connect(ui->addCustomer, &QAction::triggered, this, &mysqlManager::addUsr);
    connect(ui->addCard, &QAction::triggered, this, &mysqlManager::addCard);
    connect(ui->buttonAssign, &QPushButton::clicked, this, &mysqlManager::assignCom);
    connect(ui->buttonRepair, &QPushButton::clicked, this, &mysqlManager::repairCom);
    connect(ui->buttonRecharge, &QPushButton::clicked, this, &mysqlManager::beStrong);
    connect(ui->buttonQuery, &QPushButton::clicked, this, &mysqlManager::queryCom);
    connect(ui->buttonReset, &QPushButton::clicked, this, &mysqlManager::resetdata);
    //connect(ui->usingRecord, &QPushButton::clicked, this, &mysqlManager::getRecord);
    connect(ui->tableStatus->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortStatus);
    connect(ui->tableRecord->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortRecord);
    connect(ui->tableRepair->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortRepair);
    connect(ui->tableVIP->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortVIP);
    connect(ui->removeCom, &QPushButton::clicked, this, &mysqlManager::removeComputer);
    connect(ui->comPushUp, &QPushButton::clicked, this, &mysqlManager::statusUp);
    connect(ui->comPushDown, &QPushButton::clicked, this, &mysqlManager::statusDown);
    connect(ui->queryRecord, &QPushButton::clicked, this, &mysqlManager::queryRecord);
    connect(ui->qRepair, &QPushButton::clicked, this, &mysqlManager::queryRepair);
    connect(ui->mRepair, &QPushButton::clicked, this, &mysqlManager::modifyRepair);
    connect(ui->qCard, &QPushButton::clicked, this, &mysqlManager::queryCard);
    connect(ui->buttonShut, &QPushButton::clicked, this, &mysqlManager::shutCom);
    ui->tableStatus->viewport()->installEventFilter(this);
    ui->tableStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStatus->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableStatus->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableStatus->verticalHeader()->setHidden(true);
    ui->tableRecord->viewport()->installEventFilter(this);
    ui->tableRecord->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableRecord->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableRecord->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableRecord->verticalHeader()->setHidden(true);
    ui->tableRepair->viewport()->installEventFilter(this);
    ui->tableRepair->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableRepair->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableRepair->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableRepair->verticalHeader()->setHidden(true);
    ui->tableVIP->viewport()->installEventFilter(this);
    ui->tableVIP->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableVIP->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableVIP->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableVIP->verticalHeader()->setHidden(true);
    /*ui->tableStatus->setAcceptDrops(true);
    ui->tableStatus->setDragDropMode(QAbstractItemView::DragDrop);
    ui->tableStatus->setDragEnabled(true);*/
    comCount = 0;
    dataBase.initConnection();
    dataBase.initConnection();

    timerEvent(0);
    startTimer(1000);
}

mysqlManager::~mysqlManager()
{
    delete ui;
}

void mysqlManager::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    ui->time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"));
    static int counter = 0;
    counter++;
    if (counter %10 == 0)
    {
        counter = 0;
        checkcomputer();
    }
}

void mysqlManager::shutCom()
{
    int cur = ui->tableStatus->currentRow();
    QString ID = ui->tableStatus->item(cur,0)->text();
    dataBase.changeComputerStatus(ID.toStdString(), 0);
    ui->tableStatus->setItem(cur, 2, new QTableWidgetItem(tr("关机")));
}

void mysqlManager::checkcomputer()
{
    int sec;
    QDateTime begin;
    static vector<usingRecord> shut;
    begin = QDateTime(QDate(2000, 1, 1));
    sec = begin.secsTo(QDateTime::currentDateTime());
    qDebug() << sec;
    int flag = dataBase.selectPoweroff(sec, shut);
    if (!flag)
    {
        for (vector<usingRecord>::iterator iter = shut.begin(); iter!= shut.end(); iter++)
        {
            dataBase.changeComputerStatus(iter -> computerID, 0);
            cout << iter -> computerID;
        }
    }
}

void mysqlManager::addCom()
{
    cpu = new cpuinfo;
    connect(cpu, &cpuinfo::cpu, this, &mysqlManager::dealCom);
    cpu -> exec();
    delete cpu;
}

void mysqlManager::resetdata()
{
    QString password;
    bool ok;
    password = QInputDialog::getText(this, tr("确认"), tr("请输入密码"), QLineEdit::Password, NULL, &ok);
    if (ok && password == "123456")
        dataBase.Initialization();
}

void mysqlManager::dealCom(infocpu cinfo)
{
    qDebug() << cinfo.number << cinfo.model << comCount;
    string  number,model;
    number = cinfo.number.toStdString();
    model = cinfo.model.toStdString();
    int flag = dataBase.newComputer(number, model);
    if (flag)
    {
        warninginfo("添加用户失败，请确保当前添加电脑编号唯一");
        return;
    }
    successinfo("添加成功");
    ui-> tableStatus ->setRowCount(ui->tableStatus->rowCount() + 1);
    ui-> tableStatus ->setItem(ui->tableStatus->rowCount() - 1, 0, new QTableWidgetItem(cinfo.number));
    ui-> tableStatus ->setItem(ui->tableStatus->rowCount() - 1, 1, new QTableWidgetItem(cinfo.model));
    ui-> tableStatus ->setItem(ui->tableStatus->rowCount() - 1, 2, new QTableWidgetItem("关机"));
    comCount++;
}

void mysqlManager::queryCom()
{
    QString num, model;
    int status;
    num = ui->qNumber->text();
    model = ui->qModel->text();
    status = ui->qStatus->currentIndex() - 1;
    ui->qNumber->clear();
    ui->qModel->clear();
    ui->qStatus->setCurrentIndex(0);
    static vector<computer> comList;
    comList.clear();
    int i = 0;
    string a, b;
    string * pa, * pb;
    a = num.toStdString();
    b = model.toStdString();
    if (a == "") pa = NULL;
    else pa = &a;
    if (b == "") pb = NULL;
    else pb = &b;
    dataBase.selectComputer(pa, pb, status, comList);
    int comNumber = comList.size();
    ui->tableStatus->setRowCount(0);
    ui->tableStatus->clearContents();
    ui->tableStatus->setRowCount(comNumber);
    for (vector<computer>::iterator iter = comList.begin(); iter != comList.end(); iter++)
    {
        ui->tableStatus->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(iter -> computerID)));
        ui->tableStatus->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(iter -> computerType)));
        switch (iter -> computerStatus)
        {
        case (-1):
        {
            ui->tableStatus->removeRow(i);
            continue;
        }
        case(0):
        {
            ui->tableStatus->setItem(i, 2, new QTableWidgetItem(QString(tr("关机"))));
            i++;
            break;
        }
        case(1):
        {
            ui->tableStatus->setItem(i, 2, new QTableWidgetItem(QString(tr("使用中"))));
            i++;
            break;
        }
        case(2):
        {
            ui->tableStatus->setItem(i, 2, new QTableWidgetItem(QString(tr("维修中"))));
            i++;
            break;
        }
        }
    }

}

void mysqlManager::queryRecord()
{
    QString recordID, computerID, vipID, userID;
    recordID = ui->qRecord->text();
    computerID = ui->qCom->text();
    vipID = ui->qVIP->text();
    userID = ui->qUser->text();
    static vector<usingRecord> recordList;
    recordList.clear();
    int i = 0;
    string a, b, c ,d;
    int  pa;
    string * pb, * pc, * pd;
    a = recordID.toStdString();
    b = computerID.toStdString();
    c = vipID.toStdString();
    d = userID.toStdString();
    if (a == "") pa = -1;
    else pa = stoi(a);
    if (b == "") pb = NULL;
    else pb = &b;
    if (c == "") pc = NULL;
    else pc = &c;
    if (d == "") pd = NULL;
    else pd = &d;
    dataBase.selectUsingRecord(pa, pb, pc, pd, recordList);
    int recNumber = recordList.size();
    ui->tableRecord->setRowCount(0);
    ui->tableRecord->clearContents();
    ui->tableRecord->setRowCount(recNumber);
    for (vector<usingRecord>::iterator iter = recordList.begin(); iter != recordList.end(); iter++)
    {
        ui->tableRecord->setItem(i, 0, new QTableWidgetItem(QString::number(iter -> recordID)));
        string name;
        dataBase.getUserName(iter->userID, name);
        ui->tableRecord->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
        ui->tableRecord->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(iter -> vipID)));
        ui->tableRecord->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(iter -> computerID)));
        QDateTime temp;
        temp = QDateTime(QDate(2000, 1, 1));
        temp = temp.addSecs(iter->startTime);
        ui->tableRecord->setItem(i, 4, new QTableWidgetItem(temp.toString("yyyy-MM-dd hh:mm:ss")));
        temp = QDateTime(QDate(2000, 1, 1));
        temp = temp.addSecs(iter->endTime);
        ui->tableRecord->setItem(i, 5, new QTableWidgetItem(temp.toString("yyyy-MM-dd hh:mm:ss")));
        ++i;
    }
}

void mysqlManager::queryRepair()
{
    QString repairID, comNumber, repStatus;
    int pd;
    repairID = ui->repairID->text();
    comNumber = ui->repairNum->text();
    repStatus = ui->repairSta->text();
    pd = ui->repairReason->currentIndex() - 1;
    ui->repairID->clear();
    ui->repairNum->clear();
    ui->repairSta->clear();
    ui->repairReason->setCurrentIndex(0);
    static vector<repairment> repList;
    repList.clear();
    int i = 0;
    string a, b, c;
    int  pa, pc;
    string * pb;
    a = repairID.toStdString();
    b = comNumber.toStdString();
    c = repStatus.toStdString();
    if (a == "") pa = -1;
    else pa = stoi(a);
    if (b == "") pb = NULL;
    else pb = &b;
    if (c == "") pc = -1;
    else pc = stoi(c);
    dataBase.selectRepairment(pa, pb, pd, -1, pc, repList);
    int repNumber = repList.size();
    ui->tableRepair->setRowCount(0);
    ui->tableRepair->clearContents();
    ui->tableRepair->setRowCount(repNumber);
    for (vector<repairment>::iterator iter = repList.begin(); iter != repList.end(); iter++)
    {
        ui->tableRepair->setItem(i, 0, new QTableWidgetItem(QString::number(iter -> repairmentID)));
        ui->tableRepair->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(iter -> computerID)));
        QDateTime temp;
        temp = QDateTime(QDate(2000, 1, 1));
        temp = temp.addSecs(iter->repairmentDate);
        ui->tableRepair->setItem(i, 2, new QTableWidgetItem(temp.toString("yyyy-MM-dd hh:mm:ss")));
        switch (iter -> repairmentReason){
        case 0:
            ui->tableRepair->setItem(i, 3, new QTableWidgetItem(tr("硬件故障")));
            break;
        default:
            ui->tableRepair->setItem(i, 3, new QTableWidgetItem(tr("软件故障")));
        }
        switch (iter -> repairmentStatus){
        case 0:
            ui->tableRepair->setItem(i, 4, new QTableWidgetItem(tr("未修复")));
            break;
        default:
            ui->tableRepair->setItem(i, 4, new QTableWidgetItem(tr("已修复")));
        }
        i++;
    }
}

void mysqlManager::queryCard()
{
    QString userID;
    userID = ui->id2Card->text();
    ui->id2Card->clear();
    static vector<vipCard> cardList;
    cardList.clear();
    int i = 0;
    string a;
    string * pa;
    a = userID.toStdString();
    if (a== "") pa = NULL;
    else pa = &a;
    dataBase.selectVIP(NULL, pa, -1, cardList);
    int cardNumber = cardList.size();
    ui->tableVIP->setRowCount(0);
    ui->tableVIP->clearContents();
    ui->tableVIP->setRowCount(cardNumber);
    for (vector<vipCard>::iterator iter = cardList.begin(); iter != cardList.end(); iter++)
    {
        ui->tableVIP->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(iter -> userID)));
        ui->tableVIP->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(iter -> vipID)));
        ui->tableVIP->setItem(i, 2, new QTableWidgetItem(QString::number(iter -> vipBalance)));
        ui->tableVIP->setItem(i, 3, new QTableWidgetItem(QString::number(iter -> vipRank)));
        ++i;
    }
}

void mysqlManager::addUsr()
{
    usr = new newusr;
    connect(usr, &newusr::usr, this, &mysqlManager::dealUsr);
    usr -> exec();
    delete usr;
}

void mysqlManager::dealUsr(infousr uinfo)
{
    qDebug() << uinfo.name << uinfo.id << "\n";
    string name, id;
    name = uinfo.name.toStdString();
    id = uinfo.id.toStdString();
    int flag = dataBase.newUser(id, name);
    if (flag)
        warninginfo("添加用户失败，请确保当前添加用户为新用户且身份证合法");
    else
        successinfo("添加成功");
}

void mysqlManager::addCard()
{
    card = new newcard;
    connect(card, &newcard::card, this, &mysqlManager::dealCard);
    card -> exec();
    delete card;
}

void mysqlManager::dealCard(infocard cardinfo)
{
    cout << "START" << endl;
    if (cardinfo.name != NULL)
        cout << cardinfo.name.toStdString() << endl;
    if (cardinfo.ok_name && cardinfo.ok_cardID)
        cout << 1 << endl;
    cout << "ENDL" << endl;

    if (! (cardinfo.ok_name && cardinfo.ok_cardID) || cardinfo.name == NULL)
    {
        warninginfo("创建新卡失败，请在确认前使用两个检查按钮确认输入信息是否合法");
        return;
    }
    qDebug() << cardinfo.id << cardinfo.name << cardinfo.charge << "\n";
    int flag = dataBase.newVIP(cardinfo.cardNumber.toStdString(), cardinfo.id.toStdString(), cardinfo.charge.toInt());
    if (flag)
    {
        warninginfo("创建新卡失败，请在确认前使用两个检查按钮确认输入信息是否合法");
    }
    else
    {
        successinfo("添加成功");
    }
}

void mysqlManager::assignCom()
{
    asign = new assign;
    connect(asign, &assign::assigned, this, &mysqlManager::dealAssign);
    asign -> exec();
    delete asign;
}

void mysqlManager::dealAssign(assignInfo ainfo)
{
    qDebug() << ainfo.cardNumber << ainfo.comNumber << ainfo.useCash << "\n";
    int flag;
    qint64 startsec, endsec;
    flag = dataBase.getComputerStatus(ainfo.comNumber.toStdString());
    if (flag)
    {
        warninginfo(tr("该电脑暂时无法分配，请选择一台空闲的电脑"));
        return;
    }
    static QDateTime begintime;
    begintime = QDateTime(QDate(2000, 1, 1) );
    startsec = -QDateTime::currentDateTime().secsTo(begintime);
    endsec = -ainfo.endTime.secsTo(begintime);
    if (ainfo.useCash)
        ainfo.cardNumber = "card" + ainfo.idNumber;
    int maxid;
    flag = dataBase.getMaxRecordID(maxid);
    if (flag)
        warninginfo(tr("查询失败"));
    //这里我修了一修
    static vector<vipCard> k;
    int cost;
    cost = (endsec-startsec)/3600 + 1;
    if (! ((endsec-startsec) % 3600))
        cost --;
    cost *= 2;
    k.clear();
    if (!ainfo.useCash)
    {
        string t;
        t = ainfo.cardNumber.toStdString();
        flag = dataBase.selectVIP(&t, NULL, -1, k);
        qDebug() << cost << QString::fromStdString(k[0].vipID) << (k[0].vipBalance);
        if (flag)
        {
            warninginfo(tr("指定会员卡无效"));
             return;
        }
        if (k[0].vipBalance < cost)
        {
            warninginfo(tr("余额不足，请先充值！"));
            return;
        }
    }

    flag = dataBase.Allocation(maxid + 1, ainfo.comNumber.toStdString(),
                               ainfo.cardNumber.toStdString(), ainfo.idNumber.toStdString(),
                               startsec, endsec);
    qDebug() << maxid+1 << ainfo.comNumber << ainfo.idNumber << ainfo.cardNumber << startsec
             << endsec;
    if (flag)
        warninginfo(tr("分配失败，请确认输入合理！"));
    else
    {
        successinfo(tr("分配成功！"));
        dataBase.rechargeVIP(ainfo.cardNumber.toStdString(), -cost);
        dataBase.changeComputerStatus(ainfo.comNumber.toStdString(), 1);
        queryRecord();
    }
}

void mysqlManager::repairCom()
{
    mend = new repair;
    connect(mend, &repair::mendSig, this, &mysqlManager::dealRepair);
    mend -> exec();
    delete mend;
}

void mysqlManager::dealRepair(repairInfo rinfo)
{
    qDebug() << rinfo.comNumber << rinfo.errNumber;
    int maxid;
    int flag;
    flag = dataBase.getMaxRepairID(maxid);
    if (flag)
        warninginfo(tr("查询失败"));
    QDateTime begintime = QDateTime(QDate(2000, 1, 1) );
    dataBase.newRepairment(maxid + 1, rinfo.comNumber.toStdString(), rinfo.errNumber, -QDateTime::currentDateTime().secsTo(begintime), 0);
    dataBase.changeComputerStatus(rinfo.comNumber.toStdString(), 2);
    queryRepair();
}

void mysqlManager::modifyRepair()
{
    QString rID, rStatus, cID;
    int cur, flag;
    cur = ui->tableRepair->currentRow();
    rID = ui->tableRepair->item(cur, 0)->text();
    cID = ui->tableRepair->item(cur, 1)->text();
    rStatus = ui->tableRepair->item(cur, 4)->text();
    if (rStatus == tr("未修复"))
    {
        bool ok;
        flag = dataBase.changeRepairmentStatus(rID.toInt(&ok), 1);
        if (!flag && ok)
        {
            ui->tableRepair->setItem(cur, 4, new QTableWidgetItem(tr("已修复")));
            dataBase.changeComputerStatus(cID.toStdString(), 0);
            dataBase.changeRepairmentStatus(rID.toInt(), 1);
            successinfo(tr("更改修理状态成功！"));
        }
        else
        {
            warninginfo(tr("更改修理状态失败！"));
        }
    }
    else
    {
        bool ok;
        flag = dataBase.changeRepairmentStatus(rID.toInt(&ok), 0);
        if (!flag && ok)
        {
            ui->tableRepair->setItem(cur, 4, new QTableWidgetItem(tr("未修复")));
            dataBase.changeComputerStatus(cID.toStdString(), 2);
            dataBase.changeRepairmentStatus(rID.toInt(), 0);
            successinfo(tr("更改修理状态成功！"));
        }
        else
        {
            warninginfo(tr("更改修理状态失败！"));
        }
    }

}

void mysqlManager::beStrong()
{
    charge = new recharge;
    connect(charge, &recharge::charge, this, &mysqlManager::dealStrong);
    charge ->exec();
    delete charge;
}

void mysqlManager::dealStrong(rechargeInfo rinfo)
{
    qDebug() << rinfo.cardNumber << rinfo.money << endl;
    int flag = dataBase.rechargeVIP(rinfo.cardNumber.toStdString(), rinfo.money.toInt());
    qDebug() << flag;
    flag = flag || !dataBase.checkVIPNumber(rinfo.cardNumber.toStdString());
    qDebug() << flag;
    if (flag)
    {
        warninginfo("充值失败，请输入正确的卡号和充值金额！");
    }
    else
    {
        successinfo("充值成功，你变强了！");
    }
}

void mysqlManager::getRecord()
{
    ui->tabWidget->setCurrentIndex(2);
}

void mysqlManager::sortStatus(int column)
{
    static bool f = true;
    ui->tableStatus->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

void mysqlManager::sortRecord(int column)
{
    static bool f = true;
    ui->tableRecord->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

void mysqlManager::sortRepair(int column)
{
    static bool f = true;
    ui->tableRepair->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

void mysqlManager::sortVIP(int column)
{
    static bool f = true;
    ui->tableVIP->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

void mysqlManager::removeComputer()
{    
    QString num;
    int r = ui->tableStatus->currentRow();
    num = ui->tableStatus->item(r, 1)->text();
    dataBase.abandonComputer(num.toStdString());
    ui->tableStatus->removeRow(ui->tableStatus->currentRow());
}

void mysqlManager::statusUp()
{
    int cur = ui->tableStatus->currentRow();
    int column = ui->tableStatus->columnCount();
    if (cur > 0)
    {
        for (int i = 0; i < column; i++)
        {
            QTableWidgetItem *temp;
            temp = ui->tableStatus->item(cur, i)->clone();
            ui->tableStatus->setItem(cur, i, ui->tableStatus->item(cur - 1, i)->clone());
            ui->tableStatus->setItem(cur - 1, i, temp);
        }
    }
    ui->tableStatus->selectRow(cur - 1);
}

void mysqlManager::statusDown()
{
    int cur = ui->tableStatus->currentRow();
    int column = ui->tableStatus->columnCount();
    if (cur >= 0 && cur < ui->tableStatus->rowCount() - 1)
    {
        for (int i = 0; i < column; i++)
        {
            QTableWidgetItem *temp;
            temp = ui->tableStatus->item(cur, i)->clone();
            ui->tableStatus->setItem(cur, i, ui->tableStatus->item(cur + 1, i)->clone());
            ui->tableStatus->setItem(cur + 1, i, temp);
        }
    }
    ui->tableStatus->selectRow(cur + 1);
}

void mysqlManager::refreshStatus()
{
    vector<computer> comList;
    int i = 0;
    dataBase.selectComputer(NULL, NULL, -1, comList);
    int comNumber = comList.size();
    ui->tableStatus->setRowCount(0);
    ui->tableStatus->clearContents();
    ui->tableStatus->setRowCount(comNumber);
    for (vector<computer>::iterator iter = comList.begin(); iter != comList.end(); iter++)
    {
        ui->tableStatus->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(iter -> computerID)));
        ui->tableStatus->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(iter -> computerType)));
        switch (iter -> computerStatus)
        {
        case (-1):
        {
            ui->tableStatus->removeRow(i);
            continue;
        }
        case(0):
        {
            ui->tableStatus->setItem(i, 2, new QTableWidgetItem(QString(tr("关机"))));
            i++;
        }
        case(1):
        {
            ui->tableStatus->setItem(i, 2, new QTableWidgetItem(QString(tr("使用中"))));
            i++;
        }
        }


    }
}

void mysqlManager::successinfo(QString info)
{
    QMessageBox::information(this, tr("Success"), info, QMessageBox::Yes, QMessageBox::Yes);
}

void mysqlManager::warninginfo(QString info)
{
    QMessageBox::warning(this, tr("Warning"), info,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}


