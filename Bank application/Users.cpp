#include "Users.h"
#include "Header.h"

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
	cout << "\t   Фамилия: ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (!lastName.empty()) {
				break;
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!lastName.empty()) {
				cout << "\b \b";
				lastName.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			lastName += ch;
		}
	}
	cout << endl;
	cout << "\t   Имя: ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (!name.empty()) {
				break;
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!name.empty()) {
				cout << "\b \b";
				name.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			name += ch;
		}
	}
	cout << endl;
	cout << "\t   Логин(не менее 5 символов): ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (login.length() >= 5) {
				break;
			}
			else {
				system("cls");
				bank_logo();
				cout << "\n    Логин должен содержать не менее 5 символов. Повторите ввод." << endl;
				Sleep(1000);
				system("cls");
				bank_logo();
				login = "";
				cout << "\t   Логин (не менее 5 символов): ";
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!login.empty()) {
				cout << "\b \b";
				login.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			login += ch;
		}
	}
	cout << endl;
	cout << "\t   Пароль(не менее 8 символов): ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (password.length() >= 8) {
				break;
			}
			else {
				system("cls");
				bank_logo();
				cout << "\n    Пароль должен содержать не менее 8 символов. Повторите ввод." << endl;
				Sleep(1000);
				system("cls");
				bank_logo();
				password = "";
				cout << "\t   Пароль (не менее 8 символов): ";
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!password.empty()) {
				cout << "\b \b";
				password.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			password += ch;
		}
	}
	cout << endl;
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
	ban = "false";
	user << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " "
	<< cardNumber << " " << cardExpiration << " " << cardCVV << cardPassword << " " << endl;
	user.close();

	bank_logo();
	cout << "\t\t   Вы успешно зарегистрировались.";
	Sleep(1500);
	system("cls");
	mainMenu();
}

//Логин
bool Users::loginUser() {
	string loginInput;
	string passwordInput;
	tab();tab(); cout << "\t    Логин: ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (!loginInput.empty()) {
				break;
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!loginInput.empty()) {
				cout << "\b \b";
				loginInput.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			loginInput += ch;
		}
	}
	cout << endl;
	tab();tab(); cout << "\t    Пароль: ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (!passwordInput.empty()) {
				break;
			}
		}
		else if (ch == 27) {
			system("cls");
			mainMenu();
			break;
		}
		else if (ch == '\b') {
			if (!passwordInput.empty()) {
				cout << "\b \b";
				passwordInput.pop_back();
			}
		}
		else if (ch != '\n') {
			cout << ch;
			passwordInput += ch;
		}
	}
	cout << endl;

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
				string currentBan;

				ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> balance >> currentBan >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;
				
				if (currentLogin == loginInput && currentPassword == passwordInput && currentBan == "false") {
					lastName = currentLastName;
					name = currentName;
					login = currentLogin;
					password = currentPassword;
					ban = currentBan;
					cardNumber = currentCardNumber;
					cardExpiration = currentCardExpiration;
					cardCVV = currentCardCVV;
					cardPassword = currentCardPassword;
					break;
				}
				else if (currentBan == "true") {
					system("cls");
					bank_logo();
					cout << "\t  Ваш аккаунт заблокирован, обратитесь в ближайшее" << endl << "\t\t\t  отделение банка";
					Sleep(2700);
					system("cls");
					mainMenu();
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

	cout << "\t\t\t          Фамилия: " << lastName << endl;
	cout << "\t\t\t          Имя: " << name << endl;
	cout << "\t\t\t          Логин: " << login << endl;
	cout << "\t\t\t          Пароль: " << password << endl;
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

string Users::getBan()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
	}

	fin.close();

	return ban;
}

//Данные карты
string Users::getCardNum()
{
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
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
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
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
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
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
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;;
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

	double num = 0;
	string numStr = to_string(num);
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t         Введите сумму: ";
		numStr.clear();
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				break;
			}
			else if (ch == 27) {
				system("cls");
				Balance();
			}
			else if (ch == '\b') {
				if (!numStr.empty()) {
					cout << "\b \b";
					numStr.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				numStr += ch;
			}
		}
		cout << endl << "\t\t\t      Баланс успешно пополнен." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(800);
		break;
	}
	num = stod(numStr);
	balance += num;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;
		double currentBalance;
		string currentBan;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << balance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
			lastName = currentLastName;
			name = currentName;
			login = currentLogin;
			password = currentPassword;
			
			ban = currentBan;
			cardNumber = currentCardNumber;
			cardExpiration = currentCardExpiration;
			cardCVV = currentCardCVV;
			cardPassword = currentCardPassword;
		}
		else {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	// Обновление CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();
}

bool isDigitsOnly(const string& str) {
	return all_of(str.begin(), str.end(), ::isdigit);
}

//Создать карту
void Users::addCard()
{	
	ifstream currentUserFile2("CurrentUser.txt");
	if (currentUserFile2.is_open()) {
		string line;
		getline(currentUserFile2, line);
		stringstream ss(line);
		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
		currentUserFile2.close();
	}

	if (!cardNumber.empty()) {
		system("cls");
		center(); cout << "------------------------------------------------------------" << endl;
		cout << "\t\tУ вас уже есть карта, невозможно создать новую." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(1500);
		Balance();
	}

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
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t      Введите пароль для карты (4 цифры): ";
		cardPassword.clear(); 
		while (true) {
			char ch = _getch();

			if (ch == '\r') {
				break; 
			}
			else if (ch == 27) { 
				system("cls");
				Balance();
			}
			else if (ch == '\b') { 
				if (!cardPassword.empty()) {
					cout << "\b \b";
					cardPassword.pop_back();
				}
			}
			else if (isdigit(ch)) { 
				if (cardPassword.length() < 4) { 
					cout << ch;
					cardPassword += ch;
				}
			}
		}

		if (cardPassword.length() != 4) {
			cout << endl;
			cout << "\t\t      Пароль должен состоять ровно из 4 цифр." << endl;
			Sleep(1500);
			system("cls");
		}
		else if (!isDigitsOnly(cardPassword)) {
			cout << endl;
			cout << "\t\t      В пароле не должны присутствовать буквы." << endl;
			Sleep(1500);
			system("cls");
		}
		else {
			cout << endl << "\t\t\t      Карта успешно создана." << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
			Sleep(800);
			break; 
		}
	}

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;
		string currentBan;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
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
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();
}

//Вид карты
bool Users::displayCard()
{	
	string CardNumber = cardNumber;
	string CardExpiration = cardExpiration;
	string CardCVV = cardCVV;

	if (CardNumber.empty()) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t    У вас нет активной карты." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(800);
		return false;
	}
	else {
		cout << "\n\n\n\n\n";
		cout << "\t\t       **********************************" << endl;
		cout << "\t\t       * ТриорБанк                      *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       * " << CardNumber << "               *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       * " << CardExpiration << "                      " << CardCVV << " *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       **********************************" << endl;
	}
}

//Перевести деньги на карту другого пользователя
void Users::transferMoney() {

	string anotherUserCard;
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t   Введите номер карты другого пользователя: ";
		anotherUserCard.clear();
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (anotherUserCard.length() != 16 || !isDigitsOnly(anotherUserCard)) {
					cout << endl;
					cout << "\t\t     Номер карты должен состоять из 16 цифр." << endl;
					Sleep(1000);
					system("cls");
					transferMoney();
					break;
				}
				else {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				Balance();
			}
			else if (ch == '\b') {
				if (!anotherUserCard.empty()) {
					cout << "\b \b";
					anotherUserCard.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				anotherUserCard += ch;
			}
		}
		break;
	}

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
	string currentUserBan;

	while (getline(currentFin, line)) {
		stringstream ss(line);
		ss >> currentUserLastName >> currentUserName >> currentUserLogin >> currentUserPassword >> currentUserBalance >> currentUserBan >> currentUserCardNumber >> currentUserCardExpiration >> currentUserCardCVV >> currentUserCardPassword;
	}
	currentFin.close();

	// Проверка введенной суммы
	string transferAmountStr;
	while (true) {
		cout << endl << "\t\t\t          Введите сумму: ";
		transferAmountStr.clear();
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				break;
			}
			else if (ch == 27) {
				system("cls");
				Balance();
			}
			else if (ch == '\b') {
				if (!transferAmountStr.empty()) {
					cout << "\b \b";
					transferAmountStr.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				transferAmountStr += ch;
			}
		}
		break;
	}

	transferAmount = stod(transferAmountStr);
	if (transferAmount > currentUserBalance) {
		cout << endl << "\t\t     Недостаточно средств на счете." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(800);
		transferMoney();
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
		string ban;

		ss >> lastName >> name >> login >> password >> balance >> ban >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;

		if (cardNumber == anotherUserCard) {
			userFound = true;
			balance += transferAmount;
			fout << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
		else if (login == currentUserLogin) {
			currentUserBalance -= transferAmount;
			fout << lastName << " " << name << " " << login << " " << password << " " << currentUserBalance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
		else {
			fout << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	if (!userFound) {
		cerr << endl << "\t         Пользователь с введенным номером карты не найден." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(1000);
		remove("temp.txt");
		system("cls");
		transferMoney();
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

	currentUserFile << currentUserLastName << " " << currentUserName << " " << currentUserLogin << " " << currentUserPassword << " " << currentUserBalance << " " << currentUserBan << " " << currentUserCardNumber << " " << currentUserCardExpiration << " " << currentUserCardCVV << " " << currentUserCardPassword;
	currentUserFile.close();

	cout << endl << "\t\t\t     Деньги успешно переведены!" << endl;
	cout << "\t  ------------------------------------------------------------" << endl;
	Sleep(800);
	system("cls");
	Balance();
}

//Изменить пароль карты
void Users::changeCardPassword() {

	string newCardPassword;
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t Введите новый пароль для карты (4 цифры): ";
		newCardPassword.clear();
		while (true) {
			char ch = _getch();

			if (ch == '\r') {
				break;
			}
			else if (ch == 27) {
				system("cls");
				Balance();
			}
			else if (ch == '\b') {
				if (!newCardPassword.empty()) {
					cout << "\b \b";
					newCardPassword.pop_back();
				}
			}
			else if (isdigit(ch)) {
				if (newCardPassword.length() < 4) {
					cout << ch;
					newCardPassword += ch;
				}
			}
		}

		if (newCardPassword.length() != 4) {
			cout << endl;
			cout << "\t\t      Пароль должен состоять ровно из 4 цифр." << endl;
			Sleep(1500);
			system("cls");
		}
		else if (!isDigitsOnly(newCardPassword)) {
			cout << endl;
			cout << "\t\t      В пароле не должны присутствовать буквы." << endl;
			Sleep(1500);
			system("cls");
		}
		else {
			cout << endl;
			cout << "\t\t         Пароль карты успешно изменен!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
			Sleep(800);
			break;
		}
	}
	

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;
		double currentBalance;
		string currentBan;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << newCardPassword << endl;
		}
		else {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiration << " " << currentCardCVV << " " << currentCardPassword << endl;
		}
	}

	fin.close();
	fout.close();

	remove("Users.txt");
	rename("temp.txt", "Users.txt");

	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();

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
		string currentBan;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		if (currentLogin == login && currentPassword == password) {
			fout << currentLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << "" << " " << "" << " " << "" << " " << "" << endl;
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
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << "" << " " << "" << " " << "" << " " << "" << endl;
	currentUserFile.close();

	center();cout << "------------------------------------------------------------" << endl;
	cout << "\t\t\t      Карта успешно удалена!" << endl;
	tab();cout << "------------------------------------------------------------" << endl;
	Sleep(800);
}

void Users::loadUserInformation() {
	ifstream userFile("currentUser.txt");
	string line;

	while (getline(userFile, line)) {
		stringstream ss(line);
		string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
		double currentBalance;
		string currentBan;

		ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

		lastName = currentLastName;
		name = currentName;
		login = currentLogin;
		password = currentPassword;
		balance = currentBalance;
		ban = currentBan;
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
	while (true) {
		cout << "\t\t\t      Введите новый пароль: ";
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!newPassword.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				userCabinet();
				break;
			}
			else if (ch == '\b') {
				if (!newPassword.empty()) {
					cout << "\b \b";
					newPassword.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				newPassword += ch;
			}
		}
		break;
	}
	cout << endl;
	cout << "\t  ------------------------------------------------------------" << endl;
	cout << "\t\t\t      1.Подтвердить изменения" << endl;
	cout << "\t\t\t      2.Ввести данные заново" << endl;
	cout << "\t\t\t         Esc.Выйти в меню" << endl;

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
			string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
			double currentBalance;
			string currentBan;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << currentLastName << " " << currentName << " " << currentLogin << " " << newPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiry << " " << currentCardCVV << " " << currentCardPassword << endl;
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
			currentUser << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
			currentUser.close();
			cout << "\t  ------------------------------------------------------------" << endl;
			cout << "\t\t\t      Пароль успешно изменен!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
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
	while (true) {
		cout << "\t\t\t       Введите новое имя: ";
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!newName.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				userCabinet();
				break;
			}
			else if (ch == '\b') {
				if (!newName.empty()) {
					cout << "\b \b";
					newName.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				newName += ch;
			}
		}
		break;
	}
	cout << endl;
	cout << "\t  ------------------------------------------------------------" << endl;
	cout << "\t\t\t     1.Подтвердить изменения" << endl;
	cout << "\t\t\t     2.Ввести данные заново" << endl;
	cout << "\t\t\t        Esc.Выйти в меню" << endl;
	
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

	int choice = _getch();
	switch (choice) {
	case '1':
		while (getline(fin, line)) {
			stringstream ss(line);
			string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
			double currentBalance;
			string currentBan;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << currentLastName << " " << newName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiry << " " << currentCardCVV << " " << currentCardPassword << endl;
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
			currentUser << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
			currentUser.close();
			cout << "\t  ------------------------------------------------------------" << endl;
			cout << "\t\t\t       Имя успешно изменен!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
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
	while (true) {
		cout << "\t\t\t     Введите новую фамилию: ";
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!newLastName.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				userCabinet();
				break;
			}
			else if (ch == '\b') {
				if (!newLastName.empty()) {
					cout << "\b \b";
					newLastName.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				newLastName += ch;
			}
		}
		break;
	}
	cout << endl;
	cout << "\t  ------------------------------------------------------------" << endl;
	cout << "\t\t\t     1.Подтвердить изменения" << endl;
	cout << "\t\t\t     2.Ввести данные заново" << endl;
	cout << "\t\t\t        Esc.Выйти в меню" << endl;

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
			string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiry, currentCardCVV, currentCardPassword;
			double currentBalance;
			string currentBan;

			ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiry >> currentCardCVV >> currentCardPassword;

			if (currentLogin == login && currentPassword == password) {
				fout << newLastName << " " << currentName << " " << currentLogin << " " << currentPassword << " " << currentBalance << " " << currentBan << " " << currentCardNumber << " " << currentCardExpiry << " " << currentCardCVV << " " << currentCardPassword << endl;
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
			currentUser << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword << endl;
			currentUser.close();
			cout << "\t  ------------------------------------------------------------" << endl;
			cout << "\t\t\t     Фамилия успешно изменена!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
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