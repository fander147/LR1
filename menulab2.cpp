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
		cout << " Меню Лабораторки 1\n";
		SetColor();
		cout << "  0 - изменить размер массива\n";
		cout << "  1 - решение 1\n";
		cout << "  2 - решение 2\n";
		cout << "  3 - ввести и сохранить массив в файл\n";
		cout << "  4 - згрузить массив из файла\n";
		cout << "  5 - Решение задачи данные из файла\n";
		cout << "  6 - табличное графическое представление массива\n";
		cout << "  7 - табличное представление массива\n";
		cout << " ESC - Выход из программы \n\n";

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
			cout << " Нажата клавиша " << ch << " с кодом " << int(ch) << endl;
			Sleep(1500);
		}

	} while (ch != 27);
}


