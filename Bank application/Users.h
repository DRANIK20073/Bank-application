#pragma once
#include "Header.h";
#include "user—abinet.h"

class Users
{
	string lastName;
	string name;
	string login;
	string password;
	string balance;
public:
	Users();

	void showInformation();

	void registration();

	bool loginUser();

	void changePassword();

	void changeName();

	void changeLastName();

	string getLastName();

	string getName();

	string getlogin();

	string getPassword();

	double getBalance();
};

