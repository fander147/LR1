#include "Header.h"
#include "my_function.h"
#include "menulab1.h"

using namespace std;

void Table(double* pmas, int pnsize, int pnsec, string pstitle);
void Tabletex(double* mas, int N, const string& title, const string& namep);

int WriteBinaryFile(std::string psfilename, bool pisappend = false);
int ReadBinaryFile(std::string);

void lab2Dot1();
void lab2Dot2();
void lab2Dot3();
int nres = 0;
void menulab2() {
	masA = new double[N];
	masB = new double[N];
	for (int i = 0; i < N; i++) {
		masA[i] = masB[i] = 0;
	}

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
		case '3': lab2Dot1(); break;
		case '4': lab2Dot2(); break;
		case '5': lab2Dot3(); break;
		case '6': lab1Dot6(); break;
		case '7': lab1Dot7(); break;

		case 27: break;
		default:
			cout << " Нажата клавиша " << ch << " с кодом " << int(ch) << endl;
			Sleep(1500);
		}

	} while (ch != 27);
}
void lab2Dot1() {
	nres = WriteBinaryFile("l.txt");
	cout << nres;
	system("pause");
}
void lab2Dot2() {

}
void lab2Dot3() {

}


int WriteBinaryFile(string psfilename, bool pisappend) {
	if (psfilename.empty()) { return -1; }
	if (masA == 0) return -2;

	fstream fout;
	if (pisappend) {
		fout.open(psfilename, ios::binary | ios::app);
		fout.seekp(0, ios::end);

	}
	else
		fout.open(psfilename, ios::binary | ios::out);

	for (int i = 0; i < N; i++) {
		fout.write((char*)masA + i, sizeof(double));
	}
	fout.close();
	return 0;
}

int ReadBinaryFile(string psfilename) {
	if (psfilename.empty()) return -1;

	ifstream fin(psfilename, ios::binary);
	if (!(fin.bad() , fin.fail())) {
		//сколько данных в файле
		fin.seekg(0, ios::end);
		N = fin.tellg() / sizeof(double);

		if (masA != NULL) delete[] masA;
		masA = new double [N] {};

		int n = 0;
		fin.seekg(0);
		while (!fin.eof() && n < N) {
			fin.read((char*)(masA + n), sizeof(double));
			n++;
		}
	}
	fin.close();
	return 0;
}


