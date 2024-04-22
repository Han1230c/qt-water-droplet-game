/********************************************************************************
** Form generated from reading UI file 'level.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL_H
#define UI_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Level
{
public:
    QLabel *label;
    QToolButton *easyBtm;
    QToolButton *mediumBtm;
    QToolButton *hardBtm;

    void setupUi(QDialog *Level)
    {
        if (Level->objectName().isEmpty())
            Level->setObjectName("Level");
        Level->resize(400, 300);
        Level->setCursor(QCursor(Qt::ArrowCursor));
        label = new QLabel(Level);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 30, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(36);
        font.setBold(false);
        label->setFont(font);
        label->setCursor(QCursor(Qt::UpArrowCursor));
        label->setAlignment(Qt::AlignCenter);
        easyBtm = new QToolButton(Level);
        easyBtm->setObjectName("easyBtm");
        easyBtm->setGeometry(QRect(140, 100, 100, 32));
        mediumBtm = new QToolButton(Level);
        mediumBtm->setObjectName("mediumBtm");
        mediumBtm->setGeometry(QRect(140, 170, 100, 32));
        hardBtm = new QToolButton(Level);
        hardBtm->setObjectName("hardBtm");
        hardBtm->setGeometry(QRect(140, 240, 100, 32));
        hardBtm->setLayoutDirection(Qt::LeftToRight);
        hardBtm->setAutoFillBackground(false);

        retranslateUi(Level);

        QMetaObject::connectSlotsByName(Level);
    } // setupUi

    void retranslateUi(QDialog *Level)
    {
        Level->setWindowTitle(QCoreApplication::translate("Level", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Level", "Level", nullptr));
        easyBtm->setText(QCoreApplication::translate("Level", "Easy", nullptr));
        mediumBtm->setText(QCoreApplication::translate("Level", "Medium", nullptr));
        hardBtm->setText(QCoreApplication::translate("Level", "Hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Level: public Ui_Level {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL_H
