#include "SupportUser.h"

void SupportUser()
{
    system("mode con cols=80 lines=20");
    bool work = true;

    while (work) {
        center(); cout << "-------------------------[Поддержка]------------------------" << endl;
        cout << "\t\t\t     1.Обратиться в поддержку" << endl;
        cout << "\t\t\t      2.Просмотреть ответы" << endl;
        cout << "\t\t\t        Esc.Выйти в меню" << endl;
        cout << "\t  ------------------------------------------------------------" << endl;

        int choice = _getch();
        switch (choice) {
        case '1': {
            system("cls");
            center(); cout << "------------------------------------------------------------" << endl;

            ifstream fin("CurrentUser.txt");

            string lastName, name, login, password, cardNumber, cardExpiration, cardCVV, cardPassword;
            double balance;
            fin >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
            fin.close();

            cout << "\t\t\tВведите ваше обращение в поддержку:" << endl;
            cout << "\t  ";
            string question;
            while (true) {
                while (true) {
                    char ch = _getch();
                    if (ch == '\r') {
                        if (!question.empty()) {
                            break;
                        }
                    }
                    else if (ch == 27) {
                        system("cls");
                        SupportUser();
                        break;
                    }
                    else if (ch == '\b') {
                        if (!question.empty()) {
                            cout << "\b \b";
                            question.pop_back();
                        }
                    }
                    else if (ch != '\n') {
                        cout << ch;
                        question += ch;
                    }
                }
                break;
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
            center();cout << "------------------------------------------------------------" << endl;
            cout << "\t\t\t Ваше обращение отправлено!" << endl;
            cout << "\t  ------------------------------------------------------------" << endl;
            Sleep(1000);
            system("cls");
            break;
        }
        case '2': {
            system("cls");

            ifstream fin("CurrentUser.txt");
            string line;
            string login;

            while (getline(fin, line)) {
                stringstream ss(line);
                string currentLastName, currentName, currentLogin, currentPassword, currentCardNumber, currentCardExpiration, currentCardCVV, currentCardPassword;
                double currentBalance;
                string currentBan;

                ss >> currentLastName >> currentName >> currentLogin >> currentPassword >> currentBalance >> currentBan >> currentCardNumber >> currentCardExpiration >> currentCardCVV >> currentCardPassword;
                
                login = currentLogin;
            }
            fin.close();

            ifstream fin2("answers.txt");
            string answer;
            cout << "Ответы на ваши обращения:" << endl;
            line.clear();

            while (getline(fin2, line)) {
                stringstream ss(line);
                string id, num;

                ss >> num >> id;
                getline(ss, answer);

                if (login == id) {
                    cout << "Ответ: " << answer << endl << endl;
                }
            }
            
            fin2.close();

            cout << endl << "Нажмите любую клавишу для возврата в меню..." << endl;
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
