#include "user�abinet.h"

void userCabinet()
{
	system("mode con cols=80 lines=26");
	Users currentUser;
	center();cout << "----------------------[������ �������]----------------------" << endl;
	currentUser.showInformation();
	tab();cout << "------------------------------------------------------------" << endl;
	tab();tab();cout << "\t\t1.�������� ���." << endl;
	tab();tab();cout << "\t\t2.�������� �������." << endl;
	tab();tab();cout << "\t\t3.�������� ������." << endl;
	tab();tab();cout << "\t\tEsc.��������� � ����.";

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
		tab();cout << "  �������� �����. ����������, �������� ����� �� 1 �� 3." << endl;
		tab();cout << "------------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		break;
	}
}
