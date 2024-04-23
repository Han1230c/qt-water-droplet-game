#include "gamescene.h"
#include "cloud.h"
#include <QRandomGenerator>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

QList<qreal>* easyLevel = new QList<qreal>{1.0, 2.0, 3.0};
QList<qreal>* mediumLevel = new QList<qreal>{4.0, 5.0, 6.0};
QList<qreal>* hardLevel = new QList<qreal>{7.0, 8.0, 9.0};

GameScene::GameScene(int leveloption, User* currentUser)
{
    levelIndex = leveloption;

    this->currentUser = currentUser;

    setSceneRect(0, 0, 908, 510);
    setBackgroundBrush(QBrush(QImage(":/images/back.JPG").scaled(908, 510)));

    bucketItem = new Bucket();
    bucketItem->setPos(400, 365);
    addItem(bucketItem);

    pocket = new Pocket();
    pocket->setPos(5,85);
    addItem(pocket);

    scoreBoard = new ScoreBoard();
    scoreBoard->setPos(5,65);
    addItem(scoreBoard);

    miss = new Miss();
    miss ->setPos(5, 105);
    addItem(miss);

    cloud = new Cloud();
    addItem(cloud);

    dropletTimer = new QTimer(this);
    connect(dropletTimer, &QTimer::timeout, this, &GameScene::createDroplet);
    dropletTimer->start(5000);
}

GameScene::~GameScene()
{
    delete dropletTimer;
    delete bucketItem;
}

void GameScene::createDroplet()
{
    QList<QGraphicsItem *> items = this->items();
    foreach (QGraphicsItem *item, items) {
        if (cloud == qgraphicsitem_cast<Cloud *>(item)) {
            winWin* winWindow = new winWin();
            loseWin* loseWindow = new loseWin();

            if(levelIndex==0){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, easyLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
                connect(droplet, &Droplet::winSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
                connect(droplet, &Droplet::loseSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
            }
            else if(levelIndex==1){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, mediumLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
                connect(droplet, &Droplet::winSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
                connect(droplet, &Droplet::loseSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
            }
            else if(levelIndex==2){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, hardLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
                connect(droplet, &Droplet::winSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
                connect(droplet, &Droplet::loseSignal, this, [this]() { saveUserScore(scoreBoard->getScore()); });
            }

            return;
        }
    }
}

int GameScene::getLevelIndex() const
{
    return levelIndex;
}

void GameScene::saveUserScore(int score)
{
    currentUser->updateScoreHistory(score);

    QString basePath = QCoreApplication::applicationDirPath();
    basePath = QDir(basePath).absoluteFilePath("../../../../../");
    QDir dataDir(basePath + "/Data");
    QString filePath = dataDir.absoluteFilePath("users.json");

    QList<User> users = User::loadUsersFromFile(filePath);
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].username() == currentUser->username()) {
            users[i] = *currentUser;
            break;
        }
    }

    User::saveUsersToFile(filePath, users);
}

