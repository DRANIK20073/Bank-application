#pragma once
#include "Header.h"

class admins {
private:
	string name;
	string lastName;
	string login;
	string password;
	
public:
	admins();

	bool adminLogin();

	string getLastName();

	string getName();

	string getLogin();

	string getPassword();
};