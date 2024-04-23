/********************************************************************************
** Form generated from reading UI file 'winwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINWIN_H
#define UI_WINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_winWin
{
public:
    QLabel *labelTitle;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *winWin)
    {
        if (winWin->objectName().isEmpty())
            winWin->setObjectName("winWin");
        winWin->resize(400, 300);
        labelTitle = new QLabel(winWin);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(100, 50, 231, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(42);
        labelTitle->setFont(font);
        textEdit = new QTextEdit(winWin);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(100, 110, 181, 31));
        textEdit_2 = new QTextEdit(winWin);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(100, 160, 181, 31));
        pushButton = new QPushButton(winWin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 220, 100, 32));
        pushButton_2 = new QPushButton(winWin);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 220, 100, 32));

        retranslateUi(winWin);

        QMetaObject::connectSlotsByName(winWin);
    } // setupUi

    void retranslateUi(QDialog *winWin)
    {
        winWin->setWindowTitle(QCoreApplication::translate("winWin", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("winWin", "You Win!", nullptr));
        textEdit->setHtml(QCoreApplication::translate("winWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Your point: </p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("winWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">History point: </p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("winWin", "Play Again", nullptr));
        pushButton_2->setText(QCoreApplication::translate("winWin", "Leave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winWin: public Ui_winWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINWIN_H
