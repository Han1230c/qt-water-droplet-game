#include "logindialog.h"
#include "registerdialog.h"
#include "gamescene.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog login; // 实例化登录对话框
    RegisterDialog registerDialog; // 实例化注册对话框

    // 连接注册按钮点击信号到显示注册对话框的槽
    QObject::connect(&login, &LoginDialog::registerButtonClicked, [&](){
        registerDialog.exec();
    });

    // 显示登录对话框并等待用户登录
    if (login.exec() == QDialog::Accepted)
    {
        GameScene *scene = new GameScene(); // 创建游戏场景对象
        QGraphicsView *view = new QGraphicsView(scene); // 创建视图对象用于显示游戏场景
        view->setFixedSize(910, 512); // 设置视图大小
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 关闭水平滚动条
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 关闭垂直滚动条
        view->show(); // 显示游戏界面

        return a.exec(); // 开始事件循环
    }

    return 0; // 如果用户取消登录，则退出程序
}
