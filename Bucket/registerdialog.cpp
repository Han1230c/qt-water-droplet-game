#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QRegularExpression>
#include <QCryptographicHash>
#include "user.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    connect(ui->togglePasswordVisibilityButton, &QPushButton::clicked, this, &RegisterDialog::togglePasswordVisibility);
}

void RegisterDialog::togglePasswordVisibility()
{
    bool isPasswordVisible = ui->passwordLineEdit->echoMode() == QLineEdit::Normal;
    QLineEdit::EchoMode newEchoMode = isPasswordVisible ? QLineEdit::Password : QLineEdit::Normal;
    QString buttonText = isPasswordVisible ? "Show" : "Hide";

    ui->passwordLineEdit->setEchoMode(newEchoMode);
    ui->passwordConfirmLineEdit->setEchoMode(newEchoMode);
    ui->togglePasswordVisibilityButton->setText(buttonText);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButtonUpload_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp *.jpeg)");
    if (!filePath.isEmpty()) {
        m_filePath = filePath;
        QPixmap pixmap(filePath);
        ui->labelPhotoDisplay->setPixmap(pixmap.scaled(ui->labelPhotoDisplay->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void RegisterDialog::on_okButton_accepted()
{
    if (validateInput() && saveUsersData()) {
        QMessageBox::information(this, "Registration Successful", "You have successfully registered.");
        accept();
    }
}

bool RegisterDialog::validateInput()
{
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->passwordConfirmLineEdit->text();
    QRegularExpression passwordRegex("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z]).{8,}$");

    if (firstName.isEmpty() || lastName.isEmpty() || username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Please fill in all fields.");
        return false;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Registration", "Passwords do not match.");
        return false;
    }

    if (!passwordRegex.match(password).hasMatch()) {
        QMessageBox::warning(this, "Registration", "Password must be at least 8 characters and include numbers, uppercase and lowercase letters.");
        return false;
    }

    return true;
}

bool RegisterDialog::saveUsersData()
{

    QDir currentDir = QDir::current();
    QString basePath = QCoreApplication::applicationDirPath();
    basePath = QDir(basePath).absoluteFilePath("../../../../../");
    QDir dataDir(basePath + "/Data");



    if (!dataDir.exists()) {
        bool dirCreated = currentDir.mkdir("Data");
        qDebug() << "Data directory created:" << dirCreated;
        if (!dirCreated) {
            QMessageBox::critical(this, "Registration Error", "Unable to create data directory.");
            return false;
        }
    }

    QString filePath = dataDir.filePath("users.json");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        return false;
    }
    qDebug() << "Users file path:" << filePath;

    QList<User> users = User::loadUsersFromFile(filePath);
    qDebug() << "Loaded users count:" << users.count();

    for (const User &user : users) {
        if (user.username().compare(ui->usernameLineEdit->text(), Qt::CaseInsensitive) == 0) {
            QMessageBox::warning(this, "Registration", "Username already exists.");
            return false;
        }
    }

    User newUser(ui->firstNameLineEdit->text(), ui->lastNameLineEdit->text(), ui->usernameLineEdit->text(),
                 ui->passwordLineEdit->text(), ui->comboBoxGender->currentText(), ui->dateEdit->date(), m_filePath);
    users.append(newUser);

    bool saveResult = User::saveUsersToFile(filePath, users);
    qDebug() << "Data saved successfully:" << saveResult;

    return saveResult;
}
