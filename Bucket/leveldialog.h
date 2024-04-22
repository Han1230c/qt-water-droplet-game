#ifndef LEVELDIALOG_H
#define LEVELDIALOG_H

#include <QDialog>

namespace Ui {
class level;
}

class LevelDialog : public QDialog
{
    Q_OBJECT
public:
    LevelDialog(QWidget *parent = nullptr);

private slots:
    void easyButtonClicked();
    void mediumButtonClicked();
    void hardClicked();

private:
    Ui::level *ui;
};

#endif // LEVELDIALOG_H
