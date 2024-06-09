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
			//Изменение процентной ставки
			system("cls");
			ifstream fin("Credit.txt");
			string rate1, rate2, rate3;
			fin << rate1 << rate2 << rate3;
			cout << "Выберите какую кредитную ставку изменить: " << endl;
			cout << "1. От 1 до 3" << rate1 << "%" << endl;
			cout << "2. " << rate2 << "%" << endl;
			cout << "3. " << rate3 << "%" << endl;
			fin.close();

			ofstream fout("Cradit.txt", ios::app);

			int chocie = _getch();
			switch(choice) {
			case '1':
				system("cls");

				break;
			case '2':
				system("cls");

				break;
			case '3':
				system("cls");

				break;
			default:
				break;
			}

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
