#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include "user.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    // Connect the register button signal to the registerButtonClicked signal
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginDialog::registerButtonClicked);
}


LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (User::isValidUser(username, password)) {
        accept();
    } else {
        QMessageBox::warning(this, "Login", "Username or password is incorrect.");
        ui->passwordLineEdit->clear();
    }
}
