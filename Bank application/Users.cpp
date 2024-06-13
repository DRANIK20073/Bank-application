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
	while (true) {
		char ch = _getch();
		if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		if (ch == '\b') {
			if (!lastName.empty()) {
				cout << "\b \b";
				lastName.pop_back();
			}
		}
		else {
			cout << ch;
			lastName += ch;
		}
	}
	cout << endl;
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
	balance = 0;
	ban = false;
	user << lastName << " " << name << " " << login << " " << password << " " << balance << " " 
	<< cardNumber << " " << cardExpiration << " " << cardCVV << cardPassword << " " << ban << endl;
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

				ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> balance >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;

				if (currentLogin == loginInput && currentPassword == passwordInput) {
					lastName = currentLastName;
					name = currentName;
					login = currentLogin;
					password = currentPassword;
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

//Данные пользователя
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

//Данные карты
string Users::getCardNum()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
	}

	fin.close();

	return cardNumber;
}

string Users::getCardExpiration()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
	}

	fin.close();

	return cardExpiration;
}

string Users::getCardCVV()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
	}

	fin.close();

	return cardCVV;

}

string Users::getCardPassword()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
	}

	fin.close();

	return cardPassword;
}

//Показать баланс
double Users::getBalance() {
	ifstream fin("CurrentUser.txt");
	string line;
	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance;
	}
	fin.close();

	return balance;
}

//Пополнить баланс
void Users::addBalance()
{

	// Обновление Users.txt
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	double num;
	cout << "Введите сумму: ";
	cin >> num;
	balance += num;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << balance << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
		}
		else {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	// Обновление CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
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
	string month_str;
	if (month < 10) {
		month_str = "0" + to_string(month);
	}
	else {
		month_str = to_string(month);
	}
	string year_str = to_string(year);
	
	cardExpiration = month_str + "/" + year_str;

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
		cout << " **********************************" << endl;
		cout << " * Триорбанк                      *" << endl;
		cout << " *                                *" << endl;
		cout << " *                                *" << endl;
		cout << " * " << CardNumber << "               *" << endl;
		cout << " *                                *" << endl;
		cout << " * " << CardExpiration << "                      " << CardCVV << " *" << endl;
		cout << " *                                *" << endl;
		cout << " **********************************" << endl;
	}
}

//Перевести деньги на карту другого пользователя
void Users::transferMoney() {
	cout << "Введите номер карты другого пользователя: ";
	string anotherUserCard;
	cin >> anotherUserCard;

	bool userFound = false;
	double transferAmount;

	// Чтение текущего пользователя
	ifstream currentFin("CurrentUser.txt");
	if (!currentFin.is_open()) {
		cerr << "Ошибка при открытии файла CurrentUser.txt." << endl;
		return;
	}

	string line;
	string currentUserLastName, currentUserName, currentUserLogin, currentUserPassword, currentUserCardNumber, currentUserCardExpiration, currentUserCardCVV, currentUserCardPassword;
	double currentUserBalance;

	while (getline(currentFin, line)) {
		stringstream ss(line);
		ss >> currentUserLastName >> currentUserName >> currentUserLogin >> currentUserPassword >> currentUserBalance >> currentUserCardNumber >> currentUserCardExpiration >> currentUserCardCVV >> currentUserCardPassword;
	}
	currentFin.close();

	// Проверка введенной суммы
	cout << "Введите сумму: ";
	cin >> transferAmount;
	if (transferAmount > currentUserBalance) {
		cout << "Недостаточно средств на счете." << endl;
		return;
	}

	// Обновление Users.txt
	ifstream fin("Users.txt");
	if (!fin.is_open()) {
		cerr << "Ошибка при открытии файла Users.txt." << endl;
		return;
	}

	ofstream fout("temp.txt");
	if (!fout.is_open()) {
		cerr << "Ошибка при открытии файла temp.txt." << endl;
		fin.close();
		return;
	}

	while (getline(fin, line)) {
		stringstream ss(line);
		string lastName, name, login, password, cardNumber, cardExpiration, cardCVV, cardPassword;
		double balance;

		ss >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;

		if (cardNumber == anotherUserCard) {
			userFound = true;
			balance += transferAmount;
			fout << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
		else if (login == currentUserLogin) {
			currentUserBalance -= transferAmount;
			fout << lastName << " " << name << " " << login << " " << password << " " << currentUserBalance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
		else {
			fout << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	if (!userFound) {
		cerr << "Пользователь с введенным номером карты не найден." << endl;
		remove("temp.txt");
		return;
	}

	if (remove("Users.txt") != 0) {
		cerr << "Ошибка при удалении файла Users.txt." << endl;
		return;
	}
	if (rename("temp.txt", "Users.txt") != 0) {
		cerr << "Ошибка при переименовании файла temp.txt в Users.txt." << endl;
		return;
	}

	// Обновление CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	if (!currentUserFile.is_open()) {
		cerr << "Ошибка при открытии файла CurrentUser.txt." << endl;
		return;
	}

	currentUserFile << currentUserLastName << " " << currentUserName << " " << currentUserLogin << " " << currentUserPassword << " " << currentUserBalance << " " << currentUserCardNumber << " " << currentUserCardExpiration << " " << currentUserCardCVV << " " << currentUserCardPassword;
	currentUserFile.close();

	cout << "Деньги успешно переведены!" << endl;
	Sleep(500);
}


//Изменить пароль карты
void Users::changeCardPassword() {

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
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << newCardPassword << endl;
		}
		else {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();

	cout << "Пароль карты успешно изменен!" << endl;
	Sleep(800);
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
	Sleep(800);
}

void Users::loadUserInformation() {
	ifstream userFile("currentUser.txt");
	string line;

	while (getline(userFile, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		lastName = currentLastName;
		name = currentName;
		login = currentLogin;
		password = currentPassword;
		balance = currentBalance;
		cardNumber = currentCardNumber;
		cardExpiration = currentCardExpiry;
		cardCVV = currentCardCVV;
		cardPassword = currentCardPassword;

		break;
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