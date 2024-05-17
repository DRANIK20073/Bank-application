#include "mainMenu.h"

void mainMenu()
{
	//Объявление пременных
	bool login = false;
	bool work = true;
	Users newUser;

	while (work) {
		bank_logo();
		cout << endl; 
		tab();tab(); cout << "1.Войти как пользователь." << endl;
		tab();tab(); cout << "2.Войти как администратор." << endl;
		tab();tab(); cout << "3.Зарегистрироваться." << endl;
		tab();tab(); cout << "Esc.Выход";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//Логин как пользователь
			while (login == false) {
				system("cls");
				bank_logo();
				cout << endl;
				if (newUser.loginUser() == true) {
					ofstream fout("CurrentUser.txt");
					fout << newUser.getLastName() << " ";
					fout << newUser.getName() << " ";
					fout << newUser.getlogin() << " ";
					fout << newUser.getPassword() << " ";
					fout.close();

					login = true;
					system("cls");
					bank_logo();
					cout << endl;
					tab();tab(); cout << "     Добро пожаловать!" << endl;
					Sleep(2000);
					system("cls");
					UserMenu();
				}
				else {
					system("cls");
				}
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
			bank_logo();
			cout << endl;
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
			bank_logo();
			cout << endl;
			tab();tab();cout << "Вы действительно хотите выйти?" << endl;
			tab();tab();cout << "Y.Да " << "N.Нет" << endl;
			int exitChoice;
			exitChoice = _getch();
			switch (exitChoice) {
			case 'Y':
			case 'y':
				exit(0);
			case 'N':
			case 'n':
				system("cls");
				break;
			default:
				system("cls");
				bank_logo();
				cout << endl;
				tab();cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 2." << endl;
				Sleep(1000);
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			bank_logo();
			cout << endl;
			tab();cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 4." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}
