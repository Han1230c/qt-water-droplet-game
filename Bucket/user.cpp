#include "user.h"
#include "QtCore/qdir.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>

User::User(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &gender, const QDate &birthday, const QString &profilePhoto)
    : m_firstName(firstName), m_lastName(lastName), m_username(username), m_password(password), m_gender(gender), m_birthday(birthday), m_profilePhoto(profilePhoto)
{
}

QString User::firstName() const
{
    return m_firstName;
}

void User::setFirstName(const QString &firstName)
{
    m_firstName = firstName;
}

QString User::lastName() const
{
    return m_lastName;
}

void User::setLastName(const QString &lastName)
{
    m_lastName = lastName;
}

QString User::username() const
{
    return m_username;
}

void User::setUsername(const QString &username)
{
    m_username = username;
}

QString User::password() const
{
    return m_password;
}

void User::setPassword(const QString &password)
{
    m_password = password;
}

QString User::gender() const
{
    return m_gender;
}

void User::setGender(const QString &gender)
{
    m_gender = gender;
}

QDate User::birthday() const
{
    return m_birthday;
}

void User::setBirthday(const QDate &birthday)
{
    m_birthday = birthday;
}

QString User::profilePhoto() const
{
    return m_profilePhoto;
}

void User::setProfilePhoto(const QString &profilePhoto)
{
    m_profilePhoto = profilePhoto;
}

QList<int> User::scoreHistory() const
{
    return m_scoreHistory;
}

void User::updateScoreHistory(int score)
{
    m_scoreHistory.append(score);
}

QJsonObject User::toJsonObject() const
{
    QJsonObject json;
    json["firstName"] = m_firstName;
    json["lastName"] = m_lastName;
    json["username"] = m_username;
    json["password"] = m_password;
    json["gender"] = m_gender;
    json["birthday"] = m_birthday.toString(Qt::ISODate);
    json["profilePhoto"] = m_profilePhoto;

    QJsonArray scoreHistoryArray;
    for (int score : m_scoreHistory) {
        scoreHistoryArray.append(score);
    }
    json["scoreHistory"] = scoreHistoryArray;

    return json;
}

bool User::isRegistered(const QString &username, const QString &password, const QString &filePath) {
    QList<User> users = loadUsersFromFile(filePath);
    for (const User &user : users) {
        if (user.username() == username && user.password() == password) {
            return true;
        }
    }
    return false;
}

User User::findUserByUsername(const QString &username)
{
    QString basePath = QCoreApplication::applicationDirPath();
    basePath = QDir(basePath).absoluteFilePath("../../../../../Data");
    QString filePath = QDir(basePath).filePath("users.json");

    QList<User> users = loadUsersFromFile(filePath);
    for (const User &user : users) {
        if (user.username() == username) {
            return user;
        }
    }
    return User();
}

bool User::saveUsersToFile(const QString &filePath, const QList<User> &users) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Couldn't open file for writing:" << file.errorString();
        return false;
    }

    QJsonArray userArray;
    for (const User &user : users) {
        userArray.append(user.toJsonObject());
    }

    QJsonDocument doc(userArray);
    qint64 bytesWritten = file.write(doc.toJson());
    file.close();

    qDebug() << "Bytes written to file:" << bytesWritten;
    return bytesWritten != -1;
}

QList<User> User::loadUsersFromFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file for reading:" << file.errorString();
        return {};
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));

    QList<User> users;
    QJsonArray userArray = doc.array();
    for (const QJsonValue &value : userArray) {
        QJsonObject userObject = value.toObject();
        User user;
        user.setFirstName(userObject["firstName"].toString());
        user.setLastName(userObject["lastName"].toString());
        user.setUsername(userObject["username"].toString());
        user.setPassword(userObject["password"].toString());
        user.setGender(userObject["gender"].toString());
        user.setBirthday(QDate::fromString(userObject["birthday"].toString(), Qt::ISODate));
        user.setProfilePhoto(userObject["profilePhoto"].toString());

        QJsonArray scoreHistoryArray = userObject["scoreHistory"].toArray();
        for (const QJsonValue &scoreValue : scoreHistoryArray) {
            int score = scoreValue.toInt();
            user.updateScoreHistory(score);
        }

        users.append(user);
    }

    file.close();
    return users;
}
