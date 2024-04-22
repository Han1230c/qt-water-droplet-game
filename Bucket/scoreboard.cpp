#include "scoreboard.h"

ScoreBoard::ScoreBoard(QGraphicsItem *parent)
    : QGraphicsTextItem{parent} // inherent from QWidget
{
    // initiate the score to 0
    score = 0 ;

    // set the text
    setPlainText(QString("Score: ")+QString::number(score)); // defalt score = 0
    setDefaultTextColor(QColorConstants::Svg::blue);
    setFont(QFont("Courier",16));


}

void ScoreBoard::increase(){
    score+=5;
    setPlainText(QString("Score: ")+QString::number(score)); // score increases 5
}

int ScoreBoard::getScore(){
    return score;
}
