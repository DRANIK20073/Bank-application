#include "Header.h"
#include "Users.h"
#include "mainMenu.h"

int main() {
	//Локализация
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	settings();
	mainMenu();

	return 0;
}
