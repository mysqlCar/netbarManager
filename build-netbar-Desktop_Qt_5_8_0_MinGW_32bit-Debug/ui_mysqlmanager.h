/********************************************************************************
** Form generated from reading UI file 'mysqlmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSQLMANAGER_H
#define UI_MYSQLMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mysqlManager
{
public:
    QAction *addComputer;
    QAction *addCustomer;
    QAction *addCard;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *status;
    QTableWidget *tableStatus;
    QPushButton *buttonAssign;
    QPushButton *buttonRepair;
    QPushButton *usingRecord;
    QPushButton *removeCom;
    QPushButton *comPushUp;
    QPushButton *comPushDown;
    QPushButton *buttonQuery;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLineEdit *qNumber;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *qModel;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QComboBox *qStatus;
    QPushButton *buttonReset;
    QWidget *user;
    QPushButton *buttonRecharge;
    QLabel *label;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *useRecord;
    QTableWidget *tableRecord;
    QPushButton *queryRecord;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *qRecord;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *qUser;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *qVIP;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *qCom;
    QWidget *repairRecord;
    QTableWidget *tableRepair;
    QPushButton *qRepair;
    QPushButton *mRepair;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *repairID;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *repairNum;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLineEdit *repairSta;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QComboBox *repairReason;
    QLabel *time;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mysqlManager)
    {
        if (mysqlManager->objectName().isEmpty())
            mysqlManager->setObjectName(QStringLiteral("mysqlManager"));
        mysqlManager->resize(800, 600);
        addComputer = new QAction(mysqlManager);
        addComputer->setObjectName(QStringLiteral("addComputer"));
        addCustomer = new QAction(mysqlManager);
        addCustomer->setObjectName(QStringLiteral("addCustomer"));
        addCard = new QAction(mysqlManager);
        addCard->setObjectName(QStringLiteral("addCard"));
        centralwidget = new QWidget(mysqlManager);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 40, 741, 511));
        status = new QWidget();
        status->setObjectName(QStringLiteral("status"));
        tableStatus = new QTableWidget(status);
        if (tableStatus->columnCount() < 3)
            tableStatus->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableStatus->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableStatus->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableStatus->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableStatus->setObjectName(QStringLiteral("tableStatus"));
        tableStatus->setGeometry(QRect(40, 40, 391, 411));
        buttonAssign = new QPushButton(status);
        buttonAssign->setObjectName(QStringLiteral("buttonAssign"));
        buttonAssign->setGeometry(QRect(450, 320, 75, 23));
        buttonRepair = new QPushButton(status);
        buttonRepair->setObjectName(QStringLiteral("buttonRepair"));
        buttonRepair->setGeometry(QRect(450, 360, 75, 23));
        usingRecord = new QPushButton(status);
        usingRecord->setObjectName(QStringLiteral("usingRecord"));
        usingRecord->setGeometry(QRect(450, 400, 75, 23));
        removeCom = new QPushButton(status);
        removeCom->setObjectName(QStringLiteral("removeCom"));
        removeCom->setGeometry(QRect(450, 440, 75, 23));
        comPushUp = new QPushButton(status);
        comPushUp->setObjectName(QStringLiteral("comPushUp"));
        comPushUp->setGeometry(QRect(450, 40, 75, 23));
        comPushDown = new QPushButton(status);
        comPushDown->setObjectName(QStringLiteral("comPushDown"));
        comPushDown->setGeometry(QRect(450, 80, 75, 23));
        buttonQuery = new QPushButton(status);
        buttonQuery->setObjectName(QStringLiteral("buttonQuery"));
        buttonQuery->setGeometry(QRect(650, 440, 75, 23));
        horizontalLayoutWidget = new QWidget(status);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(560, 320, 160, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        qNumber = new QLineEdit(horizontalLayoutWidget);
        qNumber->setObjectName(QStringLiteral("qNumber"));

        horizontalLayout->addWidget(qNumber);

        horizontalLayoutWidget_2 = new QWidget(status);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(560, 360, 160, 22));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        qModel = new QLineEdit(horizontalLayoutWidget_2);
        qModel->setObjectName(QStringLiteral("qModel"));

        horizontalLayout_2->addWidget(qModel);

        horizontalLayoutWidget_3 = new QWidget(status);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(560, 400, 160, 22));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        qStatus = new QComboBox(horizontalLayoutWidget_3);
        qStatus->setObjectName(QStringLiteral("qStatus"));

        horizontalLayout_3->addWidget(qStatus);

        buttonReset = new QPushButton(status);
        buttonReset->setObjectName(QStringLiteral("buttonReset"));
        buttonReset->setGeometry(QRect(450, 280, 75, 23));
        tabWidget->addTab(status, QString());
        user = new QWidget();
        user->setObjectName(QStringLiteral("user"));
        buttonRecharge = new QPushButton(user);
        buttonRecharge->setObjectName(QStringLiteral("buttonRecharge"));
        buttonRecharge->setGeometry(QRect(480, 260, 75, 23));
        label = new QLabel(user);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 300, 81, 16));
        pushButton_5 = new QPushButton(user);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 330, 75, 23));
        pushButton_6 = new QPushButton(user);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 330, 75, 23));
        tabWidget->addTab(user, QString());
        useRecord = new QWidget();
        useRecord->setObjectName(QStringLiteral("useRecord"));
        tableRecord = new QTableWidget(useRecord);
        if (tableRecord->columnCount() < 6)
            tableRecord->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableRecord->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        tableRecord->setObjectName(QStringLiteral("tableRecord"));
        tableRecord->setGeometry(QRect(70, 30, 631, 192));
        queryRecord = new QPushButton(useRecord);
        queryRecord->setObjectName(QStringLiteral("queryRecord"));
        queryRecord->setGeometry(QRect(180, 390, 75, 23));
        horizontalLayoutWidget_4 = new QWidget(useRecord);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(180, 260, 160, 22));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        qRecord = new QLineEdit(horizontalLayoutWidget_4);
        qRecord->setObjectName(QStringLiteral("qRecord"));

        horizontalLayout_4->addWidget(qRecord);

        horizontalLayoutWidget_5 = new QWidget(useRecord);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(180, 290, 160, 22));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        qUser = new QLineEdit(horizontalLayoutWidget_5);
        qUser->setObjectName(QStringLiteral("qUser"));

        horizontalLayout_5->addWidget(qUser);

        horizontalLayoutWidget_6 = new QWidget(useRecord);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(180, 320, 160, 22));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        qVIP = new QLineEdit(horizontalLayoutWidget_6);
        qVIP->setObjectName(QStringLiteral("qVIP"));

        horizontalLayout_6->addWidget(qVIP);

        horizontalLayoutWidget_7 = new QWidget(useRecord);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(180, 350, 160, 22));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        qCom = new QLineEdit(horizontalLayoutWidget_7);
        qCom->setObjectName(QStringLiteral("qCom"));

        horizontalLayout_7->addWidget(qCom);

        tabWidget->addTab(useRecord, QString());
        repairRecord = new QWidget();
        repairRecord->setObjectName(QStringLiteral("repairRecord"));
        tableRepair = new QTableWidget(repairRecord);
        if (tableRepair->columnCount() < 5)
            tableRepair->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableRepair->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableRepair->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableRepair->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableRepair->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableRepair->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        tableRepair->setObjectName(QStringLiteral("tableRepair"));
        tableRepair->setGeometry(QRect(70, 60, 591, 192));
        qRepair = new QPushButton(repairRecord);
        qRepair->setObjectName(QStringLiteral("qRepair"));
        qRepair->setGeometry(QRect(150, 400, 75, 23));
        mRepair = new QPushButton(repairRecord);
        mRepair->setObjectName(QStringLiteral("mRepair"));
        mRepair->setGeometry(QRect(460, 400, 75, 23));
        horizontalLayoutWidget_8 = new QWidget(repairRecord);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(120, 270, 160, 22));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_8);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        repairID = new QLineEdit(horizontalLayoutWidget_8);
        repairID->setObjectName(QStringLiteral("repairID"));

        horizontalLayout_8->addWidget(repairID);

        horizontalLayoutWidget_9 = new QWidget(repairRecord);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(120, 300, 160, 22));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_9);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        repairNum = new QLineEdit(horizontalLayoutWidget_9);
        repairNum->setObjectName(QStringLiteral("repairNum"));

        horizontalLayout_9->addWidget(repairNum);

        horizontalLayoutWidget_10 = new QWidget(repairRecord);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(120, 360, 160, 22));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget_10);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        repairSta = new QLineEdit(horizontalLayoutWidget_10);
        repairSta->setObjectName(QStringLiteral("repairSta"));

        horizontalLayout_10->addWidget(repairSta);

        horizontalLayoutWidget_11 = new QWidget(repairRecord);
        horizontalLayoutWidget_11->setObjectName(QStringLiteral("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(120, 330, 160, 22));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_11);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_11->addWidget(label_14);

        repairReason = new QComboBox(horizontalLayoutWidget_11);
        repairReason->setObjectName(QStringLiteral("repairReason"));

        horizontalLayout_11->addWidget(repairReason);

        tabWidget->addTab(repairRecord, QString());
        time = new QLabel(centralwidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(530, 20, 241, 21));
        mysqlManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mysqlManager);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        mysqlManager->setMenuBar(menubar);
        statusbar = new QStatusBar(mysqlManager);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mysqlManager->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(addComputer);
        menu->addAction(addCustomer);
        menu->addAction(addCard);

        retranslateUi(mysqlManager);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(mysqlManager);
    } // setupUi

    void retranslateUi(QMainWindow *mysqlManager)
    {
        mysqlManager->setWindowTitle(QApplication::translate("mysqlManager", "MainWindow", Q_NULLPTR));
        addComputer->setText(QApplication::translate("mysqlManager", "New Computer", Q_NULLPTR));
        addCustomer->setText(QApplication::translate("mysqlManager", "New Customer", Q_NULLPTR));
        addCard->setText(QApplication::translate("mysqlManager", "New Card", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableStatus->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mysqlManager", "\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableStatus->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mysqlManager", "\345\236\213\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableStatus->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mysqlManager", "\347\224\265\350\204\221\347\212\266\346\200\201", Q_NULLPTR));
        buttonAssign->setText(QApplication::translate("mysqlManager", "\345\210\206\351\205\215", Q_NULLPTR));
        buttonRepair->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256", Q_NULLPTR));
        usingRecord->setText(QApplication::translate("mysqlManager", "\344\270\212\346\234\272\350\256\260\345\275\225", Q_NULLPTR));
        removeCom->setText(QApplication::translate("mysqlManager", "\347\247\273\351\231\244", Q_NULLPTR));
        comPushUp->setText(QApplication::translate("mysqlManager", "\344\270\212\347\247\273", Q_NULLPTR));
        comPushDown->setText(QApplication::translate("mysqlManager", "\344\270\213\347\247\273", Q_NULLPTR));
        buttonQuery->setText(QApplication::translate("mysqlManager", "\346\237\245\350\257\242", Q_NULLPTR));
        label_9->setText(QApplication::translate("mysqlManager", "\347\274\226\345\217\267", Q_NULLPTR));
        label_10->setText(QApplication::translate("mysqlManager", "\345\236\213\345\217\267", Q_NULLPTR));
        label_11->setText(QApplication::translate("mysqlManager", "\347\212\266\346\200\201", Q_NULLPTR));
        qStatus->clear();
        qStatus->insertItems(0, QStringList()
         << QApplication::translate("mysqlManager", "\344\270\215\346\214\207\345\256\232", Q_NULLPTR)
         << QApplication::translate("mysqlManager", "\345\205\263\346\234\272", Q_NULLPTR)
         << QApplication::translate("mysqlManager", "\344\275\277\347\224\250\344\270\255", Q_NULLPTR)
        );
        buttonReset->setText(QApplication::translate("mysqlManager", "\351\207\215\347\275\256", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(status), QApplication::translate("mysqlManager", "\347\224\265\350\204\221\347\212\266\346\200\201", Q_NULLPTR));
        buttonRecharge->setText(QApplication::translate("mysqlManager", "\345\205\205\345\200\274", Q_NULLPTR));
        label->setText(QApplication::translate("mysqlManager", "\344\275\277\347\224\250\350\256\260\345\275\225\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("mysqlManager", "\347\224\250\346\210\267", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("mysqlManager", "\344\274\232\345\221\230", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(user), QApplication::translate("mysqlManager", "\347\224\250\346\210\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableRecord->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("mysqlManager", "\346\265\201\346\260\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableRecord->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("mysqlManager", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableRecord->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("mysqlManager", "\345\215\241\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableRecord->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("mysqlManager", "\347\224\265\350\204\221\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableRecord->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("mysqlManager", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableRecord->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("mysqlManager", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        queryRecord->setText(QApplication::translate("mysqlManager", "\346\237\245\350\257\242", Q_NULLPTR));
        label_5->setText(QApplication::translate("mysqlManager", "\346\265\201\346\260\264\345\217\267  ", Q_NULLPTR));
        label_2->setText(QApplication::translate("mysqlManager", "\347\224\250\346\210\267\345\220\215  ", Q_NULLPTR));
        label_3->setText(QApplication::translate("mysqlManager", "\345\215\241\345\217\267    ", Q_NULLPTR));
        label_4->setText(QApplication::translate("mysqlManager", "\347\224\265\350\204\221\347\274\226\345\217\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(useRecord), QApplication::translate("mysqlManager", "\344\270\212\346\234\272\350\256\260\345\275\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableRepair->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256\346\265\201\346\260\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableRepair->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256\347\224\265\350\204\221\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableRepair->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableRepair->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256\345\216\237\345\233\240", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableRepair->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("mysqlManager", "\344\277\256\347\220\206\347\212\266\346\200\201", Q_NULLPTR));
        qRepair->setText(QApplication::translate("mysqlManager", "\346\237\245\350\257\242", Q_NULLPTR));
        mRepair->setText(QApplication::translate("mysqlManager", "\346\233\264\346\224\271", Q_NULLPTR));
        label_6->setText(QApplication::translate("mysqlManager", "\346\265\201\346\260\264\345\217\267  ", Q_NULLPTR));
        label_12->setText(QApplication::translate("mysqlManager", "\347\274\226\345\217\267    ", Q_NULLPTR));
        label_13->setText(QApplication::translate("mysqlManager", "\344\277\256\347\220\206\347\212\266\346\200\201", Q_NULLPTR));
        label_14->setText(QApplication::translate("mysqlManager", "\346\212\245\344\277\256\345\216\237\345\233\240", Q_NULLPTR));
        repairReason->clear();
        repairReason->insertItems(0, QStringList()
         << QApplication::translate("mysqlManager", "\344\273\273\346\204\217", Q_NULLPTR)
         << QApplication::translate("mysqlManager", "\347\241\254\344\273\266\346\225\205\351\232\234", Q_NULLPTR)
         << QApplication::translate("mysqlManager", "\350\275\257\344\273\266\346\225\205\351\232\234", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(repairRecord), QApplication::translate("mysqlManager", "\346\212\245\344\277\256\350\256\260\345\275\225", Q_NULLPTR));
        time->setText(QApplication::translate("mysqlManager", "TextLabel", Q_NULLPTR));
        menu->setTitle(QApplication::translate("mysqlManager", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mysqlManager: public Ui_mysqlManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQLMANAGER_H
