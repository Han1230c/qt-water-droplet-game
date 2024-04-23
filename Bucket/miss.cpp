#include "miss.h"

Miss::Miss(QGraphicsItem *parent)
    : QGraphicsTextItem{parent}
{
    // initiate the counter to 0
    missCounter = 0;

    // set up the font
    setPlainText(QString("Miss:  ")+QString::number(missCounter)); // defalt missCounter = 0
    setDefaultTextColor(QColorConstants::Svg::darkred);
    setFont(QFont("Courier" ,16));
}

void Miss::miss() {
    missCounter++;
    setPlainText(QString("Miss:  ")+QString::number(missCounter));
    if (missCounter >= 5) {
        emit gameOver();
    }
}

int Miss::getMiss(){
    return missCounter;
}
