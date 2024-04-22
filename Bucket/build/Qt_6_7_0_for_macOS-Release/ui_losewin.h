/********************************************************************************
** Form generated from reading UI file 'losewin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSEWIN_H
#define UI_LOSEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loseWin
{
public:
    QLabel *labelTitle;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *loseWin)
    {
        if (loseWin->objectName().isEmpty())
            loseWin->setObjectName("loseWin");
        loseWin->resize(400, 300);
        labelTitle = new QLabel(loseWin);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(80, 80, 231, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(42);
        labelTitle->setFont(font);
        pushButton = new QPushButton(loseWin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 180, 100, 32));
        QFont font1;
        font1.setPointSize(13);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(loseWin);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 180, 100, 32));
        pushButton_2->setFont(font1);

        retranslateUi(loseWin);

        QMetaObject::connectSlotsByName(loseWin);
    } // setupUi

    void retranslateUi(QDialog *loseWin)
    {
        loseWin->setWindowTitle(QCoreApplication::translate("loseWin", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("loseWin", "Game Over", nullptr));
        pushButton->setText(QCoreApplication::translate("loseWin", "Play Again", nullptr));
        pushButton_2->setText(QCoreApplication::translate("loseWin", "Leave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loseWin: public Ui_loseWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSEWIN_H
