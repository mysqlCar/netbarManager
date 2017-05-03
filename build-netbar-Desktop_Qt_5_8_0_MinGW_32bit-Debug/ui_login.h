/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *usr;
    QLineEdit *pswd;
    QPushButton *login_2;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(423, 215);
        label_username = new QLabel(login);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(90, 50, 71, 21));
        label_password = new QLabel(login);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(90, 90, 54, 21));
        usr = new QLineEdit(login);
        usr->setObjectName(QStringLiteral("usr"));
        usr->setGeometry(QRect(160, 50, 113, 20));
        pswd = new QLineEdit(login);
        pswd->setObjectName(QStringLiteral("pswd"));
        pswd->setGeometry(QRect(160, 90, 113, 20));
        login_2 = new QPushButton(login);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(240, 140, 75, 23));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", Q_NULLPTR));
        label_username->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_password->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", Q_NULLPTR));
        login_2->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
