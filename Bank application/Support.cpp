#include "Support.h"

void Support()
{
	bool work = true;

	while (work) {
		bank_logo();
		cout << "1. Обратиться в поддержку" << endl;
		cout << "Esc. Выйти в меню" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			system("cls");
			bank_logo();

			ifstream fin("CurrentUser.txt");

			string lastName, name, login, password, cardNumber, cardExpiration, cardCVV, cardPassword;
			double balance;
			fin >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
			fin.close();

			cout << "Введите ваше обращение в поддержку" << endl;
			cin.ignore();
			string question;
			getline(cin, question);

			ofstream fout("questions.txt", ios::app);

			fout << login << " " << question;

			fout.close();

			system("cls");
			cout << endl;
			bank_logo();
			cout << "Ваше обращение отправлено!" << endl;
			Sleep(500);
			system("cls");
			break;
		}

		case 27:
			work = false;
			UserMenu();
			break;

		default:
			system("cls");
			break;
		}
	}
}
