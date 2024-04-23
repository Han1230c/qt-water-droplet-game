#ifndef USERINFODIALOG_H
#define USERINFODIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class UserInfoDialog;
}

class UserInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfoDialog(const User &user, QWidget *parent = nullptr);
    ~UserInfoDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserInfoDialog *ui;
    User currentUser;
    void updateBirthdayGreeting(const User &user);
};

#endif // USERINFODIALOG_H
