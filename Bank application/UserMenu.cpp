#include "UserMenu.h"

void UserMenu()
{
	system("mode con cols=68 lines=33"); //Размер окна

	//Меню
	bank_logo();
	cout << endl;
	tab();tab(); cout << "	1.Счет" << endl;
	tab();tab(); cout << "	2.Конвертер валют" << endl;
	tab();tab(); cout << "	3.Кредит" << endl;
	tab();tab(); cout << "	4.Личный кабинет" << endl;
	tab();tab(); cout << "	Esc.Вернуться в меню";

	int choice;
	choice = _getch();

	bool work = true;
	while (work) {	
		switch (choice)
		{
		case '1':
			//Счет
			system("cls");
			userAccount();
			break;
		case '2':
			//Конвертер валют
			system("cls");
			currencyExchanger();
			break;
		case '3':
			//Кредит
			system("cls");
			Credit();
			break;
		case '4':
			//Личный кабинет
			system("cls");
			userCabinet();
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
