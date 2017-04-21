/********************************************************************************
** Form generated from reading UI file 'repair.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPAIR_H
#define UI_REPAIR_H

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

class Ui_repair
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *comNumber;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *errNum;

    void setupUi(QDialog *repair)
    {
        if (repair->objectName().isEmpty())
            repair->setObjectName(QStringLiteral("repair"));
        repair->resize(400, 185);
        buttonBox = new QDialogButtonBox(repair);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(repair);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 20, 241, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comNumber = new QLineEdit(horizontalLayoutWidget);
        comNumber->setObjectName(QStringLiteral("comNumber"));

        horizontalLayout->addWidget(comNumber);

        horizontalLayoutWidget_2 = new QWidget(repair);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 70, 241, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        errNum = new QLineEdit(horizontalLayoutWidget_2);
        errNum->setObjectName(QStringLiteral("errNum"));

        horizontalLayout_2->addWidget(errNum);


        retranslateUi(repair);
        QObject::connect(buttonBox, SIGNAL(accepted()), repair, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), repair, SLOT(reject()));

        QMetaObject::connectSlotsByName(repair);
    } // setupUi

    void retranslateUi(QDialog *repair)
    {
        repair->setWindowTitle(QApplication::translate("repair", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("repair", "\346\225\205\351\232\234\347\224\265\350\204\221\347\274\226\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("repair", "\346\225\205\351\232\234\345\216\237\345\233\240    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class repair: public Ui_repair {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPAIR_H
