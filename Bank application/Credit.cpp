#include "Credit.h"

void case1() {
    system("cls");
    double sum;
    double annual_interest_rate;
    int credit_years;
    center();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       Введите сумму кредита в белорусских рублях: ";
    cin >> sum;
    tab();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       Выберите вариант годовой ставки.";
    ifstream credits("Credit.txt");
    double rate1, rate2;
    credits >> rate1 >> rate2;
    cout << " 1) " << rate1 << "%, 2) " << rate2 << "%." << endl;
    char annual_interest_rate_choice = _getch();
    switch (annual_interest_rate_choice) {
    case '1':
        annual_interest_rate = rate1;
        tab();cout << "       Вы выбрали " << rate1 << "%" << endl;
        break;
    case '2':
        annual_interest_rate = rate2;
        tab();cout << "       Вы выбрали " << rate2 << "%" << endl;
        break;
    default:
        tab();cout << "       Неверный выбор. Автоматически выбран вариант 1." << endl;
        annual_interest_rate = rate1;
        break;
    }
    tab();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       Введите срок кредита в годах: ";
    cin >> credit_years;
    int credit_months = credit_years * 12;
    tab();cout << "-------------------------[Результат]------------------------" << endl;
    double month_interest_rate = annual_interest_rate / 1200;
    double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
    tab();cout << "       Ежемесячный платеж по кредиту: " << month_payment << endl;
    //Выход
    tab();cout << "------------------------------------------------------------" << endl;

    tab();tab();cout << "       1.Взять кредит(В разработке)" << endl;
    tab();tab();cout << "       2.Вернуться в меню" << endl;
    char exitChoice = _getch();
    bool Work = true;
    while (Work) {
        switch (exitChoice) {
        case '1':
            //ДОПИСАТЬ!!!
        case '2':
            system("cls");
            Credit();
            break;
        default:
            cout << "Неправильный выбор попробуйте еще раз.";
            break;
        }
        break;
    }
}

void Credit() {
    //Проценты годовой ставки
    ofstream credit("Credit.txt");
    credit << 9 << endl << 16 << endl;
    credit.close();

    system("mode con cols=80 lines=30");
    //Меню
    center();cout << "---------------------------[Кредит]-------------------------" << endl;
    tab();tab();tab();cout << "  1.Начать" << endl;
    tab();tab();tab();cout << "  Esc.Вернуться в меню" << endl;
    tab();cout << "------------------------------------------------------------" << endl;

    int choice = _getch();
    switch (choice) {
    case '1':
        case1();
        break;
    case 27:
        UserMenu();
        break;
    }

}