#include "adminMenu.h"

void adminMenu()
{
	bool work = true;
	while (work) {
		bank_logo();
		cout << endl;
		cout << "\t\t    1.�������� ���������� ������" << endl;
		cout << "\t\t    2.��������� �������������" << endl;
		cout << "\t\t    3.������������" << endl;
		cout << "\t\t    Esc.����� � ������� ����" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			// ��������� ���������� ������
			system("cls");
			bank_logo();
			changeCredit();
			Sleep(500);
			break;
		}
		case '2':
			//���������
			system("cls");
			Sleep(500);
			break;
		case '3':
			//���������� ��������������
			system("cls");
			usersManagement();
			break;
		case 27:
			system("cls");
			mainMenu();
			return;
		default:
			system("cls");
			cout << "�������� �����." << endl;
			Sleep(800);
			break;
		}
	}
}
