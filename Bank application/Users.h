#pragma once
#include "Header.h";
#include "user�abinet.h"

class Users
{
	//������������
	string lastName;
	string name;
	string login;
	string password;
	string balance;

	//����� 
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

