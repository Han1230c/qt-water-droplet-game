/********************************************************************************
** Form generated from reading UI file 'gameOverWin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWIN_H
#define UI_GAMEOVERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *labelTitle;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 200, 100, 32));
        QFont font;
        font.setPointSize(13);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 200, 100, 32));
        pushButton_2->setFont(font);
        labelTitle = new QLabel(Dialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(90, 90, 231, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font1.setPointSize(42);
        labelTitle->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Play Again", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Leave", nullptr));
        labelTitle->setText(QCoreApplication::translate("Dialog", "Game Over", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWIN_H
