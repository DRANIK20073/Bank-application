#include "Credit.h"

void Credit() {
    //�������� ������� ������
    ofstream credit("Credit.txt");
    credit << 9 << endl << 16 << endl;
    credit.close();

    system("mode con cols=80 lines=20");
    //����
    center();cout << "---------------------------[������]-------------------------" << endl;
    tab();tab();tab();cout << "  1.������" << endl;
    tab();tab();tab();cout << "  Esc.����� � ����" << endl;
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
        tab();cout << "       ������� ����� ������� � ����������� ������: ";
        cin >> sum;
        tab();cout << "------------------------------------------------------------" << endl;
        tab();cout << "       � ����������� �� ������������ ������� ���������� ������ ����� �����" << endl;
        ifstream credits("Credit.txt");
        double rate1, rate2, rate3;
        credits >> rate1 >> rate2 >> rate3;
        cout << "��� 1 - 2 �.: " << rate1 << "%; ��� 3 - 5 �.:" << rate2 << "%; ��� 6 - 9 �.:" << rate3 << "%" << endl;
        tab();cout << "------------------------------------------------------------" << endl;
        bool work = true;
        while (work) {
            tab();cout << "       ������� ���� ������� � �����: ";
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
                cout << "\t\t������ �������� ����� �������� �� 9 ���." << endl;
            }
        }
        int credit_months = credit_years * 12;
        tab();cout << "-------------------------[���������]------------------------" << endl;
        double month_interest_rate = annual_interest_rate / 1200;
        double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
        tab();cout << "       ����������� ������ �� �������: " << month_payment << endl;
        //�����
        tab();cout << "------------------------------------------------------------" << endl;

        tab();tab();cout << "       1.����� ������(� ����������)" << endl;
        tab();tab();cout << "       Esc.��������� � ����" << endl;
        char exitChoice = _getch();
        bool Work = true;
        while (Work) {
            switch (exitChoice) {
            case '1':
                //��������!!!
            case 27:
                system("cls");
                Credit();
                break;
            default:
                cout << "������������ ����� ���������� ��� ���.";
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