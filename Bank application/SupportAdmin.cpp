#include "SupportAdmin.h"


void supportAdmin() {
    ifstream fin("questions.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        int id;
        string login, question;

        ss >> id >> login >> question;

        cout << id << "." << login << " " << question;
    }
    fin.close();

    while (true) {
        char choice = _getch(); 
        if (choice == 27) { 
            system("cls"); 
            return; 
        }

        cout << "������� ����� ��������� (��� Esc ��� ������): " << endl;
        int idChoice;
        cin >> idChoice;

        string login;
        string question;

        ifstream fin("questions.txt");
        string line;

        while (getline(fin, line)) {
            stringstream ss(line);
            int id;
            string login, question;
            if (id == idChoice) {
                ss >> login >> question;
            }
        }
        fin.close();
        cout << "�� ������� ��������� �� ������������ " << login << ": " << question << endl;
        
        ofstream fout("answers.txt");
        string answer;
        getline(cin, answer);
        cin.ignore();
        fout << idChoice << " " << " " << login << answer << endl;
    }

}