#include "gamescene.h"
#include "cloud.h"
#include <QRandomGenerator>

GameScene::GameScene()
{
    setSceneRect(0, 0, 908, 510);
    setBackgroundBrush(QBrush(QImage(":/images/back.JPG").scaled(908, 510)));

    bucketItem = new Bucket();
    bucketItem->setPos(400, 365);
    addItem(bucketItem);

    dropletTimer = new QTimer(this);
    connect(dropletTimer, &QTimer::timeout, this, &GameScene::createDroplet);
    dropletTimer->start(1000);

    Cloud *cloud = new Cloud();
    addItem(cloud);
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
        if (Cloud *cloud = qgraphicsitem_cast<Cloud *>(item)) {
            Droplet *droplet = new Droplet(cloud);
            addItem(droplet);
            return;
        }
    }
}
