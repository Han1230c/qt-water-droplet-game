#include "droplet.h"
#include "bucket.h"
#include "cloud.h"
#include <QRandomGenerator>

Droplet::Droplet(Cloud *cloud)
{
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
    setPos(x(), y() + 5);

    if (y() > 520) {
        scene()->removeItem(this);
        deleteLater();
        return;
    }

    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);
    if (!colliding_items.isEmpty() && collidesWithItem(colliding_items.first())) {
        scene()->removeItem(this);
        deleteLater();
        return;
    }
}
