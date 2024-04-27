#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class User {
	string lastName;
	string name;
	string login;
	string password;

public:
	User() {}

	void information() {
		cout << "Фамимлия: ";
		cin >> lastName;
		cout << "Имя: ";
		cin >> name;
		cout << "Логин: ";
		cin >> login;
		cout << "Пароль: ";
		cin >> password;
	}

	void registration() {
		ofstream user;
		user << lastName << " " << name << " " << login << " " << password << endl;
	}
};

int main() {
	//Локализация
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Объявление пременных
	string lastName, name, login, password;
	bool work = true;

	//файл с данными пользователей
	ofstream user;
	user.open("Users.txt", ios::app);

	while (work) {
		cout << "1. Войти как пользователь." << endl;
		cout << "2. Войти как администратор." << endl;
		cout << "3. Зарегистрироваться." << endl;
		cout << "4. Выйти из программы." << endl;

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//Логин как пользователь
			system("cls");
			break;
		case '2':
			//Логин как администратор
			system("cls");
			break;
		case '3': {
			//Регистрация
			system("cls");
			User newUser;
			newUser.information();
			newUser.registration();
			cout << "Регистрация завершена." << endl;
			system("pause");
			system("cls");
			break;
		}
		case '4': {
			//выход из программы
			system("cls");
			cout << "Вы действительно хотите выйти?" << endl;
			cout << "1.Да " << "2.Нет" << endl;
			int exitChoice;
			exitChoice = _getch();
			switch (exitChoice) {
			case '1':
				user.close();
				exit(0);
			case '2':
				system("cls");
				break;
			default:
				system("cls");
				cout << "Неверный выбор. Пожалуйста, выберите опицю от 1 до 2." << endl;
				system("pause");
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			cout << "Неверный выбор. Пожалуйста, выберите опцию от 1 до 4." << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
