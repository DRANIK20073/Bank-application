#include "Balance.h"

void Balance()
{
	system("mode con cols=80 lines=26");
	Users currentUser;

	bool work = true;
	while (work) {
		center();cout << "---------------------------[C���]---------------------------" << endl;
		cout << "\t\t\t\t������: " << currentUser.getBalance() << " BYN" << endl;
		tab();cout << "------------------------------------------------------------" << endl;
		cout << "\t\t\t\t1.��������� ������" << endl;
		cout << "\t\t\t\t2.������� �����" << endl;
		cout << "\t\t\t\t3.��� �����" << endl;
		cout << "\t\t\t\t4.��������� ������" << endl;
		cout << "\t\t\t\tEsc.��������� � ����" << endl;

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
				cout << "\t\t\t    1.�������� ������ �����" << endl;
				cout << "\t\t\t\t2.������� �����" << endl;
				cout << "\t\t\t\      Esc.��������� � ����" << endl;
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
					cout << "\t\t\t\t   �� �������?" << endl;
					cout << "\t\t\t\t   1.�� " << "2.���" << endl;
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
