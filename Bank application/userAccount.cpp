#include "userAccount.h"

void userAccount()
{
	system("mode con cols=80 lines=26");
	Users currentUser;
	center();cout << "---------------------------[C���]---------------------------" << endl;
	cout << "������: " << currentUser.getBalance() << " BYN";
	tab();cout << "------------------------------------------------------------" << endl;
}
