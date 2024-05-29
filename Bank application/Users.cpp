#include "Users.h"

Users::Users()
{
}

//Генерация рандомных чисел
string generateRandomString(int length) {
	const char characters[] = "0123456789";
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(0, sizeof(characters) - 2);

	string randomString;
	for (int i = 0; i < length; ++i) {
		randomString += characters[distribution(generator)];
	}
	return randomString;
}

//Регистрация
void Users::registration() {
	cout << "Фамилия: ";
	cin >> lastName;
	cout << "Имя: ";
	cin >> name;
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль: ";
	cin >> password;
	system("cls");

	ifstream fin("Users.txt");
	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		string LN, N, checkLogin;
		ss >> LN >> N >> checkLogin;
		if (login == checkLogin) {
			cout << "Пользователь с таким логином уже существует.";
			Sleep(2000);
			system("cls");
			mainMenu();
			fin.close();
		}
	}
	fin.close();

	ofstream user;
	user.open("Users.txt", ios::app);
	cardNumber = "";
	cardExpiration = "";
	cardCVV = "";
	cardPassword = "";
	balance = "0.0";
	user << lastName << " " << name << " " << login << " " << password << " " << balance << " " 
	<< cardNumber << " " << cardExpiration << " " << cardCVV << cardPassword << endl;
	user.close();

	cout << "Вы успешно зарегистрировались.";
	Sleep(1500);
	system("cls");
	mainMenu();
}

//Логин
bool Users::loginUser() {
	string loginInput;
	string passwordInput;
	tab();tab(); cout << "\t Логин: ";
	cin >> loginInput;
	tab();tab(); cout << "\t Пароль: ";
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

		if (words.size() >= 5 && words[2] == loginInput && words[3] == passwordInput) {
			userFile.close();

			ifstream fin("Users.txt");
			string line;

			while (getline(fin, line)) {
				stringstream ss(line);
				string currentLastName, currentName, currentLogin, currentPassword, currentBalance,
					currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;

				ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance;

				if (currentLogin == loginInput && currentPassword == passwordInput) {
					lastName = currentLastName;
					name = currentName;
					login = currentLogin;
					password = currentPassword;
					balance = currentBalance;
					cardNumber = currentCardNumber;
					cardExpiration = currentCardExpiration;
					cardCVV = currentCardCVV;
					cardPassword = currentCardPassword;
					break;
				}
			}

			fin.close();

			return true;
		}
	}

	userFile.close();
	system("cls");
	cout << "Неправильный логин или пароль, повторите попытку." << endl;
	Sleep(2000);
	return false;
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

string Users::getLastName()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance;
	}

	fin.close();

	return lastName;
}

string Users::getName()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance;
	}

	fin.close();

	return name;
}

string Users::getlogin()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance;
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
		ss >> lastName >> name >> login >> password >> balance;
	}

	fin.close();

	return password;
}

//Показать баланс
double Users::getBalance() {
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance;
	}

	double Balance = stod(balance);

	fin.close();

	return Balance;
}

//Пополнить баланс
void Users::addBalance(double num)
{
	double Balance = stod(balance);
	Balance += num;
	balance = to_string(Balance);

	// Обновление Users.txt
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << balance << endl;
		}
		else {
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	// Обновление CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance;
	currentUserFile.close();

	cout << "Баланс успешно обновлен!" << endl;
	Sleep(800);
}

//Создать карту
void Users::addCard()
{
	//Номер карты
	cardNumber = generateRandomString(16);

	//Cрок годности
	int month, year;
	srand(time(NULL));
	year = rand() % (30 - 24 + 1) + 24;
	month = rand() % (12 - 1 + 1) + 1;
	string Year = to_string(rand() % (30 - 24 + 1) + 24);
	string Month = to_string(rand() % (12 - 1 + 1) + 1);
	cardExpiration = Month + "/" + Year;

	//CVV
	cardCVV = generateRandomString(3);

	//Пароль
	cout << "Введите пароль для карты(4 цифры): ";
	cin >> cardPassword;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
		else {
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();

	cout << "Карта успешно добавлена!" << endl;
}

//Вид карты
bool Users::displayCard()
{
	string CardNumber = cardNumber;
	string CardExpiration = cardExpiration;
	string CardCVV = cardCVV;

	if (CardNumber.empty()) {
		cout << "У вас нет активной карты." << endl;
		Sleep(1000);
		return false;
	}
	else {
		cout << "**********************************" << endl;
		cout << "* Триорбанк                      *" << endl;
		cout << "*                                *" << endl;
		cout << "*                                *" << endl;
		cout << "* " << CardNumber << "           *" << endl;
		cout << "*                                *" << endl;
		cout << "*" << CardExpiration << "   " << CardCVV << "*" << endl;
		cout << "*                                *" << endl;
		cout << "**********************************" << endl;
	}
}

//Перевести деньги на аккаунт другого пользователя
void Users::transferMoney()
{
}

//Изменить пароль карты
void Users::changeCardPassword() {
	if (cardNumber.empty()) {
		cout << "У вас нет активной карты." << endl;
		return;
	}

	string newCardPassword;
	cout << "Введите новый пароль для карты: ";
	cin >> newCardPassword;
	cardPassword = newCardPassword;

	// Обновление Users.txt
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentCardNumber << " " << currentCardExpiry << " " << currentCardCVV << " " << newCardPassword << endl;
		}
		else {
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << newCardPassword;
	currentUserFile.close();

	cout << "Пароль карты успешно изменен!" << endl;
}

//Удалить карту
void Users::deleteCard() {

	cardNumber.clear();
	cardExpiration.clear();
	cardCVV.clear();
	cardPassword.clear();

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << "" << " " << "" << " " << "" << " " << "" << endl;
		}
		else {
			fout << line << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << "" << " " << "" << " " << "" << " " << "" << endl;
	currentUserFile.close();

	cout << "Карта успешно удалена!" << endl;
}

void Users::loadUserInformation(string loginInput, string passwordInput) {
	ifstream userFile("Users.txt");
	string line;

	while (getline(userFile, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == loginInput && currentPassword == passwordInput) {
			lastName = currentLastName;
			name = currentName;
			login = currentLogin;
			password = currentPassword;
			balance = currentBalance;
			cardNumber = currentCardNumber;
			cardExpiration = currentCardExpiry;
			cardCVV = currentCardCVV;
			cardPassword = currentCardPassword;

			ofstream currentUserFile("CurrentUser.txt");
			currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiry << " " << cardCVV << " " << cardPassword;
			currentUserFile.close();

			break;
		}
	}

	userFile.close();
}

//Для изменения данных пользователя UserCabinet
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

//Для изменения данных пользователя UserCabinet
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

//Для изменения данных пользователя UserCabinet
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