#include "currencyExchager.h"

void currencyExchanger()
{
	//Курсы валют
	//USD
	double USD[4]{ 1, 3.22, 0.93, 92.5 }; //$, bel rub, euro, rus rub.
	//BYN
	double BYN[4]{ 0.32, 1, 0.28, 27.79 }; //$, bel rub, euro, rus rub.
	//EUR
	double EUR[4]{ 1.09, 3.52, 1, 99.5 }; //$, bel rub, euro, rus rub.
	//RUB
	double RUB[4]{ 0.011, 0.036, 0.01, 1 }; //$, bel rub, euro, rus rub.

	bool work = true;
	while (work) {

		//Выбор валюты которую надо перевести
		cout << "Выберите валюту которую нужно перевести:" << endl;
		cout << "1.USD" << endl << "2.BYN" << endl << "3.EUR" << endl << "4.RUB" << endl;
		int old_currency_choice;
		old_currency_choice = _getch();
		switch (old_currency_choice) {
		case '1':
			old_currency_choice = 1;
		case '2':
			old_currency_choice = 2;
		case '3':
			old_currency_choice = 3;
		case '4':
			old_currency_choice = 4;
		}

		//Выбор валюты для перевода
		cout << "Выберите в какую валюту нужно перевести:" << endl;
		cout << "1.USD" << endl << "2.BYN" << endl << "3.EUR" << endl << "4.RUB" << endl;
		int new_currency_choice;
		new_currency_choice = _getch();
		switch (new_currency_choice) {
		case '1':
			new_currency_choice = 1;
		case '2':
			new_currency_choice = 2;
		case '3':
			new_currency_choice = 3;
		case '4':
			new_currency_choice = 4;
		}

		//Нахождение нужного курса
		string old_kind_of_currency = "";
		double rate = 0;
		for (int i = 0; i < old_currency_choice; i++) {
			//USD
			if (old_currency_choice == 1) {
				rate = USD[new_currency_choice - 1];
				old_kind_of_currency = "долларов США";
			}
			//BYN
			if (old_currency_choice == 2) {
				rate = BYN[new_currency_choice - 1];
				old_kind_of_currency = "белорусских рублей";
			}
			//EUR
			if (old_currency_choice == 3) {
				rate = EUR[new_currency_choice - 1];
				old_kind_of_currency = "евро";
			}
			//RUB
			if (old_currency_choice == 4) {
				rate = RUB[new_currency_choice - 1];
				old_kind_of_currency = "российских рублей";
			}
		}

		//Тип выводимой валюты
		string kinds[4]{ "Долларов США.", "Белорусских рублей.", "Евро.", "Российских рублей." };
		string new_kind_of_currency = "";
		for (int i = 0; i < new_currency_choice; i++) {
			new_kind_of_currency = kinds[new_currency_choice - 1];
		}

		//Ввод количества обмениваемой валюты
		cout << "Введите количество " << old_kind_of_currency << ", которое хотите обменять : ";
		double amount_old_value = 0; 
		cin >> amount_old_value;

		//Перевод валюты
		double value = 0;
		value = amount_old_value * rate;
		cout << "Результат перевода: " << value << " " << new_kind_of_currency << endl;

		//Выход в меню 
		cout << endl << "Хотите продолжить?" << endl;
		cout << "Y.Да. " << "N.Нет." << endl;
		int choice;
		choice = _getch();
		switch (choice) {
		case 'Y':
		case 'y':
			system("cls");
			continue;
			break;
		case 'N':
		case 'n':
			system("cls");
			UserMenu();
		default:
			cout << "Неверный выбор. Пожалуйста, выберите Да или Нет." << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
