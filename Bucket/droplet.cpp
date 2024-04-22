#include "droplet.h"
#include "cloud.h"
#include <QRandomGenerator>


Droplet::Droplet(Cloud *cloud, Pocket* p,Miss* miss,ScoreBoard* scoreB, Bucket* bucket, QList<qreal>* speedLevel)
{
    this-> pocket = p;
    this->miss = miss;
    this->score = scoreB;
    this->bucket = bucket;
    this->speedLevel = speedLevel;

    setPixmap(QPixmap(":/images/Subject 2.png").scaled(30, 30));

    qreal x = cloud->x() + cloud->boundingRect().width() / 2 - boundingRect().width() / 2;
    qreal y = cloud->y() + cloud->boundingRect().height();
    setPos(x, y);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Droplet::move);
    timer->start(50);
}

Droplet::~Droplet()
{
    delete timer;
}

void Droplet::move()
{
    QMediaPlayer* collectMusic = new QMediaPlayer;
    collectMusic->setAudioOutput(new QAudioOutput);
    QMediaPlayer* missMusic = new QMediaPlayer;
    missMusic->setAudioOutput(new QAudioOutput);
    collectMusic -> setSource(QUrl("qrc:/sound/test.wav"));
    missMusic -> setSource(QUrl("qrc:/sound/fail.wav"));


    setPos(x(), y() + speedLevel->at(0));

    if ( x()>=0 && x() <= 980 && y() > 520) {
        QTextStream(stdout) << "remove a droplet" << Qt::endl;
        scene()->removeItem(this);
        missMusic->play();
        miss->miss();
        if(miss->getMiss()==5){
            emit loseSignal(miss->getMiss());
        }
        deleteLater();
        return;
    }

    if(pocket->getPocket()>5){
        setPos(x(), y() + speedLevel->at(1));
    }
    if(pocket->getPocket()>10){
        setPos(x(), y() + speedLevel->at(2));
    }
    if(pocket->getPocket()>15){
        setPos(x(), y() + speedLevel->at(3));
    }
    if(pocket->getPocket()>15){
        setPos(x(), y() + speedLevel->at(4));
    }

    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);



    if (x()> 0 && x() < 980 && !colliding_items.isEmpty() && collidesWithItem(bucket)) {
        QTextStream(stdout) << "collide a droplet" << Qt::endl;
        scene()->removeItem(this);
        collectMusic->play();
        pocket->increase();
        score->increase();
        QTextStream(stdout) << "increase score" << Qt::endl;

        if(score->getScore()==150){
            emit winSignal(score->getScore());
        }

        deleteLater();
        return;
    }

}




