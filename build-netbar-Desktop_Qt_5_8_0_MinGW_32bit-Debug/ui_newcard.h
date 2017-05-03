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
#include <QtWidgets/QPushButton>
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
    QPushButton *checkName;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *cardNumber;
    QPushButton *checkNumber;

    void setupUi(QDialog *newcard)
    {
        if (newcard->objectName().isEmpty())
            newcard->setObjectName(QStringLiteral("newcard"));
        newcard->resize(350, 243);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newcard->sizePolicy().hasHeightForWidth());
        newcard->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(newcard);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-10, 180, 341, 32));
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
        horizontalLayoutWidget_3->setGeometry(QRect(70, 130, 171, 22));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        charge = new QLineEdit(horizontalLayoutWidget_3);
        charge->setObjectName(QStringLiteral("charge"));

        horizontalLayout_3->addWidget(charge);

        checkName = new QPushButton(newcard);
        checkName->setObjectName(QStringLiteral("checkName"));
        checkName->setGeometry(QRect(250, 40, 75, 23));
        horizontalLayoutWidget_4 = new QWidget(newcard);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(70, 100, 171, 22));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        cardNumber = new QLineEdit(horizontalLayoutWidget_4);
        cardNumber->setObjectName(QStringLiteral("cardNumber"));

        horizontalLayout_4->addWidget(cardNumber);

        checkNumber = new QPushButton(newcard);
        checkNumber->setObjectName(QStringLiteral("checkNumber"));
        checkNumber->setGeometry(QRect(250, 100, 75, 23));

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
        checkName->setText(QApplication::translate("newcard", "\346\243\200\346\237\245", Q_NULLPTR));
        label_6->setText(QApplication::translate("newcard", "\345\215\241\345\217\267    \357\274\232", Q_NULLPTR));
        checkNumber->setText(QApplication::translate("newcard", "\346\243\200\346\237\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newcard: public Ui_newcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCARD_H
