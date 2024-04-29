#include "mainMenu.h"

void mainMenu()
{
	//���������� ���������
	bool work = true;
	Users newUser;

	//���� � ������� �������������
	ofstream user;
	user.open("Users.txt", ios::app);

	while (work) {
		cout << "1. ����� ��� ������������." << endl;
		cout << "2. ����� ��� �������������." << endl;
		cout << "3. ������������������." << endl;
		cout << "Esc. �����";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//����� ��� ������������
			system("cls");
			if (newUser.loginUser() == true) {
				system("cls");
				cout << "����� ����������!" << endl;
				Sleep(2000);
				system("cls");
				UserMenu();
			}
			else {
				system("cls");
				newUser.loginUser();
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
				user.close();
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
