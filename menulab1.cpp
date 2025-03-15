#include "Header.h"
#include "my_function.h"



using namespace std;

int N = 16;
double* masA = nullptr;
double* masB = nullptr;
void menulab1() {
	masA = new double[N];
	masB = new double[N];
	char ch = 0;
	do {
		
		system("cls");
		
		SetColor (CL_YELLOW,0);
		cout << " Меню Лабораторки 1\n";
		SetColor();
		cout << "  1 - решение 1\n";
		cout << "  2 - решение 2\n";
		cout << " ESC - Выход из программы \n\n";

		ch = _getch();

		switch (ch) {
		case '1': lab1Dot1(); break;
		case '2': lab1Dot2(); break;
		case '3': break;
		case '4': break;
		}

	} while (ch != 27);
}
#include <limits>
void inmas() {
	for (int i = 1; i <= N; i++) {
		while (true) {
			if (i == N) {
				SetColor(CL_RED, 0);
			}
			cout << "  A[" << i << "]=";
			cin >> masA[i - 1];
			SetColor();
			cout << "\033[F\r\033[K";
			if (cin.fail()) {
				cin.clear();
				cin.ignore(cin.rdbuf() -> in_avail());

			} 
			else {
				break;
			}
		}
	}
}
void outmasA() {
	cout << "[";
	for (int i = 0; i <= N - 2; i++) {
		cout << " " << masA[i] << ",";
	}
	cout << " " << masA[N - 1] << " ]";
}
void outmasB() {
	cout << "[";
	for (int i = 0; i <= N - 2; i++) {
		cout << " " << masB[i] << ",";
	}
	cout << " " << masB[N - 1] << " ]";
}
void lab1Dot1() {

	char ch = 0;
		system("cls");
		uslovie1();
		SetColor(CL_YELLOW, 0);
		cout << "  Решение 1:\n\n";
		SetColor();
		cout << "  Введите массив данных" << endl;
		inmas();
		cout << "\033[F\r\033[K";
		cout << "  Исходный массив: \n";
		outmasA();
		cout << endl << "  итоговый массив: \n";
		lab1res();
		outmasB();
		ch = _getch();
}
string namef;
void save() {
	cout << "  Введите название файла ";
	cin >> namef;
	cout << "  Введите массив данных" << endl;
	inmas();
	ofstream File(namef);
	if (File.is_open()) {
		for (int i = 1; i <= N; i++) {
			File << masA[i - 1] << " ";
		}
		File.close();
		cout << "\n  Дааные згружены в файл: " << namef << endl;
		Sleep(1500);
	}
	else {
		cout << "  Не удалось згрузить данные в файл" << endl;
		Sleep(1500);
	}
}
void load() {
	cout << "  Введите название файла ";
	cin >> namef;
	ifstream File(namef);
	if (File.is_open()) {
		for (int i = 1; i <= N; i++) {
			File >> masA[i - 1];
		}
		File.close();
		cout << "\n  полученыe данные из файла: " << namef << endl;
		outmasA();
		cout << "\n  обработаный массив: \n";
		lab1res();
		outmasB();
	}
	else {
		cout << "  Не удалось открыть файл" << endl;
		Sleep(1500);
	}

}

void size() {
	cout << "  введите размер массива:";
	cin >> N;
}
void lab1Dot2() {
	char ch = 0;
	do {
		system("cls");
		uslovie1();
		SetColor(CL_YELLOW, 0);
		cout << "  Решение 2:\n\n";
		SetColor();
		cout << "  1 - ввести и сохранить массив в файл\n";
		cout << "  2 - згрузить и обработать массив из файла\n";
		cout << "  3 - изменить размер массива\n";

		ch = _getch();
		switch (ch) {
		case '1': save(); break;
		case '2': load(); break;
		case '3': size(); break;
		//case '4': tabl(); break;
		}
		ch = _getch();
	} while (ch != 27);
}


void lab1res() {
	for (int i = 0; i <= N - 1; i++) {
		masB[i] = masA[i];
	}
	int maxi = 0;
	for (int i = 1; i <= N - 1; i++) {
		if (masA[i] > masA[maxi]) {
			maxi = i;
		}
	}

	if (maxi < 9) {
		double A2 = masA[1];
		for (int i = 0; i < maxi; i++) {
			masB[i] = A2;
		}
	}
	else {
		for (int i = 0; i <= N - 1; i++) {
			masB[i] = masA[i] / 3;
		}
	}
	
}