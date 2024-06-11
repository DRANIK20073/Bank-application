#include "adminMenu.h"

void adminMenu()
{
	bool work = true;
	while (work) {
		bank_logo();
		cout << endl;
		cout << "\t\t    1.Изменить процентную ставку" << endl;
		cout << "\t\t    2.Поддержка пользователей" << endl;
		cout << "\t\t    3.Пользователи" << endl;
		cout << "\t\t    Esc.Выйти в главное меню" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			// Изменение процентной ставки
			system("cls");
			bank_logo();
			changeCredit();
			Sleep(500);
			break;
		}
		case '2':
			//Поддержка
			system("cls");
			Sleep(500);
			break;
		case '3':
			//Управление пользователями
			system("cls");
			usersManagement();
			break;
		case 27:
			system("cls");
			mainMenu();
			return;
		default:
			system("cls");
			cout << "Неверный выбор." << endl;
			Sleep(800);
			break;
		}
	}
}
