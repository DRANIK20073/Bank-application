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
	double balance;
	string ban;

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

	string getCardNum();

	string getCardExpiration();

	string getCardCVV();

	string getCardPassword();

	double getBalance();

	void addBalance();

	void addCard();

	bool displayCard();

	void transferMoney();

	void changeCardPassword();

	void deleteCard();

	void loadUserInformation();

};

