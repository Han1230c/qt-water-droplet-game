#include "scorehistorydialog.h"
#include "ui_scorehistorydialog.h"
#include "user.h"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

ScoreHistoryDialog::ScoreHistoryDialog(const User &user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreHistoryDialog)
{
    ui->setupUi(this);
    loadScoreHistory(user);
    int globalBestScore = getGlobalBestScore();
    ui->labelGlobalBestScore->setText(QString("Global Best Score: %1").arg(globalBestScore));

    // Connect the Dialog Button Box signals to the dialog's slots
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ScoreHistoryDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ScoreHistoryDialog::reject);
}

ScoreHistoryDialog::~ScoreHistoryDialog()
{
    delete ui;
}

void ScoreHistoryDialog::loadScoreHistory(const User &user)
{
    QString scoreHistoryText;
    QList<int> scoreHistory = user.scoreHistory();
    for (int i = 0; i < scoreHistory.size(); ++i) {
        scoreHistoryText += QString::number(scoreHistory[i]);
        if (i < scoreHistory.size() - 1) {
            scoreHistoryText += "\n";
        }
    }
    ui->textEditScoreHistory->setPlainText(scoreHistoryText);
}

int ScoreHistoryDialog::getGlobalBestScore()
{
    int globalBestScore = 0;
    QString basePath = QCoreApplication::applicationDirPath();
    basePath = QDir(basePath).absoluteFilePath("../../../../../");
    QDir dataDir(basePath + "/Data");
    QString filePath = dataDir.absoluteFilePath("users.json");
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonArray usersArray = doc.array();
        for (const QJsonValue &userValue : usersArray) {
            QJsonObject userObject = userValue.toObject();
            QJsonArray scoreHistoryArray = userObject["scoreHistory"].toArray();
            for (const QJsonValue &scoreValue : scoreHistoryArray) {
                int score = scoreValue.toInt();
                if (score > globalBestScore) {
                    globalBestScore = score;
                }
            }
        }
        file.close();
    }
    return globalBestScore;
}

