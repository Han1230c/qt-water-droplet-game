#include "droplet.h"
#include "QtCore/qjsondocument.h"
#include "cloud.h"
#include <QRandomGenerator>


Droplet::Droplet(Cloud *cloud, Pocket* p,Miss* miss,ScoreBoard* scoreB, Bucket* bucket, QList<qreal>* speedLevel, User* currentUser)
{
    this-> pocket = p;
    this->miss = miss;
    this->score = scoreB;
    this->bucket = bucket;
    this->speedLevel = speedLevel;
    this->user = currentUser;

    setPixmap(QPixmap(":/images/Subject 2.png").scaled(30, 30));

    qreal x = cloud->x() + cloud->boundingRect().width() / 2 - boundingRect().width() / 2;
    qreal y = cloud->y() + cloud->boundingRect().height();
    setPos(x, y);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Droplet::move);
    timer->start(50);

}

Droplet::~Droplet()
{
    delete timer;
}

void Droplet::move()
{
    QMediaPlayer* collectMusic = new QMediaPlayer;
    collectMusic->setAudioOutput(new QAudioOutput);
    QMediaPlayer* missMusic = new QMediaPlayer;
    missMusic->setAudioOutput(new QAudioOutput);
    collectMusic -> setSource(QUrl("qrc:/sound/eating.wav"));
    missMusic -> setSource(QUrl("qrc:/sound/fail.wav"));


    setPos(x(), y() + speedLevel->at(0));


    if ( x()>=0 && x() <= 980 && y() > 520) {
        QTextStream(stdout) << "remove a droplet" << Qt::endl;
        scene()->removeItem(this);
        missMusic->play();
        miss->miss();
        if(miss->getMiss()==5){
             //lose game logic
            emit loseSignal(miss->getMiss());
            connect(this, &Droplet::loseSignal, this, [this](int score){

                QString basePath = QCoreApplication::applicationDirPath();
                basePath = QDir(basePath).absoluteFilePath("../../../../../");
                QDir dataDir(basePath + "/Data");


                QString filePath = dataDir.absoluteFilePath("users.json");
                QList<User> users = user->loadUsersFromFile(filePath);

                for (const User &u : users) {
                    if (u.username().compare(user->username(), Qt::CaseInsensitive) == 0) {
                        user->updateScoreHistory(score);
                        // QMessageBox::warning(this, "Registration", "Username already exists.");
                        return false;
                    }
                }


                user->saveUsersToFile(filePath, users);


                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly)) {
                    QJsonDocument doc(user->toJsonObject());
                    file.write(doc.toJson());
                    file.close();
                }
            });
        }
        deleteLater();
        return;
    }

    if(pocket->getPocket()>5){
        setPos(x(), y() + speedLevel->at(1));
    }
    if(pocket->getPocket()>10){
        setPos(x(), y() + speedLevel->at(2));
    }
    if(pocket->getPocket()>15){
        setPos(x(), y() + speedLevel->at(3));
    }
    if(pocket->getPocket()>15){
        setPos(x(), y() + speedLevel->at(4));
    }

    QList<QGraphicsItem *> colliding_items = scene()->collidingItems(this);


    if (x() > 0 && x() < 980 && !colliding_items.isEmpty() && collidesWithItem(bucket)) {
        QTextStream(stdout) << "collide a droplet" << Qt::endl;
        scene()->removeItem(this);
        collectMusic->play();
        pocket->increase();
        score->increase();
        QTextStream(stdout) << "increase score" << Qt::endl;

        //win game logic
        if (score->getScore() == 150) {
            emit winSignal(score->getScore());
            connect(this, &Droplet::winSignal, this, [this](int score){
                user->updateScoreHistory(score);

                QString basePath = QCoreApplication::applicationDirPath();
                basePath = QDir(basePath).absoluteFilePath("../../../../../");
                QDir dataDir(basePath + "/Data");


                // Define the file path
                QString filePath = dataDir.absoluteFilePath("users.json");
                QFile file(filePath);

                // Open the file and write the JSON document
                if (file.open(QIODevice::WriteOnly)) {
                    QJsonDocument doc(user->toJsonObject());
                    file.write(doc.toJson());
                    file.close();
                }
            });
        }

        deleteLater();
        return;
    }
}



