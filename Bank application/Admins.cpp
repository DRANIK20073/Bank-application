#include "Admins.h"

admins::admins()
{
}

bool admins::adminLogin()
{
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

			return true;
		}
	}

	userFile.close();
	system("cls");
	cout << "Неправильный логин или пароль, повторите попытку." << endl;
	Sleep(2000);
	return false;
}
