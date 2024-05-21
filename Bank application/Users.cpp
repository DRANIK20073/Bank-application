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
	tab();tab(); cout << "	 Логин: ";
	cin >> loginInput;
	tab();tab(); cout << "	 Пароль: ";
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
	ifstream fin("Users.txt");
	string line;

	while (getline(fin, line)) {
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

	fin.close();
}

string Users::getName()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

	return name;
}

string Users::getLastName()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

	return lastName;
}

string Users::getlogin()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

	return login;
}

string Users::getPassword()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

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

	tab();tab();tab();cout << "   Фамилия: " << lastName << endl;
	tab();tab();tab();cout << "   Имя: " << name << endl;
	tab();tab();tab();cout << "   Логин: " << login << endl;
	tab();tab();tab();cout << "   Пароль: " << password << endl;
}

void Users::changePassword()
{	
	center();cout << "------------------------------------------------------------" << endl;
	string newPassword;
	tab();tab();cout << "\t     Введите новый пароль: ";
	cin >> newPassword;
	tab();cout << "------------------------------------------------------------" << endl;
	tab();tab();cout << "\t    1.Подтвердить изменения" << endl;
	tab();tab();cout << "\t    2.Ввести данные заново" << endl;
	tab();tab();cout << "\t    Esc.Выйти в меню" << endl;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

	int choice = _getch();
	switch (choice)
	{
	case '1':
		while (getline(fin, line)) {
			stringstream ss(line);
			string currentLastName, currentName, currentLogin, currentPassword;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << currentLastName << " " << currentName << " " << currentLogin << " " << newPassword << endl;
				userFound = true;
			}
			else {
				fout << line << endl;
			}
		}

		fin.close();
		fout.close();

		if (userFound) {
			remove("Users.txt");
			rename("temp.txt", "Users.txt");
			password = newPassword;

			ofstream currentUser("currentUser.txt");
			currentUser << lastName << " " << name << " " << login << " " << password << endl;
			currentUser.close();

			tab();tab();tab();cout << "Пароль успешно изменен!" << endl;
			Sleep(1000);
		}
		else {
			cout << "Пользователь не найден." << endl;
			remove("temp.txt");
		}
		break;
	case '2':
		system("cls");
		changePassword();
		break;
	case 27:
		system("cls");
		userCabinet();
		break;
	default:
		break;
	}
}


void Users::changeName()
{
	center();cout << "------------------------------------------------------------" << endl;
	string newName;
	tab();tab();cout << "\t    Введите новое имя: ";
	cin >> newName;
	tab();cout << "------------------------------------------------------------" << endl;
	tab();tab();cout << "\t    1.Подтвердить изменения" << endl;
	tab();tab();cout << "\t    2.Ввести данные заново" << endl;
	tab();tab();cout << "\t    Esc.Выйти в меню" << endl;
	
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

	int choice = _getch();
	switch (choice) {
	case '1':
		while (getline(fin, line)) {
			stringstream ss(line);
			string currentLastName, currentName, currentLogin, currentPassword;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << currentLastName << " " << newName << " " << currentLogin << " " << currentPassword << endl;
				userFound = true;
			}
			else {
				fout << line << endl;
			}
		}

		fin.close();
		fout.close();

		if (userFound) {
			remove("Users.txt");
			rename("temp.txt", "Users.txt");
			name = newName;

			ofstream currentUser("currentUser.txt");
			currentUser << lastName << " " << name << " " << login << " " << password << endl;
			currentUser.close();

			tab();tab();tab();cout << "Имя успешно изменен!" << endl;
			Sleep(1000);
		}
		else {
			cout << "Пользователь не найден." << endl;
			remove("temp.txt");
		}
		break;
	case '2':
		system("cls");
		changeName();
		break;
	case 27:
		system("cls");
		userCabinet();
		break;
	default:
		break;
	}
	
	
}

void Users::changeLastName()
{
	center();cout << "------------------------------------------------------------" << endl;
	string newLastName;
	tab();tab();cout << "\t   Введите новую фамилию: ";
	cin >> newLastName;
	tab();cout << "------------------------------------------------------------" << endl;
	tab();tab();cout << "\t    1.Подтвердить изменения" << endl;
	tab();tab();cout << "\t    2.Ввести данные заново" << endl;
	tab();tab();cout << "\t    Esc.Выйти в меню" << endl;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

	//Подтверждение изменений
	int choice = _getch();
	switch (choice) {
	case '1':

		while (getline(fin, line)) {
			stringstream ss(line);
			string currentLastName, currentName, currentLogin, currentPassword;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << newLastName << " " << currentName << " " << currentLogin << " " << currentPassword << endl;
				userFound = true;
			}
			else {
				fout << line << endl;
			}
		}

		fin.close();
		fout.close();

		if (userFound) {
			remove("Users.txt");
			rename("temp.txt", "Users.txt");
			lastName = newLastName;

			ofstream currentUser("currentUser.txt");
			currentUser << lastName << " " << name << " " << login << " " << password << endl;
			currentUser.close();

			tab();tab();tab();cout << "Фамилия успешно изменена!" << endl;
			Sleep(1000);
		}
		else {
			cout << "Пользователь не найден." << endl;
			remove("temp.txt");
		}
		break;
	case '2':
		system("cls");
		changeLastName();
		break;
	case 27:
		system("cls");
		userCabinet();
		break;
	default:
		break;
	}
}