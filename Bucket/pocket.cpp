#include "pocket.h"

Pocket::Pocket(QGraphicsItem *parent)
    : QGraphicsTextItem{parent}
{
    // initiate the counter to 0
    bagelCounter = 0 ;

    // set the text
    setPlainText(QString("Bagel: ")+QString::number(bagelCounter)); // defalt bagelcounter = 0
    setDefaultTextColor(QColorConstants::Svg::black);
    setFont(QFont("Courier",16));

}

void  Pocket::increase(){
    bagelCounter++;
    setPlainText(QString("Bagel: ")+QString::number(bagelCounter)); // bagelcounter increases 1
}

int Pocket::getPocket(){
    return bagelCounter;
}



