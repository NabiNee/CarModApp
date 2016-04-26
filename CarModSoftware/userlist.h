/* PROBABLY NOT NEEDED SINCE DATABASE*/
#ifndef USERLIST_H
#define USERLIST_H

#include "user.h"
#include <vector>
#include <QString>

class UserList
{
private:
    vector <User> listOfUsers;
public:
    UserList();
    bool checkCredentials(string,string); //checks username and password
    void addNewUser();
    bool userExist(string); //Returns true if username exists
};

#endif // USERLIST_H
