#include "adminMenu.h"

void adminMenu()
{
	bool work = true;
	while (work) {
		bank_logo();
		cout << endl;
		cout << "1.�������� ���������� ������" << endl;
		cout << "2.������������" << endl;
		cout << "3.��������� �������������" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			//��������� ���������� ������
			system("cls");
			ifstream fin("Credit.txt");
			string rate1, rate2, rate3;
			fin << rate1 << rate2 << rate3;
			cout << "�������� ����� ��������� ������ ��������: " << endl;
			cout << "1. �� 1 �� 3" << rate1 << "%" << endl;
			cout << "2. " << rate2 << "%" << endl;
			cout << "3. " << rate3 << "%" << endl;
			fin.close();

			ofstream fout("Cradit.txt", ios::app);

			int chocie = _getch();
			switch(choice) {
			case '1':
				system("cls");

				break;
			case '2':
				system("cls");

				break;
			case '3':
				system("cls");

				break;
			default:
				break;
			}

			break;
		}
		case '2':
			system("cls");

			break;
		case '3':
			system("cls");

			break;
		default:
			break;
		}

	}
}
