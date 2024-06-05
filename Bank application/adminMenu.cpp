#include "adminMenu.h"

void adminMenu()
{
	bool work = true;
	while (work) {
		bank_logo();
		cout << endl;
		cout << "1.Изменить процентную ставку" << endl;
		cout << "2.Пользователи" << endl;
		cout << "3.Поддержка пользователей" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			system("cls");

			ofstream fout("Cradit.txt", ios::app);


			break;
		}
		case '2':
			system("cls");

			break;
		case '3':
			system("cls");

			break;
		default:
			break;
		}

	}
}
