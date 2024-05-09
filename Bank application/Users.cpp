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
			loadUserInformation(loginInput, passwordInput);
			return true;
		}
	}

	userFile.close();
	system("cls");
	cout << "Неправильный логин или пароль, повторите попытку." << endl;
	Sleep(2000);
	return false;
}

void Users::loadUserInformation(string loginInput, string passwordInput) {
	ifstream userFile("Users.txt");
	string line;

	while (getline(userFile, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword;

		if (currentLogin == loginInput && currentPassword == passwordInput) {
			lastName = currentLastName;
			name = currentName;
			login = currentLogin;
			password = currentPassword;
			break;
		}
	}

	userFile.close();
}

string Users::getName()
{
	return name;
}

string Users::getLastName()
{
	return lastName;
}

string Users::getlogin()
{
	return login;
}

string Users::getPassword()
{
	return password;
}

void Users::showInformation() {
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

	cout << "Фамилия: " << lastName << endl;
	cout << "Имя: " << name << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
}

void Users::changePassword()
{
	string newPassword;
	cout << "Введите новый пароль: ";
	cin >> newPassword;
	password = newPassword;
	cout << "Пароль успешно изменен!";
}

void Users::changeName()
{
	string newName;
	cout << "Введите новое имя: ";
	cin >> newName;
	name = newName;
	cout << "Имя успешно изменено!" << endl;
}
