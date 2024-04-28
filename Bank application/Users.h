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

	void information() {
		cout << "Фамилия: ";
		cin >> lastName;
		cout << "Имя: ";
		cin >> name;
		cout << "Логин: ";
		cin >> login;
		cout << "Пароль: ";
		cin >> password;
	}

	void registration() {
		ofstream user;
		user.open("Users.txt", ios::app);
		user << lastName << " " << name << " " << login << " " << password << endl;
		user.close();
	}

	bool loginUser() {
		string loginInput;
		string passwordInput;
		cout << "Логин: ";
		cin >> loginInput;
		cout << "Пароль: ";
		cin >> passwordInput;

		ifstream userFile("Users.txt");

		string line;
		while (getline(userFile, line)) {
			stringstream ss(line);
			vector<string> words;
			string word;
			while (ss >> word) {
				words.push_back(word);
			}

			if (words.size() >= 4 && words[2] == loginInput && words[3] == passwordInput) {
				userFile.close();
				cout << "Вы успешно зарегистрировались.";
				return true;
			}
		}

		userFile.close();
		cout << "Неправильный логин или пароль." << endl;
		return false;
	}

};

