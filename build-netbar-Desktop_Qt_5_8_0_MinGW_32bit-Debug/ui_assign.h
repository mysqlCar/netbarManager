/********************************************************************************
** Form generated from reading UI file 'assign.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGN_H
#define UI_ASSIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_assign
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *number;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *name;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *id;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *endtime;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *cardnum;
    QCheckBox *cash;

    void setupUi(QDialog *assign)
    {
        if (assign->objectName().isEmpty())
            assign->setObjectName(QStringLiteral("assign"));
        assign->resize(400, 332);
        buttonBox = new QDialogButtonBox(assign);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(assign);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 50, 221, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        number = new QLineEdit(horizontalLayoutWidget);
        number->setObjectName(QStringLiteral("number"));

        horizontalLayout->addWidget(number);

        horizontalLayoutWidget_2 = new QWidget(assign);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 90, 221, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        name = new QLineEdit(horizontalLayoutWidget_2);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout_2->addWidget(name);

        horizontalLayoutWidget_3 = new QWidget(assign);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(90, 130, 221, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        id = new QLineEdit(horizontalLayoutWidget_3);
        id->setObjectName(QStringLiteral("id"));

        horizontalLayout_3->addWidget(id);

        horizontalLayoutWidget_4 = new QWidget(assign);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(90, 170, 221, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        endtime = new QLineEdit(horizontalLayoutWidget_4);
        endtime->setObjectName(QStringLiteral("endtime"));

        horizontalLayout_4->addWidget(endtime);

        horizontalLayoutWidget_5 = new QWidget(assign);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(90, 210, 221, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        cardnum = new QLineEdit(horizontalLayoutWidget_5);
        cardnum->setObjectName(QStringLiteral("cardnum"));

        horizontalLayout_5->addWidget(cardnum);

        cash = new QCheckBox(horizontalLayoutWidget_5);
        cash->setObjectName(QStringLiteral("cash"));

        horizontalLayout_5->addWidget(cash);


        retranslateUi(assign);
        QObject::connect(buttonBox, SIGNAL(accepted()), assign, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), assign, SLOT(reject()));

        QMetaObject::connectSlotsByName(assign);
    } // setupUi

    void retranslateUi(QDialog *assign)
    {
        assign->setWindowTitle(QApplication::translate("assign", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("assign", "\347\224\265\350\204\221\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("assign", "\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("assign", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("assign", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("assign", "\345\215\241\345\217\267\357\274\232    ", Q_NULLPTR));
        cash->setText(QApplication::translate("assign", "\347\216\260\351\207\221\346\224\257\344\273\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class assign: public Ui_assign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGN_H
