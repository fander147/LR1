#include "Header.h"
#include "my_function.h"
using namespace std;



void setCursorPosition(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD GetCursorPosition() {
	CONSOLE_SCREEN_BUFFER_INFO lpCursorInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursorInfo);
	return lpCursorInfo.dwCursorPosition;
}
string CIN_N(string input) {
	int X = GetCursorPosition().X;
	getline(cin, input);
	setCursorPosition(X, GetCursorPosition().Y - 1);
}
void uslovie1()
{
	cout << "  условие задачи:\n  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "Дан массив A1, ... , A16.\n";
	SetColor();
	cout << "  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "Если номер Amax меньше десяти, то заменить все предшествующие ему элементы на A2, иначе разделить все элементы на 3.\n\n";
	SetColor();
}


void SetColor(short int pnTextColor, short int pnBKColor) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, WORD(pnBKColor & 0x000F) << 4 | (pnTextColor & 0x000F));
}

void SetColor() {
	SetColor(DefTextColor, DefBKColor);
}

void SetDefBkColor(short int pnBKColor) { DefBKColor = (enColor)pnBKColor; }
