#include "userlist.h"

UserList::UserList()
{
User tempUser;
tempUser.setUserName("User");
tempUser.setUserPassword("User");
listOfUsers.push_back(tempUser);
}

bool UserList::checkCredentials(string username, string password)
{
    for(int i = 0; i < listOfUsers.size(); i++)
    {
        if(username == listOfUsers[i].getUserName()) //if username is found, check to see that the password matches
        {
            if(password == listOfUsers[i].getUserPassword())
                return true;
            else
                return false;
        }
    }
}

void UserList::addNewUser()
{
   // User
}

/* Checks if username already exists. Returns true if yes */
bool UserList::userExist(string name)
{
    for(int i = 0; i<listOfUsers.size(); i++)
        if(name == listOfUsers[i].getUserName())
            return true;
    return false;
}
