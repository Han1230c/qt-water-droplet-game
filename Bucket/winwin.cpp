#include "winwin.h"
#include "ui_winwin.h"

winWin::winWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winWin)
{
    ui->setupUi(this);

    connect(ui->leaveBtm, &QPushButton::clicked, this, QApplication::quit);
}

winWin::~winWin()
{
    delete ui;
}

void winWin::createWinWindow(int point){
    // emit saveHistScoreSign();
    this->exec();
}





