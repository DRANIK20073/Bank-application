#include "userСabinet.h"

void userCabinet()
{
	system("mode con cols=80 lines=26");
	Users currentUser;
	center();cout << "----------------------[Личный кабинет]----------------------" << endl;
	currentUser.showInformation();
	tab();cout << "------------------------------------------------------------" << endl;
	tab();tab();cout << "\t\t1.Изменить имя." << endl;
	tab();tab();cout << "\t\t2.Изменить фамилию." << endl;
	tab();tab();cout << "\t\t3.Изменить пароль." << endl;
	tab();tab();cout << "\t\tEsc.Вернуться в меню.";

	int choice;
	choice = _getch();

	switch (choice) {
	case '1':
		system("cls");
		currentUser.changeName();
		break;
	case '2':
		system("cls");
		currentUser.changeLastName();
		break;
	case '3':
		system("cls");
		currentUser.changePassword();
		break;
	case 27:
		system("cls");
		UserMenu();
		break;
	default:
		system("cls");
		center();cout << "------------------------------------------------------------" << endl;
		tab();cout << "  Неверный выбор. Пожалуйста, выберите опцию от 1 до 3." << endl;
		tab();cout << "------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		break;
	}
}
