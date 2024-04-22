#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsTextItem>
#include <QFont>
#include <pocket.h>


class ScoreBoard: public QGraphicsTextItem
{
    Q_OBJECT
public:
    ScoreBoard(QGraphicsItem* parent = nullptr);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCOREBOARD_H
