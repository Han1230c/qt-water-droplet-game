#include "bucket.h"

Bucket::Bucket()
{
    setPixmap(QPixmap(":/images/bucket.png").scaled(60, 60));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Bucket::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (x() > 0) {
            setPos(x() - 15, y());
        }
    } else if (event->key() == Qt::Key_Right) {
        if (x() < 908 - pixmap().width()) {
            setPos(x() + 15, y());
        }
    }
}


