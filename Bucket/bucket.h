#ifndef BUCKET_H
#define BUCKET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Bucket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bucket();

protected:
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // BUCKET_H
