#include "adminMenu.h"

void adminMenu()
{
	bool work = true;
	while (work) {
		bank_logo();
		cout << endl;
		cout << "1.�������� ���������� ������" << endl;
		cout << "2.������������" << endl;
		cout << "3.��������� �������������" << endl;

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
