#include "Balance.h"

void Balance()
{
	system("mode con cols=80 lines=26");
	Users currentUser;

	bool work = true;
	while (work) {
		center();cout << "---------------------------[Cчёт]---------------------------" << endl;
		cout << "\t\t\t\tБаланс: " << currentUser.getBalance() << " BYN" << endl;
		tab();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t\t 1.Пополнить баланс" << endl;
		cout << "\t\t\t\t 2.Завести карту" << endl;
		cout << "\t\t\t\t 3.Моя карта" << endl;
		cout << "\t\t\t\t 4.Перевести деньги" << endl;
		cout << "\t\t\t\t Esc.Вернуться в меню" << endl;

		int choice = _getch();
		switch (choice) {
		case '1':
			system("cls");
			double num;
			cout << "Введите сумму: ";
			cin >> num;
			currentUser.addBalance(num);
			system("cls");
			Balance();
			break;
		case '2':
			system("cls");
			currentUser.addCard();
			system("cls");
			Balance();
			break;
		case '3': {
			system("cls");
			currentUser.loadUserInformation();
			if (currentUser.displayCard() == false) {
				Balance();
			}
			else {
				currentUser.displayCard();
				cout << "1.Изменить пароль карты." << endl;
				cout << "2.Удалить карту" << endl;
				cout << "Esc.Вернуться в меню" << endl;
				int choice = _getch();
				switch (choice) {
				case'1':
					system("cls");
					currentUser.changeCardPassword();
					break;
				case'2':
					system("cls");
					currentUser.deleteCard();
					break;
				case 27:
					system("cls");
					Balance();
					break;
				}
				system("cls");
				break;
			}
		}
		case '4':
			system("cls");
			break;
		case 27:
			system("cls");
			UserMenu();
			break;
		}
	}
}
