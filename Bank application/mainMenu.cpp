#include "mainMenu.h"

void mainMenu()
{
	//���������� ���������
	bool login = false;
	bool work = true;
	Users newUser;
	admins admin;

	while (work) {
		bank_logo(); 
		tab();tab(); cout << "  1.����� ��� ������������." << endl;
		tab();tab(); cout << "  2.����� ��� �������������." << endl;
		tab();tab(); cout << "  3.������������������." << endl;
		tab();tab(); cout << "  Esc.�����";

		int choice;
		choice = _getch();

		switch (choice) {
		case '1':
			//����� ��� ������������
			while (login == false) {
				system("cls");
				bank_logo();
				if (newUser.loginUser() == true) {
					ofstream fout("CurrentUser.txt");
					fout << newUser.getLastName() << " ";
					fout << newUser.getName() << " ";
					fout << newUser.getlogin() << " ";
					fout << newUser.getPassword() << " ";
					fout << newUser.getBalance() << " ";
					fout << newUser.getBan() << " ";
					fout << newUser.getCardNum() << " ";
					fout << newUser.getCardExpiration() << " ";
					fout << newUser.getCardCVV() << " ";
					fout << newUser.getCardPassword() << " ";
					fout.close();

					login = true;
					system("cls");
					bank_logo();
					cout << endl;
					tab();tab(); cout << "     ����� ����������!" << endl;
					Sleep(1000);
					system("cls");
					UserMenu();
				}
				else {
					system("cls");
					mainMenu();
				}
			}
			system("pause");
			system("cls");
			break;
		case '2':
			//����� ��� �������������
			while (login == false) {
				system("cls");
				bank_logo();
				if (admin.adminLogin() == true) {
					ofstream fout("CurrentAdmin.txt");
					fout << admin.getLastName() << " ";
					fout << admin.getName() << " ";
					fout << admin.getLogin() << " ";
					fout << admin.getPassword() << " ";
					fout.close();

					login = true;
					system("cls");
					bank_logo();
					cout << endl;
					tab();tab(); cout << "     ����� ����������!" << endl;
					Sleep(1000);
					system("cls");
					adminMenu();
				}
				else {
					system("cls");
					mainMenu();
				}
			}
			system("pause");
			system("cls");
			break;
		case '3': {
			//�����������
			system("cls");
			bank_logo();
			newUser.registration();
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
			tab();tab();cout << "1.�� " << "2.���" << endl;
			int exitChoice;
			exitChoice = _getch();
			switch (exitChoice) {
			case '1':
				exit(0);
			case '2':
				system("cls");
				break;
			default:
				system("cls");
				bank_logo();
				cout << endl;
				tab();cout << "�������� �����. ����������, �������� ����� �� 1 �� 2." << endl;
				Sleep(500);
				break;
			}
			system("cls");
			break;
		}
		default:
			system("cls");
			break;
		}
	}
}
