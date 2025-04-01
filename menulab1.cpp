#include "Header.h"
#include "my_function.h"
#include "menulab1.h"
using namespace std;

int N = 16;
double* masA = nullptr;
double* masB = nullptr;
void Table(double* pmas, int pnsize, int pnsec, string pstitle);
void Tabletex(double* mas, int N, const string& title, const string& namep);

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
void lab1Dot0() {
	system("cls"); 
	uslovie1(); 
	sizeMas();
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
	cout << "  Исходный массив: \n";
	outmas(masA);
	cout << endl << "  итоговый массив: \n";
	lab1res();
	outmas(masB);
	ch = _getch();
}
void lab1Dot2() {
	char ch = 0;
	system("cls");
	uslovie1();
	SetColor(CL_YELLOW, 0);
	cout << "  Решение 2:\n\n";
	SetColor();
	cout << "  Введите массив данных" << endl;
	inmas();
	del_line();del_line();
	lab1res();
	Tabletex(masA, N, "исходный массив", "A");
	cout << endl;
	Tabletex(masB, N, "итоговый массив", "B");
	system("pause");
}
void lab1Dot3() {
	system("cls");
	uslovie1();
	save();
}
void lab1Dot4() {
	system("cls");
	uslovie1();
	load();
	system("pause");
}
void lab1Dot5() {
	system("cls");
	uslovie1();
	SetColor(CL_YELLOW, 0);
	cout << "  Решение c файлом:\n\n";
	SetColor();
	load();
	del_line();del_line();
	lab1res();
	Tabletex(masA, N, "исходный массив", "A");
	cout << endl;
	Tabletex(masB, N, "обработанный массив", "B");
	system("pause");
}
void lab1Dot6() {
	system("cls");
	cout << endl;
	Table(masA, N, 16, "исходный массив");
	LINES(8);
	Table(masB, N, 16, "обработанный массив");
	cout << endl;
	_getch();
}
void lab1Dot7() {
	Tabletex(masA, N, "исходный массив", "A");
	cout << endl;
	Tabletex(masB, N, "обработанный массив", "B");
	system("pause");
}
//размер массива
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
				for (int i = 0; i < N; i++) {
					masA[i] = masB[i] = 0;
				}
			}
			return N;
			break;
		}
		CLEARLINE;
	}
}
string vvod() {
	string input;
	int Y = GetCursorPosition().Y;
	getline(cin, input);
	setCursorPosition(0, Y);
	SPACE(80);
	setCursorPosition(0, Y);
	return input;
}

//ввод массива
void inmas() {
	for (int i = 1; i <= N; i++) {
		string input;
		if (i == N) {
			SetColor(CL_RED, 0);
		}
		while (true) {
			cout << "  A[" << i << "]=";
			input = vvod();
			try {
				size_t pos = 0;
				masA[i - 1] = stod(input, &pos);
				if (pos == input.size()) {
					break;
				}
			}
			catch (const std::invalid_argument&) {}
		}
		SetColor();
	}
}

//вывод мссива
void outmas(double masi[]) {
	cout << "[";
	for (int i = 0; i < N; i++) {
		double intPart;
		double fracPart = std::modf(masi[i], &intPart);
		if (abs(fracPart) >= 0.001) {
			cout << " " << fixed << setprecision(2) << masi[i] << " ";
			cout.unsetf(ios_base::fixed);
		}
		else {
			cout << " " << masi[i] << " ";
		}
		if (i != N - 1) {
			cout << ",";
		}
		else { cout << "]"; }
	}
}

// сохранить
string namef;
void save() {
	cout << "  Введите название файла ";
	getline(cin, namef);
	cout << "\n  Введите массив данных \n";
	inmas();
	ofstream File(namef);
	if (File.is_open()) {
		for (int i = 1; i <= N; i++) {
			File << masA[i - 1] << endl;
		}
		File.close();
		cout << "  Данные згружены в файл: " << namef << endl;
		Sleep(2000);
	}
	else {
		cout << "  Не удалось згрузить данные в файл" << endl;
		Sleep(1500);
	}
}
// загрузить
void load() {
	cout << "  Введите название файла ";
	getline(cin, namef);
	ifstream File(namef);
	int lineCount = 0;
	string line;
	while (getline(File, line)) {
		lineCount++;
	}
	if (File.is_open()) {
		if (lineCount >= N) {
			if (lineCount > N) {
				cout << " в массив были загружены первые " << N << " ,так как размер массива меньше размера файла";
			}
		}
		else {
			cout << "  размер массива больше размера файла, введите недостоющие элементы\n";
			for (int i = lineCount + 1; i <= N; i++) {
				string input;
				if (i == N) {
					SetColor(CL_RED, 0);
				}
				while (true) {
					cout << "  A[" << i << "]=";
					input = vvod();
					try {
						size_t pos = 0;
						masA[i - 1] = stod(input, &pos);
						if (pos == input.size()) {
							break;
						}
					}
					catch (const std::invalid_argument&) {}
				}
				SetColor();
			}
		}
		for (int i = 1; i <= N; i++) {
			File >> masA[i - 1];
		}
		File.close();
		cout << "\n  полученныe данные из файла: " << endl;
		outmas(masA);
		cout << endl;
	}
	else {
		cout << "  Не удалось открыть файл" << endl;
		Sleep(1500);
	}
}
// обработка массива
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
//текстовая таблица
void Tabletex(double* mas, int N, const string& title, const string& namep) {
	cout << title << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << namep << left << setw(4) << i + 1 << setw(2) << ":  " << setw(10) << left << mas[i] << endl;
	}

}
//графическая таблица
void Table(double* pmas, int pnsize, int pnsec, string pstitle) {
	HWND hwnd = (HWND)GetStdHandle(STD_OUTPUT_HANDLE);
	HDC hdc = GetDC(GetConsoleWindow());

	CONSOLE_FONT_INFO conf{};
	GetCurrentConsoleFont(hwnd, false, &conf);
	COORD cxy = CURSORPOS;


	int indentY = conf.dwFontSize.Y * (cxy.Y + 1), // отступ начала граф вывода
		indentX = 30;

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
}
