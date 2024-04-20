#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QJsonObject>

class User
{
public:
    User(const QString &firstName = "", const QString &lastName = "", const QString &username = "", const QString &password = "", const QString &gender = "", const QDate &birthday = QDate(), const QString &profilePhoto = "");

    QString firstName() const;
    void setFirstName(const QString &firstName);

    QString lastName() const;
    void setLastName(const QString &lastName);

    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);

    QString gender() const;
    void setGender(const QString &gender);

    QDate birthday() const;
    void setBirthday(const QDate &birthday);

    QString profilePhoto() const;
    void setProfilePhoto(const QString &profilePhoto);

    QJsonObject toJsonObject() const;

    static bool isRegistered(const QString &username, const QString &password, const QString &filePath);
    static User findUserByUsername(const QString &username);
    static bool saveUsersToFile(const QString &filePath, const QList<User> &users);
    static QList<User> loadUsersFromFile(const QString &filePath);

private:
    QString m_firstName;
    QString m_lastName;
    QString m_username;
    QString m_password;
    QString m_gender;
    QDate m_birthday;
    QString m_profilePhoto;
};

#endif // USER_H
