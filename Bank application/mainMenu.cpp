#include "mainMenu.h"

void mainMenu()
{
	//���������� ���������
	bool login = false;
	bool work = true;
	Users newUser;

	while (work) {
		ifstream BankLogo("BankLogo.txt");
		string line;

		while (getline(BankLogo, line)) {
			cout << line << endl;
		}
		cout << endl; 
		cout << "					      1. ����� ��� ������������." << endl;
		cout << "					      2. ����� ��� �������������." << endl;
		cout << "					      3. ������������������." << endl;
		cout << "					      Esc. �����";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//����� ��� ������������
			while (login == false) {
				system("cls");
				if (newUser.loginUser() == true) {
					ofstream fout("CurrentUser.txt");
					fout << newUser.getLastName() << " ";
					fout << newUser.getName() << " ";
					fout << newUser.getlogin() << " ";
					fout << newUser.getPassword() << " ";
					fout.close();

					login = true;
					system("cls");
					cout << "����� ����������!" << endl;
					Sleep(2000);
					system("cls");
					UserMenu();
				}
				else {
					system("cls");
				}
			}
			system("pause");
			system("cls");
			break;
		case '2':
			//����� ��� �������������
			system("cls");
			break;
		case '3': {
			//�����������
			system("cls");
			newUser.information();
			newUser.registration();
			cout << "����������� ���������." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 27: {
			//����� �� ���������
			system("cls");
			cout << "�� ������������� ������ �����?" << endl;
			cout << "Y.�� " << "N.���" << endl;
			int exitChoice;
			exitChoice = _getch();
			switch (exitChoice) {
			case 'Y':
			case 'y':
				exit(0);
			case 'N':
			case 'n':
				system("cls");
				break;
			default:
				system("cls");
				cout << "�������� �����. ����������, �������� ����� �� 1 �� 2." << endl;
				Sleep(3000);
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			cout << "�������� �����. ����������, �������� ����� �� 1 �� 4." << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
