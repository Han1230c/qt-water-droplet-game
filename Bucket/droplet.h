#ifndef DROPLET_H
#define DROPLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QList>
#include "pocket.h"
#include "miss.h"
#include "scoreboard.h"
#include "bucket.h"
#include "gamescene.h"
#include "user.h"


class Cloud;

class Droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Droplet(Cloud *cloud,Pocket* p,Miss* miss, ScoreBoard* scoreB, Bucket* bucket, QList<qreal>* speedLevel, User* currentUser);
    ~Droplet();

public slots:
    void move();

signals:
    void winSignal(int point);
    void loseSignal(int);

private:
    QTimer *timer;
    Pocket* pocket;
    Miss* miss;
    ScoreBoard* score;
    Bucket* bucket;
    QList<qreal>* speedLevel;
    User* user;
};

#endif // DROPLET_H
