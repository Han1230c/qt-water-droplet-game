#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void togglePasswordVisibility();
    void on_pushButtonUpload_clicked();
    void on_okButton_accepted();

private:
    Ui::RegisterDialog *ui;
    QString m_filePath;
    bool validateInput();
    bool saveUsersData();
};

#endif // REGISTERDIALOG_H
