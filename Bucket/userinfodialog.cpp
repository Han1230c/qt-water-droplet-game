#include "userinfodialog.h"
#include "ui_userinfodialog.h"
#include <QDate>
#include "scorehistorydialog.h"

UserInfoDialog::UserInfoDialog(const User &user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfoDialog),
    currentUser(user)
{
    ui->setupUi(this);
    ui->lineEditName->setText(user.username());
    ui->lineEditBirthday->setText(user.birthday().toString("yyyy-MM-dd"));
    ui->labelAvatar->setPixmap(QPixmap(user.profilePhoto()));
    ui->labelCurrentDate->setText(QDate::currentDate().toString("MMMM d, yyyy"));
    updateBirthdayGreeting(user);
}

UserInfoDialog::~UserInfoDialog()
{
    delete ui;
}

void UserInfoDialog::updateBirthdayGreeting(const User &user)
{
    if (user.birthday().month() == QDate::currentDate().month() &&
        user.birthday().day() == QDate::currentDate().day()) {
        ui->textEditBirthdayGreeting->setVisible(true);
        ui->textEditBirthdayGreeting->setPlainText("Happy birthday, " + user.firstName() + "!");
    } else {
        ui->textEditBirthdayGreeting->setVisible(false);
    }
}

void UserInfoDialog::on_pushButton_clicked()
{
    ScoreHistoryDialog dialog(currentUser, this);
    dialog.exec();
}
