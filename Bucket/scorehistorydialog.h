#ifndef SCOREHISTORYDIALOG_H
#define SCOREHISTORYDIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class ScoreHistoryDialog;
}

class ScoreHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreHistoryDialog(const User &user, QWidget *parent = nullptr);
    ~ScoreHistoryDialog();

private:
    Ui::ScoreHistoryDialog *ui;
    void loadScoreHistory(const User &user);
    int getGlobalBestScore();
};

#endif // SCOREHISTORYDIALOG_H
