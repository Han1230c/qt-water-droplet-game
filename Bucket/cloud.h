#ifndef CLOUD_H
#define CLOUD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Cloud : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Cloud();
    ~Cloud();

public slots:
    void move();

private:
    QTimer *timer;
    int direction;
};

#endif // CLOUD_H
