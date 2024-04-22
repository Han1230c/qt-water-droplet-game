#ifndef WINWIN_H
#define WINWIN_H

#include <QDialog>

namespace Ui {
class winWin;
}

class winWin : public QDialog
{
    Q_OBJECT

public:
    explicit winWin(QWidget *parent = nullptr);
    ~winWin();

public slots:
    void createWinWindow();
// public: signals:
//     void saveHistScoreSign();
private:
    Ui::winWin *ui;
};

#endif // WINWIN_H
