#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <QDir>
#include <QMessageBox>
#include "bucket.h"
#include "droplet.h"
#include "cloud.h"
#include "scoreboard.h"
#include "pocket.h"
#include "miss.h"
#include "winwin.h"
#include "losewin.h"
#include "user.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameScene(int leveloption, User* currentUser);
    ~GameScene();
    QList<qreal>* easyLevel = new QList<qreal> {1,2,4,6,8};
    QList<qreal>* mediumLevel = new QList<qreal> {2,4,6,8,10};
    QList<qreal>* hardLevel = new QList<qreal> {4,6,8,10,12};
    // bool gameOver();

    int getLevelIndex() const;

private:
    Cloud *cloud;
    Bucket *bucketItem;
    QTimer *dropletTimer;
    ScoreBoard* scoreBoard;
    Pocket* pocket;
    Miss* miss;
    int levelIndex; // default
    User* currentUser;

private slots:
    void createDroplet();


};

#endif // GAMESCENE_H
