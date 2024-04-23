#include "gamescene.h"
#include "cloud.h"
#include <QRandomGenerator>

GameScene::GameScene(int leveloption, User* currentUser)
{
    levelIndex = leveloption;

    this->currentUser = currentUser;

    setSceneRect(0, 0, 908, 510);
    setBackgroundBrush(QBrush(QImage(":/images/back.JPG").scaled(908, 510)));

    bucketItem = new Bucket();
    bucketItem->setPos(400, 365);
    addItem(bucketItem);

    pocket = new Pocket();
    pocket->setPos(5,85);
    addItem(pocket);


    scoreBoard = new ScoreBoard();
    scoreBoard->setPos(5,65);
    addItem(scoreBoard);

    miss = new Miss();
    miss ->setPos(5, 105);
    addItem(miss);

    cloud = new Cloud();
    addItem(cloud);

    dropletTimer = new QTimer(this);
    connect(dropletTimer, &QTimer::timeout, this, &GameScene::createDroplet);
    dropletTimer->start(5000);





}

GameScene::~GameScene()
{
    delete dropletTimer;
    delete bucketItem;
}

void GameScene::createDroplet()
{
    QList<QGraphicsItem *> items = this->items();
    foreach (QGraphicsItem *item, items) {

        if (cloud == qgraphicsitem_cast<Cloud *>(item)) {

            winWin* winWindow = new winWin();
            loseWin* loseWindow = new loseWin();



            if(levelIndex==0){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, easyLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
            }
            else if(levelIndex==1){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, mediumLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
            }
            else if(levelIndex==2){
                Droplet * droplet = new Droplet(cloud, this->pocket, this->miss,this->scoreBoard, this->bucketItem, hardLevel, currentUser);
                addItem(droplet);
                connect(droplet, &Droplet::winSignal, winWindow, &winWin::createWinWindow);
                connect(droplet, &Droplet::loseSignal, loseWindow, &loseWin::createLoseWindow);
            }

            // connect(winWindow, &winWin::saveHistScoreSign, this, &GameScene::saveHistScore);

            // QTextStream(stdout) << "creat a droplet" << Qt::endl;

            return;
        }
    }
}


int GameScene::getLevelIndex() const
{
    return levelIndex;
}

// bool GameScene::saveHistScore(){
//     QDir currentDir = QDir::current();
//     QString basePath = QCoreApplication::applicationDirPath();
//     basePath = QDir(basePath).absoluteFilePath("../../../../../");
//     QDir dataDir(basePath + "/Data");



//     if (!dataDir.exists()) {
//         bool dirCreated = currentDir.mkdir("Data");
//         qDebug() << "Data directory created:" << dirCreated;
//         if (!dirCreated) {
//             // QMessageBox::critical(this, "Hist Error", "Unable to create data directory.");
//             return false;
//         }
//     }

//     QString filePath = dataDir.filePath("histScore.json");
//     QFile file(filePath);
//     if (!file.open(QIODevice::ReadWrite)) {
//         return false;
//     }

//     int hist = (int) file.readAll().toInt();


//     QTextStream(stdout) << "History score: "<<hist << Qt::endl;

//     if(hist < this->scoreBoard->getScore()){

//     }
// file.close();

//     User newUser(ui->firstNameLineEdit->text(), ui->lastNameLineEdit->text(), ui->usernameLineEdit->text(),
//                  ui->passwordLineEdit->text(), ui->comboBoxGender->currentText(), ui->dateEdit->date(), m_filePath);
//     users.append(newUser);

//     bool saveResult = User::saveUsersToFile(filePath, users);
//     qDebug() << "Data saved successfully:" << saveResult;

//     return saveResult;
// }

