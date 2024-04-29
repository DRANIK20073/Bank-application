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

	void registration();

	bool loginUser();
};

