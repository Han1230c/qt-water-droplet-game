#include "logindialog.h"
#include "registerdialog.h"
#include "gamescene.h"
#include "userinfodialog.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog login;
    RegisterDialog registerDialog;

    QObject::connect(&login, &LoginDialog::registerButtonClicked, [&](){
        registerDialog.exec();
    });

    if (login.exec() == QDialog::Accepted)
    {
        QString username = login.getUsername();
        if (!username.isEmpty()) {
            User user = User::findUserByUsername(username);
            UserInfoDialog userInfoDialog(user);
            userInfoDialog.exec();
        }


        GameScene *scene = new GameScene();
        QGraphicsView *view = new QGraphicsView(scene);
        view->setFixedSize(910, 512);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->show();

        return a.exec();
    }

    return 0;
}
