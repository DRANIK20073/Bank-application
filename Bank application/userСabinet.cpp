#include "userСabinet.h"

void userCabinet()
{
	Users currentUser;
	cout << "Добро пожаловать, " << currentUser.getName() << "." << endl;
	currentUser.showInformation();
	cout << endl;
	cout << "1.Изменить имя." << endl;
	cout << "2.Изменить пароль." << endl;
	cout << "Esc.Вернуться в меню.";

	int choice;
	choice = _getch();

	switch (choice) {
	case '1':
		system("cls");
		currentUser.changeName();
		break;
	case '2':
		system("cls");
		currentUser.changePassword();
		break;
	case 27:
		system("cls");
		UserMenu();
		break;
	default:
		system("cls");
		cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 2." << endl;
		Sleep(3000);
		system("cls");
		break;
	}
}
