#include "changeCredit.h"

void changeCredit()
{
	ifstream fin("Credit.txt");
	int rate1, rate2, rate3;
	fin >> rate1 >> rate2 >> rate3;
	fin.close();

	cout << "\t     �������� ����� ��������� ������ ��������: " << endl;
	cout << "\t\t\t1.��� 1-2 ���: " << rate1 << "%" << endl;
	cout << "\t\t\t2.��� 3-5 ���: " << rate2 << "%" << endl;
	cout << "\t\t\t3.��� 6-9 ���: " << rate3 << "%" << endl;
	cout << "\t\t\tEsc.����� � ����" << endl;

	int choice = _getch();
	switch (choice) {
	case '1': {
		system("cls");
		bank_logo();
		cout << "\t   ������� ����� �������� ������ ��� 1-2 ���: ";
		cin >> rate1;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		break;
	}
	case '2': {
		system("cls");
		bank_logo();
		cout << "\t   ������� ����� �������� ������ ��� 3-5 ���: ";
		cin >> rate2;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		break;
	}
	case '3': {
		system("cls");
		bank_logo();
		cout << "\t   ������� ����� �������� ������ ��� 6-9 ���: ";
		cin >> rate3;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		break;
	}
	case 27:
		system("cls");
		adminMenu();
		break;
	default:
		break;
	}

	ofstream fout("temp.txt");
	fout << rate1 << endl << rate2 << endl << rate3;
	fout.close();
	remove("Credit.txt");
	rename("temp.txt", "Credit.txt");

}
