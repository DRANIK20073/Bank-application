#include "SupportUser.h"

void SupportUser()
{
	bool work = true;

	while (work) {
		bank_logo();
		cout << "1.Обратиться в поддержку" << endl;
		cout << "2.Просмотреть ответы" << endl;
		cout << "Esc.Выйти в меню" << endl;

		int choice = _getch();
		switch (choice)
		{
		case '1': {
			system("cls");
			bank_logo();

			ifstream fin("CurrentUser.txt");

			string lastName, name, login, password, cardNumber, cardExpiration, cardCVV, cardPassword;
			double balance;
			fin >> lastName >> name >> login >> password >> balance >> cardNumber >> cardExpiration >> cardCVV >> cardPassword;
			fin.close();

			cout << "Введите ваше обращение в поддержку" << endl;
			cin.ignore();
			string question;
			getline(cin, question);

			ifstream fin2("questions.txt");
			int idQuestion = 0;
			string lastLine;
			while (getline(fin2, lastLine)) {
			}
			fin2.close();

			if (!lastLine.empty()) {
				stringstream ss(lastLine);
				ss >> idQuestion;
				idQuestion++;
			}
			else {
				idQuestion = 1; 
			}

			ofstream fout("questions.txt", ios::app);
			fout << idQuestion << " " << login << " " << question << endl;
			fout.close();

			system("cls");
			cout << endl;
			bank_logo();
			cout << "Ваше обращение отправлено!" << endl;
			Sleep(500);
			system("cls");
			break;
		}

		case 27:
			work = false;
			UserMenu();
			break;

		default:
			system("cls");
			break;
		}
	}
}
