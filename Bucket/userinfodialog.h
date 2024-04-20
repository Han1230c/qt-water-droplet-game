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

private:
    Ui::UserInfoDialog *ui;
    void updateBirthdayGreeting(const User &user);
};

#endif // USERINFODIALOG_H
