#include "QtWidgets/qpushbutton.h"
#include "logindialog.h"
#include "registerdialog.h"
#include "gamescene.h"
#include "userinfodialog.h"
#include <QApplication>
#include <QGraphicsView>
#include "level.h"
#include "winwin.h"
#include "losewin.h"
#include "scorehistorydialog.h"

void passLevel();


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog login;
    RegisterDialog registerDialog;
    User user;
    QObject::connect(&login, &LoginDialog::registerButtonClicked, [&](){
        registerDialog.exec();
    });

    if (login.exec() == QDialog::Accepted)
    {
        QString username = login.getUsername();
        if (!username.isEmpty()) {
            user = User::findUserByUsername(username);
            UserInfoDialog userInfoDialog(user);
            userInfoDialog.exec();

            ScoreHistoryDialog scoreHistoryDialog(user);
            scoreHistoryDialog.exec();
        }



        Level* levelPage = new Level();
        levelPage->setModal(true);
        levelPage->exec();

        // when player select the level they wants
        GameScene *scene = new GameScene(levelPage->leveloption,&user);

        QTextStream(stdout) << "speedlevel"<<scene->getLevelIndex() << Qt::endl;

        QGraphicsView *view = new QGraphicsView(scene);
        view->setFixedSize(910, 512);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->show();

        return a.exec();
    }

    return 0;
}




