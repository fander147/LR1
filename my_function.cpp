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
void del_line() {
	int Y = GetCursorPosition().Y;
	setCursorPosition(0, Y);
	SPACE(80);
	setCursorPosition(0, Y);
}
void uslovie1()
{
	cout << "  ������� ������:\n  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "��� ������ A1, ... , A16.\n";
	SetColor();
	cout << "  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "���� ����� Amax ������ ������, �� �������� ��� �������������� ��� �������� �� A2, ����� ��������� ��� �������� �� 3.\n\n";
	SetColor();
}
void uslovie3() {
	cout << "  ������� ������:\n  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "���� � ������� ���������� ������������� ��������� � ������ ������� ������ \n";
	SetColor();
	cout << "  ";
	SetColor(CL_BLACK, CL_WHITE);
	cout << "���������� ������������� ��������� � �������� ��������, �� �������� ������� 1-� ������ � ������� ��������� �������.\n\n";
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