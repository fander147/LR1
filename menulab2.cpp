#include "Header.h"
#include "my_function.h"
#include "menulab1.h"

using namespace std;

void Table(double* pmas, int pnsize, int pnsec, string pstitle);
void Tabletex(double* mas, int N, const string& title, const string& namep);

void menulab2() {
	char ch = 0;
	do {

		system("cls");

		SetColor(CL_YELLOW, 0);
		cout << " ���� ����������� 1\n";
		SetColor();
		cout << "  0 - �������� ������ �������\n";
		cout << "  1 - ������� 1\n";
		cout << "  2 - ������� 2\n";
		cout << "  3 - ������ � ��������� ������ � ����\n";
		cout << "  4 - �������� ������ �� �����\n";
		cout << "  5 - ������� ������ ������ �� �����\n";
		cout << "  6 - ��������� ����������� ������������� �������\n";
		cout << "  7 - ��������� ������������� �������\n";
		cout << " ESC - ����� �� ��������� \n\n";

		ch = _getch();

		switch (ch) {
		case '0': lab1Dot0(); break;
		case '1': lab1Dot1(); break;
		case '2': lab1Dot2(); break;
		case '3': lab1Dot3(); break;
		case '4': lab1Dot4(); break;
		case '5': lab1Dot5(); break;
		case '6': lab1Dot6(); break;
		case '7': lab1Dot7(); break;

		case 27: break;
		default:
			cout << " ������ ������� " << ch << " � ����� " << int(ch) << endl;
			Sleep(1500);
		}

	} while (ch != 27);
}


