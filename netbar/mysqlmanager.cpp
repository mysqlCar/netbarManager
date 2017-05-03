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
    connect(ui->usingRecord, &QPushButton::clicked, this, &mysqlManager::getRecord);
    connect(ui->tableStatus->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortStatus);
    connect(ui->tableRecord->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortRecord);
    connect(ui->tableRepair->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortRepair);
    connect(ui->removeCom, &QPushButton::clicked, this, &mysqlManager::removeComputer);
    connect(ui->comPushUp, &QPushButton::clicked, this, &mysqlManager::statusUp);
    connect(ui->comPushDown, &QPushButton::clicked, this, &mysqlManager::statusDown);
    connect(ui->queryRecord, &QPushButton::clicked, this, &mysqlManager::queryRecord);
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
    comCount++;
}

void mysqlManager::queryCom()
{
    QString num, model;
    int status;
    num = ui->qNumber->text();
    model = ui->qModel->text();
    status = ui->qStatus->currentIndex() - 1;
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
    string * pa, * pb, * pc, * pd;
    a = recordID.toStdString();
    b = computerID.toStdString();
    c = vipID.toStdString();
    d = userID.toStdString();
    if (a == "") pa = NULL;
    else pa = &a;
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
        ui->tableRecord->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(iter -> recordID)));
        string name;
        dataBase.getUserName(iter->userID, name);
        ui->tableRecord->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(name)));
        ui->tableRecord->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(iter -> vipID)));
        ui->tableRecord->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(iter -> computerID)));
        QDateTime temp;
        temp = QDateTime(QDate(2000, 1, 1));
        temp.addSecs(iter->startTime);
        ui->tableRecord->setItem(i, 4, new QTableWidgetItem(temp.toString("yyyy-MM-dd hh:mm:ss")));
        temp = QDateTime(QDate(2000, 1, 1));
        temp.addSecs(iter->endtTime);
        ui->tableRecord->setItem(i, 5, new QTableWidgetItem(temp.toString("yyyy-MM-dd hh:mm:ss")));
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
    if (! cardinfo.ok || cardinfo.name == NULL)
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
    int startsec, endsec;
    flag = dataBase.getComputerStatus(ainfo.comNumber);
    if (f)
    {
        warninginfo(tr("该电脑暂时无法分配，请选择一台空闲的电脑"));
        return;
    }
    static QDateTime begintime;
    begintime = (QDate(2000, 1, 1) );
    startsec = QDateTime::currentDateTime().secsTo(begintime);
    endsec = ainfo.endTime.secsTo(begintime);
    if (ainfo.useCash)
        ainfo.cardNumber = "card" + ainfo.idNumber;
    dataBase.changeComputerStatus(ainfo.comNumber.toStdString(), 1);
    int maxid = dataBase.getmaxid();

    flag = dataBase.Allocation(to_string(maxid), ainfo.comNumber.toStdString(),
                               ainfo.idNumber.toStdString(), ainfo.cardNumber.toStdString(),
                               startsec, endsec);
    if (flag)
        warninginfo(tr("分配失败，请确认输入合理！"));
    else
        successinfo(tr("分配成功！"));
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


