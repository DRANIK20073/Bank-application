#include "user�abinet.h"

void userCabinet()
{
	Users currentUser;
	cout << "����� ����������, " << currentUser.getName() << "." << endl;
	currentUser.showInformation();
	cout << endl;
	cout << "1.�������� ���." << endl;
	cout << "2.�������� ������." << endl;
	cout << "Esc.��������� � ����.";

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
		cout << "�������� �����. ����������, �������� ����� �� 1 �� 2." << endl;
		Sleep(3000);
		system("cls");
		break;
	}
}
