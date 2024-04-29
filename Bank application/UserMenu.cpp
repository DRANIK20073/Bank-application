#include "UserMenu.h"

void UserMenu()
{
	cout << "1.Счет" << endl;
	cout << "2.Конвертер валют" << endl;
	cout << "3.Кредит" << endl;
	cout << "4.Личный кабинет" << endl;
	cout << "Esc. Вернуться в меню";

	int choice;
	choice = _getch();

	bool work = true;
	while (work) {	
		switch (choice)
		{
		case '1':
			//Счет
			break;
		case '2':
			//Конвертер валют
			system("cls");
			currencyExchanger();
			break;
		case '3':
			//Кредит
			break;
		case '4':
			//Личный кабинет
			break;
		case 27:
			system("cls");
			mainMenu();
			break;
		default:
			system("cls");
			cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 4." << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
