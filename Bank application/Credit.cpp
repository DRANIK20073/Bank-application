#include "Credit.h"

void Credit() {
    system("mode con cols=80 lines=20");
    //����
    center();cout << "---------------------------[������]-------------------------" << endl;
    cout << "\t\t\t\t     1.������" << endl;
    cout << "\t\t\t\t Esc.����� � ����" << endl;
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
            tab();cout << "       ������� ����� ������� � ����������� ������: ";
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
        cout << "       � ����������� �� ������������ ������� ���������� ������ ����� �����" << endl;
        ifstream credits("Credit.txt");
        double rate1, rate2, rate3;
        credits >> rate1 >> rate2 >> rate3;
        cout << "\t       ��� 1 - 2 �.: " << rate1 << "%; ��� 3 - 5 �.:" << rate2 << "%; ��� 6 - 9 �.:" << rate3 << "%" << endl;
        tab();cout << "------------------------------------------------------------" << endl;
        bool work = true;
        string creditYearsStr;
        while (work) {
            cout << "\t\t        ������� ���� ������� � �����: ";
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
                            cout << endl << "\t\t������ �������� ����� �������� �� 9 ���." << endl;
                            Sleep(1500);
                            system("cls");
                            center(); cout << "------------------------------------------------------------" << endl;
                            cout << "\t � ����������� �� ������������ ������� ���������� ������ ����� �����:" << endl;
                            cout << "\t ��� 1 - 2 �.: " << rate1 << "%; ��� 3 - 5 �.: " << rate2 << "%; ��� 6 - 9 �.: " << rate3 << "%" << endl;
                            tab(); cout << "------------------------------------------------------------" << endl;
                            cout << "\t\t        ������� ���� ������� � �����: ";
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
            cout << "\t  -------------------------[���������]------------------------" << endl;
            double month_interest_rate = annual_interest_rate / 1200;
            double month_payment = (sum * month_interest_rate) / (1 - pow((1 + month_interest_rate), -credit_months));
            cout << "\t\t     ����������� ������ �� �������: " << month_payment << endl;
            //�����
            cout << "\t  ------------------------------------------------------------" << endl;
            cout << "\t\t\t        Esc.��������� � ����" << endl;
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

