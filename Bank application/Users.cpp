#include "Users.h"

Users::Users()
{
}

void Users::information() {
	cout << "Фамилия: ";
	cin >> lastName;
	cout << "Имя: ";
	cin >> name;
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль: ";
	cin >> password;
}

void Users::registration() {
	ofstream user;
	user.open("Users.txt", ios::app);
	user << lastName << " " << name << " " << login << " " << password << endl;
	user.close();
}

bool Users::loginUser() {
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
			return true;
		}
		}

	userFile.close();
	system("cls");
	cout << "Неправильный логин или пароль, повторите попытку." << endl;
	Sleep(2000);
	return false;
}
