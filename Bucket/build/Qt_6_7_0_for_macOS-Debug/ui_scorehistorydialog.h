/********************************************************************************
** Form generated from reading UI file 'scorehistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREHISTORYDIALOG_H
#define UI_SCOREHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreHistoryDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QTextEdit *textEditScoreHistory;
    QLabel *labelGlobalBestScore;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScoreHistoryDialog)
    {
        if (ScoreHistoryDialog->objectName().isEmpty())
            ScoreHistoryDialog->setObjectName("ScoreHistoryDialog");
        ScoreHistoryDialog->resize(400, 300);
        verticalLayoutWidget = new QWidget(ScoreHistoryDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(verticalLayoutWidget);
        labelTitle->setObjectName("labelTitle");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        textEditScoreHistory = new QTextEdit(verticalLayoutWidget);
        textEditScoreHistory->setObjectName("textEditScoreHistory");
        textEditScoreHistory->setReadOnly(true);

        verticalLayout->addWidget(textEditScoreHistory);

        labelGlobalBestScore = new QLabel(verticalLayoutWidget);
        labelGlobalBestScore->setObjectName("labelGlobalBestScore");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        labelGlobalBestScore->setFont(font1);

        verticalLayout->addWidget(labelGlobalBestScore);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ScoreHistoryDialog);

        QMetaObject::connectSlotsByName(ScoreHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *ScoreHistoryDialog)
    {
        ScoreHistoryDialog->setWindowTitle(QCoreApplication::translate("ScoreHistoryDialog", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("ScoreHistoryDialog", "Score History", nullptr));
        labelGlobalBestScore->setText(QCoreApplication::translate("ScoreHistoryDialog", "Global Best Score: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreHistoryDialog: public Ui_ScoreHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREHISTORYDIALOG_H
