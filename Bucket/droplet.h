#ifndef DROPLET_H
#define DROPLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Cloud;

class Droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Droplet(Cloud *cloud);
    ~Droplet();

public slots:
    void move();

private:
    QTimer *timer;
};

#endif // DROPLET_H
