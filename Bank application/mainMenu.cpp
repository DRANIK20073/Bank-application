#include "mainMenu.h"

void mainMenu()
{
	//Объявление пременных
	bool work = true;
	Users newUser;

	//файл с данными пользователей
	ofstream user;
	user.open("Users.txt", ios::app);

	while (work) {
		cout << "1. Войти как пользователь." << endl;
		cout << "2. Войти как администратор." << endl;
		cout << "3. Зарегистрироваться." << endl;
		cout << "Esc. Выход";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//Логин как пользователь
			system("cls");
			if (newUser.loginUser() == true) {
				system("cls");
				cout << "Добро пожаловать!" << endl;
				Sleep(2000);
				system("cls");
				UserMenu();
			}
			else {
				system("cls");
				newUser.loginUser();
			}
			system("pause");
			system("cls");
			break;
		case '2':
			//Логин как администратор
			system("cls");
			break;
		case '3': {
			//Регистрация
			system("cls");
			newUser.information();
			newUser.registration();
			cout << "Регистрация завершена." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 27: {
			//выход из программы
			system("cls");
			cout << "Вы действительно хотите выйти?" << endl;
			cout << "Y.Да " << "N.Нет" << endl;
			int exitChoice;
			exitChoice = _getch();
			switch (exitChoice) {
			case 'Y':
			case 'y':
				user.close();
				exit(0);
			case 'N':
			case 'n':
				system("cls");
				break;
			default:
				system("cls");
				cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 2." << endl;
				Sleep(3000);
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 4." << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
