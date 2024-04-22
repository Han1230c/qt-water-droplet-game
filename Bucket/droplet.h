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
#include "GameScene.h"



class Cloud;

class Droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Droplet(Cloud *cloud,Pocket* p,Miss* miss, ScoreBoard* scoreB, Bucket* bucket, QList<qreal>* speedLevel);
    ~Droplet();

public slots:
    void move();

signals:
    void winSignal(int);
    void loseSignal(int);

private:
    QTimer *timer;
    Pocket* pocket;
    Miss* miss;
    ScoreBoard* score;
    Bucket* bucket;
    QList<qreal>* speedLevel;
};

#endif // DROPLET_H
