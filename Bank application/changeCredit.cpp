#include "changeCredit.h"

void changeCredit()
{	
	system("mode con cols=68 lines=32");
	ifstream fin("Credit.txt");
	int rate1, rate2, rate3;
	fin >> rate1 >> rate2 >> rate3;
	fin.close();

	bank_logo();
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
		string rate1Str;
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!rate1Str.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				changeCredit();
				break;
			}
			else if (ch == '\b') {
				if (!rate1Str.empty()) {
					cout << "\b \b";
					rate1Str.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				rate1Str += ch;
			}
		}
		rate1 = stod(rate1Str);
		cout << endl;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		Sleep(300);
		break;
	}
	case '2': {
		system("cls");
		bank_logo();
		cout << "\t   ������� ����� �������� ������ ��� 3-5 ���: ";
		string rate2Str;
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!rate2Str.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				changeCredit();
				break;
			}
			else if (ch == '\b') {
				if (!rate2Str.empty()) {
					cout << "\b \b";
					rate2Str.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				rate2Str += ch;
			}
		}
		rate2 = stod(rate2Str);
		cout << endl;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		Sleep(300);
		break;
	}
	case '3': {
		system("cls");
		bank_logo();
		cout << "\t   ������� ����� �������� ������ ��� 6-9 ���: ";
		string rate3Str;
		while (true) {
			char ch = _getch();
			if (ch == '\r') {
				if (!rate3Str.empty()) {
					break;
				}
			}
			else if (ch == 27) {
				system("cls");
				changeCredit();
				break;
			}
			else if (ch == '\b') {
				if (!rate3Str.empty()) {
					cout << "\b \b";
					rate3Str.pop_back();
				}
			}
			else if (ch != '\n') {
				cout << ch;
				rate3Str += ch;
			}
		}
		rate3 = stod(rate3Str);
		cout << endl;
		cout << "\t       ���������� ������ ������� ���������." << endl;
		Sleep(300);
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
	system("cls");
}
