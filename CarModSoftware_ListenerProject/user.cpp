#include "user.h"

User::User()
{

}

int User::getUserId()
{
    return userId;
}

string User::getUserName()
{
    return userName;
}

string User::getUserPassword()
{
    return userPassword;
}

bool User::getHistory()
{
return userHistory;
}

void User::setUserId(int id)
{
    userId = id;
}

void User::setUserName(string name)
{
    userName = name;
}

void User::setUserPassword(string password)
{
    userPassword = password;
}
