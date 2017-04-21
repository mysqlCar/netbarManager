/********************************************************************************
** Form generated from reading UI file 'cpuinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUINFO_H
#define UI_CPUINFO_H

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

class Ui_cpuinfo
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *model;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *number;

    void setupUi(QDialog *cpuinfo)
    {
        if (cpuinfo->objectName().isEmpty())
            cpuinfo->setObjectName(QStringLiteral("cpuinfo"));
        cpuinfo->resize(400, 170);
        cpuinfo->setMinimumSize(QSize(400, 170));
        cpuinfo->setMaximumSize(QSize(400, 170));
        buttonBox = new QDialogButtonBox(cpuinfo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(cpuinfo);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 30, 171, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        model = new QLineEdit(horizontalLayoutWidget);
        model->setObjectName(QStringLiteral("model"));

        horizontalLayout->addWidget(model);

        horizontalLayoutWidget_2 = new QWidget(cpuinfo);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 70, 171, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        number = new QLineEdit(horizontalLayoutWidget_2);
        number->setObjectName(QStringLiteral("number"));

        horizontalLayout_2->addWidget(number);


        retranslateUi(cpuinfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), cpuinfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cpuinfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(cpuinfo);
    } // setupUi

    void retranslateUi(QDialog *cpuinfo)
    {
        cpuinfo->setWindowTitle(QApplication::translate("cpuinfo", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("cpuinfo", "\345\236\213\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("cpuinfo", "\347\274\226\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cpuinfo: public Ui_cpuinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUINFO_H
