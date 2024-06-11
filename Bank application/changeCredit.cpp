#include "changeCredit.h"

void changeCredit()
{
	ifstream fin("Credit.txt");
	int rate1, rate2, rate3;
	fin >> rate1 >> rate2 >> rate3;
	fin.close();

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
		cin >> rate1;
		cout << "\t       Процентная ставка успешно обновлена." << endl;
		break;
	}
	case '2': {
		system("cls");
		bank_logo();
		cout << "\t   Введите новое значение ставки при 3-5 лет: ";
		cin >> rate2;
		cout << "\t       Процентная ставка успешно обновлена." << endl;
		break;
	}
	case '3': {
		system("cls");
		bank_logo();
		cout << "\t   Введите новое значение ставки при 6-9 лет: ";
		cin >> rate3;
		cout << "\t       Процентная ставка успешно обновлена." << endl;
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
