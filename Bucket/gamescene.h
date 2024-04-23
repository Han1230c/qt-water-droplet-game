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
    int getLevelIndex() const;
    void saveUserScore(int score);

private slots:
    void createDroplet();

private:
    QTimer* dropletTimer;
    Cloud* cloud;
    Bucket* bucketItem;
    Pocket* pocket;
    ScoreBoard* scoreBoard;
    Miss* miss;
    int levelIndex;
    User* currentUser;
};

#endif // GAMESCENE_H
