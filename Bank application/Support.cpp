#include "Support.h"

void Support()
{
	bool work = true;

	while (work) {
		bank_logo();
		cout << "1. ���������� � ���������" << endl;
		cout << "Esc. ����� � ����" << endl;

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

			cout << "������� ���� ��������� � ���������" << endl;
			cin.ignore();
			string question;
			getline(cin, question);

			ofstream fout("questions.txt", ios::app);

			fout << login << " " << question;

			fout.close();

			system("cls");
			cout << endl;
			bank_logo();
			cout << "���� ��������� ����������!" << endl;
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
