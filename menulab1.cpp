#include "Header.h"
#include "my_function.h"
using namespace std;

int N = 16;
double* masA = nullptr;
double* masB = nullptr;
int sizeMas();
void save();
void load();
void Table(double* pmas, int pnsize, int pnsec, string pstitle);
void menulab1() {
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
		cout << "  2 - ввести и сохранить массив в файл\n";
		cout << "  3 - згрузить и обработать массив из файла\n";
		cout << "  4 - Табличное представление массивов";
		cout << " ESC - Выход из программы \n\n";

		ch = _getch();

		switch (ch) {
		case '0': sizeMas(); break;
		case '1': lab1Dot1(); break;
		case '2':
			system("cls");
			uslovie1();
			save();
			break;
		case '3':
			system("cls");
			uslovie1();
			load();
			system("pause");
			break;
		case '4':
			system("cls");
			uslovie1();
			Table(masA, N, N, "исходный массив");
			
			//Table(masB, N, 10, "обработанный массив");
			
			break;
		case 27: break;
		default:
			cout << " Нажата клавиша " << ch << " с кодом " << int(ch) << endl;
			Sleep(1500);
		}

	} while (ch != 27);
}
int sizeMas() {
	while (true) {
		cout << "Укажите размер массива: "; cin >> N;
		if (N < 10) {
			cout << "По условию требуется минимум 10 элементов\n";
			system("pause");
		}
		else {
			cout << "Создать массив? 1 - да\n";
			SetColor();
			if (_getch() == '1') {
				masA = new double[N];
				masB = new double[N];
			}
			return N;
			break;
		}
		CLEARLINE(3);
	}
}
void inmas() {
	for (int i = 1; i <= N; i++) {
		while (true) {
			if (i == N) {
				SetColor(CL_RED, 0);
			}
			cout << "  A[" << i << "]=";
			cin >> masA[i - 1];
			SetColor();
			CLEARLINE(1);
			if (cin.fail()) {
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());

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
	CLEARLINE(1);
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
		cout << "\n  Данные згружены в файл: " << namef << endl;
		Sleep(2000);
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
		cout << endl;
	}
	else {
		cout << "  Не удалось открыть файл" << endl;
		Sleep(1500);
	}

}
void lab1res() {
	for (int i = 0; i < N; i++) {
		masB[i] = masA[i];
	}
	int maxi = 0;
	for (int i = 1; i < N; i++) {
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
void Tabletex(double* mas, int N, const string& title, const string& namep) {
	cout << title << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << namep << left << setw(4) << i + 1 << setw(2) << ":  " << setw(10) << left << mas[i] << endl;
	}

}
void Table(double* pmas, int pnsize, int pnsec, string pstitle) {
	//system("cls");
	HWND hwnd = (HWND)GetStdHandle(STD_OUTPUT_HANDLE); //GetConsoleWindow();
	HDC hdc = GetDC(GetConsoleWindow());
	CONSOLE_FONT_INFO conf{};
	GetCurrentConsoleFont(hwnd, false, &conf);
	COORD cxy = GetCursorPosition();


	int indentY = conf.dwFontSize.Y * (cxy.Y + 1), // отступ начала граф вывода
		indentX = 60;

	HFONT hfont = CreateFontA(34, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	HFONT holdfont = (HFONT)SelectObject(hdc, hfont);

	SetTextColor(hdc, RGB(0, 255, 255));
	SetBkColor(hdc, RGB(0, 0, 0));
	TextOutA(hdc, indentX + 100, indentY, pstitle.c_str(), pstitle.length());
	SelectObject(hdc, holdfont);
	DeleteObject(hfont);


	indentY += 34;
	int nsec = pnsize / pnsec + ((pnsize % pnsec > 0) ? 1 : 0);

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	LOGBRUSH lgbr{ PS_SOLID, RGB(94, 94, 94), 0 };
	HBRUSH hbrush = CreateBrushIndirect(&lgbr);
	HANDLE oldbrush = SelectObject(hdc, hbrush),
		odlpen = SelectObject(hdc, hpen);


	Rectangle(hdc, indentX, indentY, indentX + pnsec * 5 * conf.dwFontSize.X, indentY + (5 * conf.dwFontSize.Y) * nsec);
	for (int i = 0; i < nsec; i++) {
		int nx = indentX,
			nx2 = indentX + pnsec * 5 * conf.dwFontSize.X;
		MoveToEx(hdc, nx, indentY + i * 5 * conf.dwFontSize.Y + (5 * conf.dwFontSize.Y) / 2, NULL);
		LineTo(hdc, nx2, indentY + i * 5 * conf.dwFontSize.Y + (5 * conf.dwFontSize.Y) / 2);
		MoveToEx(hdc, nx, indentY + i * (5 * conf.dwFontSize.Y), NULL);
		LineTo(hdc, nx2, indentY + i * (5 * conf.dwFontSize.Y));
	}

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkColor(hdc, RGB(94, 94, 94));

	for (int i = 0; i < pnsec; i++) {
		int nx = indentX + (i) * 5 * conf.dwFontSize.X,
			ny = indentY;
		MoveToEx(hdc, nx, ny, NULL);
		LineTo(hdc, nx, ny + (5 * conf.dwFontSize.Y * nsec));

		char txt[30]{};
		for (int j = 0; j < nsec; j++) {
			if (j * pnsec + i < pnsize) {
				sprintf_s(txt, "X%d", j * pnsec + i + 1);
				SIZE sz{};
				GetTextExtentPoint32A(hdc, txt, strlen(txt), &sz);
				SetTextColor(hdc, RGB(50, 205, 50));
				SetBkColor(hdc, RGB(94, 94, 94));
				TextOutA(hdc, nx + (5 * conf.dwFontSize.X - sz.cx) / 2, ny + j * (conf.dwFontSize.Y * 5) + conf.dwFontSize.Y, txt, strlen(txt));
				sprintf_s(txt, "%5.1f", pmas[j * pnsec + i]);
				GetTextExtentPoint32A(hdc, txt, strlen(txt), &sz);
				SetTextColor(hdc, RGB(255, 255, 255));
				SetBkColor(hdc, RGB(94, 94, 94));
				TextOutA(hdc, nx + (5 * conf.dwFontSize.X - sz.cx) / 2, ny + j * (conf.dwFontSize.Y * 5) + 3 * conf.dwFontSize.Y, txt, strlen(txt));
			}

		}

	}
	_getch();
}
