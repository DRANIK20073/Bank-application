#include "Header.h"

void settings()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = false; // изменяем видимость курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	system("mode con cols=68 lines=33");
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_THICKFRAME);
	SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX);
	SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void tab()
{
	cout << "          ";
}

void bank_logo()
{
	ifstream BankLogo("BankLogo.txt");
	string line;

	while (getline(BankLogo, line)) {
		tab();
		cout << line << endl;
	}
}
