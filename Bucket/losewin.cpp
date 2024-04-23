#include "losewin.h"
#include "ui_losewin.h"

loseWin::loseWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loseWin)
{
    ui->setupUi(this);
}

loseWin::~loseWin()
{
    delete ui;
}

void loseWin::createLoseWindow(){
    this->exec();
}

