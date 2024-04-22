#ifndef LOSEWIN_H
#define LOSEWIN_H

#include <QDialog>

namespace Ui {
class loseWin;
}

class loseWin : public QDialog
{
    Q_OBJECT

public:
    explicit loseWin(QWidget *parent = nullptr);
    ~loseWin();
public slots:
    void createLoseWindow();

private:
    Ui::loseWin *ui;
};

#endif // LOSEWIN_H
