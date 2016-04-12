#pragma once
#include "car.h"
#include <string.h>

class User {

private:
	// User information
	int Userid;
	char* userName;
	char* userPassword;
	bool userHistory;

	// application Object saves 
	Cars carModel;

	//Gallery gallery;



public:

	// major methods

	// get set methods
	int getUserId();
	char* getUserName();
	char* getUserPassword();
	bool getHistory();
	Cars getCarInfo();

	void setUserId(int id) { Userid = id; }
	void setUserName(char* name) { userName = name; }
	void setUserPassword(char* password) { userPassword = password; }

	// car model set methods

};