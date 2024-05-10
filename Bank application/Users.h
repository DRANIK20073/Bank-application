#pragma once
#include "Header.h";

class Users
{
	string lastName;
	string name;
	string login;
	string password;
public:
	Users();

	void information();

	void showInformation();

	void registration();

	bool loginUser();

	void changePassword();

	void changeName();

	void changeLastName();

	void loadUserInformation(string loginInput, string passwordInput);

	string getName();

	string getLastName();

	string getlogin();

	string getPassword();
};

