/********************************************************************************
** Form generated from reading UI file 'userinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFODIALOG_H
#define UI_USERINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_UserInfoDialog
{
public:
    QLabel *labelTitle;
    QLabel *labelAvatar;
    QLabel *labelName;
    QLabel *labelBirthday;
    QLineEdit *lineEditName;
    QLineEdit *lineEditBirthday;
    QLabel *labelCurrentDate;
    QTextEdit *textEditBirthdayGreeting;

    void setupUi(QDialog *UserInfoDialog)
    {
        if (UserInfoDialog->objectName().isEmpty())
            UserInfoDialog->setObjectName("UserInfoDialog");
        UserInfoDialog->resize(417, 544);
        labelTitle = new QLabel(UserInfoDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(120, 10, 174, 29));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(24);
        labelTitle->setFont(font);
        labelAvatar = new QLabel(UserInfoDialog);
        labelAvatar->setObjectName("labelAvatar");
        labelAvatar->setEnabled(true);
        labelAvatar->setGeometry(QRect(120, 50, 161, 141));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy);
        labelAvatar->setMinimumSize(QSize(100, 100));
        labelAvatar->setPixmap(QPixmap(QString::fromUtf8(":/images/Subject 2.png")));
        labelAvatar->setScaledContents(true);
        labelName = new QLabel(UserInfoDialog);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(110, 220, 35, 16));
        labelBirthday = new QLabel(UserInfoDialog);
        labelBirthday->setObjectName("labelBirthday");
        labelBirthday->setGeometry(QRect(110, 270, 51, 16));
        lineEditName = new QLineEdit(UserInfoDialog);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(170, 220, 125, 21));
        lineEditName->setReadOnly(true);
        lineEditBirthday = new QLineEdit(UserInfoDialog);
        lineEditBirthday->setObjectName("lineEditBirthday");
        lineEditBirthday->setGeometry(QRect(170, 270, 125, 21));
        lineEditBirthday->setReadOnly(true);
        labelCurrentDate = new QLabel(UserInfoDialog);
        labelCurrentDate->setObjectName("labelCurrentDate");
        labelCurrentDate->setGeometry(QRect(130, 490, 141, 31));
        sizePolicy.setHeightForWidth(labelCurrentDate->sizePolicy().hasHeightForWidth());
        labelCurrentDate->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font1.setPointSize(18);
        labelCurrentDate->setFont(font1);
        labelCurrentDate->setScaledContents(true);
        labelCurrentDate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textEditBirthdayGreeting = new QTextEdit(UserInfoDialog);
        textEditBirthdayGreeting->setObjectName("textEditBirthdayGreeting");
        textEditBirthdayGreeting->setGeometry(QRect(100, 350, 201, 91));
        textEditBirthdayGreeting->setMinimumSize(QSize(80, 0));
        textEditBirthdayGreeting->setReadOnly(true);

        retranslateUi(UserInfoDialog);

        QMetaObject::connectSlotsByName(UserInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *UserInfoDialog)
    {
        UserInfoDialog->setWindowTitle(QCoreApplication::translate("UserInfoDialog", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("UserInfoDialog", "User Information", nullptr));
        labelAvatar->setText(QString());
        labelName->setText(QCoreApplication::translate("UserInfoDialog", "Name", nullptr));
        labelBirthday->setText(QCoreApplication::translate("UserInfoDialog", "Birthday", nullptr));
        labelCurrentDate->setText(QCoreApplication::translate("UserInfoDialog", "<p align='right'>May 26, 2023</p", nullptr));
        textEditBirthdayGreeting->setHtml(QCoreApplication::translate("UserInfoDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEditBirthdayGreeting->setPlaceholderText(QCoreApplication::translate("UserInfoDialog", "Happy birthday to xx!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoDialog: public Ui_UserInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFODIALOG_H
