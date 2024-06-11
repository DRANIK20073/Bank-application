#include "Credit.h"

void Credit() {
    //Проценты годовой ставки
    ofstream credit("Credit.txt");
    credit << 9 << endl << 16 << endl;
    credit.close();

    system("mode con cols=80 lines=20");
    //Меню
    center();cout << "---------------------------[Кредит]-------------------------" << endl;
    tab();tab();tab();cout << "  1.Начать" << endl;
    tab();tab();tab();cout << "  Esc.Выйти в меню" << endl;
    tab();cout << "------------------------------------------------------------" << endl;

    int choice = _getch();
    switch (choice) {
    case '1': {
        system("mode con cols=80 lines=28");
        system("cls");
        double sum;
        double annual_interest_rate;
        int credit_years;
        center();cout << "------------------------------------------------------------" << endl;
        tab();cout << "       Введите сумму кредита в белорусских рублях: ";
        cin >> sum;
        tab();cout << "------------------------------------------------------------" << endl;
        tab();cout << "       В зависимости от длительности кредита процентаня ставка будет равна" << endl;
        ifstream credits("Credit.txt");
        double rate1, rate2, rate3;
        credits >> rate1 >> rate2 >> rate3;
        cout << "При 1 - 2 г.: " << rate1 << "%; При 3 - 5 л.:" << rate2 << "%; При 6 - 9 л.:" << rate3 << "%" << endl;
        tab();cout << "------------------------------------------------------------" << endl;
        bool work = true;
        while (work) {
            tab();cout << "       Введите срок кредита в годах: ";
            cin >> credit_years;
            if (credit_years == 1 || credit_years == 2) {
                annual_interest_rate = rate1;
                work = false;
            }
            else if (credit_years == 3 || credit_years == 4 || credit_years == 5) {
                annual_interest_rate = rate2;
                work = false;
            }
            else if (credit_years == 6 || credit_years == 7 || credit_years == 8 || credit_years == 9) {
                annual_interest_rate = rate3;
                work = false;
            }
            else {
                cout << "\t\tКредит возможно взять максимум на 9 лет." << endl;
            }
        }
        int credit_months = credit_years * 12;
        tab();cout << "-------------------------[Результат]------------------------" << endl;
        double month_interest_rate = annual_interest_rate / 1200;
        double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
        tab();cout << "       Ежемесячный платеж по кредиту: " << month_payment << endl;
        //Выход
        tab();cout << "------------------------------------------------------------" << endl;

        tab();tab();cout << "       1.Взять кредит(В разработке)" << endl;
        tab();tab();cout << "       Esc.Вернуться в меню" << endl;
        char exitChoice = _getch();
        bool Work = true;
        while (Work) {
            switch (exitChoice) {
            case '1':
                //ДОПИСАТЬ!!!
            case 27:
                system("cls");
                Credit();
                break;
            default:
                cout << "Неправильный выбор попробуйте еще раз.";
                break;
            }
            break;
        }
        break;
    }
    case 27:
        UserMenu();
        break;
    }

}