#ifndef POCKET_H
#define POCKET_H

#include <QGraphicsTextItem>
#include <QFont>


class Pocket : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Pocket(QGraphicsItem * parent=nullptr);
    void increase();
    int getPocket();


private:
    int bagelCounter;
};

#endif // POCKET_H
