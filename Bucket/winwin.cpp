#include "winwin.h"
#include "ui_winwin.h"

winWin::winWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winWin)
{
    ui->setupUi(this);
}

winWin::~winWin()
{
    delete ui;
}

void winWin::createWinWindow(){
    // emit saveHistScoreSign();
    this->exec();
}

// void winWin::saveHistScoreSign(){

// }


