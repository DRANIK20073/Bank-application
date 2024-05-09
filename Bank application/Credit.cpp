#include "Credit.h"

double annuity_credit(double sum, double annual_interest_rate, double credit_months) {
    double month_interest_rate = annual_interest_rate / 1200;
    double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
    return month_payment;
}

void Credit() {
    ofstream credit("Credit.txt");
    credit << 9 << endl << 16 << endl;
    credit.close();

    double sum;
    double annual_interest_rate;
    int credit_years;

    cout << "������� ����� ������� � ����������� ������: ";
    cin >> sum;

    cout << "��� ���� ����� ���������� ��� ��� �������� ������� ������." << endl;
    ifstream credits("Credit.txt");
    double rate1, rate2;
    credits >> rate1 >> rate2;
    cout << "�������� ���� �� ���������: " << "1) " << rate1 << "%, 2) " << rate2 << "%." << endl;

    char annual_interest_rate_choice = _getch();
    switch (annual_interest_rate_choice) {
    case '1':
        annual_interest_rate = rate1;
        break;
    case '2':
        annual_interest_rate = rate2;
        break;
    default:
        cout << "������������ �����. ������ ������ �������." << endl;
        annual_interest_rate = rate1;
        break;
    }

    cout << "������� ���� ������� � �����: ";
    cin >> credit_years;
    int credit_months = credit_years * 12;

    double month_payment = annuity_credit(sum, annual_interest_rate, credit_months);
    cout << "����������� ������ �� �������: " << month_payment << endl << endl;

    cout << "������� ����������?" << endl;
    cout << "Y. �� " << "N. ���" << endl;
    char exitChoice = _getch();
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
        cout << "�������� �����. ����������, �������� �� ��� ���." << endl;
        Sleep(3000);
        system("cls");
        break;
    }
}