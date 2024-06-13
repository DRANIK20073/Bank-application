#include "usersManagement.h"

struct User {
    string lastName;
    string name;
    string login;
    string password;
    double balance;
    string cardNumber;
    string cardExpiration;
    string cardCVV;
    string cardPassword;
    bool ban;
};

void displayUsers(const vector<User>& users, int page, int usersPerPage) {
    system("cls");
    int start = page * usersPerPage;
    int end = min(start + usersPerPage, (int)users.size());

    for (int i = start; i < end; ++i) {
        const User& user = users[i];
        cout << "Данные о пользователе " << (i + 1) << ":" << endl;
        cout << "Фамилия: " << user.lastName << endl;
        cout << "Имя: " << user.name << endl;
        cout << "Логин: " << user.login << endl;
        cout << "Пароль: " << user.password << endl;
        cout << "Баланс: " << user.balance << endl;

        if (!user.cardNumber.empty()) {
            cout << "Номер карты: " << user.cardNumber << endl;
            cout << "Срок действия карты: " << user.cardExpiration << endl;
            cout << "CVV карты: " << user.cardCVV << endl;
            cout << "Пароль карты: " << user.cardPassword << endl;
        }

        cout << "Бан: " << (user.ban ? "Да" : "Нет") << endl;
        cout << "-------------------------" << endl;
    }

    cout << "Страница " << (page + 1) << " из " << ((users.size() + usersPerPage - 1) / usersPerPage) << endl;
    cout << "1 пред. 2 след. Esc выход." << endl;
    cout << "Нажмите b чтобы забанить пользователя.";
}

void usersManagement() {
    ifstream fin("Users.txt");

    system("mode con cols=72 lines=35");

    vector<User> users;
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        User user;
        ss >> user.lastName >> user.name >> user.login >> user.password >> user.balance
            >> user.cardNumber >> user.cardExpiration >> user.cardCVV >> user.cardPassword >> user.ban;
        users.push_back(user);
    }
    fin.close();    

    int usersPerPage = 3;
    int page = 0;
    char choice;

    do {
        displayUsers(users, page, usersPerPage);
        choice = _getch();

        if (choice == '2' && (page + 1) * usersPerPage < users.size()) {
            ++page;
        }
        else if (choice == '1' && page > 0) {
            --page;
        }
        else if (choice == 'b') {
            cout << "\nВведите номер пользователя для изменения статуса (1-" << users.size() << "): ";
            int userIndex;
            cin >> userIndex;
            if (userIndex > 0 && userIndex <= users.size()) {
                cout << "Текущий статус пользователя: " << (users[userIndex - 1].ban ? "Забанен" : "Не забанен") << endl;
                cout << "Введите 1 для бана или 0 для разбана: ";
                int banChoice;
                cin >> banChoice;
                if (banChoice == 1) {
                    users[userIndex - 1].ban = true;
                    cout << "Пользователь " << userIndex << " забанен." << endl;
                }
                else if (banChoice == 0) {
                    users[userIndex - 1].ban = false;
                    cout << "Пользователь " << userIndex << " разбанен." << endl;
                }
                else {
                    cout << "Неверный выбор." << endl;
                }

                ofstream fout("Users.txt");
                for (const auto& user : users) {
                    fout << user.lastName << " " << user.name << " " << user.login << " "
                        << user.password << " " << user.balance << " " << user.cardNumber << " "
                        << user.cardExpiration << " " << user.cardCVV << " " << user.cardPassword << " "
                        << user.ban << endl;
                }
                fout.close();
            }
            else {
                cout << "Неверный номер пользователя." << endl;
            }
        }
    } while (choice != 27);

    if (choice == 27) {
        system("cls");
        system("mode con cols=68 lines=32");
    }
}
