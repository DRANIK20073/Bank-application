#include "Credit.h"

void Credit() {
    system("mode con cols=80 lines=20");
    //Меню
    center();cout << "---------------------------[Кредит]-------------------------" << endl;
    cout << "\t\t\t\t     1.Начать" << endl;
    cout << "\t\t\t\t Esc.Выйти в меню" << endl;
    cout << "\t ------------------------------------------------------------" << endl;

    int choice = _getch();
    switch (choice) {
    case '1': {
        system("mode con cols=80 lines=28");
        system("cls");
        double sum;
        double annual_interest_rate;
        int credit_years;

        string sumStr;
        while (true) {
            center();cout << "------------------------------------------------------------" << endl;
            tab();cout << "       Введите сумму кредита в белорусских рублях: ";
            sumStr.clear();
            while (true) {
                char ch = _getch();
                if (ch == '\r') {
                    if (!sumStr.empty()) {
                        break;
                    }
                }
                else if (ch == 27) {
                    system("cls");
                    Credit();
                    break;
                }
                else if (ch == '\b') {
                    if (!sumStr.empty()) {
                        cout << "\b \b";
                        sumStr.pop_back();
                    }
                }
                else if (ch != '\n') {
                    cout << ch;
                    sumStr += ch;
                }
            }
            break;
        }
        cout << endl;
        sum = stod(sumStr);

        cout << "\t  ------------------------------------------------------------" << endl;
        cout << "       В зависимости от длительности кредита процентаня ставка будет равна" << endl;
        ifstream credits("Credit.txt");
        double rate1, rate2, rate3;
        credits >> rate1 >> rate2 >> rate3;
        cout << "\t       При 1 - 2 г.: " << rate1 << "%; При 3 - 5 л.:" << rate2 << "%; При 6 - 9 л.:" << rate3 << "%" << endl;
        tab();cout << "------------------------------------------------------------" << endl;
        bool work = true;
        string creditYearsStr;
        while (work) {
            cout << "\t\t        Введите срок кредита в годах: ";
            creditYearsStr.clear();
            while (true) {
                char ch = _getch();
                if (ch == '\r') {
                    if (!creditYearsStr.empty()) {
                        int creditYearsInt = stoi(creditYearsStr);
                        if (creditYearsInt >= 1 && creditYearsInt <= 2) {
                            annual_interest_rate = rate1;
                            work = false;
                        }
                        else if (creditYearsInt >= 3 && creditYearsInt <= 5) {
                            annual_interest_rate = rate2;
                            work = false;
                        }
                        else if (creditYearsInt >= 6 && creditYearsInt <= 9) {
                            annual_interest_rate = rate3;
                            work = false;
                        }
                        else {
                            cout << endl << "\t\tКредит возможно взять максимум на 9 лет." << endl;
                            Sleep(1500);
                            system("cls");
                            center(); cout << "------------------------------------------------------------" << endl;
                            cout << "\t В зависимости от длительности кредита процентная ставка будет равна:" << endl;
                            cout << "\t При 1 - 2 г.: " << rate1 << "%; При 3 - 5 л.: " << rate2 << "%; При 6 - 9 л.: " << rate3 << "%" << endl;
                            tab(); cout << "------------------------------------------------------------" << endl;
                            cout << "\t\t        Введите срок кредита в годах: ";
                            creditYearsStr.clear();
                            continue;
                        }
                        break;
                    }
                }
                else if (ch == 27) { 
                    system("cls");
                    Credit();
                    return; 
                }
                else if (ch == '\b') {  
                    if (!creditYearsStr.empty()) {
                        cout << "\b \b";
                        creditYearsStr.pop_back();
                    }
                }
                else if (isdigit(ch)) {  
                    cout << ch;
                    creditYearsStr += ch;
                }
            }
        }

        cout << endl;
        credit_years = stoi(creditYearsStr);


            int credit_months = credit_years * 12;
            cout << "\t  -------------------------[Результат]------------------------" << endl;
            double month_interest_rate = annual_interest_rate / 1200;
            double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
            cout << "\t\t     Ежемесячный платеж по кредиту: " << month_payment << endl;
            //Выход
            cout << "\t  ------------------------------------------------------------" << endl;
            cout << "\t\t\t        Esc.Вернуться в меню" << endl;
            char exitChoice = _getch();
            bool Work = true;
            while (Work) {
                switch (exitChoice) {
                case 27:
                    system("cls");
                    Credit();
                    break;
                default:
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

