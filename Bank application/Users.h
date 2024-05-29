#pragma once
#include "Header.h";
#include "userСabinet.h"

class Users
{
	//Пользователь
	string lastName;
	string name;
	string login;
	string password;
	string balance;

	//Карта 
	string cardNumber;
	string cardExpiration;
	string cardCVV;
	string cardPassword;
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

	void addBalance(double num);

	void addCard();

	bool displayCard();

	void transferMoney();

	void changeCardPassword();

	void deleteCard();

	void loadUserInformation(string loginInput, string passwordInput);
};

