#include "Users.h"
#include "Header.h"

Users::Users()
{
}

//��������� ��������� �����
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

//�����������
void Users::registration() {
	cout << "\t   �������: ";
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
	cout << "\t   ���: ";
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
	cout << "\t   �����(�� ����� 5 ��������): ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (login.length() >= 5) {
				break;
			}
			else {
				system("cls");
				bank_logo();
				cout << "\n    ����� ������ ��������� �� ����� 5 ��������. ��������� ����." << endl;
				Sleep(1000);
				system("cls");
				bank_logo();
				login = "";
				cout << "\t   ����� (�� ����� 5 ��������): ";
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
	cout << "\t   ������(�� ����� 8 ��������): ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			if (password.length() >= 8) {
				break;
			}
			else {
				system("cls");
				bank_logo();
				cout << "\n    ������ ������ ��������� �� ����� 8 ��������. ��������� ����." << endl;
				Sleep(1000);
				system("cls");
				bank_logo();
				password = "";
				cout << "\t   ������ (�� ����� 8 ��������): ";
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
			cout << "������������ � ����� ������� ��� ����������.";
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
	cout << "\t\t   �� ������� ������������������.";
	Sleep(1500);
	system("cls");
	mainMenu();
}

//�����
bool Users::loginUser() {
	string loginInput;
	string passwordInput;
	tab();tab(); cout << "\t    �����: ";
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
	tab();tab(); cout << "\t    ������: ";
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
					cout << "\t  ��� ������� ������������, ���������� � ���������" << endl << "\t\t\t  ��������� �����";
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
	cout << "������������ ����� ��� ������, ��������� �������." << endl;
	Sleep(2000);
	return false;
}

//������ ������������
void Users::showInformation() {
	ifstream fin("CurrentUser.txt");
	string line;

	while (getline(fin, line)) {
		stringstream ss(line);
		ss >> lastName >> name >> login >> password;
	}

	fin.close();

	cout << "\t\t\t          �������: " << lastName << endl;
	cout << "\t\t\t          ���: " << name << endl;
	cout << "\t\t\t          �����: " << login << endl;
	cout << "\t\t\t          ������: " << password << endl;
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

//������ �����
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

//�������� ������
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

//��������� ������
void Users::addBalance()
{

	// ���������� Users.txt
	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;

	double num = 0;
	string numStr = to_string(num);
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t         ������� �����: ";
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
		cout << endl << "\t\t\t      ������ ������� ��������." << endl;
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

	// ���������� CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	currentUserFile << lastName << " " << name << " " << login << " " << password << " " << balance << " " << ban << " " << cardNumber << " " << cardExpiration << " " << cardCVV << " " << cardPassword;
	currentUserFile.close();
}

bool isDigitsOnly(const string& str) {
	return all_of(str.begin(), str.end(), ::isdigit);
}

//������� �����
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
		cout << "\t\t� ��� ��� ���� �����, ���������� ������� �����." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(1500);
		Balance();
	}

	//����� �����
	cardNumber = generateRandomString(16);

	//C��� ��������
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

	//������
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t      ������� ������ ��� ����� (4 �����): ";
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
			cout << "\t\t      ������ ������ �������� ����� �� 4 ����." << endl;
			Sleep(1500);
			system("cls");
		}
		else if (!isDigitsOnly(cardPassword)) {
			cout << endl;
			cout << "\t\t      � ������ �� ������ �������������� �����." << endl;
			Sleep(1500);
			system("cls");
		}
		else {
			cout << endl << "\t\t\t      ����� ������� �������." << endl;
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

//��� �����
bool Users::displayCard()
{	
	string CardNumber = cardNumber;
	string CardExpiration = cardExpiration;
	string CardCVV = cardCVV;

	if (CardNumber.empty()) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t    � ��� ��� �������� �����." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(800);
		return false;
	}
	else {
		cout << "\n\n\n\n\n";
		cout << "\t\t       **********************************" << endl;
		cout << "\t\t       * ���������                      *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       * " << CardNumber << "               *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       * " << CardExpiration << "                      " << CardCVV << " *" << endl;
		cout << "\t\t       *                                *" << endl;
		cout << "\t\t       **********************************" << endl;
	}
}

//��������� ������ �� ����� ������� ������������
void Users::transferMoney() {

	string anotherUserCard;
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t   ������� ����� ����� ������� ������������: ";
		anotherUserCard.clear();
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (anotherUserCard.length() != 16 || !isDigitsOnly(anotherUserCard)) {
					cout << endl;
					cout << "\t\t     ����� ����� ������ �������� �� 16 ����." << endl;
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

	// ������ �������� ������������
	ifstream currentFin("CurrentUser.txt");
	if (!currentFin.is_open()) {
		cerr << "������ ��� �������� ����� CurrentUser.txt." << endl;
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

	// �������� ��������� �����
	string transferAmountStr;
	while (true) {
		cout << endl << "\t\t\t          ������� �����: ";
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
		cout << endl << "\t\t     ������������ ������� �� �����." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(800);
		transferMoney();
	}

	// ���������� Users.txt
	ifstream fin("Users.txt");
	if (!fin.is_open()) {
		cerr << "������ ��� �������� ����� Users.txt." << endl;
		return;
	}

	ofstream fout("temp.txt");
	if (!fout.is_open()) {
		cerr << "������ ��� �������� ����� temp.txt." << endl;
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
		cerr << endl << "\t         ������������ � ��������� ������� ����� �� ������." << endl;
		cout << "\t  ------------------------------------------------------------" << endl;
		Sleep(1000);
		remove("temp.txt");
		system("cls");
		transferMoney();
		return;
	}

	if (remove("Users.txt") != 0) {
		cerr << "������ ��� �������� ����� Users.txt." << endl;
		return;
	}
	if (rename("temp.txt", "Users.txt") != 0) {
		cerr << "������ ��� �������������� ����� temp.txt � Users.txt." << endl;
		return;
	}

	// ���������� CurrentUser.txt
	ofstream currentUserFile("CurrentUser.txt");
	if (!currentUserFile.is_open()) {
		cerr << "������ ��� �������� ����� CurrentUser.txt." << endl;
		return;
	}

	currentUserFile << currentUserLastName << " " << currentUserName << " " << currentUserLogin << " " << currentUserPassword << " " << currentUserBalance << " " << currentUserBan << " " << currentUserCardNumber << " " << currentUserCardExpiration << " " << currentUserCardCVV << " " << currentUserCardPassword;
	currentUserFile.close();

	cout << endl << "\t\t\t     ������ ������� ����������!" << endl;
	cout << "\t  ------------------------------------------------------------" << endl;
	Sleep(800);
	system("cls");
	Balance();
}

//�������� ������ �����
void Users::changeCardPassword() {

	string newCardPassword;
	while (true) {
		center();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t ������� ����� ������ ��� ����� (4 �����): ";
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
			cout << "\t\t      ������ ������ �������� ����� �� 4 ����." << endl;
			Sleep(1500);
			system("cls");
		}
		else if (!isDigitsOnly(newCardPassword)) {
			cout << endl;
			cout << "\t\t      � ������ �� ������ �������������� �����." << endl;
			Sleep(1500);
			system("cls");
		}
		else {
			cout << endl;
			cout << "\t\t         ������ ����� ������� �������!" << endl;
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

//������� �����
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
	cout << "\t\t\t      ����� ������� �������!" << endl;
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

//��� ��������� ������ ������������ UserCabinet
void Users::changePassword()
{	
	center();cout << "------------------------------------------------------------" << endl;
	string newPassword;
	while (true) {
		cout << "\t\t\t      ������� ����� ������: ";
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
	cout << "\t\t\t      1.����������� ���������" << endl;
	cout << "\t\t\t      2.������ ������ ������" << endl;
	cout << "\t\t\t         Esc.����� � ����" << endl;

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
			cout << "\t\t\t      ������ ������� �������!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
			Sleep(1000);
		}
		else {
			cout << "������������ �� ������." << endl;
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

//��� ��������� ������ ������������ UserCabinet
void Users::changeName()
{
	center();cout << "------------------------------------------------------------" << endl;
	string newName;
	while (true) {
		cout << "\t\t\t       ������� ����� ���: ";
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
	cout << "\t\t\t     1.����������� ���������" << endl;
	cout << "\t\t\t     2.������ ������ ������" << endl;
	cout << "\t\t\t        Esc.����� � ����" << endl;
	
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
			cout << "\t\t\t       ��� ������� �������!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
			Sleep(1000);
		}
		else {
			cout << "������������ �� ������." << endl;
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

//��� ��������� ������ ������������ UserCabinet
void Users::changeLastName()
{
	center();cout << "------------------------------------------------------------" << endl;
	string newLastName;
	while (true) {
		cout << "\t\t\t     ������� ����� �������: ";
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
	cout << "\t\t\t     1.����������� ���������" << endl;
	cout << "\t\t\t     2.������ ������ ������" << endl;
	cout << "\t\t\t        Esc.����� � ����" << endl;

	ifstream fin("Users.txt");
	ofstream fout("temp.txt");
	string line;
	bool userFound = false;

	//������������� ���������
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
			cout << "\t\t\t     ������� ������� ��������!" << endl;
			cout << "\t  ------------------------------------------------------------" << endl;
			Sleep(1000);
		}
		else {
			cout << "������������ �� ������." << endl;
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