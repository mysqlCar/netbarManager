#include "mysqlmanager.h"
#include "ui_mysqlmanager.h"
#include <bits/stdc++.h>
#include <QDebug>
#include <QMessageBox>


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
    connect(ui->usingRecord, &QPushButton::clicked, this, &mysqlManager::getRecord);
    connect(ui->tableStatus->horizontalHeader(), &QHeaderView::sectionClicked, this, &mysqlManager::sortStatus);
    connect(ui->removeCom, &QPushButton::clicked, this, &mysqlManager::removeComputer);
    connect(ui->comPushUp, &QPushButton::clicked, this, &mysqlManager::statusUp);
    connect(ui->comPushDown, &QPushButton::clicked, this, &mysqlManager::statusDown);
    ui->tableStatus->viewport()->installEventFilter(this);
    ui->tableStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStatus->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableStatus->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableStatus->verticalHeader()->setHidden(true);
    /*ui->tableStatus->setAcceptDrops(true);
    ui->tableStatus->setDragDropMode(QAbstractItemView::DragDrop);
    ui->tableStatus->setDragEnabled(true);*/
    comCount = 0;
    dataBase.initConnection();
    dataBase.initConnection();
}

mysqlManager::~mysqlManager()
{
    delete ui;
}

void mysqlManager::addCom()
{
    cpu = new cpuinfo;
    connect(cpu, &cpuinfo::cpu, this, &mysqlManager::dealCom);
    cpu -> exec();
    delete cpu;
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

/*void mysqlManager::calcCom()
{
    int flag = dataBase.newComputer();
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
}*/

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

void mysqlManager::removeComputer()
{
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

/*
bool mysqlManager::eventFilter(QObject *obj, QEvent *eve)
{
    if(obj == ui->tableStatus->viewport())
    {
        if(eve->type() == QEvent::Drop)
        {
                const QMimeData *mime = ((QDropEvent*)eve)->mimeData();
                QByteArray encodedata = mime->data("application/x-qabstractitemmodeldatalist");
                if (encodedata.isEmpty())
                {
                    return false;
                }
                QDataStream stream(&encodedata, QIODevice::ReadOnly);
                while (!stream.atEnd())
                {
                    int row, col;
                    QMap<int,  QVariant> roleDataMap;
                    stream >> row >> col >> roleDataMap;
                    QTableWidgetItem* pDropItem = ui->tableStatus->itemAt(((QDropEvent*)eve)->pos());
                    if(!pDropItem)
                    {
                        return true;
                    }
                    if(pDropItem->row() == row)
                    {
                        return true;
                    }
                    return true;    //不要交给系统处理，否则他会给你新增一行
                }
            }else
            {
                return QWidget::eventFilter(obj,eve);
            }
        }
        return QWidget::eventFilter(obj,eve);
}
*/
