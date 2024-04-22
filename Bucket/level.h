#ifndef LEVEL_H
#define LEVEL_H

#include "QtWidgets/qlineedit.h"
#include <QDialog>
#include <QMessageBox>
#include <QDir>


namespace Ui {
class Level;
}

class Level : public QDialog
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    QToolButton* easyBtm;
    QToolButton* mediumBtm;
    QToolButton* hardBtm;
    int leveloption;
    void setEasyScene();
    void setMediumScene();
    void setHardScene();

private:
    Ui::Level *ui;

};

#endif // LEVEL_H
