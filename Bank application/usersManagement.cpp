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
        cout << "������ � ������������ " << (i + 1) << ":" << endl;
        cout << "�������: " << user.lastName << endl;
        cout << "���: " << user.name << endl;
        cout << "�����: " << user.login << endl;
        cout << "������: " << user.password << endl;
        cout << "������: " << user.balance << endl;

        if (!user.cardNumber.empty()) {
            cout << "����� �����: " << user.cardNumber << endl;
            cout << "���� �������� �����: " << user.cardExpiration << endl;
            cout << "CVV �����: " << user.cardCVV << endl;
            cout << "������ �����: " << user.cardPassword << endl;
        }

        cout << "���: " << (user.ban ? "��" : "���") << endl;
        cout << "-------------------------" << endl;
    }

    cout << "�������� " << (page + 1) << " �� " << ((users.size() + usersPerPage - 1) / usersPerPage) << endl;
    cout << "1 ����. 2 ����. Esc �����." << endl;
    cout << "������� b ����� �������� ������������.";
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
            cout << "\n������� ����� ������������ ��� ��������� ������� (1-" << users.size() << "): ";
            int userIndex;
            cin >> userIndex;
            if (userIndex > 0 && userIndex <= users.size()) {
                cout << "������� ������ ������������: " << (users[userIndex - 1].ban ? "�������" : "�� �������") << endl;
                cout << "������� 1 ��� ���� ��� 0 ��� �������: ";
                int banChoice;
                cin >> banChoice;
                if (banChoice == 1) {
                    users[userIndex - 1].ban = true;
                    cout << "������������ " << userIndex << " �������." << endl;
                }
                else if (banChoice == 0) {
                    users[userIndex - 1].ban = false;
                    cout << "������������ " << userIndex << " ��������." << endl;
                }
                else {
                    cout << "�������� �����." << endl;
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
                cout << "�������� ����� ������������." << endl;
            }
        }
    } while (choice != 27);

    if (choice == 27) {
        system("cls");
        system("mode con cols=68 lines=32");
    }
}
