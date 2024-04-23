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

QT_BEGIN_NAMESPACE

class Ui_winWin
{
public:
    QLabel *labelTitle;
    QPushButton *leaveBtm;

    void setupUi(QDialog *winWin)
    {
        if (winWin->objectName().isEmpty())
            winWin->setObjectName("winWin");
        winWin->resize(400, 300);
        labelTitle = new QLabel(winWin);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(110, 90, 231, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(42);
        labelTitle->setFont(font);
        leaveBtm = new QPushButton(winWin);
        leaveBtm->setObjectName("leaveBtm");
        leaveBtm->setGeometry(QRect(150, 170, 100, 32));

        retranslateUi(winWin);

        QMetaObject::connectSlotsByName(winWin);
    } // setupUi

    void retranslateUi(QDialog *winWin)
    {
        winWin->setWindowTitle(QCoreApplication::translate("winWin", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("winWin", "You Win!", nullptr));
        leaveBtm->setText(QCoreApplication::translate("winWin", "Leave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winWin: public Ui_winWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINWIN_H
