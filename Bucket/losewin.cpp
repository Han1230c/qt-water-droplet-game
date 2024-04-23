#include "losewin.h"
#include "ui_losewin.h"

loseWin::loseWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loseWin)
{
    ui->setupUi(this);
    connect(ui->leaveBtm, &QPushButton::clicked, this, QApplication::quit);
}

loseWin::~loseWin()
{
    delete ui;
}

void loseWin::createLoseWindow(){
    this->exec();
}


void loseWin::on_leaveBtm_clicked()
{

}

