#include "cloud.h"
#include <QRandomGenerator>

Cloud::Cloud()
{
    setPixmap(QPixmap(":/images/Subject 3.png").scaled(100, 50));

    if (QRandomGenerator::global()->bounded(2) == 0) {
        setPos(-200, 20);
        direction = 1;
    } else {
        setPos(908, 50);
        direction = -1;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cloud::move);
    timer->start(50);
}

Cloud::~Cloud()
{
    delete timer;
}

void Cloud::move()
{
    setPos(x() + (direction * 5), y());

    if ((direction == 1 && x() > 908) || (direction == -1 && x() < -200)) {
        if (direction == 1) {
            setPos(-200, 50);
        } else {
            setPos(908, 50);
        }
    }
}
