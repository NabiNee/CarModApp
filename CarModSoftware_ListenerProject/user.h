/* Holds the information of a user, and can set user information.*/
#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {

private:
    // User information
    int userId;
    string userName;
    string userPassword;
    bool userHistory;

    // application Object saves
    //Cars carModel;

    //Gallery gallery;



public:
    User();
    // major methods

    // get set methods
    int getUserId();

    string getUserName();
    string getUserPassword();
    bool getHistory();
    //Cars getCarInfo();

    void setUserId(int id);
    void setUserName(string name);
    void setUserPassword(string password);

    // car model set methods

};

#endif
