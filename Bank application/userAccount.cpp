#include "userAccount.h"

void userAccount()
{
	system("mode con cols=80 lines=26");
	Users currentUser;
	center();cout << "---------------------------[Cчёт]---------------------------" << endl;
	cout << "Баланс: " << currentUser.getBalance() << " BYN";
	tab();cout << "------------------------------------------------------------" << endl;
}
