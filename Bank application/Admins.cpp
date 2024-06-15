#include "Admins.h"

admins::admins()
{
}

bool admins::adminLogin()
{
    string loginInput;
    string passwordInput;
    cout << "\t\t\t    Логин: ";
    while (true) {
        char ch = _getch();
        if (ch == '\r') {
            if (!loginInput.empty()) {
                break;
            }
        }
        else if (ch == 27) {
            system("cls");
            mainMenu();
            break;
        }
        else if (ch == '\b') {
            if (!loginInput.empty()) {
                cout << "\b \b";
                loginInput.pop_back();
            }
        }
        else if (ch != '\n') {
            cout << ch;
            loginInput += ch;
        }
    }
    cout << endl;

    cout << "\t\t\t    Пароль: ";
    while (true) {
        char ch = _getch();
        if (ch == '\r') {
            if (!passwordInput.empty()) {
                break;
            }
        }
        else if (ch == 27) {
            system("cls");
            mainMenu();
            break;
        }
        else if (ch == '\b') {
            if (!passwordInput.empty()) {
                cout << "\b \b";
                passwordInput.pop_back();
            }
        }
        else if (ch != '\n') {
            cout << ch;
            passwordInput += ch;
        }
    }
    cout << endl;

    ifstream userFile("Admins.txt");

    string line;
    while (getline(userFile, line)) {
        stringstream ss(line);
        string currentLastName, currentName, currentLogin, currentPassword;

        ss >> currentLastName >> currentName >> currentLogin >> currentPassword;

        if (currentLogin == loginInput && currentPassword == passwordInput) {
            lastName = currentLastName;
            name = currentName;
            login = currentLogin;
            password = currentPassword;
            userFile.close();
            return true;
        }
    }

    userFile.close();
    system("cls");
    cout << "Неправильный логин или пароль, повторите попытку." << endl;
    Sleep(800);
    return false;
}

string admins::getLastName()
{
    ifstream fin("CurrentUser.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> lastName >> name >> login >> password;
    }

    fin.close();

    return lastName;
}

string admins::getName()
{
    ifstream fin("CurrentUser.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> lastName >> name >> login >> password;
    }

    fin.close();

    return name;
}

string admins::getLogin()
{
    ifstream fin("CurrentUser.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> lastName >> name >> login >> password;
    }

    fin.close();

    return login;
}

string admins::getPassword()
{
    ifstream fin("CurrentUser.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> lastName >> name >> login >> password;
    }

    fin.close();

    return password;
}
