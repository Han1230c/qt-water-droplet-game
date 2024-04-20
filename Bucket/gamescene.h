#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "bucket.h"
#include "droplet.h"
#include "cloud.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameScene();
    ~GameScene();

private:
    Bucket *bucketItem;
    QTimer *dropletTimer;

private slots:
    void createDroplet();
};

#endif // GAMESCENE_H
