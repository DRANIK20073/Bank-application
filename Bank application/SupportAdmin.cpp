#include "SupportAdmin.h"

void supportAdmin() {
    vector<pair<int, pair<string, string>>> questions;

    auto readQuestions = [&questions]() {
        ifstream fin("questions.txt");
        string line;
        questions.clear();
        while (getline(fin, line)) {
            stringstream ss(line);
            int id;
            string login, question;

            ss >> id >> login;
            getline(ss, question);

            cout << id << ". " << login << " " << question << endl;

            questions.push_back(make_pair(id, make_pair(login, question)));
        }
        fin.close();
        };

    readQuestions();

    while (true) {
        cout << "������� ����� ��������� (��� Esc ��� ������): ";
        char choice = _getch();

        if (choice == 27) {
            system("cls");
            return;
        }

        if (!isdigit(choice)) {
            cout << "�������� ����. ����������, ������� ����� ���������." << endl;
            continue;
        }

        int idChoice = choice - '0';

        bool found = false;
        string login, question;
        for (auto& q : questions) {
            if (q.first == idChoice) {
                login = q.second.first;
                question = q.second.second;
                cout << endl << "�� ������� ��������� �� ������������ " << login << ": " << question << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "������ � ������� " << idChoice << " �� ������." << endl;
            continue;
        }

        cout << "������� ����� �� ������: ";
        cin.ignore();
        string answer;
        getline(cin, answer);

        ofstream fout("answers.txt", ios::app);
        fout << idChoice << " " << login << " " << answer << endl;
        fout.close();

        questions.erase(remove_if(questions.begin(), questions.end(), [idChoice](const pair<int, pair<string, string>>& q) {
            return q.first == idChoice;
            }), questions.end());

        ofstream foutQuestions("questions.txt");
        for (const auto& q : questions) {
            foutQuestions << q.first << " " << q.second.first << " " << q.second.second << endl;
        }
        foutQuestions.close();

        cout << "����� �������� � ������ ������." << endl;
        Sleep(1000);
        system("cls");

        readQuestions();
    }
}