#include "Credit.h"

void case1() {
    system("cls");
    double sum;
    double annual_interest_rate;
    int credit_years;
    center();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       ������� ����� ������� � ����������� ������: ";
    cin >> sum;
    tab();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       �������� ������� ������� ������.";
    ifstream credits("Credit.txt");
    double rate1, rate2;
    credits >> rate1 >> rate2;
    cout << " 1) " << rate1 << "%, 2) " << rate2 << "%." << endl;
    char annual_interest_rate_choice = _getch();
    switch (annual_interest_rate_choice) {
    case '1':
        annual_interest_rate = rate1;
        tab();cout << "       �� ������� " << rate1 << "%" << endl;
        break;
    case '2':
        annual_interest_rate = rate2;
        tab();cout << "       �� ������� " << rate2 << "%" << endl;
        break;
    default:
        tab();cout << "       �������� �����. ������������� ������ ������� 1." << endl;
        annual_interest_rate = rate1;
        break;
    }
    tab();cout << "------------------------------------------------------------" << endl;
    tab();cout << "       ������� ���� ������� � �����: ";
    cin >> credit_years;
    int credit_months = credit_years * 12;
    tab();cout << "-------------------------[���������]------------------------" << endl;
    double month_interest_rate = annual_interest_rate / 1200;
    double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
    tab();cout << "       ����������� ������ �� �������: " << month_payment << endl;
    //�����
    tab();cout << "------------------------------------------------------------" << endl;

    tab();tab();cout << "       1.����� ������(� ����������)" << endl;
    tab();tab();cout << "       2.��������� � ����" << endl;
    char exitChoice = _getch();
    bool Work = true;
    while (Work) {
        switch (exitChoice) {
        case '1':
            //��������!!!
        case '2':
            system("cls");
            Credit();
            break;
        default:
            cout << "������������ ����� ���������� ��� ���.";
            break;
        }
        break;
    }
}

void Credit() {
    //�������� ������� ������
    ofstream credit("Credit.txt");
    credit << 9 << endl << 16 << endl;
    credit.close();

    system("mode con cols=80 lines=30");
    //����
    center();cout << "---------------------------[������]-------------------------" << endl;
    tab();tab();tab();cout << "  1.������" << endl;
    tab();tab();tab();cout << "  Esc.��������� � ����" << endl;
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