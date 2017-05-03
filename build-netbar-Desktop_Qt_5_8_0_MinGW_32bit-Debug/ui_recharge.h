/********************************************************************************
** Form generated from reading UI file 'recharge.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHARGE_H
#define UI_RECHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recharge
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *cardNumber;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *money;

    void setupUi(QDialog *recharge)
    {
        if (recharge->objectName().isEmpty())
            recharge->setObjectName(QStringLiteral("recharge"));
        recharge->resize(400, 207);
        buttonBox = new QDialogButtonBox(recharge);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(recharge);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 30, 211, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cardNumber = new QLineEdit(horizontalLayoutWidget);
        cardNumber->setObjectName(QStringLiteral("cardNumber"));

        horizontalLayout->addWidget(cardNumber);

        horizontalLayoutWidget_2 = new QWidget(recharge);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 80, 211, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        money = new QLineEdit(horizontalLayoutWidget_2);
        money->setObjectName(QStringLiteral("money"));

        horizontalLayout_2->addWidget(money);


        retranslateUi(recharge);
        QObject::connect(buttonBox, SIGNAL(accepted()), recharge, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), recharge, SLOT(reject()));

        QMetaObject::connectSlotsByName(recharge);
    } // setupUi

    void retranslateUi(QDialog *recharge)
    {
        recharge->setWindowTitle(QApplication::translate("recharge", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("recharge", "\345\215\241\345\217\267    ", Q_NULLPTR));
        label_2->setText(QApplication::translate("recharge", "\345\205\205\345\200\274\351\207\221\351\242\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class recharge: public Ui_recharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHARGE_H
