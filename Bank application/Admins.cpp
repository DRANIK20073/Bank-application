#include "Admins.h"

admins::admins()
{
}

bool admins::adminLogin()
{
    string loginInput;
    string passwordInput;
    tab(); tab(); cout << "\t Логин: ";
    cin >> loginInput;
    tab(); tab(); cout << "\t Пароль: ";
    cin >> passwordInput;

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
