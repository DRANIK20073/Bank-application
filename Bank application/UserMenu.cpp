#include "UserMenu.h"

void UserMenu()
{
	cout << "1.����" << endl;
	cout << "2.��������� �����" << endl;
	cout << "3.������" << endl;
	cout << "4.������ �������" << endl;
	cout << "Esc. ��������� � ����";

	int choice;
	choice = _getch();

	bool work = true;
	while (work) {	
		switch (choice)
		{
		case '1':
			//����
			system("cls");
			userAccount();
			break;
		case '2':
			//��������� �����
			system("cls");
			currencyExchanger();
			break;
		case '3':
			//������
			system("cls");
			Credit();
			break;
		case '4':
			//������ �������
			system("cls");
			userCabinet();
			break;
		case 27:
			system("cls");
			mainMenu();
			break;
		default:
			system("cls");
			cout << "�������� �����. ����������, �������� ����� �� 1 �� 4." << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
