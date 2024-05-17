#include "mainMenu.h"

void mainMenu()
{
	//���������� ���������
	bool login = false;
	bool work = true;
	Users newUser;

	while (work) {
		bank_logo();
		cout << endl; 
		tab();tab(); cout << "1.����� ��� ������������." << endl;
		tab();tab(); cout << "2.����� ��� �������������." << endl;
		tab();tab(); cout << "3.������������������." << endl;
		tab();tab(); cout << "Esc.�����";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//����� ��� ������������
			while (login == false) {
				system("cls");
				bank_logo();
				cout << endl;
				if (newUser.loginUser() == true) {
					ofstream fout("CurrentUser.txt");
					fout << newUser.getLastName() << " ";
					fout << newUser.getName() << " ";
					fout << newUser.getlogin() << " ";
					fout << newUser.getPassword() << " ";
					fout.close();

					login = true;
					system("cls");
					bank_logo();
					cout << endl;
					tab();tab(); cout << "     ����� ����������!" << endl;
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
			bank_logo();
			cout << endl;
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
			bank_logo();
			cout << endl;
			tab();tab();cout << "�� ������������� ������ �����?" << endl;
			tab();tab();cout << "Y.�� " << "N.���" << endl;
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
				bank_logo();
				cout << endl;
				tab();cout << "�������� �����. ����������, �������� ����� �� 1 �� 2." << endl;
				Sleep(1000);
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			bank_logo();
			cout << endl;
			tab();cout << "�������� �����. ����������, �������� ����� �� 1 �� 4." << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}
