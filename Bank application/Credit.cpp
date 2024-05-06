#include "Credit.h"

double annuity_credit(double sum, double annual_interest_rate, double credit_months) {
	double month_interest_rate = annual_interest_rate / 1200;
	double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), credit_months));
	return month_payment;
}

void Credit()
{
	ofstream credit("Credit.txt");
	credit << 9 << endl << 12 << endl;
	credit.close();

	double sum;
	double annual_interest_rate;
	int credit_years;

	cout << "Введите сумму кредита в белорусских рублях: ";
	cin >> sum;

	cout << "Наш банк может предложить вам два варианта годовой ставки." << endl;
	ifstream credits("Credit.txt");
	double rate1, rate2;
	credits >> rate1;
	credits >> rate2;
	cout << "Выберите один из вариантов: " << "1)" << rate1 << "%, " << "2)" << rate2 << "%." << endl;
	int annual_interest_rate_choice = _getch();
	switch (annual_interest_rate_choice) {
	case '1':
		annual_interest_rate = rate1 / 100;
		break;
	case '2':
		annual_interest_rate = rate2 / 100;
		break;
	}

	cout << "Ввведите срок кредита в годах: ";
	cin >> credit_years;
	int credit_months = credit_years * 12;

	double month_payment = annuity_credit(sum, annual_interest_rate, credit_months);
	cout << "ежемесячный платеж по кредиту: " << month_payment << endl << endl;

	cout << "Желаете продолжить?" << endl;
	cout << "Y.Да " << "N.Нет" << endl;
	int exitChoice;
	exitChoice = _getch();
	switch (exitChoice) {
	case 'Y':
	case 'y':
		system("cls");
		Credit();
		break;
	case 'N':
	case 'n':
		system("cls");
		UserMenu();
		break;
	default:
		cout << "Неверный выбор. Пожалуйста, выберите Да или Нет." << endl;
		Sleep(3000);
		system("cls");
		break;
	}
}