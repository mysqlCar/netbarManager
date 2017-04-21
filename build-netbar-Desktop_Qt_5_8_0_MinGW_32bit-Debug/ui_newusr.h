/********************************************************************************
** Form generated from reading UI file 'newusr.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSR_H
#define UI_NEWUSR_H

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

class Ui_newusr
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *id;

    void setupUi(QDialog *newusr)
    {
        if (newusr->objectName().isEmpty())
            newusr->setObjectName(QStringLiteral("newusr"));
        newusr->resize(381, 176);
        newusr->setMinimumSize(QSize(381, 176));
        newusr->setMaximumSize(QSize(381, 176));
        buttonBox = new QDialogButtonBox(newusr);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-10, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(newusr);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 30, 160, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        name = new QLineEdit(horizontalLayoutWidget);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

        horizontalLayoutWidget_2 = new QWidget(newusr);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 70, 231, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        id = new QLineEdit(horizontalLayoutWidget_2);
        id->setObjectName(QStringLiteral("id"));

        horizontalLayout_2->addWidget(id);


        retranslateUi(newusr);
        QObject::connect(buttonBox, SIGNAL(accepted()), newusr, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newusr, SLOT(reject()));

        QMetaObject::connectSlotsByName(newusr);
    } // setupUi

    void retranslateUi(QDialog *newusr)
    {
        newusr->setWindowTitle(QApplication::translate("newusr", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("newusr", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\247\223\345\220\215  </span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("newusr", "<html><head/><body><p>\350\272\253\344\273\275\350\257\201\345\217\267</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newusr: public Ui_newusr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSR_H
