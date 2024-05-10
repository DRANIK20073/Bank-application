#include "Users.h"

Users::Users()
{
}

void Users::information() {
	cout << "�������: ";
	cin >> lastName;
	cout << "���: ";
	cin >> name;
	cout << "�����: ";
	cin >> login;
	cout << "������: ";
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
	cout << "�����: ";
	cin >> loginInput;
	cout << "������: ";
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
	cout << "������������ ����� ��� ������, ��������� �������." << endl;
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

	cout << "�������: " << lastName << endl;
	cout << "���: " << name << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
}

void Users::changePassword()
{
	string newPassword;
	cout << "������� ����� ������: ";
	cin >> newPassword;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

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

		cout << "������ ������� �������!" << endl;
		Sleep(1000);
	}
	else {
		cout << "������������ �� ������." << endl;
		remove("temp.txt");
	}
}


void Users::changeName()
{
	string newName;
	cout << "������� ����� ���: ";
	cin >> newName;
	
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

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

		cout << "��� ������� �������!" << endl;
		Sleep(1000);
	}
	else {
		cout << "������������ �� ������." << endl;
		remove("temp.txt");
	}
}

void Users::changeLastName()
{
	string newLastName;
	cout << "������� ����� �������: ";
	cin >> newLastName;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

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

		cout << "������� ������� ��������!" << endl;
		Sleep(1000);
	}
	else {
		cout << "������������ �� ������." << endl;
		remove("temp.txt");
	}
}