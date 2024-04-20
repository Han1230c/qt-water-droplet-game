#include "user.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

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
    return json;
}

bool User::isValidUser(const QString &username, const QString &password)
{
    QList<User> users = loadUsersFromFile("users.json");
    for (const User &user : users) {
        if (user.username() == username && user.password() == password) {
            return true;
        }
    }
    return false;
}

void User::saveUsersToFile(const QString &filename, const QList<User> &users)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    QJsonArray userArray;
    for (const User &user : users) {
        userArray.append(user.toJsonObject());
    }

    QJsonDocument doc(userArray);
    file.write(doc.toJson());
    file.close();
}

QList<User> User::loadUsersFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
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
        users.append(user);
    }

    return users;
}
