/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QCheckBox *checkBox;
    QPushButton *loginAsGuestButton;
    QLabel *label_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(351, 300);
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 61, 16));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 120, 71, 16));
        usernameLineEdit = new QLineEdit(LoginDialog);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(170, 90, 113, 21));
        passwordLineEdit = new QLineEdit(LoginDialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(170, 120, 113, 21));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(70, 190, 71, 32));
        registerButton = new QPushButton(LoginDialog);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(210, 190, 71, 32));
        checkBox = new QCheckBox(LoginDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(70, 150, 111, 20));
        loginAsGuestButton = new QPushButton(LoginDialog);
        loginAsGuestButton->setObjectName("loginAsGuestButton");
        loginAsGuestButton->setGeometry(QRect(120, 230, 111, 32));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 20, 91, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(36);
        label_3->setFont(font);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginDialog", "Register", nullptr));
        checkBox->setText(QCoreApplication::translate("LoginDialog", "Remember Me", nullptr));
        loginAsGuestButton->setText(QCoreApplication::translate("LoginDialog", "Login as Guest", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
