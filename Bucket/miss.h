#ifndef MISS_H
#define MISS_H

#include <QGraphicsTextItem>
#include <QFont>

class Miss : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Miss(QGraphicsItem * parent=nullptr);
    void miss();
    int getMiss();
private:
    int missCounter;
};

#endif // MISS_H
