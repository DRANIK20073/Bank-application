#include "UserMenu.h"

void UserMenu()
{
	system("mode con cols=68 lines=33"); //������ ����

	//����
	bank_logo();
	cout << endl;
	tab();tab(); cout << "	1.����" << endl;
	tab();tab(); cout << "	2.��������� �����" << endl;
	tab();tab(); cout << "	3.������" << endl;
	tab();tab(); cout << "	4.������ �������" << endl;
	tab();tab(); cout << "	Esc.��������� � ����";

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
