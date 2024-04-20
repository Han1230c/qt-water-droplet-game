#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include "user.h"
#include "userinfodialog.h"
#include <QDir>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::on_loginButton_clicked);
    connect(ui->loginAsGuestButton, &QPushButton::clicked, this, &LoginDialog::on_loginAsGuestButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginDialog::registerButtonClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUsername() const
{
    return ui->usernameLineEdit->text();
}

void LoginDialog::on_loginButton_clicked()
{

    QDir currentDir = QDir::current();
    QString basePath = QCoreApplication::applicationDirPath();
    basePath = QDir(basePath).absoluteFilePath("../../../../../");
    QDir dataDir(basePath + "/Data");


    if (!dataDir.exists()) {
        QMessageBox::warning(this, "Login Failed", "Data directory does not exist!");
        return;
    }


    QString filePath = dataDir.filePath("users.json");


    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (User::isRegistered(username, password, filePath)) {
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password!");
    }
}


void LoginDialog::on_loginAsGuestButton_clicked()
{
    accept();
}
