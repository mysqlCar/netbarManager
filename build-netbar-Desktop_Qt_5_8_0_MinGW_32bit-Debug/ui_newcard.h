/********************************************************************************
** Form generated from reading UI file 'newcard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCARD_H
#define UI_NEWCARD_H

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

class Ui_newcard
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *id;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *name;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *charge;

    void setupUi(QDialog *newcard)
    {
        if (newcard->objectName().isEmpty())
            newcard->setObjectName(QStringLiteral("newcard"));
        newcard->resize(350, 202);
        newcard->setMinimumSize(QSize(350, 202));
        newcard->setMaximumSize(QSize(350, 202));
        buttonBox = new QDialogButtonBox(newcard);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-10, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(newcard);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 40, 171, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        id = new QLineEdit(horizontalLayoutWidget);
        id->setObjectName(QStringLiteral("id"));

        horizontalLayout->addWidget(id);

        horizontalLayoutWidget_2 = new QWidget(newcard);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 70, 171, 22));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        name = new QLineEdit(horizontalLayoutWidget_2);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout_2->addWidget(name);

        horizontalLayoutWidget_3 = new QWidget(newcard);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(70, 100, 171, 22));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        charge = new QLineEdit(horizontalLayoutWidget_3);
        charge->setObjectName(QStringLiteral("charge"));

        horizontalLayout_3->addWidget(charge);


        retranslateUi(newcard);
        QObject::connect(buttonBox, SIGNAL(accepted()), newcard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newcard, SLOT(reject()));

        QMetaObject::connectSlotsByName(newcard);
    } // setupUi

    void retranslateUi(QDialog *newcard)
    {
        newcard->setWindowTitle(QApplication::translate("newcard", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("newcard", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("newcard", "\345\247\223\345\220\215    \357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("newcard", "\351\242\204\345\205\205\345\200\274  \357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newcard: public Ui_newcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCARD_H
