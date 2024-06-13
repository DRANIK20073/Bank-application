#include "SupportUser.h"

void SupportUser()
{
    bool work = true;

    while (work) {
        bank_logo();
        cout << "1.Обратиться в поддержку" << endl;
        cout << "2.Просмотреть ответы" << endl;
        cout << "Esc.Выйти в меню" << endl;

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

            cout << "Введите ваше обращение в поддержку" << endl;
            cin.ignore();
            string question;
            string question;
            char ch;
            while ((ch = _getch()) != '\r') { // '\r' - символ Enter
                if (ch == '\b') { // Обработка backspace
                    if (!question.empty()) {
                        cout << "\b \b"; // Удаление символа с экрана
                        question.pop_back();
                    }
                }
                else {
                    cout << ch; // Отображение символа на экране
                    question += ch; // Добавление символа в строку
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
            cout << "Ваше обращение отправлено!" << endl;
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
            cout << "Ответы на ваши обращения:" << endl;

            while (getline(fin, line)) {
                    cout << line << endl;
            }
            fin.close();

            cout << "Нажмите любую клавишу для возврата в меню" << endl;
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
