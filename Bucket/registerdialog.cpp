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
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
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
    QList<User> users = User::loadUsersFromFile("users.json");
    for (const User &user : users) {
        if (user.username() == ui->usernameLineEdit->text()) {
            QMessageBox::warning(this, "Registration", "Username already exists.");
            return false;
        }
    }

    User newUser(ui->firstNameLineEdit->text(), ui->lastNameLineEdit->text(), ui->usernameLineEdit->text(),
                 QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha256).toHex(),
                 ui->comboBoxGender->currentText(), ui->dateEdit->date(), m_filePath);
    users.append(newUser);

    QFile file("users.json");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        return false;
    }

    QJsonArray userArray;
    for (const User& user : users) {
        userArray.append(user.toJsonObject());
    }

    QJsonDocument doc(userArray);
    file.write(doc.toJson());
    file.close();
    return true;
}
