/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QDialogButtonBox *okButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *lastNameLineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEditUsername;
    QLineEdit *passwordConfirmLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *firstNameLineEdit;
    QPushButton *pushButtonUpload;
    QComboBox *comboBoxGender;
    QLabel *labelPhotoDisplay;
    QDateEdit *dateEdit;
    QPushButton *togglePasswordVisibilityButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(403, 682);
        okButton = new QDialogButtonBox(RegisterDialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(90, 630, 181, 32));
        okButton->setContextMenuPolicy(Qt::CustomContextMenu);
        okButton->setOrientation(Qt::Horizontal);
        okButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RegisterDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 10, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 60, 71, 20));
        lastNameLineEdit = new QLabel(RegisterDialog);
        lastNameLineEdit->setObjectName("lastNameLineEdit");
        lastNameLineEdit->setGeometry(QRect(60, 120, 71, 20));
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 300, 81, 21));
        label_5 = new QLabel(RegisterDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 240, 51, 20));
        label_6 = new QLabel(RegisterDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 490, 91, 20));
        label_7 = new QLabel(RegisterDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 180, 71, 20));
        label_8 = new QLabel(RegisterDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 370, 58, 16));
        label_9 = new QLabel(RegisterDialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 430, 111, 16));
        lineEditUsername = new QLineEdit(RegisterDialog);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(60, 150, 201, 21));
        passwordConfirmLineEdit = new QLineEdit(RegisterDialog);
        passwordConfirmLineEdit->setObjectName("passwordConfirmLineEdit");
        passwordConfirmLineEdit->setGeometry(QRect(60, 460, 141, 21));
        passwordConfirmLineEdit->setEchoMode(QLineEdit::Password);
        passwordLineEdit = new QLineEdit(RegisterDialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(60, 400, 141, 21));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        usernameLineEdit = new QLineEdit(RegisterDialog);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(60, 210, 191, 21));
        firstNameLineEdit = new QLineEdit(RegisterDialog);
        firstNameLineEdit->setObjectName("firstNameLineEdit");
        firstNameLineEdit->setGeometry(QRect(60, 90, 201, 21));
        pushButtonUpload = new QPushButton(RegisterDialog);
        pushButtonUpload->setObjectName("pushButtonUpload");
        pushButtonUpload->setGeometry(QRect(60, 510, 100, 31));
        comboBoxGender = new QComboBox(RegisterDialog);
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->setObjectName("comboBoxGender");
        comboBoxGender->setGeometry(QRect(50, 270, 101, 21));
        labelPhotoDisplay = new QLabel(RegisterDialog);
        labelPhotoDisplay->setObjectName("labelPhotoDisplay");
        labelPhotoDisplay->setGeometry(QRect(180, 490, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPhotoDisplay->sizePolicy().hasHeightForWidth());
        labelPhotoDisplay->setSizePolicy(sizePolicy);
        labelPhotoDisplay->setMinimumSize(QSize(100, 100));
        labelPhotoDisplay->setAlignment(Qt::AlignCenter);
        dateEdit = new QDateEdit(RegisterDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(50, 330, 111, 31));
        dateEdit->setMinimumDate(QDate(1900, 1, 1));
        dateEdit->setCalendarPopup(true);
        togglePasswordVisibilityButton = new QPushButton(RegisterDialog);
        togglePasswordVisibilityButton->setObjectName("togglePasswordVisibilityButton");
        togglePasswordVisibilityButton->setGeometry(QRect(210, 391, 61, 41));

        retranslateUi(RegisterDialog);
        QObject::connect(okButton, &QDialogButtonBox::accepted, RegisterDialog, qOverload<>(&QDialog::accept));
        QObject::connect(okButton, &QDialogButtonBox::rejected, RegisterDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterDialog", "Create Account", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterDialog", "First Name", nullptr));
        lastNameLineEdit->setText(QCoreApplication::translate("RegisterDialog", "Last Name", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterDialog", "Date of Birth ", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterDialog", "Gender", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterDialog", "Profile Picture", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterDialog", "Username", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterDialog", "Password", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterDialog", "Confirm Password", nullptr));
        pushButtonUpload->setText(QCoreApplication::translate("RegisterDialog", "Upload", nullptr));
        comboBoxGender->setItemText(0, QCoreApplication::translate("RegisterDialog", "Choose", nullptr));
        comboBoxGender->setItemText(1, QCoreApplication::translate("RegisterDialog", "Male", nullptr));
        comboBoxGender->setItemText(2, QCoreApplication::translate("RegisterDialog", "Female", nullptr));

        labelPhotoDisplay->setText(QCoreApplication::translate("RegisterDialog", "Photo", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("RegisterDialog", "MM/dd/yyyy", nullptr));
        togglePasswordVisibilityButton->setText(QCoreApplication::translate("RegisterDialog", "Show ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
