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
		cout << "\t\t\t\t1.Пополнить баланс" << endl;
		cout << "\t\t\t\t2.Завести карту" << endl;
		cout << "\t\t\t\t3.Моя карта" << endl;
		cout << "\t\t\t\t4.Перевести деньги" << endl;
		cout << "\t\t\t\tEsc.Вернуться в меню" << endl;

		int choice = _getch();
		switch (choice) {
		case '1':
			system("cls");
			currentUser.addBalance();
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
				cout << "\t\t\t    1.Изменить пароль карты" << endl;
				cout << "\t\t\t\t2.Удалить карту" << endl;
				cout << "\t\t\t\      Esc.Вернуться в меню" << endl;
				int choice = _getch();
				switch (choice) {
				case'1':
					system("cls");
					currentUser.changeCardPassword();
					system("cls");
					Balance();
					break;
				case'2':
					system("cls");
					int choice;
					center();cout << "------------------------------------------------------------" << endl;
					cout << "\t\t\t\t   Вы уверены?" << endl;
					cout << "\t\t\t\t   1.Да " << "2.Нет" << endl;
					tab();cout << "------------------------------------------------------------" << endl;
					choice = _getch();
					switch (choice) {
					case '1':
						system("cls");
						currentUser.deleteCard();
						system("cls");
						Balance();
						break;
					case '2':
						system("cls");
						Balance();
						break;
					}
				case 27:
					system("cls");
					Balance();
					break;
				}
			}
			break;
		}
		case '4':
			system("cls");
			currentUser.transferMoney();
			system("cls");
			Balance();
			break;
		case 27:
			system("cls");
			UserMenu();
			break;
		default:
			Balance();
			break;
		}
	}

}
