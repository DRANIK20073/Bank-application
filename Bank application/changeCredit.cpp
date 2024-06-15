#include "changeCredit.h"

void changeCredit()
{	
	system("mode con cols=68 lines=32");
	ifstream fin("Credit.txt");
	int rate1, rate2, rate3;
	fin >> rate1 >> rate2 >> rate3;
	fin.close();

	bank_logo();
	cout << "\t     Выберите какую кредитную ставку изменить: " << endl;
	cout << "\t\t\t1.При 1-2 лет: " << rate1 << "%" << endl;
	cout << "\t\t\t2.При 3-5 лет: " << rate2 << "%" << endl;
	cout << "\t\t\t3.При 6-9 лет: " << rate3 << "%" << endl;
	cout << "\t\t\tEsc.Выйти в меню" << endl;

	int choice = _getch();
	switch (choice) {
	case '1': {
		system("cls");
		bank_logo();
		cout << "\t   Введите новое значение ставки при 1-2 лет: ";
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
		cout << "\t       Процентная ставка успешно обновлена." << endl;
		Sleep(300);
		break;
	}
	case '2': {
		system("cls");
		bank_logo();
		cout << "\t   Введите новое значение ставки при 3-5 лет: ";
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
		cout << "\t       Процентная ставка успешно обновлена." << endl;
		Sleep(300);
		break;
	}
	case '3': {
		system("cls");
		bank_logo();
		cout << "\t   Введите новое значение ставки при 6-9 лет: ";
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
		cout << "\t       Процентная ставка успешно обновлена." << endl;
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
