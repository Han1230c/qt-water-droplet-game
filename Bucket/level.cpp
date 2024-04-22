#include "level.h"
#include "ui_leveldialog.h"

Level::Level(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Level)
{
    ui->setupUi(this);
    this->easyBtm = ui -> easyBtm;
    this->mediumBtm = ui -> mediumBtm;
    this->hardBtm = ui -> hardBtm;

    bool clickedEasy = QObject::connect(easyBtm,&QToolButton::clicked, this, &Level::setEasyScene);
    bool clickedMedium = QObject::connect(mediumBtm,&QToolButton::clicked, this, &::Level::setMediumScene);
    bool clickedHard = QObject::connect(hardBtm,&QToolButton::clicked, this, &Level::setHardScene);


}

Level::~Level()
{
    delete ui;
}

void Level::setEasyScene(){
    leveloption = 0;
    this->hide();
}

void Level::setMediumScene(){
    leveloption = 1;
    this->hide();
}

void Level::setHardScene(){
    leveloption = 2;
    this->hide();
}









