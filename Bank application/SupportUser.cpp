#include "SupportUser.h"

void SupportUser()
{
    bool work = true;

    while (work) {
        bank_logo();
        cout << "1.���������� � ���������" << endl;
        cout << "2.����������� ������" << endl;
        cout << "Esc.����� � ����" << endl;

        int choice = _getch();
        switch (choice)
        {
        case '1': {
            system("cls");
            bank_logo();

            ifstream fin("CurrentUser.txt");

            string lastName, name, login, password, cardNumber, cardExpiration, cardCVV, cardPassword;
            double balance;
            fin >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
            fin.close();

            cout << "������� ���� ��������� � ���������" << endl;
            cin.ignore();
            string question;
            string question;
            char ch;
            while ((ch = _getch()) != '\r') { // '\r' - ������ Enter
                if (ch == '\b') { // ��������� backspace
                    if (!question.empty()) {
                        cout << "\b \b"; // �������� ������� � ������
                        question.pop_back();
                    }
                }
                else {
                    cout << ch; // ����������� ������� �� ������
                    question += ch; // ���������� ������� � ������
                }
            }
            cout << endl;

            ifstream fin2("questions.txt");
            int idQuestion = 0;
            string line;

            while (getline(fin2, line)) {
                stringstream ss(line);
                int id;
                ss >> id;
                if (ss) {
                    idQuestion = max(idQuestion, id);
                }
            }
            fin2.close();

            idQuestion++; 

            ofstream fout("questions.txt", ios::app);
            fout << idQuestion << " " << login << " " << question << endl;
            fout.close();

            system("cls");
            cout << endl;
            bank_logo();
            cout << "���� ��������� ����������!" << endl;
            Sleep(500);
            system("cls");
            break;
        }
        case '2': {
            system("cls");
            system("cls");
            bank_logo();

            ifstream fin("answers.txt");
            string line;
            cout << "������ �� ���� ���������:" << endl;

            while (getline(fin, line)) {
                    cout << line << endl;
            }
            fin.close();

            cout << "������� ����� ������� ��� �������� � ����" << endl;
            _getch();
            system("cls");
            break;
            }
        case 27:
            work = false;
            UserMenu();
            break;

        default:
            system("cls");
            break;
        }
    }
}
